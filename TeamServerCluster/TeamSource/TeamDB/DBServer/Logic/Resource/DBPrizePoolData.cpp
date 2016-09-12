#include "DBResourceManager.h"

bool CDBResourceManager::AddDBPrizePoolInfo(CDBPrizePoolInfo* pDBPrizePoolInfo)
{
	if (NULL == pDBPrizePoolInfo)
	{
		return false;
	}
	int nPrizePoolID = pDBPrizePoolInfo->get_Id();

	DBPrizePoolInfoMap::iterator it = mDBPrizePoolInfoMap.find(nPrizePoolID);
	if (it != mDBPrizePoolInfoMap.end())
	{
		return false;
	}
	mDBPrizePoolInfoMap[nPrizePoolID] = pDBPrizePoolInfo;
	return true;
}

CDBPrizePoolInfo*CDBResourceManager::GetDBPrizePoolInfo(int nPrizePoolID)
{
	DBPrizePoolInfoMap::iterator it;
	it = mDBPrizePoolInfoMap.find(nPrizePoolID);
	if (it == mDBPrizePoolInfoMap.end())
	{
		return NULL;
	}
	return it->second;
}

void  CDBResourceManager::ReleaseDBPrizePoolMap()
{
	mDBPrizePoolInfoMap.clear();
}