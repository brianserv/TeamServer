#include "TexasRoom.h"

#include "../../../../Logic/Girl/GirlManager.h"

EQ_IMPLEMENT_CACHE(CTexasRoom, 100)
CTexasRoom::CTexasRoom() :m_bIsUsed(true), m_nRoomId(0), m_nRoomType(0), m_nGirlId(0)
{
}

CTexasRoom::~CTexasRoom()
{
	Clear();
}

bool CTexasRoom::Init()
{
	return true;
}

bool CTexasRoom::Clear()
{
	m_TexasRoleMap.clear();
	return true;
}

CTexasRole* CTexasRoom::GetTexasRole(int nRoleId)
{
	TexasRoleMap::iterator it = m_TexasRoleMap.find(nRoleId);
	if (it == m_TexasRoleMap.end())
	{
		return NULL;
	}
	return it->second;
}

bool  CTexasRoom::CheckGirl(int nGirlId)
{
	if (nGirlId <= 0)
	{
		return false;
	}
	return true;
}

bool CTexasRoom::CheckRole(int nRoleId)
{
	TexasRoleMap::iterator it = m_TexasRoleMap.find(nRoleId);
	if (it == m_TexasRoleMap.end())
	{
		return false;
	}
	return true;
}

bool CTexasRoom::Girl_EnterRoom(int nGirlId)
{
	if (!CheckGirl(nGirlId))
	{
		return false;
	}
	m_nGirlId = nGirlId;
	return true;
}

bool  CTexasRoom::Girl_LeaveRoom(int nGirlId)
{
	if (!CheckGirl(nGirlId))
	{
		return false;
	}
	if (nGirlId != m_nGirlId)
	{
		return false;
	}
	m_nGirlId = 0;
	return true;
}

bool  CTexasRoom::Role_EnterRoom(int nRoleId)
{
	if (!CheckRole(nRoleId))
	{
		CTexasRole* pTexasRole = new CTexasRole();
		if (NULL == pTexasRole)
		{
			return false;
		}

		if (!pTexasRole->SetRole(nRoleId))
		{
			return false;
		}

		pTexasRole->SetRoleId(nRoleId);
		pTexasRole->SetRoomId(m_nRoomId);
		pTexasRole->SetIsSitdown(false);
		pTexasRole->SetIsUsed(true);

		m_TexasRoleMap[nRoleId] = pTexasRole;
		return true;
	}

	CTexasRole* pTexasRole = GetTexasRole(nRoleId);
	if (NULL == pTexasRole)
	{
		return false;
	}

	if (!pTexasRole->SetRole(nRoleId))
	{
		return false;
	}

	if (!pTexasRole->GetIsUsed())
	{
		pTexasRole->SetIsUsed(true);
		return true;
	}
	return true;
}

bool CTexasRoom::Role_LeaveRoom(int nRoleId)
{
	CTexasRole* pTexasRole = GetTexasRole(nRoleId);
	if (NULL == pTexasRole)
	{
		return false;
	}
	pTexasRole->SetIsSitdown(false);
	pTexasRole->SetIsUsed(false);
	return true;
}

bool CTexasRoom::Role_Sitdown(int nRoleId)
{
	CTexasRole* pTexasRole = GetTexasRole(nRoleId);
	if (NULL == pTexasRole)
	{
		return false;
	}
	pTexasRole->SetIsSitdown(true);
	return true;
}

bool CTexasRoom::Role_StandUp(int nRoleId)
{
	CTexasRole* pTexasRole = GetTexasRole(nRoleId);
	if (NULL == pTexasRole)
	{
		return false;
	}
	if (!pTexasRole->GetIsSitdown())
	{
		return false;
	}
	pTexasRole->SetIsSitdown(false);
	return true;
}

void CTexasRoom::SetVipRoomInfo(TexasRoomVip& refTexasRoomVip)
{
	memcpy(&m_TexasRoomVip, &refTexasRoomVip, sizeof(TexasRoomVip));
}

void CTexasRoom::Supplementary_Vip_TexasGame_Chip(int nUnbindChip)
{
	m_TexasRoomVip.nVipPalyersStacks += nUnbindChip;
}

void CTexasRoom::Pay_Vip_TexasGame_Chip(int nUnbindChip)
{
	m_TexasRoomVip.nVipPalyersStacks -= nUnbindChip;
}