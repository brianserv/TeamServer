#include "GirlManager.h"

CGirlManager::CGirlManager()
{
}

CGirlManager::~CGirlManager()
{
	Release();
}

bool CGirlManager::CreateGirl(int nGirlId, int nGirlRoleId,
	string strGirlName, string strPassword,
	string strThirdId, int nCreateTime,
	int nPlayerIndex, int nGateIndex)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL == pGirl)
	{
		pGirl = new CGirl();
		if (NULL == pGirl)
		{
			return false;
		}
		pGirl->SetGirlProperty(nGirlId, nGirlRoleId,
			strGirlName, strPassword,
			strThirdId, nCreateTime,
			nPlayerIndex, nGateIndex);

		if (!AddGirl(pGirl))
		{
			return false;
		}
		return true;
	}
	pGirl->SetGirlProperty(nGirlId, nGirlRoleId,
		strGirlName, strPassword,
		strThirdId, nCreateTime,
		nPlayerIndex, nGateIndex);

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
	CGirl* pGirl = it->second;
	if (NULL == pGirl)
	{
		return NULL;
	}

	return pGirl;
}

void   CGirlManager::Release()
{
	m_GirlMap.clear();
}

string CGirlManager::GetGirlName(int nGirlId)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL != pGirl)
	{
		return pGirl->getGirlName();
	}
}

bool  CGirlManager::EnterRooom(int nGirlId, int nGameType, int nRoomId)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL == pGirl)
	{
		return false;
	}
	pGirl->setGameType(nGameType);
	pGirl->setRoomID(nRoomId);

	return true;
}

bool  CGirlManager::LeaveRooom(int nGirlId, int nGameType, int nRoomId)
{
	CGirl* pGirl = GetGirl(nGirlId);
	if (NULL == pGirl)
	{
		return false;
	}
	pGirl->setGameType(0);
	pGirl->setRoomID(0);

	true;
}