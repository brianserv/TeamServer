#include "DLService.h"
#include "BaseDefine.h"
#include "ConfigFile.h"
#include "DLServer.h"
#include "DLApplication.h"

CDLService::CDLService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CDLService::~CDLService(void)
{
}

bool  CDLService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	char szLogDir[256] = { 0 };
	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamDLServerLog/TeamDLServer(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamDLServer", CConfigFile::Instance().m_nLogLevel);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDLServer Server  Initial !");

	if (!CDBLGServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, SERVER_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDLServer Server Service Initial failure!");
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDLServer Server Start Success !");

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDLServer Server Listening GameServer Port :%d", CConfigFile::Instance().m_nLocalPort);

	if (!g_DLManager.Open(CConfigFile::Instance().m_szDBLogIp, CConfigFile::Instance().m_nDBLogPort,
		CConfigFile::Instance().m_szDBLogName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDLService: Connect DBLOG Failure !");
		return true;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CDLService: Connect DBLOG Success !");

	g_DLApplication.Start();

	bRet = true;
	return bRet;
}

void  CDLService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CDLService::OnStop()
{
	CDBLGServer::Instance().StopServer();

	EQ_WaitTimeOut(1000);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDBLG Server Service Over !");
}

void  CDLService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}