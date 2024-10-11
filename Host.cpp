#include "Host.h"


Host::Host(QString ip, int port) : QObject(), ip(ip), port(port) {
    process = new QProcess();
    busy=false;
    bitRate = 0.0f;
    shouldCancelUpload = false;
    wasRemovedFromTableWidget = false;
    this->currentUpload = nullptr;
    client = new XmlRpc::XmlRpcClient("127.0.0.1", this->port);

}
Host::~Host()
{
    process->close();
    if(process != nullptr) delete process;
    process = nullptr;
    client->close();
    delete client;
}

VideoFileInfo *Host::getCurrentUpload() const
{
    return currentUpload;
}

void Host::setCurrentUpload(VideoFileInfo *value)
{

    if(value!=nullptr)
    {
        value->setIsActiveUpload(true);
    }
    else if(value==nullptr && currentUpload!=nullptr)
    {
        currentUpload->setIsActiveUpload(false);
    }
    currentUpload = value;
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
class UploadFileStatus;
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

CUploadServiceClientProgressResult Host::AskServriceAboutItsProgress()
{
	qDebug("CUploadServiceClient::AskServriceAboutItsProgress - 1 - IN");
    CUploadServiceClientProgressResult progressResult;
    progressResult.filename  = "";
    progressResult.progress  = CUploadServiceClient::UPLOAD_SERVICE_IS_OUT;
    progressResult.fileCount = 0;
    progressResult.bitRate = 0.0;



    XmlRpc::XmlRpcValue result2;
    XmlRpc::XmlRpcValue args2;

    client->reforceConnection();
    //timeout em segundos...
    if (client->execute("CXmlGetSentFileProgress", args2, result2, 3))
    {
		//qDebug("CUploadServiceClient::AskServriceAboutItsProgress - 2");
        std::string sFilename = result2[0];
        int progress = result2[1];
        int count = result2[2];
        std::string bitrate_str = result2[3];
        float bitrate = std::stof(bitrate_str);
        //qDebug("float bitRate: [%.2f]", bitrate);
        progressResult.filename  = QString::fromStdString(sFilename);
        progressResult.progress  = progress;
        progressResult.fileCount = count;
        progressResult.bitRate = bitrate;

        this->setProgressResult(progressResult);
		qDebug("Host::AskServriceAboutItsProgress progress: %d", this->getProgressResult().progress);
        return progressResult;

    }
    else
    {
		qDebug("CUploadServiceClient::AskServriceAboutItsProgress - 3");
        this->setProgressResult(progressResult);
        return progressResult;
    }
}
bool Host::TellServiceToUploadFile(QString filename, bool isSendInSilentMode, QString adviseAfterEndingIP, QString adviseAfterEndingMethodName, int adviseAfterEndingPort, QString targetSubFolder, float timeout)
{

    qDebug("CUploadServiceClient::1- port [%d]", port);



    XmlRpc::XmlRpcValue result;
    XmlRpc::XmlRpcValue args;

    //qDebug("CUploadServiceClient::2");

    QString fullFilePath = filename;
    QString filenameD = fullFilePath;
    args[0] = filenameD.toStdString();
    if (isSendInSilentMode)
    {
        args[1] = (int)1;
    }
    else
    {
        args[1] = (int)0;
    }

    //qDebug("CUploadServiceClient::3");

    args[2] = adviseAfterEndingIP.toStdString();
    args[3] = adviseAfterEndingMethodName.toStdString();
    args[4] = adviseAfterEndingPort;
    args[5] = targetSubFolder.toStdString();

    client->reforceConnection();

    //qDebug("CUploadServiceClient::4");
    //qDebug("CUploadServiceClient:: port [%d]", port);
    //timeout em segundos...
    if (client->execute("CXmlSendFile", args, result, timeout))
    {
		//qDebug("CUploadServiceClient::TRUE");
        qDebug("CUploadServiceClient::Marcado para envio [%s]", filename.toLatin1().data());

        return true;
    }
    else
    {
		//qDebug("CUploadServiceClient::FALSE");
        return false;
    }
}




