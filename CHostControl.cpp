#include "CHostControl.h"
#include "CTransferMonitor.h"
#include "CXmlTransferFinished.h"

#include <QFileInfo>
CHostControl::CHostControl(MainWindow* mainWindow) : mainWindow(mainWindow)
{
	CServiceUtils::KillAllTransferService();
	process1 = new QProcess();
	QThread::start();
	qDebug("CHostControl:: portasDisponiveis");
	for(int i=0; i<((endPort - startPort)/2); i++)
	{
		portasDisponiveis.append(startPort + (i*2)); //
		qDebug("port: [%d]", portasDisponiveis.at(i));
	}
}

QMutex &CHostControl::getHostsMutex()
{
	return hostsMutex;
}






MainWindow *CHostControl::getMainWindow() const
{
	return mainWindow;
}

Host *CHostControl::getHostByIp(QString ip)
{
	for(Host* host : getHosts())
	{
		if(host->getIp() == ip)
		{
			return host;
		}
		else
		{
			return nullptr;
		}
	}

}

void CHostControl::registerIp(QString ip)
{
	QMutexLocker locker(&hostsMutex);
	for(int i=0; i<hosts.size(); i++)
	{
		if(ip == hosts.at(i)->ip)
		{
			hosts.at(i)->setWasRemovedFromTableWidget(false); //se registerIp foi chamado mas o ip já existe no vetor de hosts
			return;											  //é porque o Host foi removido da interface mas ainda estava sendo usado pela lista de envios e agora foi adicionado na interface novamente
		}
	}
	int port = getNextAvailablePort();
	Host* host = new Host(ip, port);
	this->hosts.append(host);
	startTransferService(ip);


}
void CHostControl::removeHost(QString ip)
{
	QMutexLocker locker(&hostsMutex);
	for (int i=0; i<hosts.size(); i++) {
		Host* host = hosts.at(i);
		if(host->ip == ip)
		{

			CServiceUtils::KillTcpPort(host->port);
			freePort(host->port);
			delete host;
			this->hosts.remove(i);

		}
	}
}

void CHostControl::markHostAsRemovedFromTable(QString ip)
{
	QMutexLocker locker(&hostsMutex);
	for (int i=0; i<hosts.size(); i++) {
		Host* host = hosts.at(i);
		if(host->ip == ip)
		{
			qDebug("CHostControl::markHostAsRemovedFromTable - ip [%s]", ip);
			host->setWasRemovedFromTableWidget(true);
		}
	}
}

void CHostControl::deleteHostIfItsNotBeingUsed()
{
	QMutexLocker locker(&hostsMutex);
	for (int i=0; i<hosts.size(); i++) {
		Host* host = hosts.at(i);
		if(host->getWasRemovedFromTableWidget() && !host->isBeingUsed())
		{
			qDebug("hosts size: [%d]", hosts.size());
			freePort(host->port);
			CServiceUtils::KillTcpPort(host->port);
			this->hosts.remove(i);
			host->deleteLater();
			//delete host;

		}
	}
}
void CHostControl::startTransferServices()
{
	for (const Host* host : this->hosts) {
		QString ip = host->ip;
		int port = host->port;
		qDebug("CHostControl::startTransferServices - 1");
		qDebug("CHostControl::startTransferServices - Starting service at ip: [%s] on port: [%d]", ip.toLatin1().data(), port);
		qDebug("host.process = [%d]", host->process == nullptr ? 1 : 0);
		CServiceUtils::StartTransferService(host->process,"", ip, QString::number(port)); //pra cada máquina que receber o video, eu precisarei de um processo do transfer // por isso vou precisar de uma porta diferente pra cada transfer
		connect(host->process, &QProcess::readyReadStandardOutput, [&host]() mutable {
			QByteArray output = host->process->readAllStandardOutput();
			//qDebug() << output << "\n";
			QFile file(host->ip + ":" + QString::number(host->port) + ".txt");
			// Open the file in write mode
			if (!file.open(QIODevice::Append | QIODevice::Text)) {
				qCritical() << "Could not open file for writing";
				return;
			}
			// Create a QTextStream object for writing text to the file
			QTextStream out(&file);
			out.seek(file.size());
			// Write some text to the file
			out << output;
			file.close();
		});
	}

}

void CHostControl::startTransferService(QString ip)
{
	//QMutexLocker locker(&hostsMutex);
	for (const Host* host : this->hosts) {
		//QMutexLocker locker(&hostsMutex);
		if(host->ip == ip)
		{
			CServiceUtils::StartTransferService(host->process,"/mnt/AV1/NettoDigisend", ip, QString::number(host->port));
			connect(host->process, &QProcess::readyReadStandardOutput, [host]() mutable {
				QByteArray output = host->process->readAllStandardOutput();
				QFile file(host->ip + ":" + QString::number(host->port) + ".txt");
				if (!file.open(QIODevice::Append | QIODevice::Text)) {
					qCritical() << "Could not open file for writing";
					return;
				}
				QTextStream out(&file);
				out.seek(file.size());
				out << output;
				file.close();
			});
		}
	}

}

