#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

void CTexasGame::ProcessMsg_EnterRoomReq(EnterRoomReq& refEnterRoomReq)
{
	if (m_nRoomType == ERoomType_Common)
	{
		//if (!CheckEnterRoomChips(refEnterRoomReq.nRoleID))
		//{
		//	return;
		//}
	}

	if (CTexasRoomManager::Instance().Role_EnterRoom(refEnterRoomReq.nRoomID, refEnterRoomReq.nRoleID))
	{
		CRoleManager::Instance().SetGameType(refEnterRoomReq.nRoleID, refEnterRoomReq.nRoomID);
		CRoleManager::Instance().SetRoomId(refEnterRoomReq.nRoleID, refEnterRoomReq.nRoomID);

		ProcessMsg_EnterRoomRes(refEnterRoomReq.nRoleID);

		ProcessMsg_CardListSync();

		ProcessMsg_PrizePoolSync();

		ProcessMsg_GirlChangeSync(refEnterRoomReq.nRoleID);

		ProcessMsg_HistoryBoardSync(refEnterRoomReq.nRoleID);
	}
}

void CTexasGame::ProcessMsg_LeaveRoomReq(LeaveRoomReq& refLeaveRoomReq)
{
	if (CTexasRoomManager::Instance().Role_LeaveRoom(refLeaveRoomReq.nRoomID, refLeaveRoomReq.nRoleID))
	{
		ProcessMsg_LeaveRoomRes(refLeaveRoomReq.nRoleID);
	}
}

void CTexasGame::ProcessMsg_SitDownReq(SitDownReq& refSitDownReq)
{
	if (CTexasRoomManager::Instance().Role_Sitdown(refSitDownReq.nRoomID, refSitDownReq.nRoleID))
	{
		ProcessMsg_SitDownRes(refSitDownReq.nRoleID);
	}
}

void CTexasGame::ProcessMsg_StandUpReq(StandUpReq& refStandUpReq)
{
	if (CTexasRoomManager::Instance().Role_StandUp(refStandUpReq.nRoomID, refStandUpReq.nRoleID))
	{
		ProcessMsg_StandUpRes(refStandUpReq.nRoleID);
	}
}

void CTexasGame::ProcessMsg_BetReq(BetReq& refBetReq)
{
	OnGameRound_Bet(refBetReq);
	ProcessMsg_BetRes(refBetReq.nRoleID);
	ProcessMsg_BetBroadcastSync(refBetReq.nRoleID);
}

void CTexasGame::ProcessMsg_FoldReq(FoldReq& refFoldReq)
{
	OnGameRound_Fold(refFoldReq);
	ProcessMsg_FoldRes(refFoldReq.nRoleID);
}

void CTexasGame::ProcessMsg_ReadyLeaveRoomReq(ReadyLeaveRoomReq& refReadyLeaveRoomReq)
{
	ProcessMsg_ReadyLeaveRoomRes(refReadyLeaveRoomReq.nRoleID);
}