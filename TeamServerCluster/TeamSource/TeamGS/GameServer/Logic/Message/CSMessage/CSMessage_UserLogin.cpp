#include "CSMessage.h"
#include "../../../Logic/Httplink/HttpLinkEvent.h"

void CCSMessage::ProcessMsg_UserLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	UserLoginReq* pUserLoginReq = reinterpret_cast<UserLoginReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pUserLoginReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pUserLoginReq->nRoleID);
	if (NULL != pRole)
	{
		if (pRole->GetRoleName() != pUserLoginReq->sUserName)
		{
			ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_USERNAMEPASSWORD_ERROR,
				pTempPacketHead->GetIndex(),
				pPlayerClient->GetIndex());
			return;
		}
	}
	if (!CRoleManager::Instance().AddRole(pUserLoginReq->nRoleID,
		pUserLoginReq->nGServerID,
		pUserLoginReq->nPlatformID,
		pUserLoginReq->nSex,
		pUserLoginReq->sUserName,
		pUserLoginReq->sRoleToken,
		pUserLoginReq->sThirdID,
		pUserLoginReq->sThirdAccount,
		pTempPacketHead->GetIndex(), pPlayerClient->GetIndex()))
	{
		return;
	}
	CRole* pRoleEx = CRoleManager::Instance().GetRole(pUserLoginReq->nRoleID);
	if (NULL == pRoleEx)
	{
		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_UserLoginReq !", pRoleEx->GetPlayerIndex(), ECS_LOGIN_C2GT2S_USERLOGIN_REQ);

	pRoleEx->SetPlayerIndex(pTempPacketHead->GetIndex());
	pRoleEx->SetGateIndex(pPlayerClient->GetIndex());

	UserLoginRes refUserLoginRes;
	ProcessMsg_UserLoginRes(refUserLoginRes, pRoleEx->GetRoleId());

	CHttpLinkEvent::Instance().ProcessEvent_Request_MsgRegister(EPType_FB, EFB_HEType_V2_GetRoleDataReq, pUserLoginReq->nRoleID, 0, 0);

	CDBMessage::Instance().ProcessMsg_SaveRoleReq(pUserLoginReq->nRoleID);
	CDLMessage::Instance().ProcessMsg_SaveLoginReq(pUserLoginReq->nRoleID, pPlayerClient->GetPeerNetAddr2());
}

void CCSMessage::ProcessMsg_UserLoginRes(UserLoginRes& refUserLoginRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	UserLoginRes* pUserLoginRes = reinterpret_cast<UserLoginRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pUserLoginRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(UserLoginRes);

	pTempPacketHead->SetPacketHead(ECS_LOGIN_S2GT2C_USERLOGIN_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_UserLoginRes !",
		pRole->GetPlayerIndex(), ECS_LOGIN_S2GT2C_USERLOGIN_RES);
}