int CHostControl::getNextAvailablePort()
{
	if(!portasDisponiveis.isEmpty())
	{
		int port = portasDisponiveis.at(0);
		portasDisponiveis.removeFirst();
		return port;
	}
	qDebug("CHostControl::getNextAvailablePort - não há portas disponiveis!");
	return -1;
}

void CHostControl::freePort(int port)
{
	portasDisponiveis.append(port);
	QString antes;
	for(int porta : portasDisponiveis)
	{
		antes = antes + QString::number(porta) + ", ";
	}
	qDebug("freePort:: antes [%s]", antes.toLatin1().data());
	std::sort(portasDisponiveis.begin(), portasDisponiveis.end());
	QString depois;
	for(int porta : portasDisponiveis)
	{
		depois = depois + QString::number(porta) + " ";
	}
	qDebug("freePort:: depois [%s]", depois.toLatin1().data());
}



void CHostControl::markVideoAsSent(QString fileName, QString hostIp)
{
	qDebug("CHostControl::marVideoAsSent, ip [%s]", hostIp.toLatin1().data());
	QDateTime now = QDateTime::currentDateTime();
	QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
	QMutexLocker hostsLocker(&hostsMutex);
	QMutexLocker queueLocker(&getMainWindow()->getTransferMonitor()->getQueueMutex());
	for(Host* host : this->getHosts())
	{
		if(host->ip == hostIp)
		{
			host->setBusy(false);
		}
	}
	hostsLocker.unlock();
	for(VideoFileInfo* videoInfo : getMainWindow()->getTransferMonitor()->getCurrentQueue())
	{
		QFileInfo fileInfo(videoInfo->filename);
		QString videoInfo_fileName = fileInfo.fileName();
		QString numero = videoInfo->getId();
		QString titulo = videoInfo->getTitulo();
		QString modalidade = videoInfo->getModalidade();
		QString baseName = videoInfo->getBaseName();

		if(videoInfo_fileName == fileName && videoInfo->ip == hostIp)
		{
			videoInfo->setIsActiveUpload(false);
			/* Mesmo quando o video é cancelado pelo usuário, o transfer executa o callback que chama essa funcao "markVideoAsSent"
			por isso, precisamos checar se o video não foi cancelado antes de marcar ele como "enviado" */
			if(videoInfo->getStatus() != CVideoStatus::CANCELLED) //
			{

				videoInfo->setStatus(CVideoStatus::SENT);
				//qDebug("nowStr: [%s]", nowStr.toLatin1().data());
				//cadastra no banco de dados da máquina local (magosenddb)
//				MagoDB* db = new MagoDB();



//				db->AddHistoricoMagoSend(videoInfo->getId().toLatin1().data(),videoInfo->getTitulo().toLatin1().data(), videoInfo->getFilename().toLatin1().data(),videoInfo->getModalidade().toLatin1().data(),
//										videoInfo->getDuration(), videoInfo->getIp().toLatin1().data(),videoInfo->getStatusString().toLatin1().data(), nowStr.toLatin1().data(), getMainWindow()->getUsuario().toLatin1().data());
//				delete db;
				//cadastra o evento no banco de dados do Mago Host

//				MagoDB* magodb = new MagoDB(hostIp);
//				QString magosendIniFileName = QApplication::applicationDirPath() + "/Arquivos/MagoSend.ini";
//				QSettings settings(magosendIniFileName, QSettings::IniFormat);
//				QString magoMediaPath = settings.value("magoMediaPath").toString();
//				QString path = magoMediaPath + "/"+ baseName;
//				qDebug("CHostControl::markVideoAsSent -  gonna save in db the path: [%s]", path.toLatin1().data());
//				if(magodb->EventExistsByNumber(numero.toLatin1().data()))
//				{
//					qDebug("EventExistsByNumber");
//					magodb->UpdateEvent(numero.toLatin1().data(), numero.toLatin1().data(), path.toLatin1().data(), titulo.toLatin1().data(),0,0,0,0,"","",0,modalidade.toLatin1().data());
//				}
//				else
//				{

//					qDebug("magodb->addEvent path: [%s]", path.toLatin1().data());
//					magodb->AddEvent(numero.toLatin1().data(),path.toLatin1().data(), titulo.toLatin1().data(), 0, 0, 0, 0, "", "", 0,modalidade.toLatin1().data());
//				}
//				delete magodb;
			}
		}


	}
}


const QVector<Host*> &CHostControl::getHosts() const
{
	return this->hosts;
}

void CHostControl::run()
{
	//inicia o servidor XMLRpc deste servico...
	xmlRpcServer = new XmlRpc::XmlRpcServer();
	xmlRpcServer->bindAndListen(2000);
	xmlRpcServer->enableIntrospection(true);
	CXmlTransferFinished xmlTransferFinished(this);

	while(true)
	{
		xmlRpcServer->work(10000);
	}

	xmlRpcServer->close();
	delete xmlRpcServer;
}

XmlRpc::XmlRpcServer* CHostControl::getXmlRpcServer() const
{
	return xmlRpcServer;
}





