#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_BetReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveBetReq *pSaveBetReq = reinterpret_cast<SaveBetReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveBetReq)
		return;

	CDLBet *pDLBet = new CDLBet();
	if (NULL == pDLBet)
	{
		return;
	}
	pDLBet->SetBetProperty(
		pSaveBetReq->nRoleId,
		pSaveBetReq->nBoardId,
		pSaveBetReq->nGameType,
		pSaveBetReq->nGameId,
		pSaveBetReq->nRoomId,
		pSaveBetReq->nGirlId,
		pSaveBetReq->nJackpot,
		pSaveBetReq->nBonus,
		(string)pSaveBetReq->sJackpotDetail,
		(string)pSaveBetReq->sBonusDetail,
		pSaveBetReq->nAnte,
		pSaveBetReq->nFlop,
		(string)pSaveBetReq->sSumChipDetail,
		(string)pSaveBetReq->sChipDetail,
		pSaveBetReq->nWinChip,
		pSaveBetReq->nRewardBonus,
		pSaveBetReq->nRewardJackpot,
		pSaveBetReq->nTea,
		pSaveBetReq->nServerId,
		(string)pSaveBetReq->sWinChipDetail,
		(string)pSaveBetReq->sBeforeChipDetail,
		(string)pSaveBetReq->sAfterChipDetail,
		pSaveBetReq->nTotalAmount);

	if (!g_DLManager.SaveBetData(pDLBet))
	{
		SAFE_DELETE(pDLBet);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveBetReq Failure !");
		return;
	}
	SAFE_DELETE(pDLBet);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveBetReq Success !");
}