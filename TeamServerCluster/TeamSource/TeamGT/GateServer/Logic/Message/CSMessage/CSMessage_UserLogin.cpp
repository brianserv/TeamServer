#include "CSMessage.h"

void CCSMessage::ProcessMsg_UserLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	UserLoginReq* pUserLoginReq = reinterpret_cast<UserLoginReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pUserLoginReq))
		return;

	//if (!Encrypt_MD5_Check(pUserLoginReq->nRoleID,(const string)pUserLoginReq->sRoleToken))
	//{
	//	ProcessMsg_ClientErrorSync(ECERT_LOGIN_USERNAMEPASSWORD_ERROR,pPlayerClient->GetIndex());
	//	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,"Login key validation error");
	//	return;
	//}

	CRole* pRole = CRoleManager::Instance().GetRole(pUserLoginReq->nRoleID);
	if (NULL != pRole && pRole->GetIsUsed())
	{
		pPlayerClient->SetRoleId(pUserLoginReq->nRoleID);
		ProcessMsg_OnDisconnect(pRole->GetIndex());
	}
	CRoleManager::Instance().CreateRole(pUserLoginReq->nRoleID, pUserLoginReq->sUserName,
		pUserLoginReq->sRoleToken, pPlayerClient->GetIndex());

	pPlayerClient->SetRoleId(pUserLoginReq->nRoleID);
	pTempPacketHead->SetIndex(pPlayerClient->GetIndex());

	ProcessMsg_TransferClientMsg(pDataInfo, nDataLen, pPacketHead);
}