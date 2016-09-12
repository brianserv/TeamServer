#include "DLManager.h"

#include "../Table/DLLogout.h"

bool CDLManager::SaveLogoutData(void *pDLLogoutInfo)
{
	CDLLogout *pDLLogout = (CDLLogout *)pDLLogoutInfo;
	if (NULL == pDLLogout)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_logout(%d,'%s',%d,'%s','%s',%d,%d,%d,'%s');",
		pDLLogout->getRoleId(),
		pDLLogout->getRoleName().c_str(),
		pDLLogout->getPlatformId(),
		pDLLogout->getThirdId().c_str(),
		pDLLogout->getThirdAccount().c_str(),
		pDLLogout->getLoginTime(),
		pDLLogout->getLogoutTime(),
		pDLLogout->getServerId(),
		pDLLogout->getIp().c_str());

	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}