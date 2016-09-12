#include "PlayerClient.h"
#include "HallServer.h"

#include "DataBuffer.h"

EQ_IMPLEMENT_CACHE(CPlayerClient, 1000)
CPlayerClient::CPlayerClient(CEQ_TcpClient *pClient)
	:CBaseClient(pClient)
{
	m_nIndex = -1;
	m_nRoleId = 0;
	m_bIsGirl = false;
}

CPlayerClient::~CPlayerClient()
{
	m_nIndex = 0;
	m_nRoleId = 0;
	m_bIsGirl = false;
}

void  CPlayerClient::OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime)
{
	ProcessClientMsgInfo(pNewMessage, nMessageLen);
}

void  CPlayerClient::OnDisconnect(int nErrorCode)
{
}

void  CPlayerClient::SendMessageData(char*   pDataInfo, long nDataLen, bool bClose)
{
	PostMessage(pDataInfo, nDataLen, bClose);
}

void  CPlayerClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if ((NULL == pPacketHead))
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
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CPlayerClient::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}