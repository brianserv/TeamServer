#include "FlashPolicyService.h"

#include "BaseDefine.h"
#include "ConfigFile.h"
#include "FlashPolicyServer.h"
#include "FlashPolicyApplication.h"

CFlashPolicyService::CFlashPolicyService(char* pServiceName, char* pDisplayName)
	: CEQ_Service(pServiceName, pDisplayName)
{
}

CFlashPolicyService::~CFlashPolicyService(void)
{
}

bool  CFlashPolicyService::OnStart(int nState, int bLastNormalQuit)
{
	bool bRet = false;

	SetIdleIntervalTime(100);

	CEQ_Time::Instance().EQ_SetTime();

	CConfigFile::Instance().ReadConfigFile();

	CFlashPolicyApplication::Instance().Start();

	char szLogDir[256] = { 0 };

	EQ_SPRINTF(szLogDir, sizeof(szLogDir), "TeamFlashPolicyServerLog/TeamFlashPolicy(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir, "TeamFlashPolicy", CConfigFile::Instance().m_nLogLevel);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamFlashPolicy Server  Initial !");

	if (!CFlashPolicyServer::Instance().StartServer(CConfigFile::Instance().m_FlashWebClientPort, CLIENT_MESSAGE_LEN_MAX))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamFlashPolicy Server Service Initial failure!");
		return bRet;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamFlashPolicy Server Start Success !");
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TeamFlashPolicy Server Listenning FlashPort %s:%d", CConfigFile::Instance().m_szLocalIp, CConfigFile::Instance().m_FlashWebClientPort);

	bRet = true;
	return bRet;
}

void  CFlashPolicyService::OnIdle()
{
	CEQ_Time::Instance().EQ_SetTime();
}

void  CFlashPolicyService::OnStop()
{
	CFlashPolicyServer::Instance().StopServer();

	CFlashPolicyApplication::Instance().Stop();

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "WebSocket Server Over !");
}

void  CFlashPolicyService::PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}