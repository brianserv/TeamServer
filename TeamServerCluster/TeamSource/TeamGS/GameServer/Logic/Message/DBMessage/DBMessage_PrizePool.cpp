#include "DBMessage.h"

#include "../../../Logic/PrizePool/PrizePool.h"
#include "../../../../../TeamHS/HallServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.h"

void CDBMessage::ProcessMsg_LoadPrizePoolReq()
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadPrizePoolReq* pLoadPrizePoolReq = reinterpret_cast<LoadPrizePoolReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadPrizePoolReq))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(LoadPrizePoolReq);

	pTempPacketHead->SetPacketHead(ESDB_PRIZEPOOL_S2DB_LOAD_PRIZEPOOL_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}

void CDBMessage::ProcessMsg_LoadPrizePoolRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	LoadPrizePoolRes* pLoadPrizePoolRes = reinterpret_cast<LoadPrizePoolRes*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadPrizePoolRes))
		return;

	CPrizePoolManager::Instance().SetTotalValue(pLoadPrizePoolRes->nTotalValue);
	CPrizePoolManager::Instance().SetPayValue(pLoadPrizePoolRes->nPayValue);
	CPrizePoolManager::Instance().SetJackpotBonus_InitValue(pLoadPrizePoolRes->nJackpotBonus_InitValue);

	g_PrizePool = true;

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, " CDBMessage::Load PrizePool Success !!!");

	vector<int> nRefGameRoomIdVec = CTexasGameManager::Instance().GetGameRoomIdVec();

	{
		LoadTexasBoardReq refLoadTexasBoardReq;
		refLoadTexasBoardReq.nServerId = CGameServer::Instance().GetServerId();
		DBHallEntityMAP& refDBHallEntityMAP = CDBHallEntityManager::Instance().GetDBHallEntityMap();
		DBHallEntityMAP::iterator it = refDBHallEntityMAP.begin();
		DBHallEntityMAP::iterator it_end = refDBHallEntityMAP.end();
		for (; it != it_end; ++it)
		{
			refLoadTexasBoardReq.nRoomId = (it->first);
			ProcessMsg_LoadTexasBoardReq(refLoadTexasBoardReq);
		}
	}

	{
		LoadTexasHistoryBoard10Req refLoadTexasHistoryBoard10Req;
		DBHallEntityMAP& refDBHallEntityMAP = CDBHallEntityManager::Instance().GetDBHallEntityMap();
		DBHallEntityMAP::iterator itEx = refDBHallEntityMAP.begin();
		DBHallEntityMAP::iterator itEx_end = refDBHallEntityMAP.end();
		for (; itEx != itEx_end; ++itEx)
		{
			refLoadTexasHistoryBoard10Req.nRoomId = (itEx->first);
			ProcessMsg_LoadTexasHistoryBoardReq(refLoadTexasHistoryBoard10Req);
		}
	}
}

void CDBMessage::ProcessMsg_SavePrizePoolReq()
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SavePrizePoolReq* pSavePrizePoolReq = reinterpret_cast<SavePrizePoolReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSavePrizePoolReq))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SavePrizePoolReq);

	pSavePrizePoolReq->nTotalValue = CPrizePoolManager::Instance().GetTotalValue();
	pSavePrizePoolReq->nPayValue = CPrizePoolManager::Instance().GetPayValue();
	pSavePrizePoolReq->nJackpotBonus_InitValue = CPrizePoolManager::Instance().GetJackpotBonus_InitValue();

	pTempPacketHead->SetPacketHead(ESDB_PRIZEPOOL_S2DB_SAVE_PRIZEPOOL_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}