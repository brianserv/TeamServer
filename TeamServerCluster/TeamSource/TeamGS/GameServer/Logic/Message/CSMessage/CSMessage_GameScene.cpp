#include "CSMessage.h"

void CCSMessage::ProcessMsg_GirlChangeSync(GirlChangeSync& refGirlChangeSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GirlChangeSync* pGirlChangeSync = reinterpret_cast<GirlChangeSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGirlChangeSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_GirlChangeSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GirlChangeSync);

	pGirlChangeSync->nRoleID = refGirlChangeSync.nRoleID;
	pGirlChangeSync->nGirlID = refGirlChangeSync.nGirlID;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_GIRLCHANGE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_GirlChangeSync !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_GIRLCHANGE_SYNC);
}

void CCSMessage::ProcessMsg_StartGameSync(GameStartSync& refGameStartSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GameStartSync* pGameStartSync = reinterpret_cast<GameStartSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGameStartSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_StartGameSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(pGameStartSync);

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_STARTGAME_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_StartGameSync !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_STARTGAME_SYNC);
}

void CCSMessage::ProcessMsg_DealCardSync(DealCardSync& refDealCardSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	DealCardSync* pDealCardSync = reinterpret_cast<DealCardSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pDealCardSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_DealCardSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(DealCardSync);

	pDealCardSync->nRoleID = refDealCardSync.nRoleID;
	pDealCardSync->nCardOrderID = refDealCardSync.nCardOrderID;
	pDealCardSync->nCardType = refDealCardSync.nCardType;
	pDealCardSync->nCardValue = refDealCardSync.nCardValue;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_DEALCARD_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_DealCardSync !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_DEALCARD_SYNC);
}

void CCSMessage::ProcessMsg_NoticeBetSync(NoticeBetSync& refNoticeBetSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	NoticeBetSync* pNoticeBetSync = reinterpret_cast<NoticeBetSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pNoticeBetSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_NoticeBetSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(NoticeBetSync);

	pNoticeBetSync->nRoleID = refNoticeBetSync.nRoleID;
	pNoticeBetSync->nBetRoundID = refNoticeBetSync.nBetRoundID;
	pNoticeBetSync->nBetMaxWaitTime = refNoticeBetSync.nBetMaxWaitTime;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_NOTICEBET_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_NoticeBetSync !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_NOTICEBET_SYNC);
}

void  CCSMessage::ProcessMsg_BetReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	BetReq* pBetReq = reinterpret_cast<BetReq*>(pDataInfo + sizeof(PACKETHEAD));

	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pBetReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pBetReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_BetReq !", pRole->GetPlayerIndex(), ECS_TEXASGAME_C2GT2S_BET_REQ);

	BetReq refBetReq;
	refBetReq.nRoleID = pBetReq->nRoleID;
	refBetReq.nBetType = pBetReq->nBetType;
	refBetReq.nBetJackpotType = pBetReq->nBetJackpotType;
	refBetReq.mBetBonusType = pBetReq->mBetBonusType;
	refBetReq.nBetChips = pBetReq->nBetChips;
	pTexasGame->ProcessMsg_BetReq(refBetReq);
}
void  CCSMessage::ProcessMsg_BetRes(BetRes& refBetRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	BetRes* pBetRes = reinterpret_cast<BetRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pBetRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_BetRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(BetRes);

	pBetRes->nRoleID = refBetRes.nRoleID;
	pBetRes->nBetRoundID = refBetRes.nBetRoundID;
	pBetRes->nRemainAnte = refBetRes.nRemainAnte;
	pBetRes->nBetResult = refBetRes.nBetResult;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_BET_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_BetRes !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_BET_RES);
}

void  CCSMessage::ProcessMsg_FoldReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Fold Req!");

	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	FoldReq* pFoldReq = reinterpret_cast<FoldReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pFoldReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pFoldReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_FoldReq !", pRole->GetPlayerIndex(), ECS_TEXASGAME_C2GT2S_FOLD_REQ);

	FoldReq refFoldReq;
	refFoldReq.nRoleID = pFoldReq->nRoleID;
	pTexasGame->ProcessMsg_FoldReq(refFoldReq);
}

void  CCSMessage::ProcessMsg_FoldRes(FoldRes& refFoldRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	FoldRes* pFoldRes = reinterpret_cast<FoldRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pFoldRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_FoldRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(FoldRes);

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_FOLD_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_FoldRes !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_FOLD_RES);
}

