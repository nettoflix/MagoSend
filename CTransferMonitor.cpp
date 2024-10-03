#include "CTransferMonitor.h"
#include "CHostControl.h"
#include <QMessageBox>

CTransferMonitor::CTransferMonitor(MainWindow* mainWindow)
{
	//this->moveToThread(this);
	//this->start();
	this->mainWindow = mainWindow;

	qDebug("run- 1");
	magoDbCommandsThread = new CMagoDBCommandsThread();
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
		//currentFilesUp << CurrentUpload(host->getProgressResult().filename,host->getIp());
		host->resetUseCount();
	}
	//this->setCurrentFilesUploading(currentFilesUp);
	hostsLocker.unlock();

	if(getMainWindow() != nullptr && getMainWindow()->getWorker() != nullptr){
		if(getMainWindow()->getWorker()->isPopulatingQueue) return; //se a workerThread estiver adicionando itens na lista, nao pega esse lock pra nao travar ela
	}
	//envia os videos que estão esperando ser enviados, atualiza o progresso do envio atual de acordo com o progresso do Host e atualiza o status do video
	QMutexLocker queueLocker(&queueMutex);
	int count = 0;
	int waitingCount = 0;
	int queueSize = getCurrentQueue().size();
	for(VideoFileInfo *videoInfo : this->getCurrentQueue())
	{
		count++;
		if(videoInfo->getStatus() != WAITING && videoInfo->getStatus() != SENDING && videoInfo->getStatus() != TRYING_TO_CONNECT)
		{
			continue; //esse video já foi enviado ou já deu erro, não tem o que fazer a partir daqui
		}
		else{
			//qDebug("count: [%d]", count);
			//qDebug("run()-1");
			videoInfo->host->addUseCount(); //host está sendo usado por esse video
			bool isBusy = videoInfo->host->isBusy();

			int hostPort = videoInfo->host->port;
			CVideoStatus status = videoInfo->getStatus();
			QString hostIp = videoInfo->ip;
			QString videoFileName = videoInfo->filename;
			//queueLocker.unlock();
			//qDebug("run()-1");
			if(status == CVideoStatus::WAITING)
			{
					waitingCount++;
				if(isTransferring && !isBusy)
				{

					//qDebug("run()-2");
					//qDebug("isTransferring: [%d], isBusy: [%d]", isTransferring, isBusy);



					if(CUploadServiceClient::TellServiceToUploadFile(videoFileName, true, hostPort, "127.0.0.1", "CXmlTransferFinished", 2000))
					{
						//queueLocker.relock();
						videoInfo->host->setBusy(true);
						qDebug("CTransferMonitor:run() - SENDING, videoInf: IP[%s], fileName [%s]", hostIp.toLatin1().data(), videoFileName.toLatin1().data());
						videoInfo->status = CVideoStatus::TRYING_TO_CONNECT;
						//queueLocker.unlock();
					}
					else
					{
						qDebug("CTransferMonitor::TellServiceToUploadFile failed IP[%s], fileName [%s]", hostIp.toLatin1().data(), videoFileName.toLatin1().data());
					}

				}
			}

			videoInfo->updateProgress();
			int progresso = videoInfo->getProgress();
			if(progresso < 0)
			{
				//qDebug("CTransferMonitor:run() -4");
				//qDebug() << "CTransferMonitor::run - progresso: [%s]" << progresso;
				if(videoInfo->getStatus() == CVideoStatus::TRYING_TO_CONNECT || videoInfo->getStatus() == CVideoStatus::SENDING)
				{
					if(progresso == UploadFileStatus::TRYING_TO_CONNECT_TO_HOST)
					{
						videoInfo->setStatus(CVideoStatus::TRYING_TO_CONNECT);
					}
					else if(progresso == UploadFileStatus::HOST_IS_BUSY)
					{
						qDebug("CTransferMonitor::run - HOST IS BUSY!");
						videoInfo->setStatus(CVideoStatus::TRYING_TO_CONNECT);
					}
					else
					{

						videoInfo->setStatus(CVideoStatus::ERROR);
						videoInfo->host->setBusy(false);
						videoInfo->setIsActiveUpload(false);
						QDateTime now = QDateTime::currentDateTime();
						QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
						CMagoDBCommandsThread::commands->queuedAddHistoricoMagoSend(videoInfo->getId(),videoInfo->getTitulo(), videoInfo->getFilename(),videoInfo->getModalidade(),
																					videoInfo->getDuration(), videoInfo->getIp(),videoInfo->getStatusString(), nowStr, getMainWindow()->getUsuario());
						qDebug("CTransferMonitor:run() - 5");
					}
				}
			}
			else if(progresso > 0)
			{
				if(videoInfo->getStatus() == CVideoStatus::TRYING_TO_CONNECT)
				{
					qDebug("video [%s] setStatus(sending), progress: [%d]", videoFileName.toLatin1().data(), progresso);
					videoInfo->setStatus(CVideoStatus::SENDING);
				}
			}
		}

	}


	//host nao esta sendo usado e já foi removido da lista, então deleta ele
	hostControl->deleteHostIfItsNotBeingUsed();

	queueLocker.unlock();

	if(waitingCount <= 0) //como nao tem nenhum item esperando pra ser enviado, todos já foram enviados, entao pode pausar a transfêrencia
	{
		isTransferring = false;
	}
	qint64 elapsed = timer.elapsed();
	qDebug("elapsedTime for queueSize: [%d]: [%d ms]", queueSize, elapsed);

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

