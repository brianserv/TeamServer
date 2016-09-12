#include "GTMessage.h"

void  CGTMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case ESGT_PING_GT2S_HEARTBEAT_REQ:
			ProcessMsg_Ping_HeartBeatReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;

		case ESGT_PING_GT2S_ROLE_DISCONNECT_SYNC:
			ProcessMsg_Ping_Role_DissconnectSync(pDataInfo, nDataLen, pPacketHead, pClient);
			break;

		case ESGT_PING_GT2S_GIRL_DISCONNECT_SYNC:
			ProcessMsg_Ping_Girl_DissconnectSync(pDataInfo, nDataLen, pPacketHead, pClient);
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

void CGTMessage::SendGateMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex)
{
	CGameServer::Instance().SendClientMsg(pDataInfo, nDataLen, pPacketHead, nPlayerIndex, nGateIndex);
}