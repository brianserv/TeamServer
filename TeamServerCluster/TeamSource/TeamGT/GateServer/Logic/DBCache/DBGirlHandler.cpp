#include "DBManager.h"

#include "../../Logic/Girl/GirlManager.h"

bool CDBManager::QueryGirlProperty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
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

		int nGirlId = GetIntValue(row, 0);
		int nGirlRoleId = GetIntValue(row, 1);
		string strGirlName(GetStringValue(row, 2));
		string strGirlPassword(GetStringValue(row, 3));
		string strGirlThirdId(GetStringValue(row, 4));
		int nCreateTime = GetIntValue(row, 5);

		if (!CGirlManager::Instance().CreateGirl(nGirlId, nGirlRoleId, strGirlName, strGirlPassword, strGirlThirdId, nCreateTime, 0))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::LoadGirlData()
{
	char szSql[MAX_SQL_STR_LENGTH] = { 0 };

	EQ_SPRINTF(szSql, sizeof(szSql), "call sp_get_girl;");

	MYSQL *mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryGirlProperty(mysql, res, szSql))
	{
		return false;
	}
	return true;
}