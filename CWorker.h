#ifndef CFILES_ON_HOST_H
#define CFILES_ON_HOST_H

#include <QString>
#include <QStringList>

// Define CFilesOnHost
class CFilesOnHost {
public:
	CFilesOnHost()
	{}
	CFilesOnHost(QString ip, QStringList filespath, bool couldConnect)
		: ip(ip), filespath(filespath), couldConnect(couldConnect) {}

	QString ip;
	QStringList filespath;
	bool couldConnect;
};

#endif // CFILES_ON_HOST_H

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "mainwindow.h"

// Define Worker class
class Worker : public QObject {
	Q_OBJECT
public:
	explicit Worker(MainWindow* mw);
	bool isPopulatingQueue = false;
	bool getIsPopulatingQueue() const;
	void setIsPopulatingQueue(bool value);

public slots:
	void getFilesAlreadyPresentOnHosts(QStringList filePaths);
	void checkIfIdExistsOnHosts(QString ip, QString id);
	void onPopulateQueueWithPaths(QStringList pathsToPopulate, QString ip);

signals:
	void filesAlreadyPresentOnHostsResult(QList<CFilesOnHost> listFilesOnHost);
	void idAlreadyExistOnHost(bool value);
	void queueDonePopulating();
private:
	MainWindow* mw;
};

#endif // WORKER_H
