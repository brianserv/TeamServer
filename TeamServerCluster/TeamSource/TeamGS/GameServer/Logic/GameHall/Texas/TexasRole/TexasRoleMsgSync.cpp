#include "TexasRole.h"

void CTexasRole::ProcessMsg_GirlChangeSync(GirlChangeSync& refGirlChangeSync)
{
	CCSMessage::Instance().ProcessMsg_GirlChangeSync(refGirlChangeSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_StartGameSync(GameStartSync& refGameStartSync)
{
	CCSMessage::Instance().ProcessMsg_StartGameSync(refGameStartSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_DealCardSync(DealCardSync& refDealCardSync)
{
	CCSMessage::Instance().ProcessMsg_DealCardSync(refDealCardSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_NoticeBetSync(NoticeBetSync refNoticeBetSync)
{
	CCSMessage::Instance().ProcessMsg_NoticeBetSync(refNoticeBetSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_GameSettlementSync(GameSettlementSync& refGameSettlementSync)
{
	CCSMessage::Instance().ProcessMsg_GameSettlementSync(refGameSettlementSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_GirlCancelGameSync(GirlCancelSync& refGirlCancelSync)
{
	CCSMessage::Instance().ProcessMsg_GirlCancelGameSync(refGirlCancelSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_CardListSync(CardListSync& refCardListSync)
{
	CCSMessage::Instance().ProcessMsg_CardListSync(refCardListSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_RewardPoolSync(RewardPoolSync& refRewardPoolSync)
{
	CCSMessage::Instance().ProcessMsg_RewardPoolSync(refRewardPoolSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_HistoryBoardSync(HistoryBoardInfoSync& refHistoryBoardInfoSync)
{
	CCSMessage::Instance().ProcessMsg_HistoryBoardSync(refHistoryBoardInfoSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_BetBroadcastSync(BetBroadcastSync& refBetBroadcastSync)
{
	CCSMessage::Instance().ProcessMsg_BetBroadcastSync(refBetBroadcastSync, this->GetRoleId());
}
void CTexasRole::ProcessMsg_BrandBroadcastSync(BrandBroadcastSync& refBrandBroadcastSync)
{
	CCSMessage::Instance().ProcessMsg_BrandBroadcastSync(refBrandBroadcastSync, this->GetRoleId());
}
void CTexasRole::ProcessMsg_OnlineBroadcastSync(OnlineBroadcastSync& refOnlineBroadcastSync)
{
	CCSMessage::Instance().ProcessMsg_OnlineBroadcastSync(refOnlineBroadcastSync, this->GetRoleId());
}

void CTexasRole::ProcessMsg_ErrorSync(int nErrorID)
{
	CRole* pRole = CRoleManager::Instance().GetRole(this->GetRoleId());
	if (NULL != pRole)
	{
		CCSMessage::Instance().ProcessMsg_ClientErrorInfoSync(nErrorID, pRole->GetPlayerIndex(), pRole->GetGateIndex());
	}
}