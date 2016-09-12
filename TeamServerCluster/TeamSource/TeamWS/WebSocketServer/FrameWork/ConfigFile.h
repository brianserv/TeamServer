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

public:
	int   m_nWebClientPort;
public:
	char  m_szBackendServerIp[16];
	int   m_nBackendServerPort;

	char  m_szHallServerIp[16];
	int   m_nHallServerPort;
};
#endif//__CONFIG_FILE_H__
