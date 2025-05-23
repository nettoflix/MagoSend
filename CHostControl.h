#ifndef CHOSTCONTROL_H
#define CHOSTCONTROL_H

#include <QVector>
#include "CServiceUtils.h"
#include "CUploadServiceClient.h"
#include <QProcess>
#include <QDebug>
#include <XmlRpc.h>
#include <QThread>
#include <QFile>
#include "CTransferMonitor.h"
#include "Host.h"
#include "mainwindow.h"
//#include <QTcpServer>

class MainWindow;
class CTransferMonitor;

class CHostControl : public QThread
{
public:
	CHostControl(MainWindow* mainWindow);

private:

	MainWindow* mainWindow;
	XmlRpc::XmlRpcServer* xmlRpcServer;
	QVector<Host*> hosts;
	QMutex hostsMutex;

	quint16 startPort = 20000;
	quint16 endPort = 20050;
	//
	QVector<int> portasDisponiveis;

	int controlPort = 1700;
	QProcess* process1;
	//functions
public:
	void run();
	void registerIp(QString ip);
	void removeHost(QString ip);
	void markHostAsRemovedFromTable(QString ip);
	void deleteHostIfItsNotBeingUsed();
	void startTransferServices();
	void startTransferService(QString ip);
	int getNextAvailablePort();
	void freePort(int port);
	void markVideoAsSent(QString fileName, QString hostIp);


	const QVector<Host*> &getHosts() const;
	XmlRpc::XmlRpcServer* getXmlRpcServer() const;
	MainWindow *getMainWindow() const;
	Host* getHostByIp(QString ip);





	QMutex &getHostsMutex();
};

#endif // CHostControl_H
