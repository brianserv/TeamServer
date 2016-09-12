#include "DLManager.h"

#include "../Table/DLPvgGift.h"

bool CDLManager::SavePvgGiftData(void *pDLPvgGiftInfo)
{
	CDLPvgGift *pDLPvgGift = (CDLPvgGift*)pDLPvgGiftInfo;
	if (NULL == pDLPvgGift)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_pvggift(%d,'%s',%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
		pDLPvgGift->getRoleId(),
		pDLPvgGift->getRoleName().c_str(),
		pDLPvgGift->getGirlId(),
		pDLPvgGift->getGirlThirdId().c_str(),
		pDLPvgGift->getGiftId(),
		pDLPvgGift->getGiftNum(),
		pDLPvgGift->getGiftPrice(),
		pDLPvgGift->getType(),
		pDLPvgGift->getUnbindPink(),
		pDLPvgGift->getBindPink(),
		pDLPvgGift->getGameType(),
		pDLPvgGift->getGameId(),
		pDLPvgGift->getRoomId(),
		pDLPvgGift->getServerId(),
		pDLPvgGift->getRoomType(),
		pDLPvgGift->getEvenCount(),
		pDLPvgGift->getBroadcastType(),
		pDLPvgGift->getSaveType()
		);

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}