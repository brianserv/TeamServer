#include "DBMessage.h"

void CDBMessage::ProcessMsg_Load_TexasBoardReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	LoadTexasBoardReq* pLoadTexasBoardReq = reinterpret_cast<LoadTexasBoardReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pLoadTexasBoardReq)
		return;

	int nBoardID = 0;
	nBoardID = CDBResourceManager::Instance().GetDBTexasBoardInfo_BoardID(pLoadTexasBoardReq->nServerId, pLoadTexasBoardReq->nRoomId);

	ProcessMsg_Load_TexasBoardRes(pDataInfo, nDataLen, pClient, nBoardID, pLoadTexasBoardReq->nRoomId);
}
void CDBMessage::ProcessMsg_Load_TexasBoardRes(char* pDataInfo, long nDataLen, void* pClient, int nBoardID, int nRoomID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* ptemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(ptemp);
	LoadTexasBoardRes* pLoadTexasBoardRes = reinterpret_cast<LoadTexasBoardRes*>(ptemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pLoadTexasBoardRes))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadTexasBoardRes);

	pLoadTexasBoardRes->nBoardId = nBoardID;
	pLoadTexasBoardRes->nRoomId = nRoomID;

	pPacketHead->SetPacketHead(ESDB_TEXASBOARD_DB2S_LOAD_TEXASBOARD_RES);
	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}

void CDBMessage::ProcessMsg_Save_TexasBoardReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveTexasBoardReq* pSaveTexasBoardReq = reinterpret_cast<SaveTexasBoardReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveTexasBoardReq)
		return;

	CDBTexasBoardInfo* pDBTexasBoardInfo = new CDBTexasBoardInfo();
	if (NULL == pDBTexasBoardInfo)
	{
		return;
	}
	pDBTexasBoardInfo->SetTexasBoardProperty(
		pSaveTexasBoardReq->nBoardId,
		pSaveTexasBoardReq->nGirlId,
		(string)pSaveTexasBoardReq->strCard,
		(string)pSaveTexasBoardReq->strShowCard,
		pSaveTexasBoardReq->nServerId,
		pSaveTexasBoardReq->nGameId,
		pSaveTexasBoardReq->nRoomId,
		pSaveTexasBoardReq->nSumChip,
		pSaveTexasBoardReq->nRewardJackpotType,
		pSaveTexasBoardReq->nRewardBonusType,
		pSaveTexasBoardReq->nCardType,
		pSaveTexasBoardReq->nDealcardType,
		pSaveTexasBoardReq->nResult,
		pSaveTexasBoardReq->nEndStatus,
		pSaveTexasBoardReq->nStartTime,
		pSaveTexasBoardReq->nEndTime);

	if (!g_DBManager[0].SaveTexasBoardInfo(pDBTexasBoardInfo))
	{
		SAFE_DELETE(pDBTexasBoardInfo);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveTexasBoardReq Failure !");
		return;
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveTexasBoardReq Success !");
}