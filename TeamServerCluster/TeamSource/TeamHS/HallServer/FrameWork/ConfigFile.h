#pragma once
#ifndef __CONFIG_FILE_H__
#define __CONFIG_FILE_H__

#include "EQ_Singleton.h"
#include <string>
#include <map>

typedef std::map<int, std::string>  GameServerAddressMap;
class CConfigFile : public CEQ_SingletonT<CConfigFile>
{
public:
	CConfigFile();
	virtual ~CConfigFile();

public:
	bool  ReadConfigFile();
	bool  CheckConfigFile();

public:
	int   m_nLogLevel;
	char  m_szLocalIp[16];

	int  m_nLocalPort;

	char m_szGameServerAddress[256];

	int   m_nDBPort;
	char  m_szDBIp[16];
	char  m_szDBName[100];
	char  m_szUserName[100];
	char  m_szPassword[100];
public:
	inline std::map<int, std::string> & GetGameServerAddressMap()
	{
		return m_GameServerAddressMap;
	};
private:
	GameServerAddressMap m_GameServerAddressMap;
};
#endif//__CONFIG_FILE_H__
