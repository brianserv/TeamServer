#include "TexasRole.h"

#include "../../../../Logic/Card/Card.h"

#include "../../../../Logic/Resource/JsonTable/TableLimit/Tablelimit.h"
#include "../../../../Logic/Resource/JsonTable/TableBetTea/TableBetTea.h"
#include "../../../../Logic/Resource/JsonTable/TableBroadcast/TableBroadcast.h"

void CTexasRole::Process_Reward_Bonus(int nReward_Bonus)
{
	if (nReward_Bonus <= 0 || m_nBet_Bonus <= 0)
	{
		return;
	}

	if (!IsFoldCheck())
	{
		return;
	}

	SetBonus_RewardMultiples(nReward_Bonus);

	int nBonus_RewardValue = 0;
	nBonus_RewardValue = GetBonus_RewardMultiples()*GetBet_Bonus();

	m_pRole->AddBindChips(GetBet_Bonus_Bind());
	m_pRole->AddUnBindChips(nBonus_RewardValue - GetBet_Bonus_Bind());

	SetBonus_RewardValue(nBonus_RewardValue);
}

void CTexasRole::Process_Reward_Jackpot(int nReward_Jackpot)
{
	if (nReward_Jackpot <= 0 || m_nBet_Jackpot <= 0)
	{
		return;
	}

	if (!IsFoldCheck())
	{
		return;
	}

	SetJackpot_RewardMultiples(nReward_Jackpot);

	int nJackpot_RewardValue = 0;
	nJackpot_RewardValue = GetJackpot_RewardMultiples()*GetBet_Jackpot();

	m_pRole->AddBindChips(GetBet_Jackpot_Bind());
	m_pRole->AddUnBindChips(nJackpot_RewardValue - GetBet_Jackpot_Bind());

	SetJackpot_RewardValue(nJackpot_RewardValue);
}

void CTexasRole::Process_GameResults(int nGameWinType, int nRoleCardKindType)
{
	if (Check_FoldCard())
	{
		Process_GameResults_FoldCard();
	}
	else
	{
		switch (nGameWinType)
		{
		case (int)EGWT_TIE:
			Process_GameResults_TieWin();
			break;
		case (int)EGWT_ROLE:
			Process_GameResults_RoleWin(nRoleCardKindType);
			break;
		case (int)EGWT_GIRL:
			Process_GameResults_GirlWin();
			break;
		}
	}
	Process_GameResults_TotalAmount(nGameWinType);

	Proxess_GameResults_Detail();
}

void CTexasRole::Process_GameResults_TotalAmount(int nGameWinType)
{
	int nJackpotAndBonus_Bet = 0;
	int nJackpotAndBonus_Reward = 0;
	int nFormulaTotalAmount = 0;

	nJackpotAndBonus_Bet = g_GameFormula.GetGameBet_JackpotAndBonus_Bet(GetBet_Jackpot(), GetBet_Bonus());
	nJackpotAndBonus_Reward = g_GameFormula.GetGameReward_JackpotAndBonus_Reward(GetJackpot_RewardValue(), GetBonus_RewardValue());
	nFormulaTotalAmount = g_GameFormula.GetGameResult_TotalAmount(nGameWinType, GetWinChips(),
		nJackpotAndBonus_Reward, nJackpotAndBonus_Bet, GetTotalBetTea());
	SetFormulaTotalAmount(nFormulaTotalAmount);
}

