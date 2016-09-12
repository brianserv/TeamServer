#include "DLMessage.h"

void  CDLMessage::ProcessMsg(char*   pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		switch (pTempPacketHead->nCmd)
		{
		case ESDL_PING_S2DL_HEARTBEAT_REQ:
			ProcessMsg_Ping_HeartBeatReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_BET_S2DL_SAVE_BET_REQ:
			ProcessMsg_Save_BetReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_GM_S2DL_SAVE_GM_REQ:
			ProcessMsg_Save_GmReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_LOGIN_S2DL_SAVE_LOGIN_REQ:
			ProcessMsg_Save_LoginReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_LOGOUT_S2DL_SAVE_LOGOUT_REQ:
			ProcessMsg_Save_LogoutReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_ONLINE_S2DL_SAVE_ONLINE_REQ:
			ProcessMsg_Save_OnlineReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_PVGGIFT_S2DL_SAVE_PVG_GIFT_REQ:
			ProcessMsg_Save_PvgGiftReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_PVPGIFT_S2DL_SAVE_PVP_GIFT_REQ:
			ProcessMsg_Save_PvpGiftReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_ROOM_S2DL_SAVE_ROOM_REQ:
			ProcessMsg_Save_RoomReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDL_TRACE_S2DL_SAVE_TRACE_REQ:
			ProcessMsg_Save_TraceReq(pDataInfo, nDataLen, pClient);
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CDLMessage::SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	CPlayerClient* pPlayerClient = (CPlayerClient*)(pClient);
	if (NULL == pTempPacketHead || NULL == pClient)
	{
		return;
	}
	pPlayerClient->PostMessage(pDataInfo, nDataLen);
}