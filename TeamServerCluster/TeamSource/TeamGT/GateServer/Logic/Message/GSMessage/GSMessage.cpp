#include "GSMessage.h"

void  CGSMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case EGS_PING_G2GT_HEARTBEAT_REQ:
			ProcessMsg_HeartBeatReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EGS_LOGIN_G2GT2S_GIRLLOGIN_REQ:
			ProcessMsg_GirlLoginReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		default:
			ProcessMsg_TransferGirlClientMsg(pDataInfo, nDataLen, pPacketHead);
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGateMessage::CGSMessage Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CGSMessage::ProcessMsg_GirlClientErrorSync(int nErrorID, int nPlayerIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSErrorInfoSync* pGSErrorInfoSync = reinterpret_cast<GSErrorInfoSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pGSErrorInfoSync))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(GSErrorInfoSync);

	pGSErrorInfoSync->nErrorID = nErrorID;

	pTempPacketHead->SetPacketHead(EGS_ERROR_S2GT2G_ERRORCODE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGateServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead->GetIndex());
}

void CGSMessage::ProcessMsg_TransferGirlClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	CGateServer::Instance().SendGameServerMsg(pDataInfo, nDataLen, pPacketHead);
}

void CGSMessage::ProcessMsg_OnDisconnect(int nIndex)
{
	if (nIndex >= 0)
	{
		CPlayerClient* pPlayerClient = reinterpret_cast<CPlayerClient*>(CGateServer::Instance().m_PlayerClientInfoVec[nIndex]->GetClient());
		if (NULL == pPlayerClient)
		{
			return;
		}
		pPlayerClient->OnDisconnect(0);
	}
}