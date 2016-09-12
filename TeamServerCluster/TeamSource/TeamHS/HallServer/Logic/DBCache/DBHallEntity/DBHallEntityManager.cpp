#include "DBHallEntityManager.h"

CDBHallEntityManager::CDBHallEntityManager()
{
	m_DBHallEntityMAP.clear();
}

CDBHallEntityManager::~CDBHallEntityManager()
{
	Release();
}

bool CDBHallEntityManager::Create(CDBHallEntity* pGameHallEntity)
{
	if (NULL == pGameHallEntity)
	{
		return false;
	}
	int nHallRoomID = pGameHallEntity->get_hall_room_id();
	DBHallEntityMAP::iterator it = m_DBHallEntityMAP.find(nHallRoomID);
	if (it != m_DBHallEntityMAP.end())
	{
		return false;
	}
	m_DBHallEntityMAP[nHallRoomID] = pGameHallEntity;
	return true;
}

void CDBHallEntityManager::Release()
{
	DBHallEntityMAP::iterator it = m_DBHallEntityMAP.begin();
	DBHallEntityMAP::iterator itEnd = m_DBHallEntityMAP.end();
	for (; it != itEnd; ++it)
	{
		SAFE_DELETE(it->second);
	}
	m_DBHallEntityMAP.clear();
}