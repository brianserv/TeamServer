#include "GameService.h"

#include "BaseDefine.h"

#include "GameServer.h"
#include "GameApplication.h"
#include "HttpLinkApplication.h"

#include "../Logic/Resource/ResourceManager.h"
#include "../Logic/Httplink/HttpLinkManager.h"
#include "../Logic/Httplink/HttpLinkEvent.h"

#include "../Logic/GameHall/GameHall.h"

CGameService::CGameService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CGameService::~CGameService(void)
{
}

bool  CGameService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;
	g_StartServer = false;
	g_PrizePool = false;
	g_ResourceLoadSucc = false;
	g_GameRoomBindSucc = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	if (!CConfigFile::Instance().ReadConfigFile())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n[Error]:TeamGame Server INI Config Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " [Successes]:TeamGame Server INI Config Successes!");

	CGameApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamGameServerLog/TeamGame(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamGame", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGame Server  Initial !");

	if (!CGameServer::Instance().StartServer(CConfigFile::Instance().m_nLocalPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGame Server Service Initial failure!");
		return true;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGame Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGame Server Listenning Port %s:%d", CConfigFile::Instance().m_szLocalIp, CConfigFile::Instance().m_nLocalPort);

	if (!g_DBManager.Open(CConfigFile::Instance().m_szDBIp, CConfigFile::Instance().m_nDBPort,
		CConfigFile::Instance().m_szDBName, CConfigFile::Instance().m_szUserName, CConfigFile::Instance().m_szPassword))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameService: Connect DB:BACKEND_21PinkTeam Failure !");
		return true;
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameService: Connect DB:BACKEND_21PinkTeam Successes !");

	if (!g_DBManager.LoadHallRoom_Texas(CGameServer::Instance().GetServerId()))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "[CGameService::Loadding DB:BACKEND_21PinkTeam->Hall Failure !]");
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[CGameService::Loadding DB:BACKEND_21PinkTeam->Hall Successes !]");
	}

	g_CenterClient.StartClient(CConfigFile::Instance().m_szCenterServerIp, CConfigFile::Instance().m_nCenterServerPort);
	g_DBClient.StartClient(CConfigFile::Instance().m_szDBServerIp, CConfigFile::Instance().m_nDBServerPort);
	g_DBLogClient.StartClient(CConfigFile::Instance().m_szDBLogServerIp, CConfigFile::Instance().m_nDBLogServerPort);

	if (!CGameHall::Instance().Init())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n CGameHall::Instance().Init() Failure!", __FILE__, __LINE__, __FUNCTION__);
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " CGameHall::Instance().Init() Success !");
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "_________________________________GameHall-Initial Success________________________________");
	}

	if (!CHttpLinkManager::Instance().Init())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n CHttpLinkManager::Instance().Init() Failure!", __FILE__, __LINE__, __FUNCTION__);
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CHttpLinkManager::Instance().Init() Success !");
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "_________________________________HttpLink-Success________________________________");
	}

	for (int index = 0; index < MAX_HTTP_LINK_THREADS_NUM; index++)
	{
		g_HttpLinkApplication[index].Start(index);
	}

	CHttpLinkEvent::Instance().ProcessEvent_Request_MsgRegister(0, 0, 0, 0, 0);

	g_StartServer = true;

	bRet = true;
	return bRet;
}

void  CGameService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CGameService::OnStop()
{
	CGameServer::Instance().StopServer();

	CGameApplication::Instance().Stop();

	for (int index = 0; index < MAX_HTTP_LINK_THREADS_NUM; index++)
	{
		g_HttpLinkApplication[index].Stop();
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamGame Server Service Over !");
}

void  CGameService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}
