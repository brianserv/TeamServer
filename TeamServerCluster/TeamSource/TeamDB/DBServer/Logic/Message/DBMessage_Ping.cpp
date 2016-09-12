#include "DBMessage.h"

void CDBMessage::ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	DBHeartBeatReq *pDBHeartBeatReq = reinterpret_cast<DBHeartBeatReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pDBHeartBeatReq)
		return;

	ProcessMsg_Ping_HeartBeatRes(pDataInfo, nDataLen, pClient);
}

void CDBMessage::ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, void* pClient)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	DBHeartBeatRes* pDBHeartBeatRes = reinterpret_cast<DBHeartBeatRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pDBHeartBeatRes))
		return;

	pPacketHead->SetPacketHead(ESDB_PING_DB2S_HEARTBEAT_RES);
	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}