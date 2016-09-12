#include "GSMessage.h"

void CGSMessage::ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	if ((NULL == pPlayerClient) || (NULL == pPacketHead))
		return;

	ProcessMsg_HeartBeatRes(pPlayerClient->GetIndex(), false);
}

void CGSMessage::ProcessMsg_HeartBeatRes(int nIndex, bool bClose)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSHeartBeatReq* pGSHeartBeatReq = reinterpret_cast<GSHeartBeatReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGSHeartBeatReq))
		return;

	pPacketHead->SetIndex(nIndex);
	pPacketHead->SetPacketHead(EGS_PING_GT2G_HEARTBEAT_RES);
	sendlen = pPacketHead->GetLength();

	CGateServer::Instance().SendClientMsg(sendbuf, sendlen, nIndex, bClose);
}