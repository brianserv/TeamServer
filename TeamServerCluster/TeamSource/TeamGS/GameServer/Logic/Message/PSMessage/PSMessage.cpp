#include "PSMessage.h"

void  CPSMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case EPS_VIPROOM_P2GT2S_CREATE_REQ:
			ProcessMsg_VipRoom_Create_Req(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EPS_VIPROOM_P2GT2S_RELEASE_REQ:
			ProcessMsg_VipRoom_Release_Req(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EPS_VIPROOM_P2GT2S_APPENDCHIP_REQ:
			ProcessMsg_VipRoom_AppendChip_Req(pDataInfo, nDataLen, pPacketHead, pClient);
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