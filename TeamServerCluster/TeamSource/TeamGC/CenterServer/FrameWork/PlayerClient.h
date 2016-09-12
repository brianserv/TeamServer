#pragma  once
#ifndef __PLAYER_CLIENT_H__
#define __PLAYER_CLIENT_H__

#include "BaseClient.h"
#include "EQ_ObjPool.h"
#include "BaseDefine.h"

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
	void         SetIndex(int nIndex) { m_nIndex = nIndex; };
	int          GetIndex() { return m_nIndex; };
	void         SetAccountId(char* pAccountId) { memcpy(m_szAccountId, pAccountId, ACCOUNT_ID_LEN_MAX); };
	char*        GetAccountId() { return m_szAccountId; };
	void         SetRoleId(__UINT32 nRoleId) { m_nRoleId = nRoleId; };
	__UINT32     GetRoleId() { return m_nRoleId; };

private:
	int          m_nIndex;
	char         m_szAccountId[ACCOUNT_ID_LEN_MAX];
	__UINT32     m_nRoleId;
};
#endif//__PLAYER_CLIENT_H__