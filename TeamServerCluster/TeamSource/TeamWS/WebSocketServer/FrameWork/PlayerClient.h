#pragma once
#ifndef __PLAYER_CLIENT_H__
#define __PLAYER_CLIENT_H__

#include "BaseDefine.h"
#include "BaseClient.h"

class CPlayerClient :
	public CBaseClient
{
public:
	CPlayerClient(CEQ_TcpClient *pClient);
	virtual ~CPlayerClient();
	EQ_DECLARE_CACHE(CPlayerClient)

public:
	virtual void  OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime);
	virtual void  OnDisconnect(int nErrorCode);

public:
	void  SendMessageData(char*   pDataInfo, long nDataLen, bool bClose = false);

public:
	void  ProcessClientMsgInfo(char*   pDataInfo, long nDataLen);

public:
	void    SetIndex(int nIndex) { m_nIndex = nIndex; };
	int     GetIndex() { return m_nIndex; };
	void    SetRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	int     GetRoleId() { return m_nRoleId; };
public:
	void SetVersion(unsigned int nVersion) { m_nVersion = nVersion; };
	unsigned int  GetVersion() { return m_nVersion; };

private:
	int     m_nIndex;
	int     m_nRoleId;
	unsigned int m_nVersion;
};

#endif//__PLAYER_CLIENT_H__