#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_OnlineReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveOnlineReq* pSaveOnlineReq = reinterpret_cast<SaveOnlineReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveOnlineReq)
		return;

	CDLOnline* pDLOnline = new CDLOnline();
	if (NULL == pDLOnline)
	{
		return;
	}

	pDLOnline->SetOnlineProperty(pSaveOnlineReq->nServerId,
		pSaveOnlineReq->nGameType,
		pSaveOnlineReq->nRoomType,
		pSaveOnlineReq->nGameId,
		pSaveOnlineReq->nRoomId,
		pSaveOnlineReq->nGirlId,
		pSaveOnlineReq->nOnlineUsersCount);

	if (!g_DLManager.SaveOnlineData(pDLOnline))
	{
		SAFE_DELETE(pDLOnline);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveOnlineReq Failure !");
		return;
	}
	SAFE_DELETE(pDLOnline);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveOnlineReq Success !");
}