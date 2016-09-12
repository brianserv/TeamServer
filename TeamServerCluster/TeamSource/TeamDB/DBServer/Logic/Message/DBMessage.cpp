#include "DBMessage.h"

void  CDBMessage::ProcessMsg(char*   pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
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
		case ESDB_PING_S2DB_HEARTBEAT_REQ:
			ProcessMsg_Ping_HeartBeatReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_ROLE_S2DB_LOAD_ROLE_ACCOUNT_REQ:
			ProcessMsg_Load_RoleReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_ROLE_S2DB_SAVE_ROLE_ACCOUNT_REQ:
			ProcessMsg_Save_RoleReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_PRIZEPOOL_S2DB_LOAD_PRIZEPOOL_REQ:
			ProcessMsg_Load_PrizePoolReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_PRIZEPOOL_S2DB_SAVE_PRIZEPOOL_REQ:
			ProcessMsg_Save_PrizePoolReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_TEXASBOARD_S2DB_LOAD_TEXASBOARD_REQ:
			ProcessMsg_Load_TexasBoardReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_TEXASBOARD_S2DB_SAVE_TEXASBOARD_REQ:
			ProcessMsg_Save_TexasBoardReq(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_TEXASHISTORYBOARD_S2DB_LOAD_TEXASHISTORYBOARD_REQ:
			ProcessMsg_Load_TexasHistoryBoard10Req(pDataInfo, nDataLen, pClient);
			break;
		case ESDB_TEXASHISTORYBOARD_S2DB_SAVE_TEXASHISTORYBOARD_REQ:
			ProcessMsg_Save_TexasHistoryBoard10Req(pDataInfo, nDataLen, pClient);
			break;

		default:
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CDBMessage::SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	CPlayerClient* pPlayerClient = (CPlayerClient*)(pClient);
	if (NULL == pTempPacketHead || NULL == pClient)
	{
		return;
	}
	pPlayerClient->PostMessage(pDataInfo, nDataLen);
}