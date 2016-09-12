#include "PlayerClient.h"
#include "DataBuffer.h"

CPlayerClient::CPlayerClient(CEQ_TcpClient *pClient)
	:CBaseClient(pClient)
{
}

CPlayerClient::~CPlayerClient()
{
}

void  CPlayerClient::OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime)
{
	ProcessClientMsgInfo(pNewMessage, nMessageLen);
}

void  CPlayerClient::OnDisconnect(int nErrorCode)
{
	delete this;
}

void  CPlayerClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
		CDataBuffer* pDataBuffer = new CDataBuffer(pDataInfo, nDataLen, this, GetPeerNetAddr2(), GetPeerPort());
		if (NULL == pDataBuffer)
			return;

		g_RecvMsgLock.EQ_Lock();
		g_RecvMsg.push_back(pDataBuffer);
		g_RecvMsgLock.EQ_UnLock();
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGatewayClient::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}