#include "DBMessage.h"

void  CDBMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case ESDB_ROLE_DB2S_LOAD_ROLE_ACCOUNT_RES:
			ProcessMsg_LoadRoleRes(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case ESDB_PRIZEPOOL_DB2S_LOAD_PRIZEPOOL_RES:
			ProcessMsg_LoadPrizePoolRes(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case ESDB_TEXASBOARD_DB2S_LOAD_TEXASBOARD_RES:
			ProcessMsg_LoadTexasBoardRes(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case ESDB_TEXASHISTORYBOARD_DB2S_LOAD_TEXASHISTORYBOARD_RES:
			ProcessMsg_LoadTexasHistoryBoardRes(pDataInfo, nDataLen, pPacketHead, pClient);
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

void CDBMessage::SendDBMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	CGameServer::Instance().SendDBMsg(pDataInfo, nDataLen, pPacketHead);
}


