#include "GateMessage.h"

#include "CSMessage/CSMessage.h"
#include "GSMessage/GSMessage.h"
#include "PSMessage/PSMessage.h"

void  CGateMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		switch ((int)pTempPacketHead->nCmd)
		{
		case ECS_BEGIN + 1:
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CGateMessage::Web/ios/Androw Client HeartBeat Cmd : %ld", pTempPacketHead->nCmd);
			break;
		case EGS_BEGIN + 1:
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CGateMessage::Girl Client HeartBeat Cmd : %ld", pTempPacketHead->nCmd);
			break;
		case EPS_BEGIN + 1:
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CGateMessage::Web Platform HeartBeat Cmd : %ld", pTempPacketHead->nCmd);
			break;
		}

		if (((int)pTempPacketHead->nCmd > ECS_BEGIN) && (pTempPacketHead->nCmd < EGS_BEGIN))
		{
			ProcessMsg_Web_Mobile_Client(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EGS_BEGIN) && (pTempPacketHead->nCmd < EPS_BEGIN))
		{
			ProcessMsg_NetGirlClient(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EPS_BEGIN) && (pTempPacketHead->nCmd < ESDB_BEGIN))
		{
			ProcessMsg_PlatformClient(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "CGateMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CCenterMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void  CGateMessage::ProcessMsg_Web_Mobile_Client(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CCSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGateMessage::ProcessMsg_NetGirlClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CGSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGateMessage::ProcessMsg_PlatformClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}