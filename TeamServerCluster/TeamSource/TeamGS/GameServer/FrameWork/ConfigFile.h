#pragma once
#ifndef __CONFIG_FILE_H__
#define __CONFIG_FILE_H__

#include "EQ_Singleton.h"

class CConfigFile : public CEQ_SingletonT<CConfigFile>
{
public:
	CConfigFile();
	virtual ~CConfigFile();

public:
	bool  ReadConfigFile();
	bool  CheckConfigFile();
public:
	int   m_nGameServerId;
	int   m_nLogLevel;
	char  m_szLocalIp[16];

	int   m_nLocalPort;

	char m_szCenterServerIp[16];
	int  m_nCenterServerPort;

	char m_szDBServerIp[16];
	int  m_nDBServerPort;

	char m_szDBLogServerIp[16];
	int  m_nDBLogServerPort;

	char m_szPlatformIpType[512];

	char m_szYYDomain[512];
	char m_szFBDomain[512];

	char m_szJsonConfigDomain[512];

	char m_szGameType[512];
	char m_szTexasRoomId[512];
	char m_szBaccaratRoomId[512];

	int  m_nMaxBetWaitTime;

	int   m_nDBPort;
	char  m_szDBIp[256];
	char  m_szDBName[100];
	char  m_szUserName[100];
	char  m_szPassword[100];
};
#endif//__CONFIG_FILE_H__