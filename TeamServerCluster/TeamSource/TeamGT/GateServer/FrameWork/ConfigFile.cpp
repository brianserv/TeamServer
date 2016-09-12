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
	m_nLogLevel = EQ_ReadInifileInt("Setting", "LogLevel", nDefaultConfigValue, "Gate.ini");

	//#LocalIp
	memset(m_szLocalIp, 0, sizeof(m_szLocalIp));
	EQ_ReadInifileString("Setting", "LocalIp", m_szLocalIp, sizeof(m_szLocalIp), szDefaultConfigValue, "Gate.ini");

	//#Listen LocalPort
	m_nLocalPort = EQ_ReadInifileInt("Setting", "LocalPort", nDefaultConfigValue, "Gate.ini");

	//#Connected GameServerAddress
	memset(m_szGameServerAddress, 0, sizeof(m_szGameServerAddress));
	EQ_ReadInifileString("Setting", "GameServerAddress", m_szGameServerAddress, sizeof(m_szGameServerAddress), szDefaultConfigValue, "Gate.ini");
	
	//#DataBaseLink Info
	memset(m_szDBIp, 0, sizeof(m_szDBIp));
	EQ_ReadInifileString("Setting", "DBIp", m_szDBIp, sizeof(m_szDBIp), szDefaultConfigValue, "Gate.ini");

	m_nDBPort = EQ_ReadInifileInt("Setting", "DBPort", nDefaultConfigValue, "Gate.ini");

	memset(m_szDBName, 0, sizeof(m_szDBName));
	EQ_ReadInifileString("Setting", "DBName", m_szDBName, sizeof(m_szDBName), szDefaultConfigValue, "Gate.ini");

	memset(m_szUserName, 0, sizeof(m_szUserName));
	EQ_ReadInifileString("Setting", "UserName", m_szUserName, sizeof(m_szUserName), szDefaultConfigValue, "Gate.ini");

	memset(m_szPassword, 0, sizeof(m_szPassword));
	EQ_ReadInifileString("Setting", "Password", m_szPassword, sizeof(m_szPassword), szDefaultConfigValue, "Gate.ini");

	// Check ConfigData Validation
	if (!CheckConfigFile())
		return false;
	
	return true;
}

bool  CConfigFile::CheckConfigFile()
{
	//Generate IniConfig Log
	char szLogDir_IniConfig[256] = { 0 };

	EQ_SPRINTF(szLogDir_IniConfig, sizeof(szLogDir_IniConfig), "TeamGateServerLog/TeamGate_INIConfig(%d.%d.%d.%d.%d.%d)", CEQ_Time::Instance().EQ_GetYear(), CEQ_Time::Instance().EQ_GetMonth(),
		CEQ_Time::Instance().EQ_GetDay(), CEQ_Time::Instance().EQ_GetHour(), CEQ_Time::Instance().EQ_GetMin(),
		CEQ_Time::Instance().EQ_GetSec());

	g_LogFile.InitLogFile(szLogDir_IniConfig, "TeamGate_INIConfig", 100);
	
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
	
	//Check Connected GameServerAddress
	string  strGameServerAddress(CConfigFile::Instance().m_szGameServerAddress);
	std::vector<string> strFilter;
	std::vector<string> strFilterAddress;

	strFilterAddress = PARSE_STRINGS::ParseString::Split(strGameServerAddress, "|");
	std::vector<string>::iterator iter = strFilterAddress.begin();
	for (; iter != strFilterAddress.end(); ++iter)
	{
		strFilter = PARSE_STRINGS::ParseString::Split(*iter, ":");
		if (strFilter.size() != 2)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szGameServerAddress IP Segment Error OR Port Syntax Error!", __FILE__, __LINE__, __FUNCTION__);
			return false;
		}

		//CheckIpValidation
		if (!CEQ_IPAddresses::Instance().CheckIpValidation(strFilter[0]) || !PARSE_STRINGS::CheckIntString(strFilter[1]))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:m_szGameServerAddress Error OR Port Syntax Error!", __FILE__, __LINE__, __FUNCTION__);
			return false;
		}
		if (PARSE_STRINGS::CheckIntString(strFilter[1]))
		{
			//CheckPortValidation
			if (!CEQ_IPAddresses::Instance().CheckPortValidation(atoi(strFilter[1].c_str())))
			{
				g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Port Syntax Error!", __FILE__, __LINE__, __FUNCTION__);
				return false;
			}
		}
		m_GameServerAddressMap[atoi(strFilter[1].c_str())] = strFilter[0];
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
