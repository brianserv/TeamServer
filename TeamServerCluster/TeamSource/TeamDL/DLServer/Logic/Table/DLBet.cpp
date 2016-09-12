#include "DLBet.h"

EQ_IMPLEMENT_CACHE(CDLBet, 100)

CDLBet::CDLBet()
{
}

CDLBet::~CDLBet()
{
}

void CDLBet::SetBetProperty(
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
	int bet_total_amount)
{
	set_account_id(account_id);
	set_bet_board_id(bet_board_id);
	set_bet_game_type(bet_game_type);
	set_bet_game_id(bet_game_id);
	set_bet_room_id(bet_room_id);
	set_bet_girl_id(bet_girl_id);
	set_bet_jackpot(bet_jackpot);
	set_bet_bonus(bet_bonus);
	set_bet_jackpot_deatil(bet_jackpot_deatil);
	set_bet_bonus_detail(bet_bonus_detail);
	set_bet_ante(bet_ante);
	set_bet_flop(bet_flop);
	set_bet_sum_chip_detail(bet_sum_chip_detail);
	set_bet_chip_detail(bet_chip_detail);
	set_bet_win_chip(bet_win_chip);
	set_bet_reward_bonus(bet_reward_bonus);
	set_bet_reward_jackpot(bet_reward_jackpot);
	set_bet_tea(bet_tea);
	set_bet_server_id(bet_server_id);
	set_bet_win_chip_detail(bet_win_chip_detail);
	set_bet_before_chip_detail(bet_before_chip);
	set_bet_after_chip_detail(bet_after_chip);
	set_bet_total_amount(bet_total_amount);
}