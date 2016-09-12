#include "GirlManager.h"

CGirlManager::CGirlManager()
{
}

CGirlManager::~CGirlManager()
{
	Release();
}

bool CGirlManager::CreateGirl(int nGirlId, int nGirlRoleId, string strGirlName, string strPassword, string strThirdId, int nCreateTime, int nPlayerIndex)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL == pGirl)
	{
		pGirl = new CGirl();
		if (NULL == pGirl)
		{
			return false;
		}
		pGirl->SetGirlProperty(nGirlId, nGirlRoleId, strGirlName, strPassword, strThirdId, nCreateTime, nPlayerIndex);
		if (!AddGirl(pGirl))
		{
			return false;
		}
		return true;
	}
	pGirl->SetGirlProperty(nGirlId, nGirlRoleId, strGirlName, strPassword, strThirdId, nCreateTime, nPlayerIndex);

	return true;
}

bool CGirlManager::AddGirl(CGirl* pGirl)
{
	if (NULL == pGirl)
	{
		return false;
	}
	int nGirlID = pGirl->getGirlId();

	GIRL_MAP::iterator it;
	it = m_GirlMap.find(nGirlID);
	if (it != m_GirlMap.end())
	{
		return false;
	}

	m_GirlMap[nGirlID] = pGirl;
	return true;
}

CGirl* CGirlManager::GetGirl(int nGirlId)
{
	GIRL_MAP::iterator it;
	it = m_GirlMap.find(nGirlId);
	if (it == m_GirlMap.end())
	{
		return NULL;
	}
	return it->second;
}

void   CGirlManager::Release()
{
	m_GirlMap.clear();
}

bool CGirlManager::CheckGirl(int nGirlId, string strGirlName, string strPassword)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL == pGirl)
	{
		return false;
	}
	if (strGirlName != pGirl->getGirlName() || strPassword != pGirl->getPassword())
	{
		return false;
	}
	return true;
}

bool CGirlManager::CheckGirlName(int &nGirlId, string strGirlName, string strPassword)
{
	GIRL_MAP::iterator it = m_GirlMap.begin();
	GIRL_MAP::iterator itEnd = m_GirlMap.end();
	for (; it != itEnd; ++it)
	{
		CGirl* pGirl = it->second;
		if (NULL != pGirl)
		{
			if (strGirlName == pGirl->getGirlName() && strPassword == pGirl->getPassword())
			{
				nGirlId = pGirl->getGirlId();
				return true;
			}
		}
	}
	return false;
}