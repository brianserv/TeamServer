#include "WebSocketServer.h"
#include "PlayerClient.h"

EQ_IMPLEMENT_CACHE(CPlayerClientInfo, 1000)
CPlayerClientInfo::CPlayerClientInfo(void*  pClient)
{
	SetIsUsed(true);
	SetClient(pClient);
}

CPlayerClientInfo::~CPlayerClientInfo()
{
	SetIsUsed(false);
	SetClient(NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
CWebSocketServer::CWebSocketServer()
{
	m_PlayerClientInfoVec.clear();
}

CWebSocketServer::~CWebSocketServer()
{
	Release();
}

void CWebSocketServer::Release()
{
	EQ_AUTOLOCK(m_Lock);
	{
		PlayerClientInfoVec::iterator it = m_PlayerClientInfoVec.begin();
		for (; it != m_PlayerClientInfoVec.end(); it++)
		{
			SAFE_DELETE(*it);
		}
		m_PlayerClientInfoVec.clear();
	}
}

CEQ_TCPClientHandler* CWebSocketServer::EQ_OnAcceptEx(CEQ_TcpClient* pNewClient)
{
	CPlayerClient* pClient = new CPlayerClient(pNewClient);
	if (NULL != pClient)
	{
		if (!pClient->GetPeerAddr())
		{
			SAFE_DELETE(pClient);
			return NULL;
		}
		int nIndex = 0;

		AddPlayerClientInfo(pClient, nIndex);
		pClient->SetIndex(nIndex);

		return pClient;
	}
	return pClient;
}

void  CWebSocketServer::EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}

bool  CWebSocketServer::AddPlayerClientInfo(void* pClient, int & nIndex)
{
	CPlayerClientInfo* pPlayerClientInfo = new CPlayerClientInfo(pClient);
	if (NULL == pPlayerClientInfo)
		return false;

	EQ_AUTOLOCK(m_Lock)
	{
		m_PlayerClientInfoVec.push_back(pPlayerClientInfo);
		int nSize = m_PlayerClientInfoVec.size();

		if (nSize >= 1)
		{
			nIndex = nSize - 1;
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Connected Index:%d", nIndex);
			return true;
		}
	}
	return true;
}

bool  CWebSocketServer::DelPlayerClientInfo(void* pClient, int & nIndex)
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CWebSocketServer::DelPlayerClientInfo");

	int nSize = m_PlayerClientInfoVec.size();
	if (nSize <= 0)
		return false;

	if (nIndex < 0 || nIndex >= nSize)
		return false;

	CPlayerClientInfo* pPlayerClientInfo = m_PlayerClientInfoVec[nIndex];
	if (NULL == pPlayerClientInfo)
		return false;

	EQ_AUTOLOCK(m_Lock)
	{
		SAFE_DELETE(pPlayerClientInfo);

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Disconnect Index:%d", nIndex);
		return true;
	}
	return true;
}

void   CWebSocketServer::SendClientMsg(char* pDataInfo, long nDataLen, int nIndex, bool bClose)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0))
		return;
	{
		EQ_AUTOLOCK(m_Lock)

			int nSize = m_PlayerClientInfoVec.size();
		if (nSize <= 0)
			return;

		if (nIndex < 0 || nIndex >= nSize)
			return;

		CPlayerClientInfo* pPlayerClientInfo = m_PlayerClientInfoVec[nIndex];
		if (NULL == pPlayerClientInfo)
			return;

		if (!pPlayerClientInfo->GetIsUsed())
			return;

		CPlayerClient* pPlayerClient = (CPlayerClient*)pPlayerClientInfo->GetClient();
		if (NULL == pPlayerClient)
			return;

		pPlayerClient->SendMessageData(pDataInfo, nDataLen, bClose);
	}
}

void CWebSocketServer::SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	g_BackendClient.SendData(pDataInfo, nDataLen);
}

void CWebSocketServer::SendClientMsg(char* pDataInfo, long nDataLen, bool bClose)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0))
		return;
	{
		EQ_AUTOLOCK(m_Lock)

			int nSize = m_PlayerClientInfoVec.size();
		if (nSize <= 0)
			return;

		PlayerClientInfoVec::iterator it = m_PlayerClientInfoVec.begin();
		PlayerClientInfoVec::iterator itEnd = m_PlayerClientInfoVec.end();
		for (; it != itEnd; ++it)
		{
			CPlayerClientInfo* pPlayerClientInfo = (*it);
			if (NULL != pPlayerClientInfo && pPlayerClientInfo->GetIsUsed())
			{
				CPlayerClient* pPlayerClient = reinterpret_cast<CPlayerClient*>(pPlayerClientInfo->GetClient());
				if (NULL != pPlayerClient)
				{
					pPlayerClient->SendMessageData(pDataInfo, nDataLen, bClose);
				}
			}
		}
	}
}