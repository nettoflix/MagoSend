#include "CTransferMonitor.h"
#include "CHostControl.h"
#include <QMessageBox>

CTransferMonitor::CTransferMonitor(MainWindow* mainWindow)
{
	//this->moveToThread(this);
	//this->start();
	this->mainWindow = mainWindow;

	qDebug("run- 1");

	QThread::start();

}

CTransferMonitor::~CTransferMonitor()
{

}

QVector<VideoFileInfo*>& CTransferMonitor::getCurrentQueue()
{
	return currentQueue;
}

int CTransferMonitor::getProgress(QString ip, QString fileName)
{
	QMutexLocker queueLocker(&queueMutex);
	for(VideoFileInfo *videoInfo : this->getCurrentQueue())
	{
		if(videoInfo->host->ip == nullptr || videoInfo->filename == nullptr) break;
		//qDebug("VideoInfo progress: [%f]", videoInfo.progress);
		if(videoInfo->host->ip == ip && videoInfo->filename == fileName)
		{
			return videoInfo->getProgress();
		}
	}
	return -1;
}





void CTransferMonitor::populateQueue(QString filePath, QString ip)
{
	QMutexLocker hostsLocker(&getMainWindow()->getHostControl()->getHostsMutex());
	QMutexLocker queueLocker(&queueMutex);
	CHostControl* hostControl = getMainWindow()->getHostControl();
	for (Host* host : hostControl->getHosts()) {
		if(host->getIp() == ip)
		{if(!host->getWasRemovedFromTableWidget())
			{
				//qDebug("host was not removed, [%s]", filePath.toLatin1().data());
				int durationInSeconds = CServiceUtils::getVideoDuration(filePath);
				VideoFileInfo* file1= new VideoFileInfo(filePath,"", durationInSeconds, 0, host, CVideoStatus::WAITING);
				this->currentQueue.append(file1);
			}

		}
	}
}

void CTransferMonitor::removeFromQueue(int row)
{
	QMutexLocker queueLocker(&queueMutex);
	delete currentQueue.at(row);
	this->currentQueue.removeAt(row);
}
void CTransferMonitor::cancelActiveUpload(QString ip)
{
	QMutexLocker queueLocker(&queueMutex);
	QMutexLocker hostsLocker(&getMainWindow()->getHostControl()->getHostsMutex());
	Host* host = getMainWindow()->getHostControl()->getHostByIp(ip);
	if(host == nullptr || !host->isConnected) return;
	for(VideoFileInfo* videoInfo : this->getCurrentQueue())
	{
		if(host->getProgressResult().filename == videoInfo->filename && videoInfo->getIp()== ip)
		{
			videoInfo->status = CVideoStatus::CANCELLED;
			host->setShouldCancelUpload(true);
		}
	}

	qDebug("CTransferMonitor::cancelActiveUpload");


	//qDebug("CTransferMonitor::cancelActiveUpload - [%d]", host->getShouldCancelUpload());
}

VideoFileInfo *CTransferMonitor::getItemFromQueue(QString fileName, QString ip)
{
	//QMutexLocker queueLocker(&queueMutex);
	for (VideoFileInfo *videoInfo : this->getCurrentQueue())
	{
		if(fileName == videoInfo->filename && ip == videoInfo->host->ip)
		{
			//qDebug("videoInfo filename [%s], ip [%s], status [%d]",videoInfo.filename.toLatin1().data(),videoInfo.ip.toLatin1().data(), videoInfo.status);
			return videoInfo;
		}

	}
}

VideoFileInfo* CTransferMonitor::getItemFromQueue(int index)
{
	//QMutexLocker queueLocker(&queueMutex);
	if(index >=0 && index <= this->currentQueue.size())
	{
		return this->currentQueue.at(index);
	}
}

void CTransferMonitor::startUploads()
{
	this->isTransferring = true;
}

void CTransferMonitor::cancelUploads()
{
	this->isTransferring = false;
	QMutexLocker hostsLocker(&getMainWindow()->getHostControl()->getHostsMutex());
	for(Host* host : getMainWindow()->getHostControl()->getHosts())
	{
		hostsLocker.unlock();
		cancelActiveUpload(host->getIp());
		hostsLocker.relock();
	}


}


MainWindow *CTransferMonitor::getMainWindow() const
{
	return this->mainWindow;
}

