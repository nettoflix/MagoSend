#include "CWorker.h"
Worker::Worker(MainWindow* mw)
{
	this->mw = mw;
	QObject::connect(this, &Worker::hostTableTextColorChanged, mw, &MainWindow::changeHostsTableTextColor, Qt::QueuedConnection);
}

Worker::~Worker()
{
	delete checkConnectionTimer;
}

bool Worker::getIsPopulatingQueue() const
{
	return isPopulatingQueue;
}

void Worker::setIsPopulatingQueue(bool value)
{
	isPopulatingQueue = value;
}

void Worker::startCheckTimer()
{
	checkConnectionTimer = new QTimer();
	connect(checkConnectionTimer, &QTimer::timeout, this,&Worker::onCheckConnection);
	checkConnectionTimer->start(500);

}

void Worker::onCheckConnection()
{

	//qDebug() << "onCheckConnection: Current thread ID:" << QThread::currentThreadId();
	//QMutexLocker hostsLocker(&getMainWindow()->getHostControl()->getHostsMutex());
	for(Host* host : mw->getHostControl()->getHosts())
	{
		bool isConnected = CUploadServiceClient::CheckConnection(host->ip);
		if(isConnected)// && !host->getIsConnected())
		{
			//qDebug("[%s] is connected!", ip.toLatin1().data());
			host->setConnected(true);

			emit hostTableTextColorChanged(QColor(Qt::green), host->ip);
		}
		else if(!isConnected)// && host->getIsConnected())
		{
			//qDebug("[%s] is NOT connected!", ip.toLatin1().data());
			host->setConnected(false);
			emit hostTableTextColorChanged(QColor(Qt::red), host->ip);
		}
	}


}

void Worker::getFilesAlreadyPresentOnHosts(QStringList filePaths)
{

	QList<CFilesOnHost> listFilesOnHost;
	qDebug("Worker::getFilesAlreadyPresentOnHosts-1- filePaths size: [%d]", filePaths.size());
	QMutexLocker hostsLocker(&mw->getHostControl()->getHostsMutex());
	QElapsedTimer timer;
	timer.start();
	for(Host* host : mw->getHostControl()->getHosts())
	{
		bool couldConnect;
		qDebug("Worker::getFilesAlreadyPresentOnHosts-2");
		//list << "getFilesAlreadyPresentOnHost:resultTest1" << "getFilesAlreadyPresentOnHost:resultTest2";
		QStringList listToPutExistingFileNames;
		couldConnect = CUploadServiceClient::checkIfVideosExistOnHost(host->getIp(), filePaths, listToPutExistingFileNames);
		//if(!listToPutExistingFileNames.isEmpty())
		//{
		listFilesOnHost.append(CFilesOnHost(host->ip, listToPutExistingFileNames, couldConnect));
		//}

	}
	qint64 elapsed = timer.elapsed();  // Measure the elapsed time in milliseconds
	qDebug() << "Worker::Time elapsed:" << elapsed << "milliseconds";
	qDebug("Worker::getFilesAlreadyPresentOnHosts - 4");
	hostsLocker.unlock();
	emit filesAlreadyPresentOnHostsResult(listFilesOnHost);

}

void Worker::checkIfIdExistsOnHosts(QString ip, QString id)
{
		MagoDB* magodb = new MagoDB(ip.toLatin1().data(), false);
		bool exists = magodb->EventExistsByNumber(id.toLatin1().data());
	//	qDebug("Worker::checkIfIdExistsOnHosts - exists [%d]", exists);
		emit idAlreadyExistOnHost(exists);
}
void Worker::onPopulateQueueWithPaths(QStringList pathsToPopulate, QString ip)
{
	qDebug("Worker::onPopulateQueueWithPaths - IN");
	setIsPopulatingQueue(true);
	QMutexLocker hostsLocker(&mw->getHostControl()->getHostsMutex());
	QMutexLocker queueLocker(&mw->getTransferMonitor()->getQueueMutex());
	CHostControl* hostControl = mw->getHostControl();
	for (Host* host : hostControl->getHosts()) {

		if(host->getIp() == ip)
		{
			if(!host->getWasRemovedFromTableWidget())
			{
				int count = 0;
				for(QString filePath : pathsToPopulate)
				{
					count++;
					int durationInSeconds = CServiceUtils::getVideoDuration(filePath);
					VideoFileInfo* file1= new VideoFileInfo(filePath,"", durationInSeconds, 0, host, CVideoStatus::WAITING);
					mw->getTransferMonitor()->getCurrentQueue().append(file1);
				}
			}
		}

	}
	setIsPopulatingQueue(false);
	hostsLocker.unlock();
	queueLocker.unlock();
	qDebug("Worker::onPopulateQueueWithPaths - queueDonePopulating");
	emit queueDonePopulating();
}

void Worker::onGetModalidadesFromHosts(QStringList hosts)
{
	QList<QPair<QStringList, QString>> modList;
	for(int i=0; i<hosts.size(); i++)
	{
		MagoDB* magodb = new MagoDB(hosts.at(i).toLatin1().data(), false);
		QStringList hostModalidades = magodb->getModalidadesMago();
		modList << QPair<QStringList,QString>(hostModalidades, hosts.at(i));

		delete magodb;
	}
	emit loadMods(modList);

}
