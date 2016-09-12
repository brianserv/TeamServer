#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"
#include "../../../../Logic/Resource/JsonTable/TableLimit/Tablelimit.h"

void  CTexasGame::OnTimer()
{
	if (!CheckRole())
		return;

	OnGameStart();
	OnGameRound();
	OnGameEnded();
}

bool CTexasGame::OnGameStart()
{
	if (!CheckGirl())
	{
		if (!m_bManualModel)
		{
			OnGameStart_Auto();
		}
		return true;
	}
	return true;
}

bool CTexasGame::OnGameStart_Auto()
{
	if (!OnGameStart_Check())
	{
		return false;
	}
	ProcessMsg_StartGameSync();
	ProcessMsg_NoticeBetSync_GameStart();
	return true;
}

bool CTexasGame::OnGameStart_Manual()
{
	ProcessMsg_StartGameSync();
	ProcessMsg_NoticeBetSync_GameStart();
	return true;
}

bool CTexasGame::OnGameStart_Check()
{
	if (!CheckGameStatus_GameRun())
	{
		return false;
	}

	if (!CheckTimeRange_Minute(CEQ_Time::Instance().EQ_GetTime(), m_nStartTime))
	{
		return false;
	}

	SetStartTime();
	SetCountDown_TurnTime();
	SetGameStatus(EGS_GameRun);
	return true;
}

bool CTexasGame::OnGameEnded()
{
	if (!m_bManualModel)
	{
		OnGameEnded_Auto();
		return true;
	}
	OnGameEnded_Manual();
	return true;
}

bool CTexasGame::OnGameEnded_Auto()
{
	if (!OnGameEnded_Check())
	{
		return false;
	}
	OnGameRound_Showdown();
	OnGameRound_Reset();
	return true;
}

bool CTexasGame::OnGameEnded_Manual()
{
	if (!OnGameEnded_Check())
	{
		return false;
	}
	OnGameRound_Showdown();

	ProcessMsg_Dealer_GameEndSync();
	OnGameRound_Dealer_GameReStart();

	OnGameRound_Reset();
	return true;
}

bool  CTexasGame::OnGameEnded_Cancel()
{
	GirlStartGame();

	SetGameStatus(EGS_GameCancel);

	OnGameRound_GameCancel();
	ProcessMsg_GameCancelSync();

	OnGameRound_Reset();
	return true;
}

bool CTexasGame::OnGameEnded_Check()
{
	if ((int)ECNT_9 == m_nCardNum && (int)ERT_River == m_nGameRounds)
	{
		SetEndTime();
		return true;
	}
	return false;
}

void  CTexasGame::OnGameRound()
{
	if (!CheckGameRounds_FirstRound())
	{
		OnGameRound_FirstRound();
		return;
	}
	OnGameRound_ExtraRound();
	return;
}

void CTexasGame::OnGameRound_FirstRound()
{
	if (!CheckCountDown_TurnTime())
	{
		return;
	}
	m_nCoutDown_TurnTime = 0;

	if (!m_bManualModel)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"____________________________________________________________________");
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [>>>>[GameRoom:%d]->FirstRound GameRun:[TexasBoard:%d-Round:%d]<<<<]!",
			m_nRoomId, GetTexasBoardId() + 1, m_nGameRounds);

		AddTexasBoardId();
	}

	OnGameRound_RoundMode();
	return;
}

void CTexasGame::OnGameRound_ExtraRound()
{
	if (!CheckCountDown_TurnTime(CConfigFile::Instance().m_nMaxBetWaitTime))
	{
		return;
	}

	if (!m_bManualModel)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [>>>>[GameRoom:%d]->ExtraRound GameRun:[TexasBoard:%d-Round:%d]<<<<]!",
			m_nRoomId, GetTexasBoardId(), m_nGameRounds);
	}

	OnGameRound_RoundMode();
	return;
}

void  CTexasGame::OnGameRound_RoundMode()
{
	if (!m_bManualModel)
	{
		OnGameRound_Auto();
		return;
	}
	if (m_bDealerStart)
	{
		OnGameRound_Manual();
	}
}

void CTexasGame::OnGameRound_Auto()
{
	int nProduceCardNum = GetProduceCardNum();

	for (int index = 0; index < nProduceCardNum; index++)
	{
		OnGameRound_Deal((int)m_Card.RandomCard());
	}
	OnGameRound_NoticeBet();

	ProcessMsg_AutoFoldSync();
}

