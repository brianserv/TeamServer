#include "DBManager.h"

#include "../Table/DBTexasBoard.h"
#include "../Resource/DBResourceManager.h"

bool  CDBManager::QueryTexasBoardProperty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
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
		CDBTexasBoardInfo *pDBTexasBoardInfo = new CDBTexasBoardInfo();
		if (NULL == pDBTexasBoardInfo)
		{
			FreeRes(mysql, res);
			return false;
		}
		int         board_id = GetIntValue(row, 0);
		int			board_girl_id = GetIntValue(row, 1);
		string		board_card(GetStringValue(row, 2));
		string      board_showcard(GetStringValue(row, 3));
		int			board_server_id = GetIntValue(row, 4);
		int			board_game_id = GetIntValue(row, 5);
		int			board_room_id = GetIntValue(row, 6);
		int	        board_sum_chip = GetIntValue(row, 7);
		int			board_rewardjackpot_type = GetIntValue(row, 8);
		int			board_rewardbonus_type = GetIntValue(row, 9);
		int			board_card_type = GetIntValue(row, 10);
		int			board_dealcard_type = GetIntValue(row, 11);
		int			board_result = GetIntValue(row, 12);
		int			board_end_status = GetIntValue(row, 13);
		int			board_start_time = GetIntValue(row, 14);
		int			board_end_time = GetIntValue(row, 15);
		pDBTexasBoardInfo->SetTexasBoardProperty(
			board_id,
			board_girl_id,
			board_card,
			board_showcard,
			board_server_id,
			board_game_id,
			board_room_id,
			board_sum_chip,
			board_rewardjackpot_type,
			board_rewardbonus_type,
			board_card_type,
			board_dealcard_type,
			board_result,
			board_end_status,
			board_start_time,
			board_end_time);
		if (!CDBResourceManager::Instance().AddDBTexasBoardInfo(pDBTexasBoardInfo))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::SaveTexasBoardInfo(void *pDBTexasBoardInfo)
{
	CDBTexasBoardInfo *pDBTexasBoardInfoTemp = (CDBTexasBoardInfo *)pDBTexasBoardInfo;
	if (NULL == pDBTexasBoardInfoTemp)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_texasboard(%d,%d,'%s','%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
		pDBTexasBoardInfoTemp->get_board_id(),
		pDBTexasBoardInfoTemp->get_board_girl_id(),
		pDBTexasBoardInfoTemp->get_board_card().c_str(),
		pDBTexasBoardInfoTemp->get_board_showcard().c_str(),
		pDBTexasBoardInfoTemp->get_board_server_id(),
		pDBTexasBoardInfoTemp->get_board_game_id(),
		pDBTexasBoardInfoTemp->get_board_room_id(),
		pDBTexasBoardInfoTemp->get_board_sum_chip(),
		pDBTexasBoardInfoTemp->get_board_rewardjackpot_type(),
		pDBTexasBoardInfoTemp->get_board_rewardbonus_type(),
		pDBTexasBoardInfoTemp->get_board_card_type(),
		pDBTexasBoardInfoTemp->get_board_dealcard_type(),
		pDBTexasBoardInfoTemp->get_board_result(),
		pDBTexasBoardInfoTemp->get_board_end_status(),
		pDBTexasBoardInfoTemp->get_board_start_time(),
		pDBTexasBoardInfoTemp->get_board_end_time());
	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}
bool CDBManager::LoadTexasBoardData()
{
	char szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_get_texasboard;");
	MYSQL *mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryTexasBoardProperty(mysql, res, szSql))
	{
		return false;
	}
	return true;
}