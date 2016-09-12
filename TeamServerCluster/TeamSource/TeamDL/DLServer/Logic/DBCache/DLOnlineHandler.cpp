#include "DLManager.h"

#include "../Table/DLOnline.h"

bool CDLManager::SaveOnlineData(void *pDLOnlineInfo)
{
	CDLOnline *pDLOnline = (CDLOnline *)pDLOnlineInfo;
	if (NULL == pDLOnline)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_online(%d,%d,%d,%d,%d,%d,%d);",
		pDLOnline->getServerId(),
		pDLOnline->getGameType(),
		pDLOnline->getRoomType(),
		pDLOnline->getGameId(),
		pDLOnline->getRoomId(),
		pDLOnline->getGirlId(),
		pDLOnline->getOnlineUsersCount());

	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}