void CTexasGame::OnGameRound_Manual()
{
	OnGameRound_Dealer_GameRound();
}

void CTexasGame::SetHistoryWin()
{
	if (m_nHistoryWinVec.size() >= MAX_TEXAS_HISTORYBOARD_NUM)
	{
		m_nHistoryWinVec.erase(m_nHistoryWinVec.begin());
	}
	m_nHistoryWinVec.push_back(GetGameWinType());
}

void CTexasGame::SetHistoryWin(vector<int>& refHistoryWinVec)
{
	m_nHistoryWinVec.swap(refHistoryWinVec);
}

void CTexasGame::SetRoleCenterCard(BYTE sCard[])
{
	for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
	{
		m_nRoleCenterCard.push_back(sCard[index]);
	}
}

void CTexasGame::SetGirlCenterCard(BYTE sCard[])
{
	for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
	{
		m_nGirlCenterCard.push_back(sCard[index]);
	}
}

bool CTexasGame::CheckPrizePool_Additional()
{
	return (CPrizePoolManager::Instance().GetTotalValue() <= CPrizePoolManager::Instance().GetJackpotBonus_InitValue() / 4) ? true : false;
}

void CTexasGame::UpdatePrizePool_Add(int nVal)
{
	CPrizePoolManager::Instance().AddTotalValue(nVal);
	UpdatePrizePool_Additional();
}

void CTexasGame::UpdatePrizePool_Dec(int nVal)
{
	CPrizePoolManager::Instance().AddTotalValue((-1)*nVal);
	CPrizePoolManager::Instance().AddPayValue(nVal);
	UpdatePrizePool_Additional();
}

void CTexasGame::UpdatePrizePool_Additional()
{
	if (CheckPrizePool_Additional())
	{
		int nDiffPay = 0;
		nDiffPay = CPrizePoolManager::Instance().GetJackpotBonus_InitValue() - CPrizePoolManager::Instance().GetTotalValue();

		CPrizePoolManager::Instance().AddTotalValue(nDiffPay);
		CPrizePoolManager::Instance().AddPayValue(nDiffPay);
	}
}

void CTexasGame::UpdatePrizePool(int nVal, int nEOption)
{
	switch (nEOption)
	{
	case EUpdateOption_Add:
		UpdatePrizePool_Add(nVal);
		break;
	case EUpdateOption_Dec:
		UpdatePrizePool_Dec(nVal);
		break;
	default:
		break;
	}
}

void CTexasGame::UpdatePrizePool()
{
	UpdatePrizePool(GetTotal_Bet_Jackpot() + GetTotal_Bet_Bonus(), EUpdateOption_Add);
	UpdatePrizePool(GetTotal_Reward_Jackpot() + GetTotal_Reward_Bonus(), EUpdateOption_Dec);

	UpdatePrizePool_DB();
}

void CTexasGame::UpdateGameChips()
{
	switch (m_nGameWinType)
	{
	case (int)EGWT_ROLE:
		m_nTotalWinLostChips_Game -= m_nTotalWinLostChips_Role;
		break;
	default:
		m_nTotalWinLostChips_Game += m_nTotalWinLostChips_Role;
		break;
	}
}

void  CTexasGame::UpdateGameVipRoomChips()
{
	if (NULL != m_pTexasRoom)
	{
		switch (m_nGameWinType)
		{
		case (int)EGWT_ROLE:
			m_pTexasRoom->Pay_Vip_TexasGame_Chip(m_nTotalWinLostChips_Role);
			break;
		default:
			m_pTexasRoom->Supplementary_Vip_TexasGame_Chip(m_nTotalWinLostChips_Role);
			break;
		}
	}
}

void CTexasGame::ResetGameRole()
{
	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
		{
			pTexasRole->Reset();
		}
	}
}

