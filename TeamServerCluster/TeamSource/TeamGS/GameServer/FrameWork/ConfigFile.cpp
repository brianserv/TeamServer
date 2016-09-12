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

	//#GameServerId
	m_nGameServerId = EQ_ReadInifileInt("Setting", "GameServerId", nDefaultConfigValue, "GameServer.ini");

	//#LogLevel
	m_nLogLevel = EQ_ReadInifileInt("Setting", "LogLevel", nDefaultConfigValue, "GameServer.ini");

	//#LocalIp
	memset(m_szLocalIp, 0, sizeof(m_szLocalIp));
	EQ_ReadInifileString("Setting", "LocalIp", m_szLocalIp, sizeof(m_szLocalIp), szDefaultConfigValue, "GameServer.ini");

	//#Listen LocalPort
	m_nLocalPort = EQ_ReadInifileInt("Setting", "LocalPort", nDefaultConfigValue, "GameServer.ini");

	//#Connected CenterServer
	memset(m_szCenterServerIp, 0, sizeof(m_szCenterServerIp));
	EQ_ReadInifileString("Setting", "CenterServerIp", m_szCenterServerIp, sizeof(m_szCenterServerIp), szDefaultConfigValue, "GameServer.ini");

	m_nCenterServerPort = EQ_ReadInifileInt("Setting", "CenterServerPort", nDefaultConfigValue, "GameServer.ini");

	//#Connected DBServer
	memset(m_szDBServerIp, 0, sizeof(m_szDBServerIp));
	EQ_ReadInifileString("Setting", "DBServerIp", m_szDBServerIp, sizeof(m_szDBServerIp), szDefaultConfigValue, "GameServer.ini");

	m_nDBServerPort = EQ_ReadInifileInt("Setting", "DBServerPort", nDefaultConfigValue, "GameServer.ini");

	//#Connected DBLogServer
	memset(m_szDBLogServerIp, 0, sizeof(m_szDBLogServerIp));
	EQ_ReadInifileString("Setting", "DBLogServerIp", m_szDBLogServerIp, sizeof(m_szDBLogServerIp), szDefaultConfigValue, "GameServer.ini");

	m_nDBLogServerPort = EQ_ReadInifileInt("Setting", "DBLogServerPort", nDefaultConfigValue, "GameServer.ini");

	//#Platform:Type
	memset(m_szPlatformIpType, 0, sizeof(m_szPlatformIpType));
	EQ_ReadInifileString("Setting", "PlatformIpType", m_szPlatformIpType, sizeof(m_szPlatformIpType), szDefaultConfigValue, "GameServer.ini");

	//#Platform Domain
	memset(m_szYYDomain, 0, sizeof(m_szYYDomain));
	EQ_ReadInifileString("Setting", "Platform_YY_Domain", m_szYYDomain, sizeof(m_szYYDomain), szDefaultConfigValue, "GameServer.ini");

	memset(m_szFBDomain, 0, sizeof(m_szFBDomain));
	EQ_ReadInifileString("Setting", "Platform_FB_Domain", m_szFBDomain, sizeof(m_szFBDomain), szDefaultConfigValue, "GameServer.ini");

	//#JsonConfig:Domain
	memset(m_szJsonConfigDomain, 0, sizeof(m_szJsonConfigDomain));
	EQ_ReadInifileString("Setting", "JsonConfigDomain", m_szJsonConfigDomain, sizeof(m_szJsonConfigDomain), szDefaultConfigValue, "GameServer.ini");

	//#GameType
	memset(m_szGameType, 0, sizeof(m_szGameType));
	EQ_ReadInifileString("Setting", "GameType", m_szGameType, sizeof(m_szGameType), szDefaultConfigValue, "GameServer.ini");

	//#Game_Texas RoomId List
	memset(m_szTexasRoomId, 0, sizeof(m_szTexasRoomId));
	EQ_ReadInifileString("Setting", "TexasRoomId", m_szTexasRoomId, sizeof(m_szTexasRoomId), szDefaultConfigValue, "GameServer.ini");

	//#Game_Baccarat RoomId List
	memset(m_szBaccaratRoomId, 0, sizeof(m_szBaccaratRoomId));
	EQ_ReadInifileString("Setting", "BaccaratRoomId", m_szBaccaratRoomId, sizeof(m_szBaccaratRoomId), szDefaultConfigValue, "GameServer.ini");

	//#Game MaxBetWaitTime
	m_nMaxBetWaitTime = EQ_ReadInifileInt("Setting", "MaxBetWaitTime", nDefaultConfigValue, "GameServer.ini");

	//#DataBaseLink Info
	memset(m_szDBIp, 0, sizeof(m_szDBIp));
	EQ_ReadInifileString("Setting", "DBIp", m_szDBIp, sizeof(m_szDBIp), szDefaultConfigValue, "GameServer.ini");

	m_nDBPort = EQ_ReadInifileInt("Setting", "DBPort", nDefaultConfigValue, "GameServer.ini");

	memset(m_szDBName, 0, sizeof(m_szDBName));
	EQ_ReadInifileString("Setting", "DBName", m_szDBName, sizeof(m_szDBName), szDefaultConfigValue, "GameServer.ini");

	memset(m_szUserName, 0, sizeof(m_szUserName));
	EQ_ReadInifileString("Setting", "UserName", m_szUserName, sizeof(m_szUserName), szDefaultConfigValue, "GameServer.ini");

	memset(m_szPassword, 0, sizeof(m_szPassword));
	EQ_ReadInifileString("Setting", "Password", m_szPassword, sizeof(m_szPassword), szDefaultConfigValue, "GameServer.ini");

	// Check ConfigData Validation
	if (!CheckConfigFile())
		return false;

	return true;
}

bool CConfigFile::CheckConfigFile()
{
	//Generate IniConfig Log
	char szLogDir_IniConfig[256] = { 0 };

	EQ_SPRINTF(szLogDir_IniConfig, sizeof(szLogDir_IniConfig), "TeamGameServerLog/TeamGame_INIConfig(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir_IniConfig, "TeamGame_INIConfig", 100);

	// Check LogLevel
	if (m_nGameServerId <= 0 || m_nLogLevel <= 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nGameServerId Error Or m_nLogLevel Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	//CheckIpValidation
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szLocalIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szLocalIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szCenterServerIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szCenterServerIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szDBServerIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szDBServerIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckIpValidation(string(m_szDBLogServerIp)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szDBLogServerIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	//CheckPortValidation
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nLocalPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nLocalPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nCenterServerPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nCenterServerPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nDBServerPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nDBServerPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nDBLogServerPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nDBLogServerPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	//check Other Parameters

	if (!PARSE_STRINGS::CheckIntString(string(m_szPlatformIpType)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szPlatformIpType Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!PARSE_STRINGS::CheckIntString(string(m_szGameType)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szGameType Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!PARSE_STRINGS::CheckIntString(string(m_szTexasRoomId)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szTexasRoomId Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	if (!PARSE_STRINGS::CheckIntString(string(m_szBaccaratRoomId)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szBaccaratRoomId Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	
	//check DataBaseLink Info
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(m_szDBIp))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szDBIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nDBPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nDBPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	
	return true;
}
