#ifndef CXMLTRANSFERFINISHED_H
#define CXMLTRANSFERFINISHED_H

#include <XmlRpc.h>
#include <CHostControl.h>
class CXmlTransferFinished: public XmlRpc::XmlRpcServerMethod
{
public:
	CHostControl* server;
	CXmlTransferFinished(CHostControl* server);
	void execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result);
	std::string help();
};

#endif // CXMLTRANSFERFINISHED_H
