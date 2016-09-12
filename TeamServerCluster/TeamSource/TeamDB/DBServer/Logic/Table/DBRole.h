#pragma once
#ifndef  __DB_ROLE_H__
#define  __DB_ROLE_H__

#include "../../FrameWork/BaseDefine.h"

class CDBRoleInfo
{
public:
	CDBRoleInfo();
	virtual ~CDBRoleInfo();
	EQ_DECLARE_CACHE(CDBRoleInfo)

public:
	inline void  set_account_id(int account_id) { m_account_id = account_id; };
	inline void  set_account_name(string account_name) { m_account_name = account_name; };
	inline void  set_account_password(string account_password) { m_account_password = account_password; };
	inline void  set_account_platform_id(int account_platform_id) { m_account_platform_id = account_platform_id; };
	inline void  set_account_third_id(string account_third_id) { m_account_third_id = account_third_id; };
	inline void  set_account_third_account(string account_third_account) { m_account_third_account = account_third_account; };
	inline void  set_account_sex(int account_sex) { m_account_sex = account_sex; };
	inline void  set_account_status(int account_status) { m_account_status = account_status; };
	inline void  set_account_status_reason(string account_status_reason) { m_account_status_reason = account_status_reason; };
	inline void  set_account_last_login_time(int account_last_login_time) { m_account_last_login_time = account_last_login_time; };
	inline void  set_account_login_times(int account_login_times)
	{
		if (m_account_login_times <= account_login_times)
		{
			m_account_login_times = account_login_times;
		}
		else
		{
			m_account_login_times++;
		}
	};
	inline void    set_account_ban_time(int account_ban_time) { m_account_ban_time = account_ban_time; };
	inline void    set_account_exp(int account_exp) { m_account_exp = account_exp; };
	inline void    set_account_level(int account_level) { m_account_level = account_level; };
	inline void    set_account_unbind_chip(int account_unbind_chip) { m_account_unbind_chip = account_unbind_chip; };
	inline void    set_account_unbind_pink(int account_unbind_pink) { m_account_unbind_pink = account_unbind_pink; };
	inline void    set_account_bind_chip(int account_bind_chip) { m_account_bind_chip = account_bind_chip; };
	inline void    set_account_bind_pink(int account_bind_pink) { m_account_bind_pink = account_bind_pink; };
	inline void    set_account_max_pink(int account_max_pink) { m_account_max_pink = account_max_pink; };
	inline void    set_account_max_chip(int account_max_chip) { m_account_max_chip = account_max_chip; };
	inline void	   set_account_highest_chip(int account_highest_chip) { m_account_highest_chip = account_highest_chip; };
	inline void    set_account_vip_type(int account_vip_type) { m_account_vip_type = account_vip_type; };
	inline void    set_account_vip_level(int account_vip_level) { m_account_vip_level = account_vip_level; };
	inline void    set_account_vip_points(int account_vip_points) { m_account_vip_points = account_vip_points; };
	inline void    set_account_win_times(int account_win_times) { m_account_win_times = account_win_times; };
	inline void    set_account_lost_times(int account_lost_times) { m_account_lost_times = account_lost_times; };
	inline void    set_account_draw_times(int account_draw_times) { m_account_draw_times = account_draw_times; };
	inline void    set_account_max_cardtype(string account_max_cardtype) { m_account_max_cardtype = account_max_cardtype; };
	inline void    set_account_chat_status(int account_chat_status) { m_account_chat_status = account_chat_status; };
	inline void    set_account_gift_spend(int account_gift_spend) { m_account_gift_spend = account_gift_spend; };
	inline void	   set_account_gift_month(int account_gift_month) { m_account_gift_month = account_gift_month; };
	inline void    set_account_create_time(int account_create_time) { m_account_create_time = account_create_time; };

	inline void    set_IsOldRole(int nLoginTimes) { m_bIsOldRole = ((nLoginTimes > 0) ? true : false); };

public:

