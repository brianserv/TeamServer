#pragma  once
#ifndef __FLASH_WEB_CLIENT_H__
#define __FLASH_WEB_CLIENT_H__

#include "BaseClient.h"
#include "EQ_ObjPool.h"
#include "BaseDefine.h"

class CFlashWebClient :
	public CBaseClient
{
public:
	CFlashWebClient(CEQ_TcpClient *pClient);
	virtual ~CFlashWebClient();
	EQ_DECLARE_CACHE(CFlashWebClient)

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
	void         SetRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	int     GetRoleId() { return m_nRoleId; };

private:
	int          m_nIndex;
	char         m_szAccountId[ACCOUNT_ID_LEN_MAX];
	int     m_nRoleId;
};
#endif//__FLASH_WEB_CLIENT_H__