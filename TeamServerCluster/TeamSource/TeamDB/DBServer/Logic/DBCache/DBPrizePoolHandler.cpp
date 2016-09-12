#include "DBManager.h"

#include "../Table/DBPrizePool.h"
#include "../Resource/DBResourceManager.h"

bool CDBManager::QueryPrizePoolProterty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
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
		MYSQL_ROW  row = FetchRow(res);

		CDBPrizePoolInfo *pDBPrizePoolInfo = new CDBPrizePoolInfo();
		if (NULL == pDBPrizePoolInfo)
		{
			FreeRes(mysql, res);
			return false;
		}

		int	id = GetIntValue(row, 0);
		int prizepool_total_value = GetIntValue(row, 1);
		int prizepool_pay_value = GetIntValue(row, 2);
		int prizepool_JackpotBonus_Init = GetIntValue(row, 3);

		pDBPrizePoolInfo->setPrizePoolProperty(id, prizepool_total_value, prizepool_pay_value, prizepool_JackpotBonus_Init);
		if (!CDBResourceManager::Instance().AddDBPrizePoolInfo(pDBPrizePoolInfo))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::SavePrizePoolInfo(void *pDBPrizePoolInfo)
{
	CDBPrizePoolInfo *pDBPrizePoolInfoTemp = (CDBPrizePoolInfo *)pDBPrizePoolInfo;
	if (NULL == pDBPrizePoolInfoTemp)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };

	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_prizepool(%d,%d,%d);",
		pDBPrizePoolInfoTemp->get_prizepool_total_value(),
		pDBPrizePoolInfoTemp->get_prizepool_pay_value(),
		pDBPrizePoolInfoTemp->get_prizepool_JackpotBonus_Init());
	if (!Execute(szSql))
	{
		return false;
	}
	return true;
}

bool CDBManager::LoadPrizePoolData()
{
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_get_prizepool;");

	MYSQL* mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryPrizePoolProterty(mysql, res, szSql))
	{
		return false;
	}
	return true;
}