#include "CenterServer.h"
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
CCenterServer::CCenterServer()
{
	m_PlayerClientInfoVec.clear();
}

CCenterServer::~CCenterServer()
{
	Release();
}

void  CCenterServer::Release()
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

CEQ_TCPClientHandler* CCenterServer::EQ_OnAcceptEx(CEQ_TcpClient* pNewClient)
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

void  CCenterServer::EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}

bool  CCenterServer::AddPlayerClientInfo(void* pClient, int & nIndex)
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

bool  CCenterServer::DelPlayerClientInfo(void* pClient, int & nIndex)
{
	EQ_AUTOLOCK(m_Lock)
	{
		if (m_PlayerClientInfoVec.empty())
		{
			return false;
		}

		int nSize = m_PlayerClientInfoVec.size();
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

void   CCenterServer::SendClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nIndex, int nProtocolID)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead))
		return;

	EQ_AUTOLOCK(m_Lock)
	{
		if (m_PlayerClientInfoVec.empty())
		{
			return;
		}
		if ((NULL != m_PlayerClientInfoVec[nIndex]) &&
			(m_PlayerClientInfoVec[nIndex]->GetIsUsed()) &&
			(NULL != m_PlayerClientInfoVec[nIndex]->GetClient()))
		{
			PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
			CPlayerClient* pPlayerClient = (CPlayerClient*)m_PlayerClientInfoVec[nIndex]->GetClient();
			if (NULL == pTempPacketHead || NULL == pPlayerClient)
			{
				return;
			}
			pTempPacketHead->SetIndex(nIndex);
			pTempPacketHead->SetPacketHead(nProtocolID);
			pPlayerClient->SendMessageData(pDataInfo, nDataLen);
		}
	}
}