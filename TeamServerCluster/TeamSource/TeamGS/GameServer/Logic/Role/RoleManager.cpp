#include "RoleManager.h"

CRoleManager::CRoleManager()
{
	m_RoleMap.clear();
}

CRoleManager::~CRoleManager()
{
	m_RoleMap.clear();
}

bool CRoleManager::AddRole(int nRoleId, int nServerId, int nPlatformId, int nSex,
	string strRoleName, string strPassword, string strThirdId,
	string strThirdAccount, int nPlayerIndex, int nGateIndex)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it == m_RoleMap.end())
	{
		CRole* pRole = new CRole();
		if (NULL == pRole)
		{
			return false;
		}

		pRole->SetRoleId(nRoleId);
		pRole->SetRoleBase(nRoleId, nPlatformId,
			nSex, strRoleName, strPassword,
			strThirdId, strThirdAccount);

		pRole->SetServerId(nServerId);
		pRole->SetPlayerIndex(nPlayerIndex);
		pRole->SetGateIndex(nGateIndex);
		pRole->SetIsUsed(true);

		pRole->AddLoginTimes();

		m_RoleMap[nRoleId] = pRole;
		return true;
	}
	else
	{
		CRole* pRole = it->second;
		if (NULL == pRole)
		{
			return false;
		}

		pRole->SetRoleId(nRoleId);
		pRole->SetServerId(nServerId);
		pRole->SetPlayerIndex(nPlayerIndex);
		pRole->SetGateIndex(nGateIndex);
		pRole->SetIsUsed(true);

		pRole->AddLoginTimes();

		return true;
	}
}

CRole* CRoleManager::GetRole(int nRoleId)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it == m_RoleMap.end())
	{
		return NULL;
	}
	CRole* pRole = it->second;
	if (NULL == pRole)
	{
		return NULL;
	}

	return pRole;
}

bool CRoleManager::SetDeleteRole(int nRoleId)
{
	CRole *pRole = GetRole(nRoleId);
	if (NULL == pRole)
	{
		return false;
	}
	pRole->SetIsUsed(false);
}

void CRoleManager::ReleaseRole()
{
	ROLE_MAP::iterator it, itRemove;
	it = m_RoleMap.begin();
	while (it != m_RoleMap.end())
	{
		CRole *pRole = it->second;
		if (NULL != pRole && !pRole->GetIsUsed())
		{
			itRemove = it;
			it++;
			m_RoleMap.erase(itRemove);
			delete  pRole;
			pRole = NULL;
			continue;
		}
		it++;
	}
}

bool CRoleManager::UpdateRoleBase(int nRoleId,
	string strRoleName,
	string strPassword,
	int nPlatformId,
	string strThirdId,
	string strThirdAccount,
	int nSex,
	int nStatus,
	string strStatusReason,
	int nLastLoginTime,
	int nLoginTimes,
	int nBanTime,
	int nExp,
	int nLevel,
	int nUnbindChip,
	int nUnbindPink,
	int nBindChip,
	int nBindPink,
	int nMaxPink,
	int nMaxChip,
	int nHighestChip,
	int  nVipType,
	int  nVipLevel,
	int  nVipPoints,
	int  nWinTimes,
	int  nLostTimes,
	int  nDrawTimes,
	vector<int> nMaxCardTypeVec,
	int  nChatStatus,
	int nGiftSpend,
	int nGiftSpendMonth)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL == pRole)
	{
		return false;
	}
	pRole->UpdateRoleBase(nRoleId,
		strRoleName,
		strPassword,
		nPlatformId,
		strThirdId,
		strThirdAccount,
		nSex,
		nStatus,
		strStatusReason,
		nLastLoginTime,
		nLoginTimes,
		nBanTime,
		nExp,
		nLevel,
		nUnbindChip,
		nUnbindPink,
		nBindChip,
		nBindPink,
		nMaxPink,
		nMaxChip,
		nHighestChip,
		nVipType,
		nVipLevel,
		nVipPoints,
		nWinTimes,
		nLostTimes,
		nDrawTimes,
		nMaxCardTypeVec,
		nChatStatus,
		nGiftSpend,
		nGiftSpendMonth);

	return true;
}

bool CRoleManager::SetRolePlatformBase(int nRoleId, int nUnbindChip, int nUnbindPink,
	int nBindChip, int nBindPink, int nVipType, int nVipLevel)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL == pRole)
	{
		return false;
	}
	pRole->SetRolePlatformBase(nRoleId, nUnbindChip, nUnbindPink,
		nBindChip, nBindPink, nVipType, nVipLevel);
	return true;
}

bool CRoleManager::SetRoleMaxCardType(int nRoleId, vector<int>& nMaxCardTypeVec)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL == pRole)
	{
		return false;
	}
	pRole->SetRoleMaxCardType(nMaxCardTypeVec);
	return true;
}

UpdatePlatformRoleBaseInfo&CRoleManager::GetUpdatePlatformRoleBaseInfo(int nRoleId, int nIndex)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->GetUpdatePlatformRoleBaseInfo(nIndex);
	}
}

void CRoleManager::ReleaseUpdatePlatformRoleBaseInfo(int nRoleId, int nIndex)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->ReleaseUpdatePlatformRoleBaseInfo(nIndex);
	}
}

string CRoleManager::Get_MD5_RoleIdToken(int nRoleId)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->Get_MD5_RoleIdToken(nRoleId);
	}
}

void CRoleManager::SetGameType(int nRoleId, int nGameType)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}
	pRole->SetGameType(nGameType);
}
int  CRoleManager::GetGameType(int nRoleId)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->GetGameType();
	}
}

void CRoleManager::SetRoomId(int nRoleId, int nRoomId)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->SetRoomId(nRoomId);
	}
}
int  CRoleManager::GetRoomId(int nRoleId)
{
	CRole* pRole = GetRole(nRoleId);
	if (NULL != pRole)
	{
		return pRole->GetRoomId();
	}
}