#pragma once
#ifndef  EQ_URL_FILE
#define  EQ_URL_FILE

#include "EQUtils.h"
#include "EQ_Singleton.h"

class CEQ_URL : public CEQ_SingletonT<CEQ_URL>
{
public:
	CEQ_URL();
	virtual ~CEQ_URL();
public:
	void ParseURL(string strURL);

public:
	inline string GetURL(){ return m_strURL;};
	inline string GetHost(){ return m_strHost;};
	inline string GetProtocol(){ return m_strProtocol;};
	inline string GetPort(){ return m_strPort;};

private:
	inline void SetURL(string strURL){ m_strURL = strURL;};
	inline void SetHost(string strHost){ m_strHost = strHost;};
	inline void SetProtocol(string strProtocol){ m_strProtocol = strProtocol;};
	inline void SetPort(string strProt){ m_strPort = strProt;};

private:
	string m_strURL;
	string m_strHost;
	string m_strPath;
	string m_strProtocol;
	string m_strPort;

};

#endif//EQ_URL_FILE