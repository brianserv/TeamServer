#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_LoginReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveLoginReq* pSaveLoginReq = reinterpret_cast<SaveLoginReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveLoginReq)
		return;

	CDLLogin* pDLLogin = new CDLLogin();
	if (NULL == pDLLogin)
	{
		return;
	}

	pDLLogin->SetLoginProperty(pSaveLoginReq->nRoleId,
		(string)pSaveLoginReq->sRoleName,
		pSaveLoginReq->nPlatformId,
		(string)pSaveLoginReq->sThirdId,
		(string)pSaveLoginReq->sThirdAccount,
		pSaveLoginReq->nLoginTime,
		pSaveLoginReq->nServerId,
		(string)pSaveLoginReq->sIp,
		pSaveLoginReq->nStatus);

	if (!g_DLManager.SaveLoginData(pDLLogin))
	{
		SAFE_DELETE(pDLLogin);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveLoginReq Failure !");
		return;
	}

	SAFE_DELETE(pDLLogin);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveLoginReq Success !");
}