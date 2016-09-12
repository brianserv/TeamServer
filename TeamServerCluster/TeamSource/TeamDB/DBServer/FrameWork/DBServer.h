#pragma once
#ifndef __DB_SERVER_H__
#define __DB_SERVER_H__

#include "BaseServer.h"
#include "EQ_Singleton.h"

class CDBServer :
	public CBaseServer, public CEQ_SingletonT<CDBServer>
{
public:
	CDBServer();
	virtual ~CDBServer();

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient);
	virtual void  EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__DB_SERVER_H__