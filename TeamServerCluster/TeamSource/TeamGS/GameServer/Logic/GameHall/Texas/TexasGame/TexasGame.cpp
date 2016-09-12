#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

#include "../../../../Logic/Resource/JsonTable/TableLimit/Tablelimit.h"

EQ_IMPLEMENT_CACHE(CTexasGame, 100)
CTexasGame::CTexasGame()
	:m_bIsUsed(true),
	m_bDealerStart(false),
	m_nRoomId(0),
	m_nRoomType(0),
	m_nGirlId(0),
	m_nTexasBoardId(0),
	m_nStartTime(0),
	m_nEndTime(0),
	m_nCoutDown_TurnTime(0),
	m_nMaxBetWaitTime(0),
	m_bManualModel(false),
	m_nGameStatus(1),
	m_nGameRounds(0),
	m_nCardDealType(0),
	m_nDealerStatus(0),
	m_nCardValue(0),
	m_nCardNum(0),
	m_nMaxBetCount(0),
	m_nHistoryWinCount(0),
	m_nRoleCardKindType(0),
	m_nGirlCardKindType(0),
	m_nBonusType(0),
	m_nJackpotType(0),
	m_nTotal_Bet_Jackpot(0),
	m_nTotal_Bet_Bonus(0),
	m_nTotal_Reward_Jackpot(0),
	m_nTotal_Reward_Bonus(0),
	m_nVipRoomRemainBetAnte(CTableLimitManager::Instance().GetMaxAnte(m_nRoomId)),
	m_nVipRoomLimitBetAnte(0),
	m_nTotalWinLostChips_Game(0),
	m_nTotalWinLostChips_Role(0)
{
	Init();
}

CTexasGame::~CTexasGame()
{
	Clear();
}

bool CTexasGame::OnGameRound_Reset()
{
	Reset();
	return true;
}

bool CTexasGame::Init()
{
	m_bDealerStart = false;
	for (int i = 0; i < 5; i++)
	{
		m_bGameRoundSwitch[i] = false;
	}
	return true;
}

bool CTexasGame::GameRoomBind()
{
	CTexasRoom* pTexasRoom = CTexasRoomManager::Instance().GetTexasRoom(m_nRoomId);
	if (NULL == pTexasRoom)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			"TexasGame()->GameRoomBind() [Game<->RoomId:%d]Failure !", m_nRoomId);
		return false;
	}

	m_pTexasRoom = pTexasRoom;

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"TexasGame()->GameRoomBind() [Game<->RoomId:%d]Success !", m_nRoomId);
	return true;
}

bool  CTexasGame::GameRoomUnBind()
{
	m_pTexasRoom = NULL;
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"TexasGame()->GameRoomUnBind() [Game<->RoomId:%d]Success!", m_nRoomId);
	return true;
}

bool CTexasGame::Clear()
{
	m_nHandCardVec.clear();
	m_nCenterCardVec.clear();
	m_nGirlCardVec.clear();
	m_nGameCardVec.clear();
	m_nRoleCenterCard.clear();
	m_nGirlCenterCard.clear();
	return true;
}

bool CTexasGame::Reset()
{
	Init();

	Clear();

	ResetCardNum();
	RestGameRounds();
	ResetGameStatus();
	ResetGameRole();
	m_Card.ResetCard();

	m_nStartTime = 0;
	m_nEndTime = 0;

	m_nBonusType = 0;
	m_nJackpotType = 0;
	m_nRoleCardKindType = 0;
	m_nGirlCardKindType = 0;

	m_nTotal_Bet_Jackpot = 0;
	m_nTotal_Bet_Bonus = 0;

	m_nTotal_Reward_Jackpot = 0;
	m_nTotal_Reward_Bonus = 0;

	m_nTotalWinLostChips_Game = 0;
	m_nTotalWinLostChips_Role = 0;

	m_nVipRoomRemainBetAnte = CTableLimitManager::Instance().GetMaxAnte(m_nRoomId);
	m_nVipRoomLimitBetAnte = 0;

	return true;
}

bool CTexasGame::CheckRoom()
{
	if (NULL == m_pTexasRoom)
	{
		return false;
	}
	return true;
}

bool CTexasGame::CheckGirl()
{
	if (!CheckRoom())
	{
		return false;
	}

	if (!m_pTexasRoom->CheckGirl(m_nGirlId))
	{
		return false;
	}
	return true;
}

bool CTexasGame::CheckRole()
{
	if (!CheckRoom())
		return false;

	map<int, CRole*> refRoleMap = CRoleManager::Instance().GetRoleMap();
	if (refRoleMap.empty())
		return false;
}

bool  CTexasGame::CheckEnterRoomChips(int nRoleId)
{
	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		// log Role Not Exists
		return false;
	}
	if (pRole->GetTotalChips() < CTableLimitManager::Instance().GetChips(m_nRoomId))
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			pTexasRole->ProcessMsg_ErrorSync((int)ECERT_CHIPS_CHIPSSHORT_ERROR);
		}
		return false;
	}
	return true;
}

int  CTexasGame::GetMaxBetWaitTime()
{
	if (m_nGameStatus == (int)EGS_GameRun)
	{
		return m_nMaxBetWaitTime = ((unsigned int)CConfigFile::Instance().m_nMaxBetWaitTime);
	}
}

int CTexasGame::GetNoticeBetRoundId()
{
	if (m_nGameStatus == (int)EGS_GameReady)
	{
		return (int)ERT_Ante;
	}
	if (m_nGameStatus == (int)EGS_GameRun)
	{
		return m_nGameRounds;
	}
	return (int)ERT_Ante;
}

int CTexasGame::GetProduceCardNum()
{
	int nCardNum = 0;
	switch (m_nCardNum)
	{
	case 0: nCardNum = 2; break;
	case (int)ECNT_2: nCardNum = 3; break;
	case (int)ECNT_6: nCardNum = 3; break;
	case (int)ECNT_5: nCardNum = 1; break;
	}
	return nCardNum;
}

void CTexasGame::Supplementary_Vip_TexasGame_Chip(int nUnbindChip)
{
	if (NULL != m_pTexasRoom)
	{
		m_pTexasRoom->Supplementary_Vip_TexasGame_Chip(nUnbindChip);
	}
}