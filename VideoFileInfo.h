#ifndef VIDEOFILEINFO_H
#define VIDEOFILEINFO_H

#include "Host.h"


enum CVideoStatus {
WAITING=0,SENDING,SENT,CANCELLED, ERROR, TRYING_TO_CONNECT
};
class VideoFileInfo {
public:
	VideoFileInfo(QString filename, QString modalidade ,int duration, int progress, Host* host, CVideoStatus status);
	QString id;
	QString titulo;
	QString filename;
	QString baseName;
	QString modalidade;
	int duration;  // Duration in seconds
	bool wasAddedToTableWidget = false;
	Host* host;
	CVideoStatus status;
	QString ip;
	bool isActiveUpload;
	QString dbTime;
	void updateProgress();
	int getProgress() const;
	void setId(const QString &value);

	void setTitulo(const QString &value);

	void setFilename(const QString &value);

	void setModalidade(const QString &value);

	void setDuration(int value);

	bool getWasAddedToTableWidget() const;
	void setWasAddedToTableWidget(bool value);


	QString getFilename() const;

	QString getTitulo() const;
	QString getBaseName() const;

	QString getId() const;

	QString getModalidade() const;

	int getDuration() const;

	Host *getHost() const;

	CVideoStatus getStatus() const;

	QString getIp() const;
	QString getStatusString() const;

	void setStatus(const CVideoStatus &value);

	bool getIsActiveUpload() const;
	void setIsActiveUpload(bool value);

	QString getDbTime() const;
	void setDbTime(const QString &value);

private:
	int progress;
};
#endif // VIDEOFILEINFO_H
