#pragma once
#ifndef __DB_TEXAS_BOARD_H__
#define __DB_TEXAS_BOARD_H__

#include "../../FrameWork/BaseDefine.h"

class CDBTexasBoardInfo
{
public:
	CDBTexasBoardInfo();
	virtual ~CDBTexasBoardInfo();
	EQ_DECLARE_CACHE(CDBTexasBoardInfo)

public:

	inline void			set_board_id(int board_id) { m_board_id = board_id; };
	inline void			set_board_girl_id(int board_girl_id) { m_board_girl_id = board_girl_id; };
	inline void			set_board_card(string board_card) { m_board_card = board_card; };
	inline void			set_board_showcard(string board_showcard) { m_board_showcard = board_showcard; };
	inline void			set_board_server_id(int board_server_id) { m_board_server_id = board_server_id; };
	inline void			set_board_game_id(int board_game_id) { m_board_game_id = board_game_id; };
	inline void			set_board_room_id(int board_room_id) { m_board_room_id = board_room_id; };
	inline void			set_board_sum_chip(int board_sum_chip) { m_board_sum_chip = board_sum_chip; };
	inline void			set_board_rewardjackpot_type(int board_rewardjackpot_type) { m_board_rewardjackpot_type = board_rewardjackpot_type; };
	inline void			set_board_rewardbonus_type(int board_rewardbonus_type) { m_board_rewardbonus_type = board_rewardbonus_type; };
	inline void			set_board_card_type(int board_card_type) { m_board_card_type = board_card_type; };
	inline void			set_board_dealcard_type(int board_dealcard_type) { m_board_dealcard_type = board_dealcard_type; };
	inline void			set_board_result(int board_result) { m_board_result = board_result; };
	inline void			set_board_end_status(int board_end_status) { m_board_end_status = board_end_status; };
	inline void			set_board_start_time(int board_start_time) { m_board_start_time = board_start_time; };
	inline void			set_board_end_time(int board_end_time) { m_board_end_time = board_end_time; };

public:

	inline int			get_board_id() { return m_board_id; };
	inline int			get_board_girl_id() { return m_board_girl_id; };
	inline string		get_board_card() { return m_board_card; };
	inline string		get_board_showcard() { return m_board_showcard; };
	inline int			get_board_server_id() { return m_board_server_id; };
	inline int			get_board_game_id() { return m_board_game_id; };
	inline int			get_board_room_id() { return m_board_room_id; };
	inline int			get_board_sum_chip() { return m_board_sum_chip; };
	inline int			get_board_rewardjackpot_type() { return m_board_rewardjackpot_type; };
	inline int			get_board_rewardbonus_type() { return m_board_rewardbonus_type; };
	inline int			get_board_card_type() { return m_board_card_type; };
	inline int			get_board_dealcard_type() { return m_board_dealcard_type; };
	inline int			get_board_result() { return m_board_result; };
	inline int			get_board_end_status() { return m_board_end_status; };
	inline int			get_board_start_time() { return m_board_start_time; };
	inline int			get_board_end_time() { return m_board_end_time; };

public:
	void				SetTexasBoardProperty(
		int board_id,
		int	board_girl_id,
		string board_card,
		string board_showcard,
		int	board_server_id,
		int	board_game_id,
		int	board_room_id,
		int	board_sum_chip,
		int	board_rewardjackpot_type,
		int	board_rewardbonus_type,
		int	board_card_type,
		int	board_dealcard_type,
		int	board_result,
		int	board_end_status,
		int	board_start_time,
		int	board_end_time);

private:
	int m_board_id;
	int	m_board_girl_id;
	string m_board_card;
	string m_board_showcard;
	int	m_board_server_id;
	int	m_board_game_id;
	int	m_board_room_id;
	int	m_board_sum_chip;
	int	m_board_rewardjackpot_type;
	int	m_board_rewardbonus_type;
	int	m_board_card_type;
	int	m_board_dealcard_type;
	int	m_board_result;
	int	m_board_end_status;
	int	m_board_start_time;
	int	m_board_end_time;
};

#endif//__DB_TEXAS_BOARD_H__