void  CTexasGame::SetMaxHandCard(BYTE sCard[])
{
	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
		{
			vector<int> nMaxHandCardVec;
			nMaxHandCardVec.swap(pTexasRole->GetMaxHandCard());
			if (nMaxHandCardVec.empty())
			{
				for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
				{
					nMaxHandCardVec.push_back(sCard[index]);
				}
				pTexasRole->SetMaxHandCard(nMaxHandCardVec);
			}
			else if (nMaxHandCardVec.size() == MAX_TEXAS_CENTERCARD_NUM)
			{
				BYTE sRoleMaxHandCard[MAX_TEXAS_CENTERCARD_NUM];

				for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
				{
					sRoleMaxHandCard[index] = nMaxHandCardVec[index];
				}

				nMaxHandCardVec.clear();

				if (m_Card.CompareCard(sCard, sRoleMaxHandCard, MAX_TEXAS_CENTERCARD_NUM) == 2)
				{
					for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
					{
						nMaxHandCardVec.push_back(sCard[index]);
					}
					pTexasRole->SetMaxHandCard(nMaxHandCardVec);
				}
			}
		}
	}
}

void CTexasGame::OnGameRound_Deal(int nCard)
{
	m_nCardValue = nCard;

	AddCardNum();
	OnGameRound_DealCard(nCard);

	ProcessMsg_DealCardSync();

	OnGameRound_SetRound();
}

void  CTexasGame::OnGameRound_DealCard(int nCard)
{
	switch (m_nCardNum)
	{
	case (int)ECNT_1:
	{
		SetCardDealType((int)ECDT_Hand);
		OnGameRound_SetCard((int)ECDT_Hand, nCard);
	}

	break;
	case (int)ECNT_2:
	{
		SetCardDealType((int)ECDT_Hand);
		OnGameRound_SetCard((int)ECDT_Hand, nCard);
	}

	break;
	case (int)ECNT_3:
	{
		SetCardDealType((int)ECDT_Center);
		OnGameRound_SetCard((int)ECDT_Center, nCard);
	}

	break;
	case (int)ECNT_4:
	{
		SetCardDealType((int)ECDT_Center);
		OnGameRound_SetCard((int)ECDT_Center, nCard);
	}

	break;
	case (int)ECNT_5:
	{
		SetCardDealType((int)ECDT_Center);
		OnGameRound_SetCard((int)ECDT_Center, nCard);
	}
	break;
	case (int)ECNT_6:
	{
		SetCardDealType((int)ECDT_Center);
		OnGameRound_SetCard((int)ECDT_Center, nCard);
	}
	break;
	case (int)ECNT_7:
	{
		SetCardDealType((int)ECDT_Center);
		OnGameRound_SetCard((int)ECDT_Center, nCard);
	}
	break;
	case (int)ECNT_8:
	{
		SetCardDealType((int)ECDT_GIRL);
		OnGameRound_SetCard((int)ECDT_GIRL, nCard);
	}

	break;
	case (int)ECNT_9:
	{
		SetCardDealType((int)ECDT_GIRL);
		OnGameRound_SetCard((int)ECDT_GIRL, nCard);
	}
	break;
	default:
		break;
	}
}

void CTexasGame::OnGameRound_Dealer_DealCard(int nCard)
{
	OnGameRound_Deal(nCard);

	OnGameRound_NoticeBet();

	ProcessMsg_AutoFoldSync();
}

void CTexasGame::OnGameRound_SetCard(int nCardDealType, int nCard)
{
	switch (nCardDealType)
	{
	case (int)ECDT_Hand:
	{
		m_nHandCardVec.push_back(nCard);
		m_nGameCardVec.push_back(nCard);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [GameRoom:%d->FirstRound:HandCard: %d->%s]!",
			m_nRoomId, nCard, (m_Card.GetCardName(BYTE(nCard))).c_str());
	}
	break;
	case (int)ECDT_Center:
	{
		m_nCenterCardVec.push_back(nCard);
		m_nGameCardVec.push_back(nCard);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [GameRoom:%d->ExtraRound:CenterCard: %d->%s]!",
			m_nRoomId, nCard, (m_Card.GetCardName(BYTE(nCard))).c_str());
	}

	break;
	case (int)ECDT_GIRL:
	{
		m_nGirlCardVec.push_back(nCard);
		m_nGameCardVec.push_back(nCard);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [GameRoom:%d->ExtraRound:GirlCard: %d->%s]!",
			m_nRoomId, nCard, (m_Card.GetCardName(BYTE(nCard))).c_str());
	}
	break;
	}
}

