#pragma once
#ifndef _BACKEND_SERVER_H__
#define _BACKEND_SERVER_H__

#include "BaseServer.h"
#include "EQ_Singleton.h"
#include "EQ_ObjPool.h"

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

/////////////////////////////////////////////////////////////////////////////////////////////////////
class CBackendServer :
	public CBaseServer, public CEQ_SingletonT<CBackendServer>
{
public:
	CBackendServer();
	virtual ~CBackendServer();
public:
	void Release();

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient);
	virtual void  EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);

public:
	bool                    AddPlayerClientInfo(void* pClient, int & nIndex);
	bool                    DelPlayerClientInfo(void* pClient, int & nIndex);
	void                    SendClientMsg(char* pDataInfo, long nDataLen, int nIndex, bool bClose = false);
	void                    SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead);

public:
	typedef std::vector<CPlayerClientInfo*> PlayerClientInfoVec;
	PlayerClientInfoVec m_PlayerClientInfoVec;
	CEQ_Lock                   m_Lock;
};

#endif//_BACKEND_SERVER_H__