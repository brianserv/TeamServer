#include "GameServer.h"
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
CGameServer::CGameServer()
{
	m_PlayerClientInfoVec.clear();
}

CGameServer::~CGameServer()
{
	Release();
}

void  CGameServer::Release()
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

CEQ_TCPClientHandler* CGameServer::EQ_OnAcceptEx(CEQ_TcpClient* pNewClient)
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

void  CGameServer::EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}

bool  CGameServer::AddPlayerClientInfo(void* pClient, int & nIndex)
{
	CPlayerClientInfo* pPlayerClientInfo = new CPlayerClientInfo(pClient);
	if (NULL == pPlayerClientInfo)
		return false;

	EQ_AUTOLOCK(m_Lock)
	{
		if (m_PlayerClientInfoVec.empty())
		{
			m_PlayerClientInfoVec.push_back(pPlayerClientInfo);
			nIndex = 0;
		}
		else
		{
			if (m_PlayerClientInfoVec.size() >= 1)
			{
				m_PlayerClientInfoVec.push_back(pPlayerClientInfo);
				nIndex = m_PlayerClientInfoVec.size() - 1;
			}
		}
	}
	return true;
}

bool  CGameServer::DelPlayerClientInfo(void* pClient, int & nIndex)
{
	EQ_AUTOLOCK(m_Lock)
	{
		int nSize = m_PlayerClientInfoVec.size();

		if (m_PlayerClientInfoVec.empty())
		{
			return false;
		}

		if (nIndex < 0 || nIndex >= nSize)
		{
			return false;
		}

		PlayerClientInfoVec::iterator it;
		it = m_PlayerClientInfoVec.begin();
		while (it != m_PlayerClientInfoVec.end())
		{
			CPlayerClientInfo* pPlayerClientInfo = *it;
			if (NULL != pPlayerClientInfo &&
				pPlayerClientInfo == m_PlayerClientInfoVec[nIndex] && m_PlayerClientInfoVec[nIndex]->GetIsUsed())
			{
				SAFE_DELETE(pPlayerClientInfo);
				return true;
			}
			it++;
		}
	}

	return true;
}

void   CGameServer::SendClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	EQ_AUTOLOCK(m_Lock)
	{
		if (m_PlayerClientInfoVec.empty())
		{
			return;
		}
		if (nGateIndex < 0 || nGateIndex >= m_PlayerClientInfoVec.size())
		{
			return;
		}
		if ((NULL != m_PlayerClientInfoVec[nGateIndex]) &&
			(m_PlayerClientInfoVec[nGateIndex]->GetIsUsed()) &&
			(NULL != m_PlayerClientInfoVec[nGateIndex]->GetClient()))
		{
			PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
			CPlayerClient* pPlayerClient = (CPlayerClient*)m_PlayerClientInfoVec[nGateIndex]->GetClient();
			if (NULL == pTempPacketHead || NULL == pPlayerClient)
			{
				return;
			}
			pTempPacketHead->SetIndex(nPlayerIndex);
			pPlayerClient->SendMessageData(pDataInfo, nDataLen);
		}
	}
}

void CGameServer::SendDBMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
	{
		return;
	}
	g_DBClient.SendData(pDataInfo, nDataLen);
}

void CGameServer::SendDBLogMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
	{
		return;
	}
	g_DBLogClient.SendData(pDataInfo, nDataLen);
}

void  CGameServer::SendCenterMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
	{
		return;
	}
	g_CenterClient.SendData(pDataInfo, nDataLen);
}

int CGameServer::GetServerId()
{
	return CConfigFile::Instance().m_nGameServerId;
}