void CTexasRole::Proxess_GameResults_Detail()
{
	if (!CheckRole())
		return;

	string strSplit(",");
	string strSplitEx("|");

	{
		m_strBeforeChipDetail += PARSE_STRINGS::toString(m_nBetBeforeChips_Unbind);
		m_strBeforeChipDetail += strSplit;
		m_strBeforeChipDetail += PARSE_STRINGS::toString(m_nBetBeforeChips_Bind);
		m_strBeforeChipDetail += strSplit;
		m_strBeforeChipDetail += PARSE_STRINGS::toString(m_nBetBeforeChips_Total);
	}

	{
		m_strJackpotDetail += PARSE_STRINGS::toString(m_nBet_Jackpot_Unbind);
		m_strJackpotDetail += strSplit;
		m_strJackpotDetail += PARSE_STRINGS::toString(m_nBet_Jackpot_Bind);
	}

	{
		m_strBonusDetail += PARSE_STRINGS::toString(m_nBet_Bonus_Unbind);
		m_strBonusDetail += strSplit;
		m_strBonusDetail += PARSE_STRINGS::toString(m_nBet_Bonus_Bind);
	}

	{
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Ante_Unbind);
		m_strSumChipDetail += strSplit;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Ante_Bind);

		m_strSumChipDetail += strSplitEx;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Flop_Unbind);
		m_strSumChipDetail += strSplit;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Flop_Bind);

		m_strSumChipDetail += strSplitEx;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Turn_Unbind);
		m_strSumChipDetail += strSplit;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_Turn_Bind);

		m_strSumChipDetail += strSplitEx;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_River_Unbind);
		m_strSumChipDetail += strSplit;
		m_strSumChipDetail += PARSE_STRINGS::toString(m_nBet_River_Bind);
	}

	{
		for (size_t i = 0; i < MAX_TEXAS_BETROUND_NUM; i++)
		{
			m_strChipDetail += PARSE_STRINGS::toString(m_nRoundBet_Chips[i]);
			m_strChipDetail += strSplit;
		}
	}

	{
		m_strWinChipDetail += PARSE_STRINGS::toString(m_nWinChips_Unbind);
		m_strWinChipDetail += strSplit;
		m_strWinChipDetail += PARSE_STRINGS::toString(m_nWinChips_Bind);
	}

	{
		m_strAfterChipDetail += PARSE_STRINGS::toString(m_pRole->GetUnBindChips());
		m_strAfterChipDetail += strSplit;
		m_strAfterChipDetail += PARSE_STRINGS::toString(m_pRole->GetBindChips());
		m_strAfterChipDetail += strSplit;
		m_strAfterChipDetail += PARSE_STRINGS::toString(m_pRole->GetTotalChips());
	}
}

void CTexasRole::Process_GameResults_FoldCard()
{
	// VIP情况特殊处理后续补充
	SetWinChips((-1)*GetTotalBetChips());

	SetWinChips_Bind((-1)*GetBet_Ante_Bind());
	SetWinChips_Unbind((-1)*GetBet_Ante_Unbind());
}

void CTexasRole::Process_GameResults_TieWin()
{
	// 根据等级增加经验后续补充

	// AddExp(Level);

	// 金钱筹码
	m_pRole->AddUnBindChips(GetTotalBetChips());

	//累计输赢
	SetTotalLostWinChips(GetTotalBetChips());

	SetWinChips(0);
	SetWinChips_Bind(0);
	SetWinChips_Unbind(0);

	m_pRole->AddDrawTimes();
}

void CTexasRole::Process_GameResults_RoleWin(int nRoleCardKindType)
{
	// AddExp(Level);

	int nWinChips = 0;
	nWinChips = (2 * GetTotalBetChips());

	if (nRoleCardKindType < (int)ECK_Straight)
	{
		nWinChips -= GetBet_Ante();
	}

	int nTotalBindChips_add = 0;
	nTotalBindChips_add = g_GameFormula.GetGameResult_TotalBindChips(GetBet_Ante_Bind(), GetBet_Flop_Bind(),
		GetBet_Turn_Bind(), GetBet_River_Bind());

	int nTotalUnBindChips_add = 0;
	nTotalUnBindChips_add = nWinChips - nTotalBindChips_add;

	// 金钱筹码
	m_pRole->AddBindChips(nTotalBindChips_add);
	m_pRole->AddUnBindChips(nTotalUnBindChips_add);

	if (CTableBetTeaManager::Instance().CheckBetTeaSwitch(BET_TEA_ID))
	{
		int nBetTea = 0;
		nBetTea = CTableBetTeaManager::Instance().GetBetTea_WinChips(BET_TEA_ID, nWinChips);

		AddTotalBetTea(nBetTea);

		//扣金钱筹码(规则：先扣非绑，非绑不足再扣绑定)
		int nUnBindChip_dec = 0;
		int nBindChip_dec = 0;
		m_pRole->DecChipByCostRulers(nBetTea, nUnBindChip_dec, nBindChip_dec);
	}
	nWinChips -= GetTotalBetChips();

	SetWinChips(nWinChips);

	SetWinChips_Bind(0);
	SetWinChips_Unbind(nWinChips);

	//累计输赢
	SetTotalLostWinChips(nWinChips);

	m_pRole->UpdateMaxChip(nWinChips);

	m_pRole->AddWinTimes();

	//VIP 后期系统设计完善 情况另行考虑
}

