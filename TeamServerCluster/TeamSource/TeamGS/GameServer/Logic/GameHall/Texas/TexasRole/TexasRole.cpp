#include "TexasRole.h"

EQ_IMPLEMENT_CACHE(CTexasRole, 100)
CTexasRole::CTexasRole() :
	m_pRole(NULL),
	m_nRoleId(0),
	m_nRoomId(0),
	m_bIsUsed(false),
	m_bIsSitDown(false),
	m_bIsSetFoldCard(false),
	m_bIsSetCheckCard(false),
	m_bIsSetAnteCard(false),
	m_bIsBetResultSucc(false),
	m_nRoleStatus(0),
	m_nBet_Jackpot(0),
	m_nBet_Bonus(0),
	m_nBet_Ante(0),
	m_nBet_Flop(0),
	m_nBet_Turn(0),
	m_nBet_River(0),
	m_nBet_Jackpot_Unbind(0),
	m_nBet_Bonus_Unbind(0),
	m_nBet_Ante_Unbind(0),
	m_nBet_Flop_Unbind(0),
	m_nBet_Turn_Unbind(0),
	m_nBet_River_Unbind(0),
	m_nBet_Jackpot_Bind(0),
	m_nBet_Bonus_Bind(0),
	m_nBet_Ante_Bind(0),
	m_nBet_Flop_Bind(0),
	m_nBet_Turn_Bind(0),
	m_nBet_River_Bind(0),
	m_nTotalBetTea(0),
	m_nTotalBetChips(0),
	m_nTotalLostWinChips(0),
	m_nWinChips(0),
	m_nWinChips_Unbind(0),
	m_nWinChips_Bind(0),
	m_nJackpot_RewardMultiples(0),
	m_nBonus_RewardMultiples(0),
	m_nJackpot_RewardValue(0),
	m_nBonus_RewardValue(0),
	m_nFormulaTotalAmount(0),
	m_nBetBeforeChips_Unbind(0),
	m_nBetBeforeChips_Bind(0),
	m_nBetBeforeChips_Total(0)
{
	for (int i = 0; i < MAX_TEXAS_BETROUND_NUM; i++)
	{
		m_nRoundBet_Chips[i] = 0;
		m_bRoundBetMark[i] = false;
	}
}

CTexasRole::~CTexasRole()
{
	Clear();
}

bool CTexasRole::Init()
{
	m_pRole = NULL;
	m_nRoleId = 0;
	m_nRoomId = 0;
	m_bIsUsed = false;
	m_bIsSitDown = false;
	return true;
}

bool CTexasRole::Clear()
{
	Init();
	Reset();

	return true;
}

bool CTexasRole::Reset()
{
	m_bIsSetFoldCard = false;
	m_bIsSetCheckCard = false;
	m_bIsSetAnteCard = false;
	m_bIsBetResultSucc = false;
	m_nRoleStatus = 0;
	m_nBet_Jackpot = 0;
	m_nBet_Bonus = 0;
	m_nBet_Ante = 0;
	m_nBet_Flop = 0;
	m_nBet_Turn = 0;
	m_nBet_River = 0;
	m_nBet_Jackpot_Unbind = 0;
	m_nBet_Bonus_Unbind = 0;
	m_nBet_Ante_Unbind = 0;
	m_nBet_Flop_Unbind = 0;
	m_nBet_Turn_Unbind = 0;
	m_nBet_River_Unbind = 0;
	m_nBet_Jackpot_Bind = 0;
	m_nBet_Bonus_Bind = 0;
	m_nBet_Ante_Bind = 0;
	m_nBet_Flop_Bind = 0;
	m_nBet_Turn_Bind = 0;
	m_nBet_River_Bind = 0;
	m_nTotalBetTea = 0;
	m_nTotalBetChips = 0;
	m_nTotalLostWinChips = 0;
	m_nWinChips = 0;
	m_nWinChips_Unbind = 0;
	m_nWinChips_Bind = 0;
	m_nJackpot_RewardMultiples = 0;
	m_nBonus_RewardMultiples = 0;
	m_nJackpot_RewardValue = 0;
	m_nBonus_RewardValue = 0;
	m_nFormulaTotalAmount = 0;

	m_nBetBeforeChips_Unbind = 0;
	m_nBetBeforeChips_Bind = 0;
	m_nBetBeforeChips_Total = 0;

	for (int i = 0; i < MAX_TEXAS_BETROUND_NUM; i++)
	{
		m_nRoundBet_Chips[i] = 0;
		m_bRoundBetMark[i] = false;
	}

	m_strJackpotDetail = "";
	m_strBonusDetail = "";
	m_strSumChipDetail = "";
	m_strChipDetail = "";
	m_strWinChipDetail = "";
	m_strBeforeChipDetail = "";
	m_strAfterChipDetail = "";

	return true;
}

bool CTexasRole::SetRole(int nRoleId)
{
	CRole* pRole = CRoleManager::Instance().GetRole((int)nRoleId);
	if (NULL == pRole)
	{
		return false;
	}
	m_pRole = pRole;
	return true;
}

CRole* CTexasRole::GetRole()
{
	if (NULL == m_pRole)
	{
		return NULL;
	}
	return m_pRole;
}

bool CTexasRole::CheckRole()
{
	if (NULL == m_pRole)
	{
		return false;
	}
	return true;
}

void CTexasRole::SetMaxHandCard(vector<int>& nMaxCardTypeVec)
{
	if (NULL == m_pRole)
	{
		return;
	}
	m_pRole->SetMaxCardType(nMaxCardTypeVec);
}

vector<int>& CTexasRole::GetMaxHandCard()
{
	if (NULL != m_pRole)
	{
		return m_pRole->GetMaxCardType();
	}
}

string CTexasRole::GetThirdId()
{
	if (NULL != m_pRole)
	{
		return m_pRole->GetThirdId();
	}
}

string CTexasRole::GetUserName()
{
	if (NULL != m_pRole)
	{
		return m_pRole->GetRoleName();
	}
}