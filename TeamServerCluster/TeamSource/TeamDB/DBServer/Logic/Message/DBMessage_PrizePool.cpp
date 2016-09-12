#include "DBMessage.h"

void CDBMessage::ProcessMsg_Load_PrizePoolReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
	{
		return;
	}

	ProcessMsg_Load_PrizePoolRes(pDataInfo, nDataLen, pClient);
}
void CDBMessage::ProcessMsg_Load_PrizePoolRes(char* pDataInfo, long nDataLen, void* pClient)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	const int nPrizePoolID = 1;
	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadPrizePoolRes* pLoadPrizePoolRes = reinterpret_cast<LoadPrizePoolRes*>(pTemp + sizeof(PACKETHEAD));

	CDBPrizePoolInfo *pDBPrizePoolInfo = CDBResourceManager::Instance().GetDBPrizePoolInfo(nPrizePoolID);
	if ((NULL == pPacketHead) || (NULL == pLoadPrizePoolRes) || (NULL == pDBPrizePoolInfo))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadPrizePoolRes);

	pLoadPrizePoolRes->nTotalValue = pDBPrizePoolInfo->get_prizepool_total_value();
	pLoadPrizePoolRes->nPayValue = pDBPrizePoolInfo->get_prizepool_pay_value();
	pLoadPrizePoolRes->nJackpotBonus_InitValue = pDBPrizePoolInfo->get_prizepool_JackpotBonus_Init();

	pPacketHead->SetPacketHead(ESDB_PRIZEPOOL_DB2S_LOAD_PRIZEPOOL_RES);
	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}

void CDBMessage::ProcessMsg_Save_PrizePoolReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	const int nPrizePoolID = 1;
	SavePrizePoolReq* pSavePrizePoolReq = reinterpret_cast<SavePrizePoolReq*>(pDataInfo + sizeof(PACKETHEAD));

	CDBPrizePoolInfo *pDBPrizePoolInfo = CDBResourceManager::Instance().GetDBPrizePoolInfo(nPrizePoolID);
	if (NULL == pSavePrizePoolReq || NULL == pDBPrizePoolInfo)
		return;

	pDBPrizePoolInfo->setPrizePoolProperty(nPrizePoolID,
		pSavePrizePoolReq->nTotalValue,
		pSavePrizePoolReq->nPayValue,
		pSavePrizePoolReq->nJackpotBonus_InitValue);

	if (!g_DBManager[0].SavePrizePoolInfo(pDBPrizePoolInfo))
	{
		SAFE_DELETE(pDBPrizePoolInfo);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SavePrizePoolReq Failure !");
		return;
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SavePrizePoolReq Success !");
}