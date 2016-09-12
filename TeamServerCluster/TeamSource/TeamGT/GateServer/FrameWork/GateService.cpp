#include "GateService.h"

#include "BaseDefine.h"
#include "ConfigFile.h"
#include "GateServer.h"
#include "GateApplication.h"

CGateService::CGateService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CGateService::~CGateService(void)
{
}

bool  CGateService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	CGateApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamGateServerLog/TeamGate(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamGate", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGate Server  Initial !");

	if (!g_DBManager.Open(CConfigFile::Instance().m_szDBIp, CConfigFile::Instance().m_nDBPort,
		CConfigFile::Instance().m_szDBName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamGate Server Connect DB Failure !]");
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamGate Server Connect DB Success !]");

	if (!g_DBManager.LoadGirlData())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamGate Server Load DBGirl Data Failure !]");
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamGate Server Load DBGirl Data Success !]");
	}

	if (!CGateServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGate Server Service Initial failure!");
		return bRet;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGate Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGate Server Listenning WebPort:%d", CConfigFile::Instance().m_nLocalPort);
	
	std::map<int, std::string>& refAddressMap = CConfigFile::Instance().GetGameServerAddressMap();
	std::map<int, std::string>::iterator iter = refAddressMap.begin();
	for (; iter != refAddressMap.end(); ++iter)
	{
		g_GameClient.StartClient(const_cast<char*>(iter->second.c_str()), iter->first);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamGate Server Connect GameServer IPAddress:[%s,%d]]", const_cast<char*>(iter->second.c_str()), iter->first);;
	}

	bRet = true;
	return bRet;
}

void  CGateService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CGateService::OnStop()
{
	CGateServer::Instance().StopServer();

	CGateApplication::Instance().Stop();

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGate Server Service Over !");
}

void  CGateService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}
