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
	QTimer* checkConnectionTimer;
	explicit Worker(MainWindow* mw);
	~Worker();
	bool isPopulatingQueue = false;
	bool getIsPopulatingQueue() const;
	void setIsPopulatingQueue(bool value);
	void startCheckTimer();
	void onCheckConnection();

public slots:
	void getFilesAlreadyPresentOnHosts(QStringList filePaths);
	void checkIfIdExistsOnHosts(QString ip, QString id);
	void onPopulateQueueWithPaths(QStringList pathsToPopulate, QString ip);
	void onGetModalidadesFromHosts(QStringList hosts);

signals:
	void filesAlreadyPresentOnHostsResult(QList<CFilesOnHost> listFilesOnHost);
	void idAlreadyExistOnHost(bool value);
	void queueDonePopulating();
	void hostTableTextColorChanged(QColor color, QString ip);
	void loadMods(QList<QPair<QStringList, QString>> modalidades);
private:
	MainWindow* mw;
};

#endif // WORKER_H