	inline int    get_account_id() { return m_account_id; };
	inline string get_account_name() { return m_account_name; };
	inline string get_account_password() { return m_account_password; };
	inline int    get_account_platform_id() { return m_account_platform_id; };
	inline string get_account_third_id() { return m_account_third_id; };
	inline string get_account_third_account() { return m_account_third_account; };
	inline int    get_account_sex() { return m_account_sex; };
	inline int    get_account_status() { return m_account_status; };
	inline string get_account_status_reason() { return m_account_status_reason; };
	inline int    get_account_last_login_time() { return m_account_last_login_time; };
	inline int    get_account_login_times() { return m_account_login_times; };
	inline int    get_account_ban_time() { return m_account_ban_time; };
	inline int    get_account_exp() { return m_account_exp; };
	inline int    get_account_level() { return m_account_level; };
	inline int    get_account_unbind_chip() { return m_account_unbind_chip; };
	inline int    get_account_unbind_pink() { return m_account_unbind_pink; };
	inline int    get_account_bind_chip() { return m_account_bind_chip; };
	inline int    get_account_bind_pink() { return m_account_bind_pink; };
	inline int    get_account_max_pink() { return m_account_max_pink; };
	inline int    get_account_max_chip() { return m_account_max_chip; };
	inline int	  get_account_highest_chip() { return m_account_highest_chip; };
	inline int    get_account_vip_type() { return m_account_vip_type; };
	inline int    get_account_vip_level() { return m_account_vip_level; };
	inline int    get_account_vip_points() { return m_account_vip_points; };
	inline int    get_account_win_times() { return m_account_win_times; };
	inline int    get_account_lost_times() { return m_account_lost_times; };
	inline int    get_account_draw_times() { return m_account_draw_times; };
	inline string get_account_max_cardtype() { return m_account_max_cardtype; };
	inline int    get_account_chat_status() { return m_account_chat_status; };
	inline int    get_account_gift_spend() { return m_account_gift_spend; };
	inline int	  get_account_gift_month() { return m_account_gift_month; };
	inline int    get_account_create_time() { return m_account_create_time; };

	inline int    get_IsOldRole() { return m_bIsOldRole; };

public:
	void   SetIsUpdata(bool bIsUpdata) { m_bIsUpdata = bIsUpdata; };
	bool   GetIsUpdata() { return m_bIsUpdata; };

	void   SetIsUpdataRoleInfo(bool bIsUpdataRoleInfo) { m_bIsUpdataRoleInfo = bIsUpdataRoleInfo; };
	bool   GetIsUpdataRoleInfo() { return m_bIsUpdataRoleInfo; };

public:
	void   UpdataRoleInfo(bool bIsOldRole);

	void   SetRoleProperty(int account_id,
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
		int account_create_time);
private:

	int m_account_id;
	string m_account_name;
	string m_account_password;
	int m_account_platform_id;
	string m_account_third_id;
	string m_account_third_account;
	int  m_account_sex;
	int  m_account_status;
	string m_account_status_reason;
	int m_account_last_login_time;
	int m_account_login_times;

	int m_account_ban_time;
	int m_account_exp;
	int m_account_level;

	int m_account_unbind_chip;
	int m_account_unbind_pink;
	int m_account_bind_chip;
	int m_account_bind_pink;
	int m_account_max_pink;
	int m_account_max_chip;
	int m_account_highest_chip;
	int m_account_vip_type;
	int m_account_vip_level;
	int m_account_vip_points;
	int m_account_win_times;
	int m_account_lost_times;
	int m_account_draw_times;

	string m_account_max_cardtype;
	int m_account_chat_status;

	int m_account_gift_spend;
	int m_account_gift_month;
	int m_account_create_time;

	bool m_bIsOldRole;

private:
	bool                 m_bIsUpdata;
	bool                 m_bIsUpdataRoleInfo;
};
#endif//__DB_ROLE_H__