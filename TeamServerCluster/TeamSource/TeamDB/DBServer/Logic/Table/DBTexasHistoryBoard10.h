#pragma once
#ifndef __DB_TEXAS_HISTORY_BOARD10_H__
#define __DB_TEXAS_HISTORY_BOARD10_H__

#include "../../FrameWork/BaseDefine.h"

class CDBTexasHistoryBoard10Info
{
public:
	CDBTexasHistoryBoard10Info();
	virtual ~CDBTexasHistoryBoard10Info();
	EQ_DECLARE_CACHE(CDBTexasHistoryBoard10Info)

public:

	inline void			set_board10_game_id(int board10_game_id) { m_board10_game_id = board10_game_id; };
	inline void			set_board10_room_id(int board10_room_id) { m_board10_room_id = board10_room_id; };
	inline void			set_board10_server_id(int board10_server_id) { m_board10_server_id = board10_server_id; };
	inline void			set_board10_result_detail(string board10_result_detail) { m_board10_result_detail = board10_result_detail; };
	inline void			set_board10_board_count(int board10_board_count) { m_board10_board_count = board10_board_count; };
public:

	inline int			get_board10_game_id() { return m_board10_game_id; };
	inline int			get_board10_room_id() { return m_board10_room_id; };
	inline int			get_board10_server_id() { return m_board10_server_id; };
	inline string		get_board10_result_detail() { return m_board10_result_detail; };
	inline int			get_board10_board_count() { return m_board10_board_count; };

public:
	void   SetIsUpdata(bool bIsUpdata) { m_bIsUpdata = bIsUpdata; };
	bool   GetIsUpdata() { return m_bIsUpdata; };

public:
	void				setDBTexasHistoryBoard10InfoProperty(
		int		board10_game_id,
		int		board10_room_id,
		int		board10_server_id,
		string	board10_result_detail,
		int		board10_board_count);

private:
	int			m_board10_game_id;
	int			m_board10_room_id;
	int			m_board10_server_id;
	string		m_board10_result_detail;
	int			m_board10_board_count;
private:
	bool		m_bIsUpdata;
};

#endif//__DB_TEXAS_HISTORY_BOARD10_H__