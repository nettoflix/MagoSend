#ifndef HOST_H
#define HOST_H
#include <CUploadServiceClient.h>
#include <QProcess>
#include <QString>
#include "VideoFileInfo.h"
#include <QObject>
class VideoFileInfo;
enum CHostState{
	UNVERIFIED = 0, HOST_ERROR, CONNECTED
};
class Host : public QObject
{
	Q_OBJECT
public:
	Host(QString ip, int port);
	~Host();
	QString ip;
	int port;
	QProcess* process;
	CHostState state;
	bool busy;
	float bitRate;
	bool wasRemovedFromTableWidget;
	bool shouldCancelUpload;
	bool isConnected;
	VideoFileInfo* currentUpload;
	//aqui e sempre local o ip, pq o servico que envia e local...
	XmlRpc::XmlRpcClient* client;
	const bool isBusy();
	void setBusy(bool busy);
	void setBitRate(float value);
	float getBitRate();
	void setShouldCancelUpload(bool value);
	bool getShouldCancelUpload() const;
	void resetUseCount();
	void addUseCount();
	void setConnected(bool value);
	bool isBeingUsed();

	CUploadServiceClientProgressResult getProgressResult() const;
	void setProgressResult(const CUploadServiceClientProgressResult &value);

	bool getWasRemovedFromTableWidget() const;
	void setWasRemovedFromTableWidget(bool value);

	QString getIp() const;

	bool getIsConnected() const;

	VideoFileInfo *getCurrentUpload() const;
	void setCurrentUpload(VideoFileInfo *value);
	CUploadServiceClientProgressResult AskServriceAboutItsProgress();
public slots:
	bool TellServiceToUploadFile(QString filename, bool isSendInSilentMode = false, QString adviseAfterEndingIP = "", QString adviseAfterEndingMethodName = "", int adviseAfterEndingPort = 0, QString targetSubFolder = "", float timeout = 3);
private:
	CUploadServiceClientProgressResult progressResult;
	int useCount = 0;
};

#endif // HOST_H

