#include "DLManager.h"

#include "../Table/DLBet.h"

bool CDLManager::SaveBetData(void *pDLBetInfo)
{
	CDLBet* pDLBet = (CDLBet*)pDLBetInfo;
	if (NULL == pDLBet)
	{
		return false;
	}

	char szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call sp_save_bet(%d,%d,%d,%d,%d,%d,%d,%d,'%s','%s',%d,%d,'%s','%s',%d,%d,%d,%d,%d,'%s','%s','%s',%d);",
		pDLBet->get_account_id(),
		pDLBet->get_bet_board_id(),
		pDLBet->get_bet_game_type(),
		pDLBet->get_bet_game_id(),
		pDLBet->get_bet_room_id(),
		pDLBet->get_bet_girl_id(),
		pDLBet->get_bet_jackpot(),
		pDLBet->get_bet_bonus(),
		pDLBet->get_bet_jackpot_deatil().c_str(),
		pDLBet->get_bet_bonus_detail().c_str(),
		pDLBet->get_bet_ante(),
		pDLBet->get_bet_flop(),
		pDLBet->get_bet_sum_chip_detail().c_str(),
		pDLBet->get_bet_chip_detail().c_str(),
		pDLBet->get_bet_win_chip(),
		pDLBet->get_bet_reward_bonus(),
		pDLBet->get_bet_reward_jackpot(),
		pDLBet->get_bet_tea(),
		pDLBet->get_bet_server_id(),
		pDLBet->get_bet_win_chip_detail().c_str(),
		pDLBet->get_bet_before_chip_detail().c_str(),
		pDLBet->get_bet_after_chip_detail().c_str(),
		pDLBet->get_bet_total_amount());

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}