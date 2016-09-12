#include "DLManager.h"

#include "../Table/DLGm.h"

bool CDLManager::SaveGmData(void* pDLGmInfo)
{
	CDLGm *pDLGm = (CDLGm *)pDLGmInfo;
	if (NULL == pDLGm)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };

	EQ_SPRINTF(szSql, sizeof(szSql), "call sp_save_gm(%d,%d,%d,'%s');",
		pDLGm->getRoleId(),
		pDLGm->getGmId(),
		pDLGm->getGmActionType(),
		pDLGm->getDescribe().c_str());

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}