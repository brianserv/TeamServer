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
	int   m_nLogLevel;
	char  m_szLocalIp[16];

	int  m_nLocalPort;

	char m_szCenterServerIp[16];
	int  m_nCenterServerPort;

	int   m_nDBPort;
	char  m_szDBIp[16];
	char  m_szDBName[100];
	char  m_szUserName[100];
	char  m_szPassword[100];
};
#endif//__CONFIG_FILE_H__
