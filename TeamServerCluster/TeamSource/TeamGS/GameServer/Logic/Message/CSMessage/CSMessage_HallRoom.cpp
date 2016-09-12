#include "CSMessage.h"

void CCSMessage::ProcessMsg_EnterRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	EnterRoomReq* pEnterRoomReq = reinterpret_cast<EnterRoomReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pEnterRoomReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pEnterRoomReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pEnterRoomReq->nRoomID);
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_EnterRoomReq !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_C2GT2S_ENTERROOM_REQ);

	EnterRoomReq refEnterRoomReq;
	refEnterRoomReq.nRoleID = pEnterRoomReq->nRoleID;
	refEnterRoomReq.nGameType = pEnterRoomReq->nGameType;
	refEnterRoomReq.nRoomID = pEnterRoomReq->nRoomID;
	pTexasGame->ProcessMsg_EnterRoomReq(refEnterRoomReq);
}

void CCSMessage::ProcessMsg_EnterRoomRes(EnterRoomRes& refEnterRoomRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	EnterRoomRes* pEnterRoomRes = reinterpret_cast<EnterRoomRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pEnterRoomRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_EnterRoomRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(EnterRoomRes);

	memcpy(pEnterRoomRes, &refEnterRoomRes, sizeof(EnterRoomRes));

	pTempPacketHead->SetPacketHead(ECS_HALLROOM_S2GT2C_ENTERROOM_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_EnterRoomRes !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_S2GT2C_ENTERROOM_RES);
}

void CCSMessage::ProcessMsg_LeaveRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	LeaveRoomReq* pLeaveRoomReq = reinterpret_cast<LeaveRoomReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pLeaveRoomReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pLeaveRoomReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_LeaveRoomReq !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_C2GT2S_LEAVEROOM_REQ);

	LeaveRoomReq refLeaveRoomReq;
	refLeaveRoomReq.nRoleID = pLeaveRoomReq->nRoleID;
	refLeaveRoomReq.nRoomID = pRole->GetRoomId();
	pTexasGame->ProcessMsg_LeaveRoomReq(refLeaveRoomReq);
}
void CCSMessage::ProcessMsg_LeaveRoomRes(LeaveRoomRes& refLeaveRoomRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LeaveRoomRes* pLeaveRoomRes = reinterpret_cast<LeaveRoomRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLeaveRoomRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_LeaveRoomRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(LeaveRoomRes);

	memcpy(pLeaveRoomRes, &refLeaveRoomRes, sizeof(pLeaveRoomRes));

	pTempPacketHead->SetPacketHead(ECS_HALLROOM_S2GT2C_LEAVEROOM_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_LeaveRoomRes !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_S2GT2C_LEAVEROOM_RES);
}

void CCSMessage::ProcessMsg_SitDownReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	SitDownReq* pSitDownReq = reinterpret_cast<SitDownReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pSitDownReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pSitDownReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_SitDownReq !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_C2GT2S_SITDOWN_REQ);

	SitDownReq refSitDownReq;
	refSitDownReq.nRoleID = pSitDownReq->nRoleID;
	refSitDownReq.nRoomID = pRole->GetRoomId();
	pTexasGame->ProcessMsg_SitDownReq(refSitDownReq);
}
void CCSMessage::ProcessMsg_SitDownRes(SitDownRes& refSitDownRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SitDownRes* pSitDownRes = reinterpret_cast<SitDownRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSitDownRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_SitDownRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SitDownRes);

	pTempPacketHead->SetPacketHead(ECS_HALLROOM_S2GT2C_SITDOWN_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_SitDownRes !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_S2GT2C_SITDOWN_RES);
}

void CCSMessage::ProcessMsg_StandUpReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	StandUpReq* pStandUpReq = reinterpret_cast<StandUpReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pStandUpReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pStandUpReq->nRoleID);
	if (NULL == pRole)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROLENOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Role Not Exist  error");

		return;
	}

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pRole->GetRoomId());
	if (NULL == pTexasGame)
	{
		ProcessMsg_ClientErrorInfoSync(ECERT_LOGIN_ROOMNOTEXIST_ERROR,
			pTempPacketHead->GetIndex(),
			pPlayerClient->GetIndex());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Room Not Exist  error");

		return;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_StandUpReq !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_C2GT2S_STANDUP_REQ);

	StandUpReq refStandUpReq;
	refStandUpReq.nRoleID = pStandUpReq->nRoleID;
	refStandUpReq.nRoomID = pRole->GetRoomId();
	pTexasGame->ProcessMsg_StandUpReq(refStandUpReq);
}

void CCSMessage::ProcessMsg_StandUpRes(StandUpRes& refStandUpRes, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	StandUpRes* pStandUpRes = reinterpret_cast<StandUpRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pStandUpRes))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "ProcessMsg_StandUpRes:Role Not Exist!");
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(StandUpRes);

	pTempPacketHead->SetPacketHead(ECS_HALLROOM_S2GT2C_STANDUP_RES);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_StandUpRes !",
		pRole->GetPlayerIndex(), ECS_HALLROOM_S2GT2C_STANDUP_RES);
}