void CTexasRole::Process_GameResults_GirlWin()
{
	int nTotalBindChips_add = 0;
	nTotalBindChips_add = g_GameFormula.GetGameResult_TotalBindChips(GetBet_Ante_Bind(), GetBet_Flop_Bind(),
		GetBet_Turn_Bind(), GetBet_River_Bind());

	int nTotalUnBindChips_add = 0;
	nTotalUnBindChips_add = g_GameFormula.GetGameResult_TotalUnBindChips(GetBet_Ante_Unbind(), GetBet_Flop_Unbind(),
		GetBet_Turn_Unbind(), GetBet_River_Unbind());

	// 金钱筹码
	m_pRole->AddBindChips((-1)*nTotalBindChips_add);
	m_pRole->AddUnBindChips((-1)*nTotalUnBindChips_add);

	SetWinChips((-1)*GetTotalBetChips());

	m_pRole->AddLostTimes();

	//VIP 后期系统设计完善 情况另行考虑
}

void CTexasRole::Process_SetBetBefore()
{
	SetBetBeforeChips_Unbind(m_pRole->GetUnBindChips());
	SetBetBeforeChips_Bind(m_pRole->GetBindChips());
	SetBetBeforeChips_Total(m_pRole->GetTotalChips());
}

void CTexasRole::Process_SetBet_Ante(BetReq& refBetReq)
{
	if (CTableBetTeaManager::Instance().CheckBetTeaSwitch(BET_TEA_ID))
	{
		int nBetTea = 0;
		nBetTea = CTableBetTeaManager::Instance().GetBetTeaMoney(BET_TEA_ID);
		if (nBetTea > 0)
		{
			int nUnbindChip_BetTea_dec = 0;
			int nBindChip_BetTea_dec = 0;

			SetTotalBetTea(nBetTea);
			m_pRole->DecChipByCostRulers(GetTotalBetTea(), nUnbindChip_BetTea_dec, nBindChip_BetTea_dec);
		}
	}

	SetBet_Ante(refBetReq.nBetChips);
	SetTotalBetChips(refBetReq.nBetChips);
	SetTotalLostWinChips((-1)*refBetReq.nBetChips);

	SetRoundBet_Chips((int)ERT_Ante, refBetReq.nBetChips);

	int nUnbindChip = 0;
	int nBindChip = 0;
	m_pRole->DecChipByCostRulers(GetBet_Ante(), nUnbindChip, nBindChip);

	SetBet_Ante_Unbind(nUnbindChip);
	SetBet_Ante_Bind(nBindChip);

	SetRoundBet_Mark(ERT_Ante);
	SetIsSetBetResult(true);

	SetRoleStatus((int)ERS_Game);
}

void CTexasRole::Process_SetBet_Flop(BetReq& refBetReq)
{
	SetBet_Flop((2 * GetBet_Ante()));
	SetTotalBetChips(GetBet_Flop());
	SetTotalLostWinChips((-1)*GetBet_Flop());

	SetRoundBet_Chips((int)ERT_Flop, GetBet_Flop());

	int nUnbindChip = 0;
	int nBindChip = 0;
	m_pRole->DecChipByCostRulers(GetBet_Flop(), nUnbindChip, nBindChip);

	SetBet_Flop_Unbind(nUnbindChip);
	SetBet_Flop_Bind(nBindChip);

	SetRoundBet_Mark(ERT_Flop);
	SetIsSetBetResult(true);

	SetRoleStatus((int)ERS_Game);
}

