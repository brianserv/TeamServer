#include "DBMessage.h"

void CDBMessage::ProcessMsg_LoadTexasBoardReq(LoadTexasBoardReq& refLoadTexasBoardReq)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadTexasBoardReq* pLoadTexasBoardReq = reinterpret_cast<LoadTexasBoardReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pLoadTexasBoardReq))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadTexasBoardReq);

	pLoadTexasBoardReq->nServerId = refLoadTexasBoardReq.nServerId;
	pLoadTexasBoardReq->nRoomId = refLoadTexasBoardReq.nRoomId;

	pPacketHead->SetPacketHead(ESDB_TEXASBOARD_S2DB_LOAD_TEXASBOARD_REQ);
	sendlen = pPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pPacketHead);
}

void CDBMessage::ProcessMsg_LoadTexasBoardRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	LoadTexasBoardRes* pLoadTexasBoardRes = reinterpret_cast<LoadTexasBoardRes*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadTexasBoardRes))
		return;

	CTexasGameManager::Instance().SetTexasGameBoardID(pLoadTexasBoardRes->nRoomId, pLoadTexasBoardRes->nBoardId);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " CDBMessage::Load TexasBoardID Success !!!");
}

void CDBMessage::ProcessMsg_SaveTexasBoardReq(SaveTexasBoardReq& refSaveTexasBoardReq)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SaveTexasBoardReq* pSaveTexasBoardReq = reinterpret_cast<SaveTexasBoardReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSaveTexasBoardReq))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SaveTexasBoardReq);

	pSaveTexasBoardReq->nBoardId = refSaveTexasBoardReq.nBoardId;

	pSaveTexasBoardReq->nGirlId = refSaveTexasBoardReq.nGirlId;

	memcpy(pSaveTexasBoardReq->strCard, refSaveTexasBoardReq.strCard, sizeof(pSaveTexasBoardReq->strCard));
	memcpy(pSaveTexasBoardReq->strShowCard, refSaveTexasBoardReq.strShowCard, sizeof(pSaveTexasBoardReq->strShowCard));

	pSaveTexasBoardReq->nServerId = refSaveTexasBoardReq.nServerId;
	pSaveTexasBoardReq->nGameId = refSaveTexasBoardReq.nGameId;
	pSaveTexasBoardReq->nRoomId = refSaveTexasBoardReq.nRoomId;
	pSaveTexasBoardReq->nSumChip = refSaveTexasBoardReq.nSumChip;
	pSaveTexasBoardReq->nRewardJackpotType = refSaveTexasBoardReq.nRewardJackpotType;
	pSaveTexasBoardReq->nRewardBonusType = refSaveTexasBoardReq.nRewardBonusType;
	pSaveTexasBoardReq->nCardType = refSaveTexasBoardReq.nCardType;
	pSaveTexasBoardReq->nDealcardType = refSaveTexasBoardReq.nDealcardType;
	pSaveTexasBoardReq->nResult = refSaveTexasBoardReq.nResult;
	pSaveTexasBoardReq->nEndStatus = refSaveTexasBoardReq.nEndStatus;
	pSaveTexasBoardReq->nStartTime = refSaveTexasBoardReq.nStartTime;
	pSaveTexasBoardReq->nEndTime = refSaveTexasBoardReq.nEndTime;

	pTempPacketHead->SetPacketHead(ESDB_TEXASBOARD_S2DB_SAVE_TEXASBOARD_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}