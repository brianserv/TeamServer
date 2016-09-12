#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_LogoutReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveLogoutReq* pSaveLogoutReq = reinterpret_cast<SaveLogoutReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveLogoutReq)
		return;
	CDLLogout *pDLLogout = new CDLLogout();
	if (NULL == pDLLogout)
	{
		return;
	}

	pDLLogout->SetLogoutProperty(pSaveLogoutReq->nRoleId,
		(string)pSaveLogoutReq->sRoleName,
		pSaveLogoutReq->nPlatformId,
		(string)pSaveLogoutReq->sThirdId,
		(string)pSaveLogoutReq->sThirdAccount,
		pSaveLogoutReq->nLoginTime,
		pSaveLogoutReq->nLogoutTime,
		pSaveLogoutReq->nServerId,
		(string)pSaveLogoutReq->sIp);

	if (!g_DLManager.SaveLogoutData(pDLLogout))
	{
		SAFE_DELETE(pDLLogout);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveLogoutReq Failure !");
		return;
	}

	SAFE_DELETE(pDLLogout);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveLogoutReq Success !");
}