void CTexasRole::Process_SetBet_Turn(BetReq& refBetReq)
{
	if (Check_FoldCard())
	{
		SetIsSetBetResult(false);
		return;
	}
	switch (refBetReq.nBetType)
	{
	case (int)EBetType_Call:
	{
		SetBet_Turn(GetBet_Ante());
		SetTotalBetChips(GetBet_Turn());
		SetTotalLostWinChips((-1)*GetBet_Turn());

		SetRoundBet_Chips((int)ERT_Turn, GetBet_Turn());

		int nUnbindChip = 0;
		int nBindChip = 0;
		m_pRole->DecChipByCostRulers(GetBet_Turn(), nUnbindChip, nBindChip);

		SetBet_Turn_Unbind(nUnbindChip);
		SetBet_Turn_Bind(nBindChip);

		SetRoundBet_Mark(ERT_Turn);
		SetIsSetBetResult(true);
	}
	break;
	case (int)EBetType_Check:
	{
		SetIsSetBetResult(false);
	}
	break;
	}

	SetRoleStatus((int)ERS_Game);
}
void CTexasRole::Process_SetBet_River(BetReq& refBetReq)
{
	if (Check_FoldCard())
	{
		SetIsSetBetResult(false);
		return;
	}
	switch (refBetReq.nBetType)
	{
	case (int)EBetType_Call:
	{
		SetBet_River(GetBet_Ante());
		SetTotalBetChips(GetBet_River());
		SetTotalLostWinChips((-1)*GetBet_River());

		SetRoundBet_Chips((int)ERT_River, GetBet_River());

		int nUnbindChip = 0;
		int nBindChip = 0;
		m_pRole->DecChipByCostRulers(GetBet_River(), nUnbindChip, nBindChip);

		SetBet_River_Unbind(nUnbindChip);
		SetBet_River_Bind(nBindChip);

		SetRoundBet_Mark(ERT_River);
		SetIsSetBetResult(true);
	}
	break;
	case (int)EBetType_Check:
	{
		SetIsSetBetResult(false);
	}
	break;
	}
	SetRoleStatus((int)ERS_Game);
}

void CTexasRole::Process_SetBet_Ante_Bonus(BetReq& refBetReq)
{
	if (refBetReq.mBetBonusType == 1)
	{
		SetBet_Bonus((GetBet_Ante() / 2));

		int nUnbindChip = 0;
		int nBindChip = 0;
		m_pRole->DecChipByCostRulers(GetBet_Bonus(), nUnbindChip, nBindChip);

		SetBet_Bonus_UnBind(nUnbindChip);
		SetBet_Bonus_Bind(nBindChip);
	}
}

void CTexasRole::Process_SetBet_Ante_JackPot(BetReq& refBetReq)
{
	if (refBetReq.nBetJackpotType == 1)
	{
		SetBet_Jackpot((GetBet_Ante() / 2));

		int nUnbindChip = 0;
		int nBindChip = 0;
		m_pRole->DecChipByCostRulers(GetBet_Jackpot(), nUnbindChip, nBindChip);

		SetBet_Jackpot_UnBind(nUnbindChip);
		SetBet_Jackpot_Bind(nBindChip);
	}
}

void CTexasRole::Process_SetBet(int m_nRoomType, int nGameRounds, int &nMaxBetCount, BetReq& refBetReq)
{
	if (!Process_Bet_RepeatBetCheck(nGameRounds))
		return;

	if (!CheckRole())
		return;

	if (!Process_BetShort(refBetReq.nBetChips))
		return;

	if (!Process_Bet_AnteInterface(m_nRoomType, nMaxBetCount, refBetReq))
		return;

	switch (nGameRounds)
	{
	case (int)ERT_Flop:
		Process_SetBet_Flop(refBetReq);
		break;
	case (int)ERT_Turn:
		Process_SetBet_Turn(refBetReq);
		break;
	case (int)ERT_River:
		Process_SetBet_River(refBetReq);
		break;
	}
}

