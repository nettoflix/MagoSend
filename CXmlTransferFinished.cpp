#include "CXmlTransferFinished.h"
#include <QDebug>
#include <QString>
CXmlTransferFinished::CXmlTransferFinished(CHostControl* server):
	XmlRpc::XmlRpcServerMethod("CXmlTransferFinished", server->getXmlRpcServer())

{
this->server = server;
}
void CXmlTransferFinished::execute(XmlRpc::XmlRpcValue &params, XmlRpc::XmlRpcValue &result)
{
	std::string p0 = params[0];
	std::string p1 = params[1];
	QString fileName = QString::fromLatin1(p0.c_str());
	QString hostIp = QString::fromLatin1(p1.c_str());
	qDebug("CXmlTransferFinished::execute - IN: [%s]",fileName.toLatin1().data());
	server->markVideoAsSent(fileName, hostIp);

}

std::string CXmlTransferFinished::help()
{
	return "";
}
