#include "DBMessage.h"

void CDBMessage::ProcessMsg_Load_TexasHistoryBoard10Req(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	LoadTexasHistoryBoard10Req* pLoadTexasHistoryBoard10Req = reinterpret_cast<LoadTexasHistoryBoard10Req*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pLoadTexasHistoryBoard10Req)
		return;

	ProcessMsg_Load_TexasHistoryBoard10Res((char*)pLoadTexasHistoryBoard10Req, nDataLen, pClient, pLoadTexasHistoryBoard10Req->nRoomId);
}
void CDBMessage::ProcessMsg_Load_TexasHistoryBoard10Res(char* pDataInfo, long nDataLen, void* pClient, int nRoomId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadTexasHistoryBoard10Res* pLoadTexasHistoryBoard10Res = reinterpret_cast<LoadTexasHistoryBoard10Res*>(pTemp + sizeof(PACKETHEAD));
	CDBTexasHistoryBoard10Info* pDBTexasHistoryBoard10Info = CDBResourceManager::Instance().GetDBTexasHistoryBoard10Info(nRoomId);
	if ((NULL == pPacketHead) || (NULL == pLoadTexasHistoryBoard10Res) || (NULL == pDBTexasHistoryBoard10Info))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadTexasHistoryBoard10Res);

	pLoadTexasHistoryBoard10Res->nGameId = pDBTexasHistoryBoard10Info->get_board10_game_id();
	pLoadTexasHistoryBoard10Res->nRoomId = pDBTexasHistoryBoard10Info->get_board10_room_id();
	pLoadTexasHistoryBoard10Res->nServerId = pDBTexasHistoryBoard10Info->get_board10_server_id();

	memcpy(pLoadTexasHistoryBoard10Res->sResult, pDBTexasHistoryBoard10Info->get_board10_result_detail().c_str(), sizeof(pLoadTexasHistoryBoard10Res->sResult));

	pLoadTexasHistoryBoard10Res->nBoardCount = pDBTexasHistoryBoard10Info->get_board10_board_count();

	pPacketHead->SetPacketHead(ESDB_TEXASHISTORYBOARD_DB2S_LOAD_TEXASHISTORYBOARD_RES);
	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}

void CDBMessage::ProcessMsg_Save_TexasHistoryBoard10Req(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveTexasHistoryBoard10Req* pSaveTexasHistoryBoard10Req = reinterpret_cast<SaveTexasHistoryBoard10Req*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveTexasHistoryBoard10Req)
		return;

	CDBTexasHistoryBoard10Info* pDBTexasHistoryBoard10Info = new CDBTexasHistoryBoard10Info();
	if (NULL == pDBTexasHistoryBoard10Info)
		return;

	pDBTexasHistoryBoard10Info->setDBTexasHistoryBoard10InfoProperty(
		pSaveTexasHistoryBoard10Req->nGameId,
		pSaveTexasHistoryBoard10Req->nRoomId,
		pSaveTexasHistoryBoard10Req->nServerId,
		(string)pSaveTexasHistoryBoard10Req->sResult,
		pSaveTexasHistoryBoard10Req->nBoardCount);

	if (!g_DBManager[0].SaveTexasHistoryBoard10Info(pDBTexasHistoryBoard10Info))
	{
		SAFE_DELETE(pDBTexasHistoryBoard10Info);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveTexasHistoryBoard10Req Failure !");
		return;
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveTexasHistoryBoard10Req Success !");
}