#include "DBResourceManager.h"

bool CDBResourceManager::AddDBRoleInfo(CDBRoleInfo* pDBRoleInfo)
{
	if (NULL == pDBRoleInfo)
	{
		return false;
	}
	int nRoleID = pDBRoleInfo->get_account_id();
	DBRoleInfoMap::iterator it = m_DBRoleInfoMap.find(nRoleID);
	if (it != m_DBRoleInfoMap.end())
	{
		return false;
	}
	m_DBRoleInfoMap[nRoleID] = pDBRoleInfo;

	m_DBRoleInfoVec.push_back(pDBRoleInfo);
	return true;
}

CDBRoleInfo*  CDBResourceManager::GetDBRoleInfo(int nRoleId)
{
	DBRoleInfoMap::iterator it;
	it = m_DBRoleInfoMap.find(nRoleId);
	if (it == m_DBRoleInfoMap.end())
	{
		return NULL;
	}
	return it->second;
}

void  CDBResourceManager::ReleaseDBRoleMap()
{
	DBRoleInfoVec::iterator it = m_DBRoleInfoVec.begin();
	for (; it != m_DBRoleInfoVec.end(); it++)
	{
		SAFE_DELETE(*it);
	}
	m_DBRoleInfoVec.clear();
	m_DBRoleInfoMap.clear();
}

void  CDBResourceManager::SaveRoleData(int nIndex, int & nRoleIndex)
{
	int nSaveNum = 0;
	int nDBRoleInfoVecSize = m_DBRoleInfoVec.size();
	for (int i = nRoleIndex; i < nDBRoleInfoVecSize; i++)
	{
		CDBRoleInfo* pDBRoleInfo = m_DBRoleInfoVec[i];
		if (NULL != pDBRoleInfo)
		{
			int nIndexTemp = (pDBRoleInfo->get_account_id() % (DB_CONN_NUM - 1)) + 1;
			if (nIndexTemp == nIndex)
			{
				if (pDBRoleInfo->GetIsUpdata())
				{
					pDBRoleInfo->SetIsUpdata(false);
					if (pDBRoleInfo->GetIsUpdataRoleInfo())
					{
						pDBRoleInfo->SetIsUpdataRoleInfo(false);

						g_DBManager[nIndexTemp].SaveRoleInfo(pDBRoleInfo);
					}

					nSaveNum++;
					if (nSaveNum > DB_SAVEROLE_NUM_MAX)
					{
						nRoleIndex = i;
						return;
					}
				}
			}
		}
	}
	nRoleIndex = 0;
}