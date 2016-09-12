#include "TexasRoomManager.h"
#include "../../../DBCache/DBHallEntity/DBHallEntityManager.h"

CTexasRoomManager::CTexasRoomManager()
{
}
CTexasRoomManager::~CTexasRoomManager()
{
	Clear();
}

bool CTexasRoomManager::Init()
{
	Clear();

	m_GameRoomIdVec = CEQ_UniqueVector::Instance().GetUniqueVec(CConfigFile::Instance().m_szTexasRoomId);
	GameRoomIdVec::iterator it = m_GameRoomIdVec.begin();
	for (; it != m_GameRoomIdVec.end(); ++it)
	{
		if (!CreateRoom(*it, ERoomType_Common))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Room[RoomId:%d] Failure !", *it);
			return false;
		}
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Room[RoomId:%d] Success !", *it);
	}

	return true;
}

bool CTexasRoomManager::InitEx()
{
	DBHallEntityMAP& refDBHallEntityMAP = CDBHallEntityManager::Instance().GetDBHallEntityMap();
	DBHallEntityMAP::iterator it = refDBHallEntityMAP.begin();
	DBHallEntityMAP::iterator it_end = refDBHallEntityMAP.end();
	for (; it != it_end; ++it)
	{
		if (!CreateRoom(it->first, ERoomType_Common))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Room[RoomId:%d] Failure !", it->first);
			return false;
		}
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Room[RoomId:%d] Success !", it->first);
	}
	return true;
}
bool CTexasRoomManager::Clear()
{
	m_GameRoomIdVec.clear();
	m_TexasRoomMap.clear();
	return true;
}

bool  CTexasRoomManager::CreateRoom(int nRoomId, int nRoomType)
{
	CTexasRoom* pTexasRoom = new CTexasRoom();
	if (NULL == pTexasRoom)
	{
		return false;
	}
	pTexasRoom->SetIsUsed(true);
	pTexasRoom->SetRoomId(nRoomId);
	pTexasRoom->SetRoomType(nRoomType);

	m_TexasRoomMap[nRoomId] = pTexasRoom;
	return true;
}

bool  CTexasRoomManager::ReleaseVipRoom(int nRoomId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	pTexasRoom->SetIsUsed(false);
	return true;
}

void CTexasRoomManager::ReleaseVipRoom()
{
	TexasRoomMap::iterator it, itRemove;
	it = m_TexasRoomMap.begin();
	while (it != m_TexasRoomMap.end())
	{
		CTexasRoom* pTexasRoom = it->second;
		if (NULL != pTexasRoom &&  pTexasRoom->GetRoomType() == (int)ERoomType_Vip && !pTexasRoom->GetIsUsed())
		{
			itRemove = it;
			it++;
			m_TexasRoomMap.erase(itRemove);
			delete  pTexasRoom;
			pTexasRoom = NULL;
			continue;
		}
		it++;
	}
}

CTexasRoom* CTexasRoomManager::GetTexasRoom(int nRoomId)
{
	TexasRoomMap::iterator it = m_TexasRoomMap.find(nRoomId);
	if (it == m_TexasRoomMap.end())
	{
		return NULL;
	}
	return it->second;
}

bool CTexasRoomManager::CheckGirl(int nRoomId, int nGirlId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	if (!pTexasRoom->CheckGirl(nGirlId))
	{
		return false;
	}
	return true;
}

bool CTexasRoomManager::Girl_EnterRoom(int nRoomId, int nGirlId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	return pTexasRoom->Girl_EnterRoom(nGirlId);
}

bool CTexasRoomManager::Girl_LeaveRoom(int nRoomId, int nGirlId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	return pTexasRoom->Girl_LeaveRoom(nGirlId);
}

bool CTexasRoomManager::Role_EnterRoom(int nRoomId, int nRoleId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}

	return pTexasRoom->Role_EnterRoom(nRoleId);
}

bool CTexasRoomManager::Role_LeaveRoom(int nRoomId, int nRoleId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}

	return pTexasRoom->Role_LeaveRoom(nRoleId);
}

bool CTexasRoomManager::Role_Sitdown(int nRoomId, int nRoleId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	return pTexasRoom->Role_Sitdown(nRoleId);
}
bool CTexasRoomManager::Role_StandUp(int nRoomId, int nRoleId)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	return pTexasRoom->Role_StandUp(nRoleId);
}

bool  CTexasRoomManager::SetVipRoomInfo(TexasRoomVip& refTexasRoomVip)
{
	CTexasRoom* pTexasRoom = GetTexasRoom(refTexasRoomVip.nRoomId);
	if (NULL == pTexasRoom)
	{
		return false;
	}
	pTexasRoom->SetVipRoomInfo(refTexasRoomVip);
	return true;
}