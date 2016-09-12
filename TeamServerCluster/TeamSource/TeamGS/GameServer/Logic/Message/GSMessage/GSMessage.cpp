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
		case EGS_LOGIN_G2GT2S_GIRLLOGIN_REQ:
			ProcessMsg_GirlLoginReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EGS_TEXASGAME_G2GT2S_GAMESTART_REQ:
			ProcessMsg_GameStartReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EGS_TEXASGAME_G2GT2S_DEALCARD_REQ:
			ProcessMsg_DealCardReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case EGS_TEXASGAME_G2GT2S_GAMECANCEL_REQ:
			ProcessMsg_GameCancelReq(pDataInfo, nDataLen, pPacketHead, pClient);
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

void CGSMessage::SendGirlClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex)
{
	CGameServer::Instance().SendClientMsg(pDataInfo, nDataLen, pPacketHead, nPlayerIndex, nGateIndex);
}

void  CGSMessage::ProcessMsg_GirlClientErrorSync(int nErrorID, int nPlayerIndex, int nGateIndex)
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

	pGSErrorInfoSync->nErrorID = nErrorID;

	pTempPacketHead->SetPacketHead(EGS_ERROR_S2GT2G_ERRORCODE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	SendGirlClientMsg(sendbuf, sendlen, pTempPacketHead, nPlayerIndex, nGateIndex);
}