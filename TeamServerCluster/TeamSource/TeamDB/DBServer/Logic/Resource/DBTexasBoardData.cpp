#include "DBResourceManager.h"

bool CDBResourceManager::AddDBTexasBoardInfo(CDBTexasBoardInfo* pDBTexasBoardInfo)
{
	if (NULL == pDBTexasBoardInfo)
	{
		return false;
	}
	m_DBTexasBoardInfoMap.insert(DBTexasBoardInfoMap::value_type(pDBTexasBoardInfo->get_board_id(), pDBTexasBoardInfo));
	return true;
}

int CDBResourceManager::GetDBTexasBoardInfo_BoardID(int nServerId, int nRoomID)
{
	int nMaxBoardID = 0;
	DBTexasBoardInfoMap::iterator it = m_DBTexasBoardInfoMap.begin();
	DBTexasBoardInfoMap::iterator itEnd = m_DBTexasBoardInfoMap.end();
	for (; it != itEnd; ++it)
	{
		CDBTexasBoardInfo* pDBTexasBoardInfo = it->second;
		if (NULL != pDBTexasBoardInfo)
		{
			if (nServerId == pDBTexasBoardInfo->get_board_server_id() && nRoomID == pDBTexasBoardInfo->get_board_room_id())
			{
				if (nMaxBoardID < pDBTexasBoardInfo->get_board_id())
				{
					nMaxBoardID = pDBTexasBoardInfo->get_board_id();
				}
			}
		}
	}
	return nMaxBoardID;
}

void  CDBResourceManager::ReleaseDBTexasBoardMap()
{
	m_DBTexasBoardInfoMap.clear();
}