#pragma once
#ifndef __DBLG_SERVER_H__
#define __DBLG_SERVER_H__

#include "BaseServer.h"
#include "EQ_Singleton.h"

class CDBLGServer :
	public CBaseServer, public CEQ_SingletonT<CDBLGServer>
{
public:
	CDBLGServer();
	virtual ~CDBLGServer();

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient);
	virtual void  EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};

#endif//__DBLG_SERVER_H__