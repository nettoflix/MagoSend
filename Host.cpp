#include "Host.h"


Host::Host(QString ip, int port) : QObject(), ip(ip), port(port) {
	process = new QProcess();
	busy=false;
	bitRate = 0.0f;
	shouldCancelUpload = false;
	wasRemovedFromTableWidget = false;

}
Host::~Host()
{
	process->close();
	if(process != nullptr) delete process;
	process = nullptr;
}

bool Host::getIsConnected() const
{
	return isConnected;
}

QString Host::getIp() const
{
	return ip;
}

bool Host::getWasRemovedFromTableWidget() const
{
	return wasRemovedFromTableWidget;
}

void Host::setWasRemovedFromTableWidget(bool value)
{
	wasRemovedFromTableWidget = value;
}

bool Host::getShouldCancelUpload() const
{
	return shouldCancelUpload;
}

void Host::resetUseCount()
{
	this->useCount = 0;
}

void Host::addUseCount()
{
	useCount++;
}

void Host::setConnected(bool value)
{
	this->isConnected = value;
}

bool Host::isBeingUsed()
{
	if(useCount == 0) return false;
	return true;
}

CUploadServiceClientProgressResult Host::getProgressResult() const
{
//	qDebug << "Get progress reesult: thread: " << QThread::currentThread();
	return progressResult;
}

void Host::setProgressResult(const CUploadServiceClientProgressResult &value)
{
	progressResult = value;
	setBitRate(value.bitRate);
}

void Host::setShouldCancelUpload(bool value)
{
	qDebug("Host::setShouldCancelUpload");
	shouldCancelUpload = value;
}

const bool Host::isBusy()
{
	return this->busy;
}

void Host::setBusy(bool busy)
{
	this->busy = busy;
}

void Host::setBitRate(float value)
{
	this->bitRate = value;
}

float Host::getBitRate()
{
	return this->bitRate;
}




