#include "DLMessage.h"

void CDLMessage::ProcessMsg_SaveTexasBetReq(int nRoleId, SaveBetReq& refSaveBetReq)
{
	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		// log
		return;
	}
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SaveBetReq* pSaveBetReq = reinterpret_cast<SaveBetReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pSaveBetReq))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(SaveBetReq);

	pSaveBetReq->nBoardId = refSaveBetReq.nBoardId;
	pSaveBetReq->nRoleId = refSaveBetReq.nRoleId;
	pSaveBetReq->nGameType = refSaveBetReq.nGameType;
	pSaveBetReq->nGameId = refSaveBetReq.nGameId;
	pSaveBetReq->nRoomId = refSaveBetReq.nRoomId;
	pSaveBetReq->nGirlId = refSaveBetReq.nGirlId;
	pSaveBetReq->nJackpot = refSaveBetReq.nJackpot;
	pSaveBetReq->nBonus = refSaveBetReq.nBonus;

	memcpy(pSaveBetReq->sJackpotDetail, refSaveBetReq.sJackpotDetail, sizeof(pSaveBetReq->sJackpotDetail));
	memcpy(pSaveBetReq->sBonusDetail, refSaveBetReq.sBonusDetail, sizeof(pSaveBetReq->sBonusDetail));
	pSaveBetReq->nAnte = refSaveBetReq.nAnte;
	pSaveBetReq->nFlop = refSaveBetReq.nFlop;

	memcpy(pSaveBetReq->sSumChipDetail, refSaveBetReq.sSumChipDetail, sizeof(pSaveBetReq->sSumChipDetail));
	memcpy(pSaveBetReq->sChipDetail, refSaveBetReq.sChipDetail, sizeof(pSaveBetReq->sChipDetail));

	pSaveBetReq->nWinChip = refSaveBetReq.nWinChip;
	pSaveBetReq->nRewardBonus = refSaveBetReq.nRewardBonus;
	pSaveBetReq->nRewardJackpot = refSaveBetReq.nRewardJackpot;
	pSaveBetReq->nTea = refSaveBetReq.nTea;
	pSaveBetReq->nServerId = refSaveBetReq.nServerId;

	memcpy(pSaveBetReq->sWinChipDetail, refSaveBetReq.sWinChipDetail, sizeof(pSaveBetReq->sWinChipDetail));
	memcpy(pSaveBetReq->sBeforeChipDetail, refSaveBetReq.sBeforeChipDetail, sizeof(pSaveBetReq->sBeforeChipDetail));
	memcpy(pSaveBetReq->sAfterChipDetail, refSaveBetReq.sAfterChipDetail, sizeof(pSaveBetReq->sAfterChipDetail));

	pSaveBetReq->nTotalAmount = refSaveBetReq.nTotalAmount;

	pPacketHead->SetPacketHead(ESDL_BET_S2DL_SAVE_BET_REQ);
	sendlen = pPacketHead->GetLength();
	SendDBLogMsg(sendbuf, sendlen, pPacketHead);
}