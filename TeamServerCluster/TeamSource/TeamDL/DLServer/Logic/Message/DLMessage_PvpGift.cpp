#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_PvpGiftReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SavePVPGiftReq* pSavePVPGiftReq = reinterpret_cast<SavePVPGiftReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSavePVPGiftReq)
		return;

	CDLPvpGift* pDLPvpGift = new CDLPvpGift();
	if (NULL == pDLPvpGift)
	{
		return;
	}

	pDLPvpGift->setPvpGiftProperty(pSavePVPGiftReq->nFromRoleId,
		pSavePVPGiftReq->nToRoleId,
		(string)pSavePVPGiftReq->sFromRoleName,
		(string)pSavePVPGiftReq->sToRoleName,
		pSavePVPGiftReq->nPlatformId,
		(string)pSavePVPGiftReq->sFromThirdId,
		(string)pSavePVPGiftReq->sToThirdId,
		(string)pSavePVPGiftReq->sFromThirdAccount,
		(string)pSavePVPGiftReq->sToThirdAccount,
		pSavePVPGiftReq->nGiftId,
		pSavePVPGiftReq->nGiftPrice,
		pSavePVPGiftReq->nUnbindChip,
		pSavePVPGiftReq->nBindChip,
		pSavePVPGiftReq->nServerId,
		pSavePVPGiftReq->nRoomId);

	if (!g_DLManager.SavePvpGiftData(pDLPvpGift))
	{
		SAFE_DELETE(pDLPvpGift);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SavePVPGiftReq Failure !");
		return;
	}

	SAFE_DELETE(pDLPvpGift);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SavePVPGiftReq Success !");
}