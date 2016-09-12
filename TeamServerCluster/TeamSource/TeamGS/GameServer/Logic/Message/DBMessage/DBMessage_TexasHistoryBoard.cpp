#include "DBMessage.h"

void CDBMessage::ProcessMsg_LoadTexasHistoryBoardReq(LoadTexasHistoryBoard10Req& refLoadTexasHistoryBoard10Req)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadTexasHistoryBoard10Req* pLoadTexasHistoryBoard10Req = reinterpret_cast<LoadTexasHistoryBoard10Req*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadTexasHistoryBoard10Req))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(LoadTexasHistoryBoard10Req);

	pLoadTexasHistoryBoard10Req->nRoomId = refLoadTexasHistoryBoard10Req.nRoomId;

	pTempPacketHead->SetPacketHead(ESDB_TEXASHISTORYBOARD_S2DB_LOAD_TEXASHISTORYBOARD_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}

void CDBMessage::ProcessMsg_LoadTexasHistoryBoardRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	LoadTexasHistoryBoard10Res* pLoadTexasHistoryBoard10Res = reinterpret_cast<LoadTexasHistoryBoard10Res*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadTexasHistoryBoard10Res))
		return;

	string strdotSplit(",");
	vector<string> strHistoryBoard10Vec;
	strHistoryBoard10Vec = PARSE_STRINGS::ParseString::Split(pLoadTexasHistoryBoard10Res->sResult, strdotSplit);

	vector<int> refHistoryWinVec;
	for (int index = 0; index < MAX_TEXAS_HISTORYBOARD_NUM; index++)
	{
		refHistoryWinVec.push_back(PARSE_STRINGS::stringToInt(strHistoryBoard10Vec[index]));
	}

	CTexasGameManager::Instance().SetTexasHistoryWin(pLoadTexasHistoryBoard10Res->nRoomId, refHistoryWinVec);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " CDBMessage::Load TexasHistoryBoard Success !!!");
}

void CDBMessage::ProcessMsg_SaveTexasHistoryBoardReq(SaveTexasHistoryBoard10Req& refSaveTexasHistoryBoard10Req)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SaveTexasHistoryBoard10Req* pSaveTexasHistoryBoard10Req = reinterpret_cast<SaveTexasHistoryBoard10Req*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSaveTexasHistoryBoard10Req))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SaveTexasHistoryBoard10Req);

	pSaveTexasHistoryBoard10Req->nGameId = refSaveTexasHistoryBoard10Req.nGameId;
	pSaveTexasHistoryBoard10Req->nRoomId = refSaveTexasHistoryBoard10Req.nRoomId;
	pSaveTexasHistoryBoard10Req->nServerId = refSaveTexasHistoryBoard10Req.nServerId;

	memcpy(pSaveTexasHistoryBoard10Req->sResult, refSaveTexasHistoryBoard10Req.sResult, sizeof(pSaveTexasHistoryBoard10Req->sResult));

	pSaveTexasHistoryBoard10Req->nBoardCount = refSaveTexasHistoryBoard10Req.nBoardCount;

	pTempPacketHead->SetPacketHead(ESDB_TEXASHISTORYBOARD_S2DB_SAVE_TEXASHISTORYBOARD_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}