#pragma once
#include "EQBaseSever.h"
#include "EQNet.h"

class CBaseServer :
	public CEQ_BaseServer,
	public CEQ_TCPAcceptorHander
{
public:
	CBaseServer(){};
	virtual ~CBaseServer(){};

public:
	virtual bool StartServer(short nPort,int nIODataSize)
	{
		if (!CEQ_BaseServer::EQ_CreateServer(nIODataSize))
			return false;

		if(!CEQ_BaseServer::EQ_Listen(nPort,this))
			return false;

		return true;
	};

	virtual void StopServer()
	{
		CEQ_BaseServer::EQ_CloseServer();
	};
};