void CTexasGame::OnGameRound_SetRound()
{
	switch (m_nCardNum)
	{
	case (int)ECNT_2:
	{
		SetCountDown_TurnTime();
		AddGameRounds();
	}
	break;
	case (int)ECNT_5:
	{
		SetCountDown_TurnTime();
		AddGameRounds();
	}
	break;
	case (int)ECNT_6:
	{
		SetCountDown_TurnTime();
		AddGameRounds();
	}
	break;
	default:
		break;
	}
}

void CTexasGame::OnGameRound_Showdown()
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" [>>>>[GameRoom:%d]-> OnGameRound_Showdown:[TexasBoard:%d-Round:%d]<<<<]!",
		m_nRoomId, GetTexasBoardId(), m_nGameRounds);

	BYTE sRoleCardData[MAX_TEXAS_CENTERCARD_NUM];
	BYTE sGirlCardData[MAX_TEXAS_CENTERCARD_NUM];
	BYTE sJackPotCardData[MAX_TEXAS_CENTERCARD_NUM];

	if (m_nHandCardVec.empty() || m_nCenterCardVec.empty())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [>>>>[GameRoom:%d]-> OnGameRound_Showdown:[TexasBoard:%d-Round:%d] HandCard,CenterCard Exception<<<<]!",
			m_nRoomId, GetTexasBoardId(), m_nGameRounds);
		return;
	}

	SetRoleCardKindType((int)m_Card.FiveFromSeven(m_nHandCardVec, m_nCenterCardVec, sRoleCardData, MAX_TEXAS_CENTERCARD_NUM));
	SetGirlCardKindType((int)m_Card.FiveFromSeven(m_nGirlCardVec, m_nCenterCardVec, sGirlCardData, MAX_TEXAS_CENTERCARD_NUM));

	SetGameWinType((int)m_Card.CompareCard(sRoleCardData, sGirlCardData, MAX_TEXAS_CENTERCARD_NUM));

	SetHistoryWin();

	SetRoleCenterCard(sRoleCardData);
	SetGirlCenterCard(sGirlCardData);

	SetMaxHandCard(sRoleCardData);

	SetJackpotType(m_Card.JackPotReward(m_Card.FiveFromSevenWithHand(m_nHandCardVec, m_nCenterCardVec,
		sJackPotCardData, MAX_TEXAS_CENTERCARD_NUM)));

	SetBonusType(m_Card.BonusReward(m_nHandCardVec, m_nGirlCardVec));

	if (m_nJackpotType >= 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [>>>>[GameRoom:%d]-> OnGameRound_Showdown:[ JackpotReward: Mulitples:%d]<<<<]!",
			m_nRoomId, m_nJackpotType);
	}
	if (m_nBonusType >= 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" [>>>>[GameRoom:%d]-> OnGameRound_Showdown:[ BonusReward: Mulitples:%d]<<<<]!",
			m_nRoomId, m_nBonusType);
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" [>>>>[GameRoom:%d]-> OnGameRound_Showdown:[ Winner[EGWT_TIE=0|EGWT_GIRL=1|EGWT_ROLE= 2]: %d]<<<<]!"
		, m_nRoomId, m_nGameWinType);

	OnGameRound_GameResultsSettlement();

	ProcessMsg_GameResultsSettlementSync();

	ProcessMsg_PrizePoolSync();

	ProcessMsg_BrandBroadcastSync();

	SaveTexasBoard_DB();
	SaveTexasHistoryBoard10_DB();

	SaveTexasBet_DL();
}

void  CTexasGame::OnGameRound_GameCancel()
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" [>>>>[GameRoom:%d]-> OnGameRound_GameCancel:[TexasBoard:%d]<<<<]!",
		m_nRoomId, GetTexasBoardId());
	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->CheckRole() &&
			pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
		{
			pTexasRole->Process_GameCancel();
		}
	}
}

void  CTexasGame::OnGameRound_NoticeBet()
{
	switch (m_nCardNum)
	{
	case (int)ECNT_2:
		ProcessMsg_NoticeBetSync_GameBet();
		break;
	case (int)ECNT_5:
		ProcessMsg_NoticeBetSync_GameBet();
		break;
	case (int)ECNT_6:
		ProcessMsg_NoticeBetSync_GameBet();
		break;
	}
}

