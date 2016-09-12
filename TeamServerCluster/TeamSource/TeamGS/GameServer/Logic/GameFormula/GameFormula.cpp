#include "GameFormula.h"

#include "../../Logic/Common/GameEnum.h"
CGameFormula::CGameFormula()
{
}

CGameFormula::~CGameFormula()
{
}

int CGameFormula::GetGameResult_TotalAmount(int nGameResultType, int nMoney, int nReward, int nBet, int nBetTea)
{
	int nTotalAmount = 0;
	switch (nGameResultType)
	{
	case EGRT_WIN:
	{
		nTotalAmount = (nMoney + nReward - nBet - nBetTea);
	}
	break;
	case EGRT_LOSE:
	{
		nTotalAmount = (nMoney*(-1) + nReward - nBet);
	}
	break;
	case EGRT_FOLD:
	{
		nTotalAmount = (nMoney*(-1) + nReward - nBet);
	}
	break;
	case EGRT_TIE:
	{
		nTotalAmount = (nReward - nBet);
	}
	break;
	}
	return nTotalAmount;
}

int CGameFormula::GetGameReward_JackpotAndBonus_Reward(int nJackpotReward, int nBonusRewrd)
{
	return (nJackpotReward + nBonusRewrd);
}

int CGameFormula::GetGameBet_JackpotAndBonus_Bet(int nJackpotBet, int nBonusBet)
{
	return (nJackpotBet + nBonusBet);
}

int CGameFormula::GetGameResult_TotalBindChips(int nBet_Ante_Bind, int nBet_Flop_Bind, int nBet_Turn_Bind, int nBetRiver_Bind)
{
	return (nBet_Ante_Bind + nBet_Flop_Bind + nBet_Turn_Bind + nBetRiver_Bind);
}

int CGameFormula::GetGameResult_TotalUnBindChips(int nBet_Ante_Unbind, int nBet_Flop_Unbind, int nBet_Turn_Unbind, int nBetRiver_Unbind)
{
	return (nBet_Ante_Unbind + nBet_Flop_Unbind + nBet_Turn_Unbind + nBetRiver_Unbind);
}