#include "VideoFileInfo.h"

#include <QFileInfo>

VideoFileInfo::VideoFileInfo(QString filename, QString modalidade ,int duration, int progress, Host* host, CVideoStatus status){
	QFileInfo fileInfo(filename);
	this->baseName = fileInfo.baseName() + "." + fileInfo.suffix();
	this->id = fileInfo.baseName();
	this->filename = filename;
	this->titulo = fileInfo.baseName();
	this->duration=duration;
	this->progress=progress;
	this->host = host;
	this->status = status;
	this->modalidade = modalidade;
	this->ip = host->ip;
	//qDebug("id [%s], titulo [%s], filename [%s]", this->id.toLatin1().data(), this->titulo.toLatin1().data(), this->filename.toLatin1().data());
}

QString VideoFileInfo::getDbTime() const
{
	return dbTime;
}

void VideoFileInfo::setDbTime(const QString &value)
{
	dbTime = value;
}

bool VideoFileInfo::getIsActiveUpload() const
{
	return isActiveUpload;
}

void VideoFileInfo::setIsActiveUpload(bool value)
{
	isActiveUpload = value;
}

void VideoFileInfo::setStatus(const CVideoStatus &value)
{
	status = value;

}

QString VideoFileInfo::getIp() const
{
	return ip;
}

QString VideoFileInfo:: getStatusString() const {
	switch (this->getStatus()) {
	case CVideoStatus::WAITING:
		return "ESPERANDO";
	case CVideoStatus::SENDING:
		return "ENVIANDO";
	case CVideoStatus::SENT:
		return "ENVIADO";
	case CVideoStatus::CANCELLED:
		return "CANCELADO";
	case CVideoStatus::ERROR:
		switch (getProgress()) {
		case CUploadServiceClient::NO_ERROR:
			return "SEM ERROS";
		case CUploadServiceClient::NO_POSSIBLE_CONNECTION_TO_HOST:
			return "IMPOSSIVEL CONECTAR-SE AO HOST";
		case CUploadServiceClient::CONNECTION_FAIL_WHILE_UPLOADING:
			return "FALHA DURANTE O ENVIO DO ARQUIVO";
		case CUploadServiceClient::FILE_DOSENT_EXIST:
			return "ARQUIVO NAO EXISTE";
		case CUploadServiceClient::UPLOAD_SERVICE_IS_OUT:
			return "UPLOAD_SERVICE_IS_OUT";
		case CUploadServiceClient::THERE_IS_NO_UPLOAD_AT_THIS_MOMENT:
			return "THERE_IS_NO_UPLOAD_AT_THIS_MOMENT";
		default:
			return "UNKNOWN_ERROR";
		}
		return "ERROR";
	default:
		return "UNKNOWN STATUS";
	}
}

CVideoStatus VideoFileInfo::getStatus() const
{
	return status;
}

Host *VideoFileInfo::getHost() const
{
	return host;
}

int VideoFileInfo::getDuration() const
{
	return duration;
}

QString VideoFileInfo::getModalidade() const
{
	return modalidade;
}

QString VideoFileInfo::getId() const
{
	return id;
}

QString VideoFileInfo::getTitulo() const
{
	return titulo;
}

QString VideoFileInfo::getBaseName() const
{
	return baseName;
}

QString VideoFileInfo::getFilename() const
{
	return filename;
}


bool VideoFileInfo::getWasAddedToTableWidget() const
{
	return wasAddedToTableWidget;
}

void VideoFileInfo::setWasAddedToTableWidget(bool value)
{
	wasAddedToTableWidget = value;
}

void VideoFileInfo:: updateProgress()
{
	CUploadServiceClientProgressResult progressResult = this->host->getProgressResult();
	if(progressResult.filename == this->filename) //só atualiza o progresso se o host tiver realmente upando esse arquivo
	{
		setIsActiveUpload(true);
		//qDebug("VideoFileInfo::updateProgress - progressResult: [%s] [%d]", filename.toLatin1().data(), progressResult.progress);
		this->progress = progressResult.progress;
	}
	else
	{
		setIsActiveUpload(false);
	}
}
int VideoFileInfo:: getProgress() const
{

	return this->progress;

}
void VideoFileInfo::setTitulo(const QString &value)
{
	titulo = value;
}

void VideoFileInfo::setFilename(const QString &value)
{
	filename = value;
}

void VideoFileInfo::setModalidade(const QString &value)
{
	modalidade = value;
}

void VideoFileInfo::setDuration(int value)
{
	duration = value;
}

void VideoFileInfo::setId(const QString &value)
{
	id = value;
}
