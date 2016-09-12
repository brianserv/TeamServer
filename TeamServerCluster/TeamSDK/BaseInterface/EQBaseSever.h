#pragma once

#ifndef  EQ_GAMESERVER_FILE
#define  EQ_GAMESERVER_FILE
#include "EQNet.h"

class CEQ_BaseServer
{
public:
	CEQ_BaseServer();
	virtual ~CEQ_BaseServer();

public:
	
	bool EQ_CreateServer(int nIODataSize);

	
	bool EQ_Listen( short nPort,CEQ_TCPAcceptorHander* pHandler );

	
	void EQ_CloseServer();

	
	void EQ_CloseClient(int nSocketID);

	
	int  EQ_GetNetHandleCount();

	
	virtual void EQ_PostExceptionMessageEx(int nLevel,const char* szErrInfo ,...) = 0;

private:
	void*        m_pServer;
};


#endif