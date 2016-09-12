#include "DBManager.h"

#include "../Table/DBTexasHistoryBoard10.h"

#include "../Resource/DBResourceManager.h"

bool CDBManager::QueryTexasHistoryBoard10Property(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
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
		CDBTexasHistoryBoard10Info *pCDBTexasHistoryBoard10Info = new CDBTexasHistoryBoard10Info();
		if (NULL == pCDBTexasHistoryBoard10Info)
		{
			FreeRes(mysql, res);
			return false;
		}
		int board10_game_id = GetIntValue(row, 0);
		int board10_room_id = GetIntValue(row, 1);
		int board10_server_id = GetIntValue(row, 2);
		string board10_result_detail(GetStringValue(row, 3));
		int board10_board_count = GetIntValue(row, 4);

		pCDBTexasHistoryBoard10Info->setDBTexasHistoryBoard10InfoProperty(
			board10_game_id,
			board10_room_id,
			board10_server_id,
			board10_result_detail,
			board10_board_count);
		if (!CDBResourceManager::Instance().AddDBTexasHistoryBoard10Info(pCDBTexasHistoryBoard10Info))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::SaveTexasHistoryBoard10Info(void* pDBTexasHistoryBoard10Info)
{
	CDBTexasHistoryBoard10Info* pDBTexasHistoryBoard10InfoTemp = (CDBTexasHistoryBoard10Info*)pDBTexasHistoryBoard10Info;
	if (NULL == pDBTexasHistoryBoard10InfoTemp)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };

	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_texasboard10(%d,%d,%d,'%s',%d);",
		pDBTexasHistoryBoard10InfoTemp->get_board10_game_id(),
		pDBTexasHistoryBoard10InfoTemp->get_board10_room_id(),
		pDBTexasHistoryBoard10InfoTemp->get_board10_server_id(),
		pDBTexasHistoryBoard10InfoTemp->get_board10_result_detail().c_str(),
		pDBTexasHistoryBoard10InfoTemp->get_board10_board_count());

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}

bool CDBManager::LoadTexasHistoryBoard10Data()
{
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_get_texasboard10;");

	MYSQL* mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryTexasHistoryBoard10Property(mysql, res, szSql))
	{
		return false;
	}
	return true;
}