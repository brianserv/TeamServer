#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_RoomReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveRoomReq* pSaveRoomReq = reinterpret_cast<SaveRoomReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveRoomReq)
		return;

	CDLRoom *pDLRoom = new CDLRoom();
	if (NULL == pDLRoom)
	{
		return;
	}
	pDLRoom->SetRoomProperty(pSaveRoomReq->nRoleId,
		(string)pSaveRoomReq->sRoleName,
		pSaveRoomReq->nPlatformId,
		(string)pSaveRoomReq->sThirdId,
		(string)pSaveRoomReq->sThirdAccount,
		pSaveRoomReq->nRoomId,
		pSaveRoomReq->nGirlId,
		pSaveRoomReq->nAction);

	if (!g_DLManager.SaveRoomData(pDLRoom))
	{
		SAFE_DELETE(pDLRoom);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveRoomReq Failure !");
		return;
	}
	SAFE_DELETE(pDLRoom);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveRoomReq Success !");
}