#include "GameMessage.h"

#include "CSMessage/CSMessage.h"
#include "GSMessage/GSMessage.h"
#include "PSMessage/PSMessage.h"
#include "DBMessage/DBMessage.h"
#include "DLMessage/DLMessage.h"
#include "GTMessage/GTMessage.h"
#include "GCMessage/GCMessage.h"

#include  "HGSMessage/HGSMessage.h"
#include  "WSSMessage/WSSMessage.h"

void  CGameMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		if ((pTempPacketHead->nCmd > ESGC_BEGIN) && (pTempPacketHead->nCmd < ESGC_END))
		{
			ProcessMsg_CenterMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > ESGT_BEGIN) && (pTempPacketHead->nCmd < ESGT_END))
		{
			ProcessMsg_GateMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EHGS_BEGIN) && (pTempPacketHead->nCmd < EHGS_END))
		{
			ProcessMsg_HGSMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EWSS_BEGIN) && (pTempPacketHead->nCmd < EWSS_END))
		{
			ProcessMsg_WSSMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > ECS_BEGIN) && (pTempPacketHead->nCmd < ECS_END))
		{
			ProcessMsg_Web_Mobile_Client(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EGS_BEGIN) && (pTempPacketHead->nCmd < EGS_END))
		{
			ProcessMsg_NetGirlClient(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > EPS_BEGIN) && (pTempPacketHead->nCmd < EPS_END))
		{
			ProcessMsg_PlatformClient(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > ESDB_BEGIN) && (pTempPacketHead->nCmd < ESDB_END))
		{
			ProcessMsg_DBClient(pDataInfo, nDataLen, pPacketHead, pClient);
		}
		else if ((pTempPacketHead->nCmd > ESDL_BEGIN) && (pTempPacketHead->nCmd < ESDL_END))
		{
			ProcessMsg_DLClient(pDataInfo, nDataLen, pPacketHead, pClient);
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

void CGameMessage::ProcessMsg_CenterMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CGCMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void CGameMessage::ProcessMsg_GateMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CGTMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGameMessage::ProcessMsg_Web_Mobile_Client(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CCSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGameMessage::ProcessMsg_NetGirlClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CGSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGameMessage::ProcessMsg_PlatformClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGameMessage::ProcessMsg_DBClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CDBMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

void  CGameMessage::ProcessMsg_DLClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CDLMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGameMessage::ProcessMsg_HGSMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CHGSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}
void CGameMessage::ProcessMsg_WSSMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CWSSMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
}