#include "DLManager.h"

#include "../Table/DLLogin.h"

bool CDLManager::SaveLoginData(void *pDLLoginInfo)
{
	CDLLogin *pDLLogin = (CDLLogin *)pDLLoginInfo;
	if (NULL == pDLLogin)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_login(%d,'%s',%d,'%s','%s',%d,%d,'%s',%d);",
		pDLLogin->getRoleId(),
		pDLLogin->getRoleName().c_str(),
		pDLLogin->getPlatformId(),
		pDLLogin->getThirdId().c_str(),
		pDLLogin->getThirdAccount().c_str(),
		pDLLogin->getLoginTime(),
		pDLLogin->getServerId(),
		pDLLogin->getIp().c_str(),
		pDLLogin->getStatus());

	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}