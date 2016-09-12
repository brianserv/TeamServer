#include "DBResourceManager.h"

bool CDBResourceManager::AddDBTexasHistoryBoard10Info(CDBTexasHistoryBoard10Info* pDBTexasHistoryBoard10Info)
{
	if (NULL == pDBTexasHistoryBoard10Info)
	{
		return false;
	}
	int nRoomId = pDBTexasHistoryBoard10Info->get_board10_room_id();

	DBTexasHistoryBoard10InfoMap::iterator it = m_DBTexasHistoryBoard10InfoMap.find(nRoomId);
	if (it != m_DBTexasHistoryBoard10InfoMap.end())
	{
		return false;
	}
	m_DBTexasHistoryBoard10InfoMap[nRoomId] = pDBTexasHistoryBoard10Info;
	return true;
}

CDBTexasHistoryBoard10Info*CDBResourceManager::GetDBTexasHistoryBoard10Info(int nRoomId)
{
	DBTexasHistoryBoard10InfoMap::iterator it;
	it = m_DBTexasHistoryBoard10InfoMap.find(nRoomId);
	if (it == m_DBTexasHistoryBoard10InfoMap.end())
	{
		return NULL;
	}
	return it->second;
}

void  CDBResourceManager::ReleaseDBTexasHistoryBoard10Map()
{
	m_DBTexasHistoryBoard10InfoMap.clear();
}