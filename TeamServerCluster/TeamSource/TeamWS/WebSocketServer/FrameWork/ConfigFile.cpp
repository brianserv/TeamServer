#include "ConfigFile.h"
#include "EQ_Inifile.h"
#include "BaseDefine.h"
#include <memory.h>

CConfigFile::CConfigFile()
{
}

CConfigFile::~CConfigFile()
{
}

bool  CConfigFile::ReadConfigFile()
{
	char szDefaultConfigValue[128] = { 0 };
	int nDefaultConfigValue = 0;

	//#LogLevel
	m_nLogLevel = EQ_ReadInifileInt("Setting", "LogLevel", nDefaultConfigValue, "WebSocketServer.ini");

	//#WebClientPort
	m_nWebClientPort = EQ_ReadInifileInt("Setting", "WebClientPort", nDefaultConfigValue, "WebSocketServer.ini");

	//#LocalIp
	memset(m_szLocalIp, 0, sizeof(m_szLocalIp));
	EQ_ReadInifileString("Setting", "LocalIp", m_szLocalIp, sizeof(m_szLocalIp), szDefaultConfigValue, "WebSocketServer.ini");

	//#BackendServerPort
	m_nBackendServerPort = EQ_ReadInifileInt("Setting", "BackendServerPort", nDefaultConfigValue, "WebSocketServer.ini");

	//#BackendServerIp
	memset(m_szBackendServerIp, 0, sizeof(m_szBackendServerIp));
	EQ_ReadInifileString("Setting", "BackendServerIp", m_szBackendServerIp, sizeof(m_szBackendServerIp), szDefaultConfigValue, "WebSocketServer.ini");

	//#HallServerPort
	m_nHallServerPort = EQ_ReadInifileInt("Setting", "HallServerPort", nDefaultConfigValue, "WebSocketServer.ini");

	//#HallServerIp
	memset(m_szHallServerIp, 0, sizeof(m_szHallServerIp));
	EQ_ReadInifileString("Setting", "HallServerIp", m_szHallServerIp, sizeof(m_szHallServerIp), szDefaultConfigValue, "WebSocketServer.ini");

	// Check ConfigData Validation
	if (!CheckConfigFile())
		return false;

	return true;
}

bool CConfigFile::CheckConfigFile()
{
	//Generate IniConfig Log
	char szLogDir_IniConfig[256] = { 0 };

	EQ_SPRINTF(szLogDir_IniConfig, sizeof(szLogDir_IniConfig), "TeamWebSocketServerLog/TeamWebSocket_INIConfig(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir_IniConfig, "TeamWebSocket_INIConfig", 100);

	// Check LogLevel
	if (m_nLogLevel <= 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nLogLevel Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	//CheckIpValidation
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szLocalIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szLocalIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szBackendServerIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szBackendServerIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szHallServerIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szHallServerIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	//CheckPortValidation
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nWebClientPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nWebClientPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nBackendServerPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nBackendServerPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nHallServerPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nHallServerPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	return true;
}