#pragma once
#ifndef __FLASH_POLICY_SERVER_H__
#define __FLASH_POLICY_SERVER_H__

#include "BaseServer.h"
#include "EQ_Singleton.h"
#include "EQ_ObjPool.h"

class CWebClientInfo
{
public:
	CWebClientInfo(void*  pClient);
	virtual ~CWebClientInfo();
	EQ_DECLARE_CACHE(CWebClientInfo)

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
class CFlashPolicyServer :
	public CBaseServer, public CEQ_SingletonT<CFlashPolicyServer>
{
public:
	CFlashPolicyServer();
	virtual ~CFlashPolicyServer();
public:
	void Release();

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient);
	virtual void  EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);

public:
	bool                    AddPlayerClientInfo(void* pClient, int & nIndex);
	bool                    DelPlayerClientInfo(void* pClient, int & nIndex);
	void                    SendClientMsg(char* pDataInfo, long nDataLen, int nIndex);

private:
	typedef std::vector<CWebClientInfo*> WebClientInfoVec;
	WebClientInfoVec m_WebClientInfoVec;
	CEQ_Lock                   m_Lock;
};
#endif//__FLASH_POLICY_SERVER_H__