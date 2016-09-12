#include "GSMessage.h"

void  CGSMessage::ProcessMsg_GameStartReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	GSGameStartReq* pGSGameStartReq = reinterpret_cast<GSGameStartReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pGSGameStartReq))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(pGSGameStartReq->nGirlID);
	if (NULL == pGirl)
	{
		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pGirl->getRoomID());
	if (NULL == pTexasGame)
		return;

	if (pGSGameStartReq->nGirlID != pTexasGame->GetGirlId())
		return;

	GSGameStartReq refGSGameStartReq;
	refGSGameStartReq.nGirlID = pGSGameStartReq->nGirlID;
	pTexasGame->ProcessMsg_Dealer_GameStartReq(refGSGameStartReq);
}

void CGSMessage::ProcessMsg_GameStartRes(GSGameStartRes& refGSGameStartRes, int nGirlID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSGameStartRes* pGSGameStartRes = reinterpret_cast<GSGameStartRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGSGameStartRes))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(nGirlID);
	if (NULL == pGirl)
	{
		return;
	}
	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GSGameStartRes);

	pGSGameStartRes->nGameStartResult = refGSGameStartRes.nGameStartResult;

	pTempPacketHead->SetPacketHead(EGS_TEXASGAME_S2GT2G_GAMESTART_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pGirl->GetPlayerIndex(), pGirl->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[ClientID:%d|ProtocolID:%d]ProcessMsg_GameStartRes:nResult:%d !", pGirl->GetPlayerIndex(), EGS_TEXASGAME_S2GT2G_GAMESTART_RES, refGSGameStartRes.nGameStartResult);
}

void  CGSMessage::ProcessMsg_DealNoticeSync(GSDealNotesSync& refGSDealNotesSync, int nGirlID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSDealNotesSync* pGSDealNotesSync = reinterpret_cast<GSDealNotesSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGSDealNotesSync))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(nGirlID);
	if (NULL == pGirl)
	{
		return;
	}
	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GSDealNotesSync);

	pGSDealNotesSync->nDealerStatus = refGSDealNotesSync.nDealerStatus;

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_DEALNOTICE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pGirl->GetPlayerIndex(), pGirl->GetGateIndex());
}

void CGSMessage::ProcessMsg_DealCardReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	GSDealCardReq* pGSDealCardReq = reinterpret_cast<GSDealCardReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pGSDealCardReq))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(pGSDealCardReq->nGirlID);
	if (NULL == pGirl)
		return;

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pGirl->getRoomID());
	if (NULL == pTexasGame)
		return;

	GSDealCardReq refGGSDealCardReq;
	refGGSDealCardReq.nGirlID = pGSDealCardReq->nGirlID;
	refGGSDealCardReq.nCardValue = pGSDealCardReq->nCardValue;
	pTexasGame->ProcessMsg_Dealer_DealCardReq(refGGSDealCardReq);
}

void CGSMessage::ProcessMsg_GameEndSync(GSGameEndSync& refGSGameEndSync, int nGirlID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSGameEndSync* pGSGameEndSync = reinterpret_cast<GSGameEndSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGSGameEndSync))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(nGirlID);
	if (NULL == pGirl)
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GSGameEndSync);

	pGSGameEndSync->nManualGameResultType = (refGSGameEndSync.nManualGameResultType - 1);

	pTempPacketHead->SetPacketHead(ECS_TEXASGAME_S2GT2C_GAMEEND_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pGirl->GetPlayerIndex(), pGirl->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_GameEndSync !",
		pGirl->GetPlayerIndex(), ECS_TEXASGAME_S2GT2C_GAMEEND_SYNC);
}

void CGSMessage::ProcessMsg_GameCancelReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	GSGameCancelReq* pGSGameCancelReq = reinterpret_cast<GSGameCancelReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pGSGameCancelReq))
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(pGSGameCancelReq->nGirlID);
	if (NULL == pGirl)
		return;

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pGirl->getRoomID());
	if (NULL == pTexasGame)
		return;
	GSGameCancelReq refGSGameCancelReq;
	refGSGameCancelReq.nGirlID = pGSGameCancelReq->nGirlID;
	pTexasGame->ProcessMsg_Dealer_GameCancelReq(refGSGameCancelReq);
}