void CTexasGame::OnGameRound_Dealer_GameRound()
{
	switch (m_nCardNum)
	{
	case (int)ECNT_0:
	{
		if (!CheckGameRoundSwitch((int)EMDNT_Ante))
		{
			SetGameRoundSwitch((int)EMDNT_Ante);
			SetDealerStatus(EMDNT_Ante);
			ProcessMsg_Dealer_DealNoticeSync();
		}
	}
	break;

	case (int)ECNT_2:
	{
		if (!CheckGameRoundSwitch((int)EMDNT_Flop))
		{
			SetGameRoundSwitch((int)EMDNT_Flop);
			SetDealerStatus(EMDNT_Flop);
			ProcessMsg_Dealer_DealNoticeSync();
		}
	}
	break;
	case (int)ECNT_5:
	{
		if (!CheckGameRoundSwitch((int)EMDNT_Turn))
		{
			SetGameRoundSwitch((int)EMDNT_Turn);
			SetDealerStatus(EMDNT_Turn);
			ProcessMsg_Dealer_DealNoticeSync();
		}
	}
	break;
	case (int)ECNT_6:
	{
		if (!CheckGameRoundSwitch((int)EMDNT_River))
		{
			SetGameRoundSwitch((int)EMDNT_River);
			SetDealerStatus(EMDNT_River);
			ProcessMsg_Dealer_DealNoticeSync();
		}
	}
	break;
	}
}

void CTexasGame::OnGameRound_Dealer_GameReStart()
{
	SetDealerStatus((int)EMDNT_ReStart);
	ProcessMsg_Dealer_DealNoticeSync();
}

void CTexasGame::OnGameRound_Bet(BetReq& refBetReq)
{
	OnGameRound_VipRoom_Bet(refBetReq);

	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(refBetReq.nRoleID);
		if (NULL != pTexasRole)
		{
			if (pTexasRole->GetIsSitdown())
			{
				pTexasRole->Process_SetBet(m_nRoomType, m_nGameRounds, m_nMaxBetCount, refBetReq);
			}
		}
	}
}

void CTexasGame::OnGameRound_VipRoom_Bet(BetReq& refBetReq)
{
	if (m_nRoomType == (int)ERoomType_Vip)
	{
		if (m_nGameRounds == (int)ERT_Ante)
		{
			if (CheckVipRoomLimitBetAnte(refBetReq.nBetChips,
				CTableLimitManager::Instance().GetMaxAnte(m_nRoomId)))
			{
				AddVipRoomLimitBetAnte(refBetReq.nBetChips);
				DecVipRoomRemainBetAnte(refBetReq.nBetChips);
			}
		}
	}
}

void CTexasGame::OnGameRound_Fold(FoldReq& refFoldReq)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(refFoldReq.nRoleID);
		if (NULL != pTexasRole)
		{
			if (pTexasRole->GetIsSitdown())
			{
				pTexasRole->SetRoleStatus((int)ERS_Fold);;
			}
		}
	}
}

void CTexasGame::OnGameRound_GameResultsSettlement()
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" [>>>>[GameRoom:%d]-> OnGameRound_GameResultsSettlement:[TexasBoard:%d]<<<<]!",
		m_nRoomId, GetTexasBoardId());

	bool bFlag = false;
	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->CheckRole() &&
			pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
		{
			if (m_nRoomType == ERoomType_Common)
			{
				pTexasRole->Process_Reward_Bonus(m_nBonusType);
				pTexasRole->Process_Reward_Jackpot(m_nJackpotType);
			}
			pTexasRole->Process_GameResults(m_nGameWinType, m_nRoleCardKindType);

			AddTotal_Bet_Jackpot(pTexasRole->GetBet_Jackpot_Unbind());
			AddTotal_Bet_Bonus(pTexasRole->GetBet_Bonus_Unbind());
			AddTotal_Reward_Jackpot(pTexasRole->GetJackpot_RewardValue());
			AddTotal_Reward_Bonus(pTexasRole->GetBonus_RewardValue());

			AddTotalLostWinChips_Role(pTexasRole->GetTotalLostWinChips());

			bFlag = true;
		}
	}
	if (bFlag)
	{
		if (m_nRoomType == ERoomType_Common)
		{
			UpdatePrizePool();

			UpdateGameChips();
		}
		else if (m_nRoomType == ERoomType_Vip)
		{
			UpdateGameVipRoomChips();
		}
	}
}