#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

#include "../../../../Logic/Message/GSMessage/GSMessage.h"

void CTexasGame::ProcessMsg_GirlChangeSync(int nRoleId)
{
	if (CheckGirl() && m_bManualModel)
	{
		GirlChangeSync refGirlChangeSync;
		refGirlChangeSync.nGirlID = GetGirlId();
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			refGirlChangeSync.nRoleID = pTexasRole->GetRoleId();
			pTexasRole->ProcessMsg_GirlChangeSync(refGirlChangeSync);
		}
	}
}

void CTexasGame::ProcessMsg_StartGameSync()
{
	GameStartSync refGameStartSync;

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole)
		{
			if (pTexasRole->GetIsSitdown())
			{
				pTexasRole->SetRoleStatus((int)ERS_Ready);
				pTexasRole->ProcessMsg_StartGameSync(refGameStartSync);
			}
		}
	}
}

void CTexasGame::ProcessMsg_DealCardSync()
{
	DealCardSync refDealCardSync;
	refDealCardSync.nCardOrderID = m_nCardNum;
	refDealCardSync.nCardType = m_nCardDealType;
	refDealCardSync.nCardValue = m_nCardValue;

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" [ProcessMsg_DealCardSync::GameRoom:%d->CardOrder:%d->CardDealType:%d->CardValue:%d->%s]!",
		m_nRoomId, m_nCardNum, m_nCardDealType, m_nCardValue, (m_Card.GetCardName(BYTE(m_nCardValue))).c_str());

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole)
		{
			refDealCardSync.nRoleID = pTexasRole->GetRoleId();
			pTexasRole->ProcessMsg_DealCardSync(refDealCardSync);
		}
	}
}

void CTexasGame::ProcessMsg_NoticeBetSync_GameStart()
{
	NoticeBetSync refNoticeBetSync;
	refNoticeBetSync.nBetRoundID = GetNoticeBetRoundId();
	refNoticeBetSync.nBetMaxWaitTime = (unsigned int)MAX_TEXAS_GAMESTART_INTERVAL;

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->GetIsSitdown())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
				" [ProcessMsg_NoticeBetSync_GameStart::GameRoom:%d->nBetRoundID:%d->nBetMaxWaitTime:%d->%s]!",
				m_nRoomId, refNoticeBetSync.nBetRoundID, refNoticeBetSync.nBetMaxWaitTime, (m_Card.GetCardName(BYTE(m_nCardValue))).c_str());

			refNoticeBetSync.nRoleID = pTexasRole->GetRoleId();
			pTexasRole->ProcessMsg_NoticeBetSync(refNoticeBetSync);
		}
	}
}

void CTexasGame::ProcessMsg_NoticeBetSync_GameBet()
{
	NoticeBetSync refNoticeBetSync;
	refNoticeBetSync.nBetRoundID = GetNoticeBetRoundId();
	refNoticeBetSync.nBetMaxWaitTime = GetMaxBetWaitTime();

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->GetIsUsed() && pTexasRole->GetIsSitdown())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
				" [ProcessMsg_NoticeBetSync_GameBet::GameRoom:%d->nBetRoundID:%d->nBetMaxWaitTime:%d->%s]!",
				m_nRoomId, refNoticeBetSync.nBetRoundID, refNoticeBetSync.nBetMaxWaitTime, (m_Card.GetCardName(BYTE(m_nCardValue))).c_str());

			if (m_nGameRounds > (int)ERT_Flop && pTexasRole->Check_FoldCard())
			{
				continue;
			}
			else
			{
				if (pTexasRole->IsCheckBet() > 0)
				{
					refNoticeBetSync.nRoleID = pTexasRole->GetRoleId();
					pTexasRole->ProcessMsg_NoticeBetSync(refNoticeBetSync);
				}
			}
		}
	}
}

void CTexasGame::ProcessMsg_GameResultsSettlementSync()
{
	GameSettlementSync refGameSettlementSync;
	refGameSettlementSync.nLostWinType = GetGameWinType();
	refGameSettlementSync.nRoleCardKindType = GetRoleCardKindType();
	refGameSettlementSync.nGirlCardKindType = GetGirlCardKindType();
	refGameSettlementSync.nJackpotType = GetJackpotType();
	refGameSettlementSync.nBonusType = GetBonusType();

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole && pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
		{
			if (pTexasRole->Check_FoldCard())
			{
				refGameSettlementSync.nLostWinType = (int)EGWT_FOLD;
			}
			refGameSettlementSync.nRoleID = pTexasRole->GetRoleId();
			refGameSettlementSync.nLostWinChips = pTexasRole->GetWinChips();
			refGameSettlementSync.nJackpotRewardValue = pTexasRole->GetJackpot_RewardValue();
			refGameSettlementSync.nBonusRewardValue = pTexasRole->GetBonus_RewardValue();

			pTexasRole->ProcessMsg_GameSettlementSync(refGameSettlementSync);

			ProcessMsg_HistoryBoardSync(pTexasRole->GetRoleId());
		}
	}
}

void CTexasGame::ProcessMsg_GameCancelSync()
{
	GirlCancelSync refGirlCancelSync;

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole)
		{
			pTexasRole->ProcessMsg_GirlCancelGameSync(refGirlCancelSync);
		}
	}
}

