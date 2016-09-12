#include "BackendService.h"

#include "BaseDefine.h"
#include "ConfigFile.h"
#include "BackendServer.h"
#include "BackendApplication.h"

CBackendService::CBackendService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CBackendService::~CBackendService(void)
{
}

bool  CBackendService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	CBackendApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamBackendServerLog/TeamBackend(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamBackend", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamBackend Server  Initial !");

	if (!g_DBManager.Open(CConfigFile::Instance().m_szDBIp, CConfigFile::Instance().m_nDBPort,
		CConfigFile::Instance().m_szDBName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamBackend Server Connect DB Failure !]");
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamBackend Server Connect DB Success !]");

	if (!CBackendServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamBackend Server Service Initial failure!");
		return bRet;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamBackend Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamBackend Server Listenning WebPort:%d", CConfigFile::Instance().m_nLocalPort);

	g_CenterClient.StartClient(CConfigFile::Instance().m_szCenterServerIp, CConfigFile::Instance().m_nCenterServerPort);

	bRet = true;
	return bRet;
}

void  CBackendService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CBackendService::OnStop()
{
	CBackendServer::Instance().StopServer();

	CBackendApplication::Instance().Stop();

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamBackend Server Service Over !");
}

void  CBackendService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}