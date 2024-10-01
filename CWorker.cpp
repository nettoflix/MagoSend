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
	checkConnectionTimer->start(100);

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
	//	MagoDB* magodb = new MagoDB(ip);
	//	bool exists = magodb->EventExistsByNumber(id.toLatin1().data());
	//	qDebug("Worker::checkIfIdExistsOnHosts - exists [%d]", exists);
	//	emit idAlreadyExistOnHost(exists);
}
void Worker::onPopulateQueueWithPaths(QStringList pathsToPopulate, QString ip)
{
	setIsPopulatingQueue(true);
	qDebug("Worker::onPopulateQueueWithPaths -1 ");
	//qDebug() << "populateQueueWithPaths: Current thread ID: " << QThread::currentThreadId() << "IP:" << ip;
	QMutexLocker hostsLocker(&mw->getHostControl()->getHostsMutex());
	qDebug("Worker::onPopulateQueueWithPaths -2 ");
	QMutexLocker queueLocker(&mw->getTransferMonitor()->getQueueMutex());
	qDebug("Worker::onPopulateQueueWithPaths -3 ");
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
					//qDebug("host was not removed, [%s]", filePath.toLatin1().data());
					//qDebug("Worker::onPopulateQueueWithPaths - 1");
					int durationInSeconds = CServiceUtils::getVideoDuration(filePath);
					//qDebug("Worker::onPopulateQueueWithPaths - 2");

					VideoFileInfo* file1= new VideoFileInfo(filePath,"", durationInSeconds, 0, host, CVideoStatus::WAITING);
					mw->getTransferMonitor()->getCurrentQueue().append(file1);
					if(count >=20)
					{
						count = 0;
						//qDebug("Worker::onPopulateQueueWithPaths - SLEEP");
						//						if(ip == "192.168.0.145")
						//						{
						//							qDebug("Worker::onPopulateQueueWithPaths - SLEEP");

						//						}
						QThread::msleep(10);
					}
				}
			}
		}

	}

	setIsPopulatingQueue(false);
	qDebug("Worker::onPopulateQueueWithPaths -4 ");
	hostsLocker.unlock();
	queueLocker.unlock();
		qDebug("Worker::onPopulateQueueWithPaths -emit queueDonePopulating - 5 ");
	emit queueDonePopulating();

	qDebug("Worker::onPopulateQueueWithPaths -6 ");


}
