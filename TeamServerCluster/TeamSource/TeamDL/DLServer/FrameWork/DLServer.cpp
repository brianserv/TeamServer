#include "DLServer.h"
#include "PlayerClient.h"

CDBLGServer::CDBLGServer()
{
}

CDBLGServer::~CDBLGServer()
{
}

CEQ_TCPClientHandler* CDBLGServer::EQ_OnAcceptEx(CEQ_TcpClient* pNewClient)
{
	CPlayerClient* pClient = new CPlayerClient(pNewClient);
	if (NULL != pClient)
	{
		if (!pClient->GetPeerAddr())
		{
			SAFE_DELETE(pClient);
			return NULL;
		}
		return pClient;
	}
	return pClient;
}

void  CDBLGServer::EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}