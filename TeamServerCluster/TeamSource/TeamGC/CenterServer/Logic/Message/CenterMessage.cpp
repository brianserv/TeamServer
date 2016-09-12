#include "CenterMessage.h"

void  CCenterMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case ESGC_PING_S2GC_REGISTER_REQ:
			ProcessMsg_RegisterReq(pDataInfo, nDataLen, pTempPacketHead, pClient);
			break;

		case ESGC_PING_S2GC_HEARTBEAT_REQ:
			ProcessMsg_HeartBeatReq(pDataInfo, nDataLen, pTempPacketHead, pClient);
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

void CCenterMessage::ProcessMsg_RegisterReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GCRegisterReq *pGCRegisterReq = reinterpret_cast<GCRegisterReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pGCRegisterReq)
		return;

	ProcessMsg_RegisterRes(pDataInfo, nDataLen, pPlayerClient->GetIndex(), pGCRegisterReq->nGameServerID);
}

void CCenterMessage::ProcessMsg_RegisterRes(char* pDataInfo, long nDataLen, int nIndex, int nServerId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GCRegisterRes* pGCRegisterRes = reinterpret_cast<GCRegisterRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGCRegisterRes))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(GCRegisterRes);

	pGCRegisterRes->nGameServerID = nServerId;

	sendlen = pPacketHead->GetLength();
	CCenterServer::Instance().SendClientMsg(sendbuf, sendlen, pPacketHead, nIndex, ESGC_PING_GC2S_REGISTER_RES);
}

void CCenterMessage::ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GCHeartBeatReq *pGCHeartBeatReq = reinterpret_cast<GCHeartBeatReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pGCHeartBeatReq)
		return;

	ProcessMsg_HeartBeatRes(pDataInfo, nDataLen, pPlayerClient->GetIndex());
}

void CCenterMessage::ProcessMsg_HeartBeatRes(char* pDataInfo, long nDataLen, int nIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GCHeartBeatRes* pGCHeartBeatRes = reinterpret_cast<GCHeartBeatRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGCHeartBeatRes))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(GCHeartBeatRes);

	sendlen = pPacketHead->GetLength();
	CCenterServer::Instance().SendClientMsg(sendbuf, sendlen, pPacketHead, nIndex, ESGC_PING_GC2S_HEARTBEAT_RES);
}