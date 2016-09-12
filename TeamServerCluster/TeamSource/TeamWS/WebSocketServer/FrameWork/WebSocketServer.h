#pragma once
#ifndef __WEBSOCKET_SERVER__H
#define __WEBSOCKET_SERVER__H

#include "BaseDefine.h"
#include "BaseServer.h"

class CPlayerClientInfo
{
public:
	CPlayerClientInfo(void*  pClient);
	virtual ~CPlayerClientInfo();
	EQ_DECLARE_CACHE(CPlayerClientInfo)

public:
	bool     GetIsUsed() { return m_bIsUsed; };
	void     SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };
	void*    GetClient() { return m_pClient; };
	void     SetClient(void* pClient) { m_pClient = pClient; };

private:
	bool          m_bIsUsed;
	void*         m_pClient;
};

//---------------------------------------------------------------------------------------------
class CWebSocketServer :
	public CBaseServer, public CEQ_SingletonT<CWebSocketServer>
{
public:
	CWebSocketServer();
	virtual ~CWebSocketServer();
public:
	void Release();

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient);
	virtual void  EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);

public:
	bool  AddPlayerClientInfo(void* pClient, int & nIndex);
	bool  DelPlayerClientInfo(void* pClient, int & nIndex);
	void  SendClientMsg(char* pDataInfo, long nDataLen, int nIndex, bool bClose = false);
	void  SendClientMsg(char* pDataInfo, long nDataLen, bool bClose = false);
	void  SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead);

public:
	typedef std::vector<CPlayerClientInfo*> PlayerClientInfoVec;
	PlayerClientInfoVec m_PlayerClientInfoVec;
	CEQ_Lock m_Lock;
};

#endif//__WEBSOCKET_SERVER__H