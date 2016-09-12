#ifndef __DL_BET_H__
#define __DL_BET_H__

#include "../../FrameWork/BaseDefine.h"

class CDLBet
{
public:
	CDLBet();
	virtual ~CDLBet();
	EQ_DECLARE_CACHE(CDLBet)

public:
	inline void  set_account_id(int account_id) { m_account_id = account_id; };
	inline void  set_bet_board_id(int bet_board_id) { m_bet_board_id = bet_board_id; };
	inline void  set_bet_game_type(int bet_game_type) { m_bet_game_type = bet_game_type; };
	inline void  set_bet_game_id(int bet_game_id) { m_bet_game_id = bet_game_id; };
	inline void  set_bet_room_id(int bet_room_id) { m_bet_room_id = bet_room_id; };
	inline void  set_bet_girl_id(int bet_girl_id) { m_bet_girl_id = bet_girl_id; };
	inline void  set_bet_jackpot(int bet_jackpot) { m_bet_jackpot = bet_jackpot; };
	inline void  set_bet_bonus(int bet_bonus) { m_bet_bonus = bet_bonus; };
	inline void  set_bet_jackpot_deatil(string bet_jackpot_deatil) { m_bet_jackpot_deatil = bet_jackpot_deatil; };
	inline void  set_bet_bonus_detail(string bet_bonus_detail) { m_bet_bonus_detail = bet_bonus_detail; };
	inline void  set_bet_ante(int bet_ante) { m_bet_ante = bet_ante; };
	inline void  set_bet_flop(int bet_flop) { m_bet_flop = bet_flop; };
	inline void  set_bet_sum_chip_detail(string bet_sum_chip_detail) { m_bet_sum_chip_detail = bet_sum_chip_detail; };
	inline void  set_bet_chip_detail(string bet_chip_detail) { m_bet_chip_detail = bet_chip_detail; };
	inline void  set_bet_win_chip(int bet_win_chip) { m_bet_win_chip = bet_win_chip; };
	inline void  set_bet_reward_bonus(int bet_reward_bonus) { m_bet_reward_bonus = bet_reward_bonus; };
	inline void  set_bet_reward_jackpot(int bet_reward_jackpot) { m_bet_reward_jackpot = bet_reward_jackpot; };
	inline void  set_bet_tea(int bet_tea) { m_bet_tea = bet_tea; };
	inline void  set_bet_server_id(int bet_server_id) { m_bet_server_id = bet_server_id; };
	inline void  set_bet_win_chip_detail(string bet_win_chip_detail) { m_bet_win_chip_detail = bet_win_chip_detail; };
	inline void  set_bet_before_chip_detail(string bet_before_chip_detail) { m_bet_before_chip_detail = bet_before_chip_detail; };
	inline void  set_bet_after_chip_detail(string bet_after_chip_detail) { m_bet_after_Chip_detail = bet_after_chip_detail; };
	inline void  set_bet_total_amount(int bet_total_amount) { m_bet_total_amount = bet_total_amount; };

public:
	inline int  get_account_id() { return m_account_id; };
	inline int  get_bet_board_id() { return m_bet_board_id; };
	inline int  get_bet_game_type() { return m_bet_game_type; };
	inline int  get_bet_game_id() { return m_bet_game_id; };
	inline int  get_bet_room_id() { return m_bet_room_id; };
	inline int  get_bet_girl_id() { return m_bet_girl_id; };
	inline int  get_bet_jackpot() { return m_bet_jackpot; };
	inline int  get_bet_bonus() { return m_bet_bonus; };
	inline string  get_bet_jackpot_deatil() { return m_bet_jackpot_deatil; };
	inline string  get_bet_bonus_detail() { return m_bet_bonus_detail; };
	inline int  get_bet_ante() { return m_bet_ante; };
	inline int  get_bet_flop() { return m_bet_flop; };
	inline string  get_bet_sum_chip_detail() { return m_bet_sum_chip_detail; };
	inline string  get_bet_chip_detail() { return m_bet_chip_detail; };
	inline int  get_bet_win_chip() { return m_bet_win_chip; };
	inline int  get_bet_reward_bonus() { return m_bet_reward_bonus; };
	inline int  get_bet_reward_jackpot() { return m_bet_reward_jackpot; };
	inline int  get_bet_tea() { return m_bet_tea; };
	inline int  get_bet_server_id() { return m_bet_server_id; };
	inline string  get_bet_win_chip_detail() { return m_bet_win_chip_detail; };
	inline string  get_bet_before_chip_detail() { return m_bet_before_chip_detail; };
	inline string  get_bet_after_chip_detail() { return m_bet_after_Chip_detail; };
	inline int  get_bet_total_amount() { return m_bet_total_amount; };

public:
	void SetBetProperty(
		int account_id,
		int bet_board_id,
		int bet_game_type,
		int bet_game_id,
		int bet_room_id,
		int bet_girl_id,
		int bet_jackpot,
		int bet_bonus,
		string bet_jackpot_deatil,
		string bet_bonus_detail,
		int bet_ante,
		int bet_flop,
		string bet_sum_chip_detail,
		string bet_chip_detail,
		int bet_win_chip,
		int bet_reward_bonus,
		int bet_reward_jackpot,
		int bet_tea,
		int bet_server_id,
		string bet_win_chip_detail,
		string bet_before_chip,
		string bet_after_chip,
		int bet_total_amount);

private:
	int m_account_id;
	int m_bet_board_id;
	int m_bet_game_type;
	int m_bet_game_id;
	int m_bet_room_id;
	int m_bet_girl_id;
	int m_bet_jackpot;
	int m_bet_bonus;
	string m_bet_jackpot_deatil;
	string m_bet_bonus_detail;
	int m_bet_ante;
	int m_bet_flop;
	string m_bet_sum_chip_detail;
	string m_bet_chip_detail;
	int m_bet_win_chip;
	int m_bet_reward_bonus;
	int m_bet_reward_jackpot;
	int m_bet_tea;
	int m_bet_server_id;
	string m_bet_win_chip_detail;
	string m_bet_before_chip_detail;
	string m_bet_after_Chip_detail;
	int m_bet_total_amount;
};

#endif//__DL_BET_H__