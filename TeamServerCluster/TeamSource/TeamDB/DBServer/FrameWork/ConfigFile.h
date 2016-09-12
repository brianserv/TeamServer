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
	int   m_nLocalPort;
	int   m_nDBPort;

	char  m_szLocalIp[16];

	char  m_szDBIp[256];
	char  m_szDBName[100];
	char  m_szUserName[100];
	char  m_szPassword[100];
};
#endif//__CONFIG_FILE_H__