bool CTexasRole::Process_Bet_Ante(BetReq& refBetReq)
{
	if (IsSetAnteCard())
	{
		return true;
	}

	if (!Process_Bet_Ante_Limit(refBetReq.nBetChips))
	{
		return true;
	}

	Process_SetBetBefore();
	Process_SetBet_Ante(refBetReq);

	Process_SetBet_Ante_Bonus(refBetReq);
	Process_SetBet_Ante_JackPot(refBetReq);

	SetIsSetAnteCard(true);
	return false;
}

bool  CTexasRole::Process_VipRoom_Bet_Ante(BetReq& refBetReq)
{
	if (IsSetAnteCard())
	{
		return true;
	}

	Process_SetBetBefore();
	Process_SetBet_Ante(refBetReq);

	SetIsSetAnteCard(true);

	return false;
}

bool CTexasRole::Process_Bet_AnteInterface(int m_nRoomType, int &nMaxBetCount, BetReq& refBetReq)
{
	if (m_nRoomType == ERoomType_Vip)
	{
		if (!Process_VipRoom_Bet_Ante(refBetReq))
		{
			Process_Bet_Ante_Broadcast(nMaxBetCount, refBetReq.nBetChips);
			return false;
		}
	}
	else
	{
		if (!Process_Bet_Ante(refBetReq))
		{
			Process_Bet_Ante_Broadcast(nMaxBetCount, refBetReq.nBetChips);
			return false;
		}
	}
	return true;
}

bool CTexasRole::Process_BetShort(int nChips)
{
	// Bet Chips
	if (m_pRole->GetTotalChips() < nChips)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Bet Chips Short!");

		ProcessMsg_ErrorSync((int)ECERT_CHIPS_CHIPSSHORT_ERROR);

		SetIsSetBetResult(false);

		return false;
	}
	return true;
}

bool  CTexasRole::Process_Bet_Ante_Limit(int nChips)
{
	//Bet Limit
	if ((nChips < CTableLimitManager::Instance().GetMinAnte(m_nRoomId)) ||
		(nChips > CTableLimitManager::Instance().GetMaxAnte(m_nRoomId)))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Bet Chips Not In Room Limit Range!");

		ProcessMsg_ErrorSync((int)ECERT_CHIPS_CHIPSSHORT_ERROR);

		SetIsSetBetResult(false);

		return false;
	}
	return true;
}

bool CTexasRole::Process_Bet_Ante_Broadcast(int &nMaxBetCount, int nChips)
{
	//Bet BroadCast Check
	if (nChips >= CTableBroadcastManager::Instance().GetCostValue((int)EBCT_Bet))
	{
		nMaxBetCount++;
		BetBroadcastSync refBetBroadcastSync;
		ProcessMsg_BetBroadcastSync(refBetBroadcastSync);
		return false;
	}
	return true;
}

bool  CTexasRole::Process_Bet_RepeatBetCheck(int nGameRounds)
{
	if (nGameRounds > 0 && m_bRoundBetMark[nGameRounds])
	{
		SetIsSetBetResult(false);
		return false;
	}
	return true;
}

void  CTexasRole::Process_GameCancel()
{
	int nBindChips = m_nBet_Jackpot_Bind + m_nBet_Bonus_Bind +
		m_nBet_Ante_Bind + m_nBet_Flop_Bind +
		m_nBet_Turn_Bind + m_nBet_River_Bind;

	m_pRole->AddBindChips(nBindChips);

	int nUnbindChips = m_nBet_Jackpot_Unbind + m_nBet_Bonus_Unbind +
		m_nBet_Ante_Unbind + m_nBet_Flop_Unbind +
		m_nBet_Turn_Unbind + m_nBet_River_Unbind;

	m_pRole->AddUnBindChips(nUnbindChips);
}