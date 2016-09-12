#include "DLManager.h"

#include "../Table/DLRoom.h"

bool CDLManager::SaveRoomData(void *pDLRoomInfo)
{
	CDLRoom *pDLRoom = (CDLRoom *)pDLRoomInfo;
	if (NULL == pDLRoom)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_room(%d,'%s',%d,'%s','%s',%d,%d,%d);",
		pDLRoom->getRoleId(),
		pDLRoom->getRoleName().c_str(),
		pDLRoom->getPlatformId(),
		pDLRoom->getThirdId().c_str(),
		pDLRoom->getThirdAccount().c_str(),
		pDLRoom->getRoomId(),
		pDLRoom->getGirlId(),
		pDLRoom->getAction());

	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}