void CCSMessage::ProcessMsg_GameSettlementSync(GameSettlementSync& refGameSettlementSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GameSettlementSync* pGameSettlementSync = reinterpret_cast<GameSettlementSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGameSettlementSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_GameSettlementSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GameSettlementSync);

	int nWinLostType = refGameSettlementSync.nLostWinType - 1;

	pGameSettlementSync->nRoleID = refGameSettlementSync.nRoleID;
	pGameSettlementSync->nLostWinType = nWinLostType;
	pGameSettlementSync->nRoleCardKindType = refGameSettlementSync.nRoleCardKindType;
	pGameSettlementSync->nGirlCardKindType = refGameSettlementSync.nGirlCardKindType;;
	pGameSettlementSync->nLostWinChips = refGameSettlementSync.nLostWinChips;
	pGameSettlementSync->nJackpotType = refGameSettlementSync.nJackpotType;
	pGameSettlementSync->nBonusType = refGameSettlementSync.nBonusType;
	pGameSettlementSync->nJackpotRewardValue = refGameSettlementSync.nJackpotRewardValue;
	pGameSettlementSync->nBonusRewardValue = refGameSettlementSync.nBonusRewardValue;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_GAMESETTLEMENT_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_GameSettlementSync !", pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_GAMESETTLEMENT_SYNC);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[ClientID:%d|ProtocolID:%d]ProcessMsg_GameSettlementSync MemoParmeter: !"
		"[nRoleID:%d,nLostWinType:%d,nRoleCardKindType:%d,nGirlCardKindType:%d,nLostWinChips:%d]"
		"[nJackpotType:%d,nBonusType:%d,nJackpotRewardValue:%d,nBonusRewardValue:%d]"
		, pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_GAMESETTLEMENT_SYNC,
		pGameSettlementSync->nRoleID, nWinLostType,
		pGameSettlementSync->nRoleCardKindType,
		pGameSettlementSync->nGirlCardKindType,
		pGameSettlementSync->nLostWinChips,
		pGameSettlementSync->nJackpotType,
		pGameSettlementSync->nBonusType,
		pGameSettlementSync->nJackpotRewardValue,
		pGameSettlementSync->nBonusRewardValue);
}

void CCSMessage::ProcessMsg_GirlCancelGameSync(GirlCancelSync& refGirlCancelSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GirlCancelSync* pGirlCancelSync = reinterpret_cast<GirlCancelSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGirlCancelSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_GirlCancelGameSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GirlCancelSync);

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_GIRLCANCEL_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_GirlCancelGameSync !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_GIRLCANCEL_SYNC);
}

void CCSMessage::ProcessMsg_CardListSync(CardListSync& refCardListSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	CardListSync* pCardListSync = reinterpret_cast<CardListSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pCardListSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_CardListSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(CardListSync);

	pCardListSync->nRoleID = refCardListSync.nRoleID;
	pCardListSync->nCardNum = refCardListSync.nCardNum;
	memcpy(pCardListSync->nCardListInfo, refCardListSync.nCardListInfo, sizeof(pCardListSync->nCardListInfo));

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_CARDLIST_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_CardListSync !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_CARDLIST_SYNC);
}

void CCSMessage::ProcessMsg_RewardPoolSync(RewardPoolSync& refRewardPoolSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	RewardPoolSync* pRewardPoolSync = reinterpret_cast<RewardPoolSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pRewardPoolSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_RewardPoolSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(RewardPoolSync);

	pRewardPoolSync->nRoleID = refRewardPoolSync.nRoleID;
	pRewardPoolSync->nCurRewardPool = refRewardPoolSync.nCurRewardPool;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_REWARDPOOL_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_RewardPoolSync !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_REWARDPOOL_SYNC);
}

void CCSMessage::ProcessMsg_HistoryBoardSync(HistoryBoardInfoSync& refHistoryBoardInfoSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	HistoryBoardInfoSync* pHistoryBoardInfoSync = reinterpret_cast<HistoryBoardInfoSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pHistoryBoardInfoSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_HistoryBoardSync:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(HistoryBoardInfoSync);

	pHistoryBoardInfoSync->nRoleID = refHistoryBoardInfoSync.nRoleID;
	pHistoryBoardInfoSync->nHistoryBoardNum = refHistoryBoardInfoSync.nHistoryBoardNum;
	memcpy(pHistoryBoardInfoSync->nHistoryBoardInfo, refHistoryBoardInfoSync.nHistoryBoardInfo, sizeof(pHistoryBoardInfoSync->nHistoryBoardInfo));

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_HISTORYBOARD_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_HistoryBoardSync !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_HISTORYBOARD_SYNC);
}

void CCSMessage::ProcessMsg_ReadyLeaveRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ReadyLeaveRoomReq  Req!");

	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	ReadyLeaveRoomReq* pReadyLeaveRoomReq = reinterpret_cast<ReadyLeaveRoomReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pReadyLeaveRoomReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pReadyLeaveRoomReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_ReadyLeaveRoomReq !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_C2GT2S_READYLEAVEROOM_REQ);

	ReadyLeaveRoomReq refReadyLeaveRoomReq;
	refReadyLeaveRoomReq.nRoleID = pReadyLeaveRoomReq->nRoleID;
	pTexasGame->ProcessMsg_ReadyLeaveRoomReq(refReadyLeaveRoomReq);
}

void CCSMessage::ProcessMsg_ReadyLeaveRoomRes(ReadyLeaveRoomRes& refReadyLeaveRoomRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	ReadyLeaveRoomRes* pReadyLeaveRoomRes = reinterpret_cast<ReadyLeaveRoomRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pReadyLeaveRoomRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_ReadyLeaveRoomRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(FoldRes);

	pReadyLeaveRoomRes->nRoleID = refReadyLeaveRoomRes.nRoleID;
	pReadyLeaveRoomRes->nRoleStatus = refReadyLeaveRoomRes.nRoleStatus;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_READYLEAVEROOM_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_ReadyLeaveRoomRes !",
		pRole->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_READYLEAVEROOM_RES);
}