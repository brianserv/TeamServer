#include "FlashWebClient.h"
#include "FlashPolicyServer.h"
#include "BaseDefine.h"
#include "DataBuffer.h"

EQ_IMPLEMENT_CACHE(CFlashWebClient, 1000)
CFlashWebClient::CFlashWebClient(CEQ_TcpClient *pClient)
	:CBaseClient(pClient)
{
	m_nIndex = -1;
	memset(m_szAccountId, sizeof(m_szAccountId), 0);
	m_nRoleId = 0;
}

CFlashWebClient::~CFlashWebClient()
{
	m_nIndex = 0;
	memset(m_szAccountId, sizeof(m_szAccountId), 0);
	m_nRoleId = 0;
}

void  CFlashWebClient::OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime)
{
	ProcessClientMsgInfo(pNewMessage, nMessageLen);
}

void  CFlashWebClient::OnDisconnect(int nErrorCode)
{
	CFlashPolicyServer::Instance().DelPlayerClientInfo(this, m_nIndex);
	delete this;
}

void  CFlashWebClient::SendMessageData(char*   pDataInfo, long nDataLen, bool bClose)
{
	PostMessage(pDataInfo, nDataLen, bClose);
}

void  CFlashWebClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen)
{
	if (NULL == pDataInfo || nDataLen <= 0)
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
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CFlashWebClient::Exception Cmd : %s");
	}
}