#include "CSMessage.h"

void CCSMessage::ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	if ((NULL == pPlayerClient) || (NULL == pPacketHead))
		return;

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Client:%d  HeartBeat Req!", pPlayerClient->GetIndex());
	ProcessMsg_HeartBeatRes(pPlayerClient->GetIndex(), false);
}

void CCSMessage::ProcessMsg_HeartBeatRes(int nIndex, bool bClose)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	CGTHeartBeatRes* pCGTHeartBeatRes = reinterpret_cast<CGTHeartBeatRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pCGTHeartBeatRes))
		return;

	pPacketHead->SetIndex(nIndex);
	pPacketHead->SetPacketHead(ECS_PING_GT2C_HEARTBEAT_RES);
	sendlen = pPacketHead->GetLength();
	CGateServer::Instance().SendClientMsg(sendbuf, sendlen, nIndex, bClose);

	if (!bClose)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "Client:%d  Normal->HeartBeat Res!", nIndex);
	}
}