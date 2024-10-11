#ifndef CTRANSFERMONITOR_H
#define CTRANSFERMONITOR_H
#include <QThread>
#include <QTimer>
//#include "CHostControl.h"
#include "CMagoDBCommandsThread.h"
#include "CUploadServiceClient.h"
#include "Host.h"
#include "VideoFileInfo.h"
#include <QVector>
#include <QColor>
class MainWindow;
class CurrentUpload
{
public:
	CurrentUpload(QString name, QString ip): name(name), ip(ip)
	{}
	QString name;
	QString ip;
};
enum UploadFileStatus
{
	NO_ERROR = 0,
	NO_POSSIBLE_CONNECTION_TO_HOST = -1,
	CONNECTION_FAIL_WHILE_UPLOADING = -2,
	FILE_DOSENT_EXIST = -3,
	UPLOAD_SERVICE_IS_OUT = -4,
	THERE_IS_NO_UPLOAD_AT_THIS_MOMENT = -5,
	TRYING_TO_CONNECT_TO_HOST = -6,
	HOST_IS_BUSY = -7
};
class CHostControl;
class CTransferMonitor : public QThread
{
Q_OBJECT


private:
	QMutex queueMutex;
	MainWindow* mainWindow;
	bool isTransferring = false;
	QVector<VideoFileInfo*> currentQueue;
	//bool isPopulatingQueue = false;
	QTimer* timer;
    QElapsedTimer timer_;
	QTimer* checkConnectionTimer;
	void run();
	private slots:
		void runLogic();

public:
	CTransferMonitor(MainWindow* mainWindow);
	~CTransferMonitor();
	//CMagoDBCommandsThread* magoDbCommandsThread;
	QThread workerThread;
	void populateQueue(QString filePath, QString ip);
	//void onPopulateQueueWithPaths(QStringList pathsToPopulate, QString ip);
	void removeFromQueue(int row);
	void cancelActiveUpload(QString ip);
	void startUploads();
	void cancelUploads();


	QList<CurrentUpload> currentFilesUploading;
	MainWindow *getMainWindow() const;
	QMutex& getQueueMutex();
	VideoFileInfo* getItemFromQueue(QString fileName, QString ip);
	VideoFileInfo* getItemFromQueue(int index);
	QVector<VideoFileInfo*>& getCurrentQueue();
	int getProgress(QString ip, QString fileName);
signals:
		void showErrorMessage(QString error);



};

#endif // CTRANSFERMONITOR_H
