#include "WebSocketService.h"

#include "WebSocketServer.h"
#include "WebSocketApplication.h"

#include "ConfigFile.h"

CWebSocketService::CWebSocketService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CWebSocketService::~CWebSocketService(void)
{
}

bool  CWebSocketService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	CWebSocketApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamWebSocketServerLog/TeamWebSocketServer(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamWebSocket", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamWebSocket Server  Initial !");

	if (!CWebSocketServer::Instance().StartServer(CConfigFile::Instance().m_nWebClientPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamWebSocket Server Service Initial failure!");
		return bRet;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamWebSocket Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamWebSocket Server Listening WebPort:%d", CConfigFile::Instance().m_nWebClientPort);

	g_BackendClient.StartClient(CConfigFile::Instance().m_szBackendServerIp, CConfigFile::Instance().m_nBackendServerPort);

	bRet = true;
	return bRet;
}

void  CWebSocketService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CWebSocketService::OnStop()
{
	CWebSocketServer::Instance().StopServer();

	CWebSocketApplication::Instance().Stop();

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamWebSocketService Over !");
}

void  CWebSocketService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}