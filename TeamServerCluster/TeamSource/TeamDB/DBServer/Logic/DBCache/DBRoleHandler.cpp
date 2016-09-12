#include "DBManager.h"

#include "../Table/DBRole.h"
#include "../Resource/DBResourceManager.h"

bool CDBManager::QueryRoleProperty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
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

		CDBRoleInfo* pDBRoleInfo = new CDBRoleInfo();
		if (NULL == pDBRoleInfo)
		{
			FreeRes(mysql, res);
			return false;
		}
		int account_id = GetIntValue(row, 0);
		string account_name(GetStringValue(row, 1));
		string account_password(GetStringValue(row, 2));
		int account_platform_id = GetIntValue(row, 3);
		string account_third_id(GetStringValue(row, 4));
		string account_third_account(GetStringValue(row, 5));
		int  account_sex = GetIntValue(row, 6);
		int  account_status = GetIntValue(row, 7);
		string account_status_reason(GetStringValue(row, 8));
		int account_last_login_time = GetIntValue(row, 9);
		int account_login_times = GetIntValue(row, 10);
		int account_ban_time = GetIntValue(row, 11);
		int account_exp = GetIntValue(row, 12);
		int account_level = GetIntValue(row, 13);
		int account_unbind_chip = GetIntValue(row, 14);
		int account_unbind_pink = GetIntValue(row, 15);
		int account_bind_chip = GetIntValue(row, 16);
		int account_bind_pink = GetIntValue(row, 17);
		int account_max_pink = GetIntValue(row, 18);
		int account_max_chip = GetIntValue(row, 19);
		int account_highest_chip = GetIntValue(row, 20);
		int account_vip_type = GetIntValue(row, 21);
		int account_vip_level = GetIntValue(row, 22);
		int account_vip_points = GetIntValue(row, 23);
		int account_win_times = GetIntValue(row, 24);
		int account_lost_times = GetIntValue(row, 25);
		int account_draw_times = GetIntValue(row, 26);

		string account_max_cardtype(GetStringValue(row, 27));

		int account_chat_status = GetIntValue(row, 28);
		int account_gift_spend = GetIntValue(row, 29);
		int	account_gift_month = GetIntValue(row, 30);
		int account_create_time = GetIntValue(row, 31);

		pDBRoleInfo->SetRoleProperty(account_id,
			account_name,
			account_password,
			account_platform_id,
			account_third_id,
			account_third_account,
			account_sex,
			account_status,
			account_status_reason,
			account_last_login_time,
			account_login_times,
			account_ban_time,
			account_exp,
			account_level,
			account_unbind_chip,
			account_unbind_pink,
			account_bind_chip,
			account_bind_pink,
			account_max_pink,
			account_max_chip,
			account_highest_chip,
			account_vip_type,
			account_vip_level,
			account_vip_points,
			account_win_times,
			account_lost_times,
			account_draw_times,
			account_max_cardtype,
			account_chat_status,
			account_gift_spend,
			account_gift_month,
			account_create_time);
		if (!CDBResourceManager::Instance().AddDBRoleInfo(pDBRoleInfo))
		{
			FreeRes(mysql, res);
			return false;
		}
	}
	FreeRes(mysql, res);
	return true;
}

bool CDBManager::SaveRoleInfo(void* pDBRoleInfo)
{
	CDBRoleInfo* pDBRoleInfoTemp = (CDBRoleInfo*)pDBRoleInfo;
	if (NULL == pDBRoleInfoTemp)
	{
		return false;
	}

	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_save_role(%d,'%s','%s',%d,'%s','%s',%d,%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,'%s',%d,%d,%d);",
		pDBRoleInfoTemp->get_account_id(),
		pDBRoleInfoTemp->get_account_name().c_str(),
		pDBRoleInfoTemp->get_account_password().c_str(),
		pDBRoleInfoTemp->get_account_platform_id(),
		pDBRoleInfoTemp->get_account_third_id().c_str(),
		pDBRoleInfoTemp->get_account_third_account().c_str(),
		pDBRoleInfoTemp->get_account_sex(),
		pDBRoleInfoTemp->get_account_status(),
		pDBRoleInfoTemp->get_account_status_reason().c_str(),
		pDBRoleInfoTemp->get_account_last_login_time(),
		pDBRoleInfoTemp->get_account_login_times(),
		pDBRoleInfoTemp->get_account_ban_time(),
		pDBRoleInfoTemp->get_account_exp(),
		pDBRoleInfoTemp->get_account_level(),
		pDBRoleInfoTemp->get_account_unbind_chip(),
		pDBRoleInfoTemp->get_account_unbind_pink(),
		pDBRoleInfoTemp->get_account_bind_chip(),
		pDBRoleInfoTemp->get_account_bind_pink(),
		pDBRoleInfoTemp->get_account_max_pink(),
		pDBRoleInfoTemp->get_account_max_chip(),
		pDBRoleInfoTemp->get_account_highest_chip(),
		pDBRoleInfoTemp->get_account_vip_type(),
		pDBRoleInfoTemp->get_account_vip_level(),
		pDBRoleInfoTemp->get_account_vip_points(),
		pDBRoleInfoTemp->get_account_win_times(),
		pDBRoleInfoTemp->get_account_lost_times(),
		pDBRoleInfoTemp->get_account_draw_times(),
		pDBRoleInfoTemp->get_account_max_cardtype().c_str(),
		pDBRoleInfoTemp->get_account_chat_status(),
		pDBRoleInfoTemp->get_account_gift_spend(),
		pDBRoleInfoTemp->get_account_gift_month());

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}

bool CDBManager::LoadRoleData()
{
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call  sp_get_role;");

	MYSQL* mysql = NULL;
	MYSQL_RES *res = NULL;
	if (!QueryRoleProperty(mysql, res, szSql))
	{
		return false;
	}
	return true;
}