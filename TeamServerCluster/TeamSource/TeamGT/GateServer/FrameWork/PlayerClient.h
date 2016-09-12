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
	void  OnDisconnect_Windows();
	void  OnDisconnect_Linux();
public:
	void         SetIndex(int nIndex) { m_nIndex = nIndex; };
	int          GetIndex() { return m_nIndex; };
	void         SetRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	int     GetRoleId() { return m_nRoleId; };

	void        SetGirlId(int nGirlId) { m_nGirlId = nGirlId; };
	int         GetGirlId() { return m_nGirlId; };

	void        SetGirl() { m_bIsGirl = true; }

	bool        IsCheckGirl() { return m_bIsGirl; };

private:
	int          m_nIndex;
	int     m_nRoleId;
	int         m_nGirlId;
	bool        m_bIsGirl;
};

#endif//__PLAYER_CLIENT_H__