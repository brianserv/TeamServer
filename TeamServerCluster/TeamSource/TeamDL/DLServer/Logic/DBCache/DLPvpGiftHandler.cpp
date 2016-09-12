#include "DLManager.h"

#include "../Table/DLPvpGift.h"

bool CDLManager::SavePvpGiftData(void *pDLPvpGiftInfo)
{
	CDLPvpGift *pDLPvpGift = (CDLPvpGift *)pDLPvpGiftInfo;
	if (NULL == pDLPvpGift)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_pvpgift(%I64d,%I64d,'%s','%s',%d,'%s','%s','%s','%s',%d,%d,%d,%d,%d,%d);",
		pDLPvpGift->getFromRoleId(),
		pDLPvpGift->getToRoleId(),
		pDLPvpGift->getFromRoleName().c_str(),
		pDLPvpGift->getToRoleName().c_str(),
		pDLPvpGift->getPlatformId(),
		pDLPvpGift->getFromThirdId().c_str(),
		pDLPvpGift->getToThirdId().c_str(),
		pDLPvpGift->getFromThirdAccount().c_str(),
		pDLPvpGift->getToThirdAccount().c_str(),
		pDLPvpGift->getGiftId(),
		pDLPvpGift->getGiftPrice(),
		pDLPvpGift->getUnbindChip(),
		pDLPvpGift->getBindChip(),
		pDLPvpGift->getServerId(),
		pDLPvpGift->getRoomId());

	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}