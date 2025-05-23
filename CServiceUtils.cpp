#include "CServiceUtils.h"

#include <QRegExpValidator>




CServiceUtils::CServiceUtils()
{

}
void CServiceUtils::KillAllTransferService()
{
#ifdef _WIN32
	KillAllServicesWithThisname("4SMagoTransferServer.exe");
#else
	KillAllServicesWithThisname("4SMagoTransferServer");

	//por garantia, caso o transfer server esteja preso por motivos de problemas com rede,
	//mandaremos o linux matar quem controla as portas do TransferServer, no caso, ele mesmo...
	CServiceUtils::KillTcpPort(MAGO_TRANSFER_SERVER_PORT_1);
	CServiceUtils::KillTcpPort(MAGO_TRANSFER_SERVER_PORT_2);
#endif
}
void CServiceUtils::KillAllServicesWithThisname(QString name)
{
#ifdef WIN32
	QStringList appIds = COpenedWindows::getAllOpenedWindowsIDThathStarWith(name.toLatin1().data());
	for (int i = 0; i < appIds.size(); i++)
	{
		QString killCommand = "taskkill /PID " + appIds[i] + " /f";
		qDebug("CServiceUtils::killAllInputServices() : killcommand [%s]", killCommand.toLatin1().data());

		QStringList params;
		params << "/c" << killCommand;
		QProcess* myProcess = new QProcess();
		myProcess->start("cmd.exe", params);
		myProcess->waitForFinished(INT_MAX);
	}
#else
	{
		QString killCommand = "pkill";
		QStringList params;
		params << "-9";
		params << "-f";
		params << name;
		QProcess* myProcess = new QProcess();
		myProcess->start(killCommand, params);
		myProcess->waitForFinished(INT_MAX);
	}
#endif
}
void CServiceUtils::StartTransferService(QProcess* process1, QString localPath, QString remoteIp, QString port)
{
	QProcess* process;
	if(process1 == nullptr)
	{
	process = new QProcess();
	}
	else
	{
		process = process1;
	}

	QStringList args;
	args.append(localPath);
	args.append(remoteIp);
	args.append(port);
	args.append("false"); //shouldLoadList = false

#ifdef _WIN32
	QString appName(QApplication::instance()->applicationDirPath() + "/4SMagoTransferServer.exe");
#else
	QString appName(QApplication::instance()->applicationDirPath() + "/4SMagoTransferServer");
#endif

	if (QFile::exists(appName))
	{
		//process->setStandardOutputFile(QProcess::nullDevice());
		//process->setStandardErrorFile(QProcess::nullDevice());
		//process->setStandardInputFile(QProcess::nullDevice());
		process->start(appName, args);
		if(process->waitForStarted())
		{
			qDebug("Processo do TransferServer não iniciou");
		}
		else
		{
			qDebug("Processo do TransferServer iniciado");
		}

	}

}
bool CServiceUtils::KillTcpPort(int portId)
{
	QString killCommand = "fuser";
	QStringList params;
	params << "-k";
	params << QString::number(portId) + "/tcp";
	QProcess* myProcess = new QProcess();
	myProcess->start(killCommand, params);
	return myProcess->waitForFinished(INT_MAX);
}

//int CServiceUtils:: getVideoDuration(QString filePath){
//	const char* inputFilename = filePath.toUtf8().constData();
//	 AVFormatContext* formatContext = avformat_alloc_context();

//	 // Open the media file
//	 if (avformat_open_input(&formatContext, inputFilename, nullptr, nullptr) != 0) {
//		 qDebug("Error: Couldn't open file.");
//	 }
//	// avformat_find_stream_info(formatContext, NULL); - to work with video types that have no headers such as MPEG

//	 // Retrieve stream information
//	 if(formatContext== nullptr) return -1;
//	 if (avformat_find_stream_info(formatContext, nullptr) < 0) {
//		 qDebug("Error: Couldn't find stream information.");
//	 }

//	 // Get duration in seconds
//	 int durationInSeconds = formatContext->duration / AV_TIME_BASE;

//	// qDebug("Duration: [%d] seconds", durationInSeconds);
//	 avformat_close_input(&formatContext);
//	 avformat_free_context(formatContext);

//	 return durationInSeconds;

//}

int CServiceUtils::getVideoDuration(QString filePath) {
	if (filePath.isEmpty()) {
		//qDebug("Error: File path is empty.");
		return -1;
	}
	av_log_set_level(AV_LOG_ERROR); // tira os logs de warning

	// Convert QString to std::string
	std::string inputFilename = filePath.toStdString();

	AVFormatContext* formatContext = avformat_alloc_context();
	//qDebug("File path: [%s]", inputFilename.c_str());
	// Open the media file
	if (avformat_open_input(&formatContext, inputFilename.c_str(), nullptr, nullptr) != 0) {
		//qDebug("Error: Couldn't open file.");
		avformat_free_context(formatContext);
		return -1;
	}

	// Retrieve stream information
	if (formatContext == nullptr) {
		//qDebug("Error: Format context is null.");
		avformat_close_input(&formatContext);
		return -1;
	}

	if (avformat_find_stream_info(formatContext, nullptr) < 0) {
		//qDebug("Error: Couldn't find stream information.");
		avformat_close_input(&formatContext);
		return -1;
	}

	// Get duration in seconds
	int durationInSeconds = formatContext->duration / AV_TIME_BASE;

	// Clean up
	avformat_close_input(&formatContext);
	avformat_free_context(formatContext);

	return durationInSeconds;
}

bool CServiceUtils::isValidIPv4format(QString ip)
{
	// Expressão regular para endereços IPV4 válidos
	QRegExp regExp("^((25[0-5]|(2[0-4]|1[0-9]|[1-9]|)[0-9])(\.(?!$)|$)){4}$");
	QRegExpValidator validator(regExp);
	int pos =0;
	QValidator::State state = validator.validate(ip,pos);
	if(state == QValidator::Acceptable)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CServiceUtils::isValidFilename(QString filename) {
	QRegularExpression invalidPattern("[/\\\\:*?\"<>|\\^%&;\\[\\]{}\`'~$+,]");//caracteres especiais
	int countDot = filename.count('.');
	if(countDot > 1) return false; //nao aceita nomes de arquivos com pontos (o unico ponto permitido é do da extensao)
	return !filename.contains(invalidPattern);
}
bool CServiceUtils::isValidIDname(QString filename) {
	QRegularExpression invalidPattern("[/\\\\:*?\"<>|\\^%&;\\[\\]{}\`'~$+,]");//caracteres especiais
	int countDot = filename.count('.'); //tambem nao aceita pontos
	if(countDot > 0) return false;
	return !filename.contains(invalidPattern);
}