QMutex& CTransferMonitor::getQueueMutex()
{
	return queueMutex;
}
void CTransferMonitor::runLogic()
{
	//this->quit();
	QElapsedTimer timer;
	timer.start();

	CHostControl* hostControl = getMainWindow()->getHostControl();
	QMutexLocker hostsLocker(&hostControl->getHostsMutex());
	//CUploadServiceClientProgressResult progressResult;
	//qDebug("run- 3");
	// pega o progresso e outras coisas relacionadas ao host
	for(int i=0; i<hostControl->getHosts().size(); i++)
	{
		Host* host = hostControl->getHosts().at(i);

		QString ip = host->ip;
		int port = host->port;


		if(getMainWindow() != nullptr && getMainWindow()->getWorker() != nullptr){
			if(!getMainWindow()->getWorker()->isPopulatingQueue)  //se a workerThread estiver adicionando itens na lista, nao pega esse lock pra nao travar ela
			{

				QMutexLocker queueLocker(&queueMutex);
				if(!host->isBusy() && isTransferring) //host esta disponivel e demos play nos envios, entao vamos pegar um video da lista pra enviar
				{
					for(VideoFileInfo *videoInfo : this->getCurrentQueue())
					{
						//if(!host->isBusy())
						//{
							CVideoStatus status = videoInfo->getStatus();
							QString videoIp = videoInfo->ip;
							QString videoFileName = videoInfo->filename;
							//envia os videos que estão esperando ser enviados
							if(status == CVideoStatus::WAITING && videoIp == host->getIp())
							{
								if(CUploadServiceClient::TellServiceToUploadFile(videoFileName, true, host->port, "127.0.0.1", "CXmlTransferFinished", 2000))
								{
									host->setBusy(true);
									qDebug("CTransferMonitor:run() - SENDING, videoInf: IP[%s], fileName [%s]", videoIp.toLatin1().data(), videoFileName.toLatin1().data());
									videoInfo->status = CVideoStatus::TRYING_TO_CONNECT;
									host->setCurrentUpload(videoInfo);
									break; //esse host já mandou enviar o video dele, então posso ir pro próximo host
								}
								else
								{
									qDebug("CTransferMonitor::TellServiceToUploadFile failed IP[%s], fileName [%s]", videoIp.toLatin1().data(), videoFileName.toLatin1().data());
								}
							}
					//	}

					}
				}
				queueLocker.unlock();
			}
		}



		bool shouldCancelUpload = host->getShouldCancelUpload();
		hostsLocker.unlock();

		//Usuário clicou no botão de cancelar o envio atual desse host
		if(shouldCancelUpload)
		{
			//qDebug("run() - should cancel");
			if(CUploadServiceClient::cancelActiveUpload(port))
			{
				CUploadServiceClient::deleteFileOnHost(ip,host->getProgressResult().filename);
				host->setShouldCancelUpload(false);
			}
			else
			{
				qDebug("run() - nao foi possivel cancelar ActiveUpload");
			}

		}

		//pergunto pro host qual o progresso do envio atual
		host->setProgressResult(CUploadServiceClient::AskServriceAboutItsProgress(host->port));

		VideoFileInfo* currentUpload = host->getCurrentUpload();
		if(currentUpload != nullptr)
		{
			//qDebug("run() - 1");

			int progresso = host->getProgressResult().progress;

			if(currentUpload->filename == host->getProgressResult().filename)
			{
				currentUpload->updateProgress(progresso);

				//qDebug("currentHost; [%s] currentUpload [%s] progress [%d], status [%d]",host->getIp().toLatin1().data(), currentUpload->getFilename().toLatin1().data(), progresso, currentUpload->getStatus());
				QString videoFileName = host->getProgressResult().filename;
				if(progresso != UploadFileStatus::THERE_IS_NO_UPLOAD_AT_THIS_MOMENT)
				{
					if(progresso < 0)
					{
						if(currentUpload->getStatus() == CVideoStatus::TRYING_TO_CONNECT || currentUpload->getStatus() == CVideoStatus::SENDING)
						{
							//qDebug("run() - 2");
							if(progresso == UploadFileStatus::TRYING_TO_CONNECT_TO_HOST)
							{
								currentUpload->setStatus(CVideoStatus::TRYING_TO_CONNECT);
							}
							else if(progresso == UploadFileStatus::HOST_IS_BUSY)
							{
								//	qDebug("CTransferMonitor::run - HOST IS BUSY!");
								currentUpload->setStatus(CVideoStatus::TRYING_TO_CONNECT);
							}
							else
							{

								currentUpload->setStatus(CVideoStatus::ERROR);
								currentUpload->host->setBusy(false);
								currentUpload->setIsActiveUpload(false);
								QDateTime now = QDateTime::currentDateTime();
								QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
								CMagoDBCommandsThread::commands->queuedAddHistoricoMagoSend(currentUpload->getId(),currentUpload->getTitulo(), currentUpload->getFilename(),currentUpload->getModalidade(),
																							currentUpload->getDuration(), currentUpload->getIp(),currentUpload->getStatusString(), nowStr, getMainWindow()->getUsuario());
								qDebug("CTransferMonitor:run() - 5");
							}
						}
					}
					else if(progresso > 0)
					{
						//qDebug("run() - 3");
						if(currentUpload->getStatus() == CVideoStatus::TRYING_TO_CONNECT)
						{
							qDebug("video [%s] setStatus(sending), progress: [%d]", videoFileName.toLatin1().data(), progresso);
							currentUpload->setStatus(CVideoStatus::SENDING);
						}
					}
				}
			}
		}

	}
	//this->setCurrentFilesUploading(currentFilesUp);
	hostsLocker.unlock();



	int queueSize = getCurrentQueue().size();


	//host nao esta sendo usado e já foi removido da lista, então deleta ele
	hostControl->deleteHostIfItsNotBeingUsed();

	//vamos dar um loop na lista, se encontrarmos alguem que esta esperando pra ser enviado, mantemos a lista em play,
	//caso todos os videos ja tenham sido enviados, podemos pausar a transferencia
	bool somebodyWaiting = false;
	for(int i=getCurrentQueue().size()-1; i>=0; i--)  //vamos de trás pra frente porque os videos que ainda nao foram enviados estao no final da lista
	{
		VideoFileInfo* videoInfo = getCurrentQueue().at(i);
		if(videoInfo->status == CVideoStatus::WAITING)
		{
			somebodyWaiting = true;
			break;
		}
	}
	if(!somebodyWaiting) isTransferring = false;
	//	queueLocker.unlock();
	qint64 elapsed = timer.elapsed();
	//qDebug("elapsedTime for queueSize: [%d]: [%d ms]", queueSize, elapsed);

}



void CTransferMonitor::run()
{
	//	QThread::exec();
	//qDebug("run- 2");
	while(true)
	{
		runLogic();
		QThread::msleep(70);

	}


}

