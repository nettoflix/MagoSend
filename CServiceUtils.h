#ifndef CSERVICEUTILS_H
#define CSERVICEUTILS_H

#define MAGO_TRANSFER_SERVER_PORT_1	1655
#define MAGO_TRANSFER_SERVER_PORT_2	1656

#include <QString>
#include <QProcess>
#include <QApplication>
#include <QFile>
extern "C"
{
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
}


class CServiceUtils
{
public:
	CServiceUtils();

	static void KillAllServicesWithThisname(QString name);
	static void KillAllTransferService();
	static void StartTransferService(QProcess* process1, QString localPath, QString remoteIp, QString port);
	static bool KillTcpPort(int portId);
	static int getVideoDuration(QString filePath);
	static bool isValidIPv4format(QString ip);
	static bool isValidFilename(QString filename);

};

#endif // CSERVICEUTILS_H
