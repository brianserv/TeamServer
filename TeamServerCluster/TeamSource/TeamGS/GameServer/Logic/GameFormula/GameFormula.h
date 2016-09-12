#pragma  once
#ifndef __GAME_FORMULA_H__
#define __GAME_FORMULA_H__

#include "EQ_Singleton.h"
class CGameFormula : public CEQ_SingletonT<CGameFormula>
{
public:
	CGameFormula();
	virtual ~CGameFormula();
public:
	int GetGameResult_TotalAmount(int nGameResultType, int nMoney, int nReward, int nBet, int nBetTea);

	int GetGameReward_JackpotAndBonus_Reward(int nJackpotReward, int nBonusRewrd);
	int GetGameBet_JackpotAndBonus_Bet(int nJackpotBet, int nBonusBet);
public:
	int GetGameResult_TotalBindChips(int nBet_Ante_Bind, int nBet_Flop_Bind, int nBet_Turn_Bind, int nBetRiver_Bind);
	int GetGameResult_TotalUnBindChips(int nBet_Ante_UnBind, int nBet_Flop_UnBind, int nBet_Turn_UnBind, int nBetRiver_UnBind);
};
#endif//__GAME_FORMULA_H__
