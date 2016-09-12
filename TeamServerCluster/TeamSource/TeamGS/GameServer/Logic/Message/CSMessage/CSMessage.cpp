#include "CSMessage.h"

void  CCSMessage ::ProcessMsg(char* pDataInfo,long nDataLen,void* pPacketHead,void* pClient)
{
	if((NULL == pDataInfo) || (nDataLen <= 0)  || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		switch (pTempPacketHead->nCmd)
		{
		case ECS_LOGIN_C2GT2S_USERLOGIN_REQ:
			ProcessMsg_UserLoginReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_HALLROOM_C2GT2S_ENTERROOM_REQ:
			ProcessMsg_EnterRoomReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_HALLROOM_C2GT2S_LEAVEROOM_REQ:
			ProcessMsg_LeaveRoomReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_HALLROOM_C2GT2S_SITDOWN_REQ:
			ProcessMsg_SitDownReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_HALLROOM_C2GT2S_STANDUP_REQ:
			ProcessMsg_StandUpReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_TEXASGAME_C2GT2S_BET_REQ:
			ProcessMsg_BetReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_TEXASGAME_C2GT2S_FOLD_REQ:
			ProcessMsg_FoldReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		case ECS_TEXASGAME_C2GT2S_READYLEAVEROOM_REQ:
			ProcessMsg_ReadyLeaveRoomReq(pDataInfo,nDataLen,pPacketHead,pClient);
			break;
		default:
			break;
		}
	}
	catch(...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,"CCenterMessage::Exception Cmd : %ld",pTempPacketHead->nCmd);
	}
}

void CCSMessage ::SendClientMsg(char* pDataInfo,long nDataLen,void* pPacketHead,int nPlayerIndex,int nGateIndex)
{
	CGameServer::Instance().SendClientMsg(pDataInfo,nDataLen,pPacketHead,nPlayerIndex,nGateIndex);
}


void  CCSMessage ::ProcessMsg_ClientErrorInfoSync(int nErrorID,int nPlayerIndex,int nGateIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = {0};
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	CSErrorInfoSync* pCSErrorInfoSync = reinterpret_cast<CSErrorInfoSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pCSErrorInfoSync))
		return;

	pCSErrorInfoSync->nErrorID = nErrorID;

	pTempPacketHead->SetPacketHead(ECS_ERROR_S2GT2C_ERRORCODE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	SendClientMsg(sendbuf,sendlen,pTempPacketHead,nPlayerIndex,nGateIndex);
}


