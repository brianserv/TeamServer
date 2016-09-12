#include "DBResourceManager.h"

CDBResourceManager::CDBResourceManager()
{
	Clear();
}

CDBResourceManager::~CDBResourceManager()
{
	Release();
}

void CDBResourceManager::Clear()
{
	m_DBRoleInfoMap.clear();
	m_DBRoleInfoVec.clear();
	m_DBTexasBoardInfoMap.clear();
	m_DBTexasHistoryBoard10InfoMap.clear();
	mDBPrizePoolInfoMap.clear();
}

void CDBResourceManager::Release()
{
	ReleaseDBRoleMap();
	ReleaseDBTexasBoardMap();
	ReleaseDBTexasHistoryBoard10Map();
	ReleaseDBPrizePoolMap();
}

void CDBResourceManager::SaveDBData(int nIndex, int & nRoleIndex)
{
	SaveRoleData(nIndex, nRoleIndex);
}