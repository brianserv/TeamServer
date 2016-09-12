#include "HttpLinkManager.h"

CHttpLinkManager::CHttpLinkManager()
{
}

CHttpLinkManager::~CHttpLinkManager()
{
}

bool CHttpLinkManager::Init()
{
	CreateHttplink();
	return true;
}

void  CHttpLinkManager::CreateHttplink()
{
	m_PlatformVec = CEQ_UniqueVector::Instance().GetUniqueVec(CConfigFile::Instance().m_szPlatformIpType);

	string strYYDomain(CConfigFile::Instance().m_szYYDomain);
	string strFBDomain(CConfigFile::Instance().m_szFBDomain);

	m_PlatformMap.clear();
	PLATFORM_VEC::iterator it = m_PlatformVec.begin();
	PLATFORM_VEC::iterator it_End = m_PlatformVec.end();
	for (it; it != it_End; ++it)
	{
		CreateHttplink(*it);
		SetPlatformDomain(*it, strYYDomain, strFBDomain);
	}
}

void  CHttpLinkManager::CreateHttplink(const int nPlatformType)
{
	switch (nPlatformType)
	{
	case EPType_YY:
		CreateHttpLinkYY();
		break;

	case EPType_FB:
		CreateHttpLinkFB();
		break;

	default:
		break;
	}
}
void  CHttpLinkManager::CreateHttpLinkYY()
{
	CHttpLinkYY* pHttpLinkYY = new CHttpLinkYY();
	if (NULL != pHttpLinkYY)
	{
		pHttpLinkYY->Init();
		this->SetHttpLinkYY(pHttpLinkYY);
	}
}

void  CHttpLinkManager::CreateHttpLinkFB()
{
	CHttpLinkFB* pHttpLinkFB = new CHttpLinkFB();
	if (NULL != pHttpLinkFB)
	{
		pHttpLinkFB->Init();
		this->SetHttpLinkFB(pHttpLinkFB);
	}
}

void  CHttpLinkManager::SetHttpLinkYY(CHttpLinkYY* pHttpLinkYY)
{
	if (NULL != pHttpLinkYY)
	{
		this->m_pHttpLinkYY = pHttpLinkYY;
	}
}
void  CHttpLinkManager::SetHttpLinkFB(CHttpLinkFB* pHttpLinkFB)
{
	if (NULL != pHttpLinkFB)
	{
		this->m_pHttpLinkFB = pHttpLinkFB;
	}
}

void  CHttpLinkManager::SetPlatformDomain(const int nPlatformType, const string strYYDomain, const string strFBDomain)
{
	switch (nPlatformType)
	{
	case EPType_YY:
		m_PlatformMap[EPType_YY] = strYYDomain;
		break;

	case EPType_FB:
		m_PlatformMap[EPType_FB] = strFBDomain;
		break;

	default:
		break;
	}
}

string  CHttpLinkManager::GetPlatformDomain(const int nPlatformType)
{
	PLATFORM_MAP::iterator it;
	it = m_PlatformMap.find(nPlatformType);
	if (it != m_PlatformMap.end())
	{
		return it->second;
	}
	string str("");
	return str;
}

CHttpLinkYY*  CHttpLinkManager::GetHttpLinkYY()
{
	if (NULL != m_pHttpLinkYY)
	{
		return this->m_pHttpLinkYY;
	}
}

CHttpLinkFB*  CHttpLinkManager::GetHttpLinkFB()
{
	if (NULL != m_pHttpLinkFB)
	{
		return this->m_pHttpLinkFB;
	}
}

void  CHttpLinkManager::HttpLinkHandler(const int nPlatformType, const int nHttpEventType,
	const int nRoleId, const int nRoomId, const int nIndex)
{
	switch (nPlatformType)
	{
	case EPType_YY:
	{
		CHttpLinkYY* pHttpLinkYY = GetHttpLinkYY();
		if (NULL != pHttpLinkYY)
		{
			pHttpLinkYY->HttpEventHandler(GetPlatformDomain(nPlatformType), nHttpEventType, nRoleId, nRoomId, nIndex);
		}
	}
	break;

	case EPType_FB:
	{
		CHttpLinkFB* pHttpLinkFB = GetHttpLinkFB();
		if (NULL != pHttpLinkFB)
		{
			pHttpLinkFB->HttpEventHandler(GetPlatformDomain(nPlatformType), nHttpEventType, nRoleId, nRoomId, nIndex);
		}
	}
	break;

	default:
		break;
	}
}