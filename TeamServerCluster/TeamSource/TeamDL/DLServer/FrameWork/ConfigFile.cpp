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
	m_nLogLevel = EQ_ReadInifileInt("Setting", "LogLevel", nDefaultConfigValue, "DBLogServer.ini");

	//#Listen LocalPort
	m_nLocalPort = EQ_ReadInifileInt("Setting", "LocalPort", nDefaultConfigValue, "DBLogServer.ini");

	//#LocalIP
	memset(m_szLocalIp, 0, sizeof(m_szLocalIp));
	EQ_ReadInifileString("Setting", "LocalIp", m_szLocalIp, sizeof(m_szLocalIp), szDefaultConfigValue, "DBLogServer.ini");

	//#DataBase Link Info
	memset(m_szDBLogIp, 0, sizeof(m_szDBLogIp));
	EQ_ReadInifileString("Setting", "DBLogIp", m_szDBLogIp, sizeof(m_szDBLogIp), szDefaultConfigValue, "DBLogServer.ini");

	m_nDBLogPort = EQ_ReadInifileInt("Setting", "DBLogPort", nDefaultConfigValue, "DBLogServer.ini");

	memset(m_szDBLogName, 0, sizeof(m_szDBLogName));
	EQ_ReadInifileString("Setting", "DBLogName", m_szDBLogName, sizeof(m_szDBLogName), szDefaultConfigValue, "DBLogServer.ini");

	memset(m_szUserName, 0, sizeof(m_szUserName));
	EQ_ReadInifileString("Setting", "UserName", m_szUserName, sizeof(m_szUserName), szDefaultConfigValue, "DBLogServer.ini");

	memset(m_szPassword, 0, sizeof(m_szPassword));
	EQ_ReadInifileString("Setting", "Password", m_szPassword, sizeof(m_szPassword), szDefaultConfigValue, "DBLogServer.ini");

	// Check ConfigData Validation
	if (!CheckConfigFile())
		return false;

	return true;
}

bool CConfigFile::CheckConfigFile()
{
	//Generate IniConfig Log
	char szLogDir_IniConfig[256] = { 0 };

	EQ_SPRINTF(szLogDir_IniConfig, sizeof(szLogDir_IniConfig), "TeamDLServerLog/TeamDLServer_INIConfig(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir_IniConfig, "TeamDLServer_INIConfig", 100);

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

	//CheckPortValidation
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nLocalPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nLocalPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	//check DataBaseLink Info
	if (!CEQ_IPAddresses::Instance().CheckIpValidation(m_szDBLogIp))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szDBLogIp Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}
	if (!CEQ_IPAddresses::Instance().CheckPortValidation(m_nDBLogPort))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_nDBLogPort Error!", __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	return true;
}