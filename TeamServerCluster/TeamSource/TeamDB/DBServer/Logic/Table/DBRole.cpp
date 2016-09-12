#include "DBRole.h"

EQ_IMPLEMENT_CACHE(CDBRoleInfo, 100)
CDBRoleInfo::CDBRoleInfo()
{
	m_bIsUpdata = false;
	m_bIsUpdataRoleInfo = false;
	m_bIsOldRole = true;
}

CDBRoleInfo::~CDBRoleInfo()
{
	m_bIsUpdata = false;
	m_bIsUpdataRoleInfo = false;
	m_bIsOldRole = false;
}

void   CDBRoleInfo::UpdataRoleInfo(bool bIsOldRole)
{
	m_bIsOldRole = bIsOldRole;
	m_bIsUpdata = true;
	m_bIsUpdataRoleInfo = true;
}

void   CDBRoleInfo::SetRoleProperty(
	int account_id,
	string account_name,
	string account_password,
	int account_platform_id,
	string account_third_id,
	string account_third_account,
	int  account_sex,
	int account_status,
	string account_status_reason,
	int account_last_login_time,
	int account_login_times,
	int account_ban_time,
	int account_exp,
	int account_level,
	int account_unbind_chip,
	int account_unbind_pink,
	int account_bind_chip,
	int account_bind_pink,
	int account_max_pink,
	int account_max_chip,
	int account_highest_chip,
	int account_vip_type,
	int account_vip_level,
	int account_vip_points,
	int account_win_times,
	int account_lost_times,
	int account_draw_times,
	string account_max_cardtype,
	int account_chat_status,
	int account_gift_spend,
	int account_gift_month,
	int account_create_time)
{
	set_account_id(account_id);
	set_account_name(account_name);
	set_account_password(account_password);
	set_account_platform_id(account_platform_id);
	set_account_third_id(account_third_id);
	set_account_third_account(account_third_account);
	set_account_sex(account_sex);
	set_account_status(account_status);
	set_account_status_reason(account_status_reason);
	set_account_last_login_time(account_last_login_time);
	set_account_login_times(account_login_times);
	set_account_ban_time(account_ban_time);
	set_account_exp(account_exp);
	set_account_level(account_level);
	set_account_unbind_chip(account_unbind_chip);
	set_account_unbind_pink(account_unbind_pink);
	set_account_bind_chip(account_bind_chip);
	set_account_bind_pink(account_bind_pink);
	set_account_max_pink(account_max_pink);
	set_account_max_chip(account_max_chip);
	set_account_highest_chip(account_highest_chip);
	set_account_vip_type(account_vip_type);
	set_account_vip_level(account_vip_level);
	set_account_vip_points(account_vip_points);
	set_account_win_times(account_win_times);
	set_account_lost_times(account_lost_times);
	set_account_draw_times(account_draw_times);
	set_account_max_cardtype(account_max_cardtype);
	set_account_chat_status(account_chat_status);
	set_account_gift_spend(account_gift_spend);
	set_account_gift_month(account_gift_month);
	set_account_create_time(account_create_time);

	set_IsOldRole(account_login_times);
}