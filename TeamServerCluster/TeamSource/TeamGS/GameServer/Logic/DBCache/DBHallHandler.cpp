#include "DBManager.h"
#include "../../FrameWork/BaseDefine.h"

#include  "DBHallEntity/DBHallEntityManager.h"
#include "../../../../TeamGC/CenterServer/Logic/ServerManager/GameServer.h"

bool CDBManager::QueryHallProperty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
{
	if (NULL == szSql)
	{
		return false;
	}
	if (!Execute(mysql, res, szSql))
	{
		return false;
	}

	int nLineNum = GetRows(res);
	for (int index = 0; index < nLineNum; ++index)
	{
		MYSQL_ROW row = FetchRow(res);
		CDBHallEntity* pDBHallEntity = new CDBHallEntity();
		if (NULL == pDBHallEntity)
		{
			FreeRes(mysql, res);
			return false;
		}

		int hall_server_id = GetIntValue(row, 0);
		string hall_server_name(GetStringValue(row, 1));
		int hall_room_id = GetIntValue(row, 2);
		int hall_room_class = GetIntValue(row, 3);
		int hall_room_type = GetIntValue(row, 4);
		string hall_room_name(GetStringValue(row, 5));
		int hall_room_game_id = GetIntValue(row, 6);
		int hall_room_game_type = GetIntValue(row, 7);
		string hall_room_game_name(GetStringValue(row, 8));
		int hall_room_create_time = GetIntValue(row, 9);

		pDBHallEntity->SetProperty(
			hall_server_id,
			hall_server_name,
			hall_room_id,
			hall_room_class,
			hall_room_type,
			hall_room_name,
			hall_room_game_id,
			hall_room_game_type,
			hall_room_game_name,
			hall_room_create_time);

		if (!CDBHallEntityManager::Instance().Create(pDBHallEntity))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::LoadHallRoom_Texas(int nServerId)
{
	int nGameType = (int)EGameType_Texas;

	char szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call sp_get_hall(%d,%d);", nServerId, nGameType);

	MYSQL *mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryHallProperty(mysql, res, szSql))
	{
		return false;
	}
	return true;
}