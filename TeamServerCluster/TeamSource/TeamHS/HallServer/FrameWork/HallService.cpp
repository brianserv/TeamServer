#include "HallService.h"

#include "BaseDefine.h"
#include "ConfigFile.h"
#include "HallServer.h"
#include "HallApplication.h"

CHallService::CHallService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CHallService::~CHallService(void)
{
}

bool  CHallService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	CHallApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamHallServerLog/TeamHall(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamHall", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamHall Server  Initial !");
	if (!CHallServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamHall Server Service Initial failure!");
		return bRet;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamHall Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamHall Server Listenning WebPort:%d", CConfigFile::Instance().m_nLocalPort);

	if (!g_DBManager.Open(CConfigFile::Instance().m_szDBIp, CConfigFile::Instance().m_nDBPort,
		CConfigFile::Instance().m_szDBName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamHall Server Connect DB:BACKEND_21PinkTeamFailure !]");
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamHall Server Connect DB:BACKEND_21PinkTeam Success !]");

	//if (!g_DBManager.LoadHallRoom_Texas(1))
	//{
	//	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "[CHallService::Loadding DB:BACKEND_21PinkTeam->Hall Failure !]");
	//}
	//else
	//{
	//	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[CHallService::Loadding DB:BACKEND_21PinkTeam->Hall Successes !]");
	//}

	std::map<int, std::string>& refAddressMap = CConfigFile::Instance().GetGameServerAddressMap();
	std::map<int, std::string>::iterator iter = refAddressMap.begin();
	for (; iter != refAddressMap.end(); ++iter)
	{
		g_GameClient.StartClient(const_cast<char*>(iter->second.c_str()), iter->first);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[TeamHall Server Connect GameServer IPAddress:[%s,%d]]", const_cast<char*>(iter->second.c_str()), iter->first);;
	}

	bRet = true;
	return bRet;
}

void  CHallService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CHallService::OnStop()
{
	CHallServer::Instance().StopServer();

	CHallApplication::Instance().Stop();

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamHall Server Service Over !");
}

void  CHallService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}