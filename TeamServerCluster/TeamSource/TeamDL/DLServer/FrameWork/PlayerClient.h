#pragma  once
#ifndef __PLAYER_CLIENT_H__
#define __PLAYER_CLIENT_H__

#include "BaseClient.h"
#include "BaseDefine.h"

class CPlayerClient :public CBaseClient
{
public:
	CPlayerClient(CEQ_TcpClient *pClient);
	virtual ~CPlayerClient();

public:
	virtual void  OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime);
	virtual void  OnDisconnect(int nErrorCode);

protected:
	void  ProcessClientMsgInfo(char*   pDataInfo, long nDataLen);
};
#endif//__PLAYER_CLIENT_H__