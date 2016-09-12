#include "FlashPolicyServer.h"
#include "FlashWebClient.h"

EQ_IMPLEMENT_CACHE(CWebClientInfo, 1000)
CWebClientInfo::CWebClientInfo(void*  pClient)
{
	SetIsUsed(true);
	SetClient(pClient);
}

CWebClientInfo::~CWebClientInfo()
{
	SetIsUsed(false);
	SetClient(NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
CFlashPolicyServer::CFlashPolicyServer()
{
	m_WebClientInfoVec.clear();
}

CFlashPolicyServer::~CFlashPolicyServer()
{
	Release();
}

void  CFlashPolicyServer::Release()
{
	EQ_AUTOLOCK(m_Lock);
	{
		WebClientInfoVec::iterator it = m_WebClientInfoVec.begin();
		for (; it != m_WebClientInfoVec.end(); it++)
		{
			SAFE_DELETE(*it);
		}
		m_WebClientInfoVec.clear();
	}
}

CEQ_TCPClientHandler* CFlashPolicyServer::EQ_OnAcceptEx(CEQ_TcpClient* pNewClient)
{
	CFlashWebClient* pClient = new CFlashWebClient(pNewClient);
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

void  CFlashPolicyServer::EQ_PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...)
{
	va_list list;
	va_start(list, szErrInfo);

	g_LogFile.WriteErrorLogInfo2(nLevel, (char*)szErrInfo, list);

	va_end(list);
}

bool  CFlashPolicyServer::AddPlayerClientInfo(void* pClient, int & nIndex)
{
	CWebClientInfo* pWebClientInfo = new CWebClientInfo(pClient);
	if (NULL == pWebClientInfo)
		return false;

	EQ_AUTOLOCK(m_Lock)
	{
		if (m_WebClientInfoVec.empty())
		{
			m_WebClientInfoVec.push_back(pWebClientInfo);
			nIndex = 0;
		}
		else
		{
			if (m_WebClientInfoVec.size() >= 1)
			{
				m_WebClientInfoVec.push_back(pWebClientInfo);
				nIndex = m_WebClientInfoVec.size() - 1;
			}
		}
	}
	return true;
}

bool  CFlashPolicyServer::DelPlayerClientInfo(void* pClient, int & nIndex)
{
	EQ_AUTOLOCK(m_Lock)
	{
		if (m_WebClientInfoVec.empty())
		{
			return false;
		}

		int nSize = m_WebClientInfoVec.size();
		if (nIndex < 0 || nIndex >= nSize)
		{
			return false;
		}

		WebClientInfoVec::iterator it;
		it = m_WebClientInfoVec.begin();
		while (it != m_WebClientInfoVec.end())
		{
			CWebClientInfo* pWebClientInfo = *it;
			if (NULL != pWebClientInfo &&
				pWebClientInfo == m_WebClientInfoVec[nIndex] && m_WebClientInfoVec[nIndex]->GetIsUsed())
			{
				SAFE_DELETE(pWebClientInfo);
				return true;
			}
			it++;
		}
	}

	return true;
}

void   CFlashPolicyServer::SendClientMsg(char* pDataInfo, long nDataLen, int nIndex)
{
	EQ_AUTOLOCK(m_Lock)
	{
		if (m_WebClientInfoVec.empty())
		{
			return;
		}

		if (nIndex < 0 || nIndex >= m_WebClientInfoVec.size())
		{
			return;
		}

		if ((NULL != m_WebClientInfoVec[nIndex]) &&
			(m_WebClientInfoVec[nIndex]->GetIsUsed()) &&
			(NULL != m_WebClientInfoVec[nIndex]->GetClient()))
		{
			CFlashWebClient* pFlashWebClient = (CFlashWebClient*)m_WebClientInfoVec[nIndex]->GetClient();
			if (NULL != pFlashWebClient)
			{
				pFlashWebClient->SendMessageData(pDataInfo, nDataLen);
			}
		}
	}
}