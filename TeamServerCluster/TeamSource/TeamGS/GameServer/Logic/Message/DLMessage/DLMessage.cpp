#include "DLMessage.h"

void  CDLMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case ESDL_BET_DL2S_SAVE_BET_RES:
			break;
		case ESDL_LOGIN_DL2S_SAVE_LOGIN_RES:
			break;
		case ESDL_LOGOUT_DL2S_SAVE_LOGOUT_RES:
			break;
		case ESDL_ONLINE_DL2S_SAVE_ONLINE_RES:
			break;
		case ESDL_PVGGIFT_DL2S_SAVE_PVG_GIFT_RES:
			break;
		case ESDL_PVPGIFT_DL2S_SAVE_PVP_GIFT_RES:
			break;
		case ESDL_ROOM_DL2S_SAVE_ROOM_RES:
			break;
		case ESDL_TRACE_DL2S_SAVE_TRACE_RES:
			break;
		case ESDL_GM_DL2S_SAVE_GM_RES:
			break;
		default:
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CCenterMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CDLMessage::SendDBLogMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	CGameServer::Instance().SendDBLogMsg(pDataInfo, nDataLen, pPacketHead);
}