void CTexasGame::ProcessMsg_CardListSync()
{
	if (m_nCardNum <= ECNT_6)
	{
		CardListSync refCardListSync;
		refCardListSync.nCardNum = m_nGameCardVec.size();
		for (size_t index = 0; index < refCardListSync.nCardNum; index++)
		{
			refCardListSync.nCardListInfo[index] = m_nGameCardVec[index];

			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " [GameRoom:%d->CardOrder:%d->CardValue:%d->%s]!",
				m_nRoomId, index, m_nGameCardVec[index], (m_Card.GetCardName(BYTE(m_nGameCardVec[index]))).c_str());
		}

		TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
		TexasRoleMap::iterator it = refMap.begin();
		TexasRoleMap::iterator it_end = refMap.end();
		for (; it != it_end; ++it)
		{
			CTexasRole* pTexasRole = it->second;
			if (NULL != pTexasRole)
			{
				refCardListSync.nRoleID = pTexasRole->GetRoleId();
				pTexasRole->ProcessMsg_CardListSync(refCardListSync);
			}
		}
	}
}

void CTexasGame::ProcessMsg_PrizePoolSync()
{
	if (m_nRoomType == ERoomType_Common)
	{
		RewardPoolSync refRewardPoolSync;
		refRewardPoolSync.nCurRewardPool = CPrizePoolManager::Instance().GetTotalValue();

		TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
		TexasRoleMap::iterator it = refMap.begin();
		TexasRoleMap::iterator it_end = refMap.end();
		for (; it != it_end; ++it)
		{
			CTexasRole* pTexasRole = it->second;
			if (NULL != pTexasRole)
			{
				refRewardPoolSync.nRoleID = pTexasRole->GetRoleId();
				pTexasRole->ProcessMsg_RewardPoolSync(refRewardPoolSync);
			}
		}
	}
}

void CTexasGame::ProcessMsg_BetBroadcastSync(int nRoleId)
{
	if (m_nMaxBetCount >= MAX_TEXAS_BETBROADCAST_NUM)
		return;

	if (NULL != m_pTexasRoom && m_pTexasRoom->GetRoomType() == ERoomType_Vip)
	{
		CTexasRole* pTexasRole_Bet = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole_Bet)
		{
			if (pTexasRole_Bet->GetIsSitdown() && pTexasRole_Bet->IsCheckBetResult())
			{
				BetBroadcastSync refBetBroadcastSync;

				TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
				TexasRoleMap::iterator it = refMap.begin();
				TexasRoleMap::iterator it_end = refMap.end();
				for (; it != it_end; ++it)
				{
					CTexasRole* pTexasRole = it->second;
					if (NULL != pTexasRole && pTexasRole->GetRoleId() != nRoleId)
					{
						pTexasRole->ProcessMsg_BetBroadcastSync(refBetBroadcastSync);
					}
				}
			}
		}
	}
}

void CTexasGame::ProcessMsg_BrandBroadcastSync()
{
	if (GetRoleCardKindType() > ECK_FourofaKind)
	{
		BrandBroadcastSync refBrandBroadcastSync;
		refBrandBroadcastSync.nGirlID = GetGirlId();
		refBrandBroadcastSync.nCardKindType = GetRoleCardKindType();

		TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
		TexasRoleMap::iterator it = refMap.begin();
		TexasRoleMap::iterator it_end = refMap.end();
		for (; it != it_end; ++it)
		{
			CTexasRole* pTexasRole = it->second;
			if (NULL != pTexasRole)
			{
				refBrandBroadcastSync.nRoleID = pTexasRole->GetRoleId();
				pTexasRole->ProcessMsg_BrandBroadcastSync(refBrandBroadcastSync);
			}
		}
	}
}

void CTexasGame::ProcessMsg_OnlineBroadcastSync()
{
	OnlineBroadcastSync refOnlineBroadcastSync;

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole)
		{
			refOnlineBroadcastSync.nRoleID = pTexasRole->GetRoleId();
			memcpy(refOnlineBroadcastSync.sThirdID, (pTexasRole->GetThirdId()).c_str(), sizeof(refOnlineBroadcastSync.sThirdID));
			memcpy(refOnlineBroadcastSync.sUserName, (pTexasRole->GetUserName()).c_str(), sizeof(refOnlineBroadcastSync.sUserName));
			pTexasRole->ProcessMsg_OnlineBroadcastSync(refOnlineBroadcastSync);
		}
	}
}

void  CTexasGame::ProcessMsg_AutoFoldSync()
{
	if (m_nGameRounds == ERT_Turn)
	{
		TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
		TexasRoleMap::iterator it = refMap.begin();
		TexasRoleMap::iterator it_end = refMap.end();
		for (; it != it_end; ++it)
		{
			CTexasRole* pTexasRole = it->second;
			if (NULL != pTexasRole && pTexasRole->GetIsSitdown())
			{
				if (pTexasRole->IsCheckBet() && pTexasRole->Check_FoldCard())
				{
					pTexasRole->SetRoleStatus((int)ERS_Fold);

					FoldRes refFoldRes;
					pTexasRole->ProcessMsg_FoldRes(refFoldRes);
				}
			}
		}
	}
}

void CTexasGame::ProcessMsg_HistoryBoardSync(int nRoleId)
{
	CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
	if (NULL != pTexasRole)
	{
		HistoryBoardInfoSync refHistoryBoardInfoSync;
		refHistoryBoardInfoSync.nRoleID = nRoleId;
		refHistoryBoardInfoSync.nHistoryBoardNum = m_nHistoryWinVec.size();
		for (size_t index = 0; index < refHistoryBoardInfoSync.nHistoryBoardNum; index++)
		{
			refHistoryBoardInfoSync.nHistoryBoardInfo[index] = (m_nHistoryWinVec[index] - 1);
		}
		pTexasRole->ProcessMsg_HistoryBoardSync(refHistoryBoardInfoSync);
	}
}