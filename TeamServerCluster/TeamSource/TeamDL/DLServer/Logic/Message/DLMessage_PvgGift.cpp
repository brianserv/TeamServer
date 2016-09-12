#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_PvgGiftReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SavePVGGiftReq* pSavePVGGiftReq = reinterpret_cast<SavePVGGiftReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSavePVGGiftReq)
		return;

	CDLPvgGift* pDLPvgGift = new CDLPvgGift();
	if (NULL == pDLPvgGift)
	{
		return;
	}

	pDLPvgGift->SetpvgGiftProperty(pSavePVGGiftReq->nRoleId,
		(string)pSavePVGGiftReq->sRoleName,
		pSavePVGGiftReq->nGirlId,
		(string)pSavePVGGiftReq->sGirlThirdId,
		pSavePVGGiftReq->nGiftId,
		pSavePVGGiftReq->nGiftNum,
		pSavePVGGiftReq->nGiftPrice,
		pSavePVGGiftReq->nType,
		pSavePVGGiftReq->nUnbindPink,
		pSavePVGGiftReq->nBindPink,
		pSavePVGGiftReq->nGameType,
		pSavePVGGiftReq->nGameId,
		pSavePVGGiftReq->nRoomId,
		pSavePVGGiftReq->nServerId,
		pSavePVGGiftReq->nRoomType,
		pSavePVGGiftReq->nEvenCount,
		pSavePVGGiftReq->nBroadcastType,
		pSavePVGGiftReq->nSaveType);

	if (!g_DLManager.SavePvgGiftData(pDLPvgGift))
	{
		SAFE_DELETE(pDLPvgGift);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SavePVGGiftReq Failure !");
		return;
	}
	SAFE_DELETE(pDLPvgGift);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SavePVGGiftReq Success !");
}