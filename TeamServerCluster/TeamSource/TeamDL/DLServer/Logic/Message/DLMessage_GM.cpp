#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_GmReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveGmReq *pSaveGmReq = reinterpret_cast<SaveGmReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveGmReq)
		return;

	CDLGm* pDLGm = new CDLGm();
	if (NULL == pDLGm)
	{
		return;
	}

	pDLGm->SetGmProperty(pSaveGmReq->nRoleId, pSaveGmReq->nGmId, pSaveGmReq->nGmActionType, (string)pSaveGmReq->sDescribe);

	if (!g_DLManager.SaveGmData(pDLGm))
	{
		SAFE_DELETE(pDLGm);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveGmReq Failure !");
		return;
	}

	SAFE_DELETE(pDLGm);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveGmReq Success !");
}