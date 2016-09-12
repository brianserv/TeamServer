#include "DLMessage.h"

void CDLMessage::ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	DLHeartBeatReq *pDLHeartBeatReq = reinterpret_cast<DLHeartBeatReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pDLHeartBeatReq)
		return;

	ProcessMsg_Ping_HeartBeatRes(pDataInfo, nDataLen, pClient);
}

void CDLMessage::ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, void* pClient)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	DLHeartBeatRes* pDLHeartBeatRes = reinterpret_cast<DLHeartBeatRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pDLHeartBeatRes))
		return;

	pPacketHead->SetPacketHead(ESDL_PING_DL2S_HEARTBEAT_RES);

	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}