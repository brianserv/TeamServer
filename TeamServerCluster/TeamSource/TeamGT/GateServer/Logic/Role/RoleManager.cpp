#include "RoleManager.h"

CRoleManager::CRoleManager()
{
}

CRoleManager::~CRoleManager()
{
}

bool CRoleManager::CreateRole(int nRoleId, string strRoleName, string strPassword, int nIndex)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it == m_RoleMap.end())
	{
		CRole* pRole = new CRole(nRoleId, strRoleName, strPassword, nIndex);
		if (NULL == pRole)
		{
			return false;
		}
		pRole->SetRoleId(nRoleId);
		pRole->SetRoleName(strRoleName);
		pRole->SetPassword(strPassword);

		pRole->SetIndex(nIndex);
		pRole->SetIsUsed(true);
		m_RoleMap[nRoleId] = pRole;
	}
	else
	{
		CRole* pRole = it->second;
		if (NULL == pRole)
			return false;

		pRole->SetRoleId(nRoleId);
		pRole->SetRoleName(strRoleName);
		pRole->SetPassword(strPassword);

		pRole->SetIndex(nIndex);
		pRole->SetIsUsed(true);
		return true;
	}
	return false;
}

CRole* CRoleManager::GetRole(int nRoleId)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it == m_RoleMap.end())
	{
		return NULL;
	}
	return it->second;
}

bool  CRoleManager::GetIndex(int nRoleId, int& nIndex)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it != m_RoleMap.end())
	{
		CRole* pRole = it->second;
		if ((NULL == pRole) || (!pRole->GetIsUsed()))
		{
			return false;
		}
		nIndex = pRole->GetIndex();
		return true;
	}
	return  false;
}

bool CRoleManager::DisConnectRole(int nRoleId)
{
	ROLE_MAP::iterator it;
	it = m_RoleMap.find(nRoleId);
	if (it != m_RoleMap.end())
	{
		CRole* pRole = it->second;
		if ((NULL == pRole) || (!pRole->GetIsUsed()))
		{
			return false;
		}

		pRole->SetIsUsed(false);
		return true;
	}
	return false;
}