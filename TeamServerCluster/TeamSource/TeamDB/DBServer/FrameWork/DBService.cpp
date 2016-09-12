#include "DBService.h"
#include "BaseDefine.h"
#include "ConfigFile.h"
#include "DBServer.h"
#include "DBApplication.h"

CDBService::CDBService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CDBService::~CDBService(void)
{
}

bool  CDBService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	char szLogDir[256] = { 0 };
	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamDBServerLog/TeamDBServer(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamDBServer", CConfigFile::Instance().m_nLogLevel);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDBServer Server  Initial !");

	if (!CDBServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, SERVER_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDBServer Server Service Initial failure!");
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDBServer Server Start Success !");

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDBServer Server Listening GameServerPort :%d", CConfigFile::Instance().m_nLocalPort);

	for (int i = 0; i < DB_CONN_NUM; i++)
	{
		if (!g_DBManager[i].Open(CConfigFile::Instance().m_szDBIp, CConfigFile::Instance().m_nDBPort,
			CConfigFile::Instance().m_szDBName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBService: Connect DB Failure !");
			return true;
		}
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[Connect DB Mysql Success !]");

	for (int i = 0; i < DB_CONN_NUM; i++)
	{
		g_DBApplication[i].Start(i);
	}

	if (!g_DBManager[0].LoadDBData())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "[CDBService::Loadding DB Data Failure !]");
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[CDBService::Loadding DB Data Success !]");
	}

	bRet = true;
	return bRet;
}

void  CDBService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CDBService::OnStop()
{
	CDBServer::Instance().StopServer();

	for (int i = 0; i < DB_CONN_NUM; i++)
	{
		g_DBManager[i].Close();
	}

	for (int i = 0; i < DB_CONN_NUM; i++)
	{
		g_DBApplication[i].Stop();
	}

	EQ_WaitTimeOut(1000);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamDB Server Service Over !");
}

void  CDBService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}