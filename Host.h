#ifndef HOST_H
#define HOST_H
#include <CUploadServiceClient.h>
#include <QProcess>
#include <QString>
enum CHostState{
	UNVERIFIED = 0, HOST_ERROR, CONNECTED
};
class Host : public QObject
{
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

private:
	CUploadServiceClientProgressResult progressResult;
	int useCount = 0;
};

#endif // HOST_H

