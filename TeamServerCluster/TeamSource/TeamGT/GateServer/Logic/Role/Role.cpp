#include "Role.h"

EQ_IMPLEMENT_CACHE(CRole, 1000)
CRole::CRole(int nRoleId, string strRoleName, string strPassword, int nIndex)
	:m_nRoleId(nRoleId), m_nIndex(nIndex), m_bIsUsed(true)
{
	m_strRoleName = "";
	m_strPassword = "";
}

CRole::~CRole()
{
	Clear();
}

void CRole::Clear()
{
	m_nRoleId = 0;
	m_nIndex = 0;
	m_bIsUsed = false;
}