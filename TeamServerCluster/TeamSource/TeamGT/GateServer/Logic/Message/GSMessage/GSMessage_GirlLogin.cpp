#include "GSMessage.h"

void CGSMessage::ProcessMsg_GirlLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GSLoginReq* pGirlLoginReq = reinterpret_cast<GSLoginReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pGirlLoginReq))
		return;

	if (!CGirlManager::Instance().CheckGirlName((int&)pGirlLoginReq->nGirlID, pGirlLoginReq->sGirlName, pGirlLoginReq->sGirlPassword))
	{
		ProcessMsg_GirlClientErrorSync(EGERT_LOGIN_USERNAMEPASSWORD_ERROR, pPlayerClient->GetIndex());
		return;
	}

	CGirl* pGirl = CGirlManager::Instance().GetGirl(pGirlLoginReq->nGirlID);
	if (NULL == pGirl)
		return;

	// ReLogin Check
	if (pGirl->getIsUsed())
	{
		ProcessMsg_OnDisconnect(pGirl->GetPlayerIndex());
	}

	GSLoginRes refGSLoginRes;
	refGSLoginRes.nGirlID = pGirlLoginReq->nGirlID;
	ProcessMsg_GirlLoginRes(refGSLoginRes, pPlayerClient->GetIndex());

	pPlayerClient->SetGirl();
	pPlayerClient->SetGirlId(pGirlLoginReq->nGirlID);
	pTempPacketHead->SetIndex(pPlayerClient->GetIndex());

	pGirl->setIsUsed(true);
	pGirl->setPlayerIndex(pTempPacketHead->GetIndex());

	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHeadEx = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSLoginReq* pGirlLoginReqEx = reinterpret_cast<GSLoginReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHeadEx) || (NULL == pGirlLoginReqEx))
		return;

	pTempPacketHeadEx->nSize = pTempPacketHeadEx->GetHeadLength();
	pTempPacketHeadEx->nSize += sizeof(GSLoginReq);

	pGirlLoginReqEx->nRoomID = pGirlLoginReq->nRoomID;
	pGirlLoginReqEx->nGirlID = pGirlLoginReq->nGirlID;
	pGirlLoginReqEx->nGirlRoleID = pGirl->getGirlRoleId();
	memcpy(pGirlLoginReqEx->sGirlName, pGirl->getGirlName().c_str(), sizeof(pGirlLoginReqEx->sGirlName));
	memcpy(pGirlLoginReqEx->sGirlPassword, pGirl->getPassword().c_str(), sizeof(pGirlLoginReqEx->sGirlPassword));
	memcpy(pGirlLoginReqEx->sGirlThirdId, pGirl->getThirdId().c_str(), sizeof(pGirlLoginReqEx->sGirlThirdId));

	pTempPacketHeadEx->SetIndex(pTempPacketHead->GetIndex());
	pTempPacketHeadEx->SetPacketHead(EGS_LOGIN_G2GT2S_GIRLLOGIN_REQ);

	sendlen = pTempPacketHeadEx->GetLength();

	ProcessMsg_TransferGirlClientMsg(sendbuf, sendlen, pTempPacketHeadEx);
}

void CGSMessage::ProcessMsg_GirlLoginRes(GSLoginRes refGSLoginRes, int nIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GSLoginRes* pGSLoginRes = reinterpret_cast<GSLoginRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGSLoginRes))
		return;

	pGSLoginRes->nGirlID = refGSLoginRes.nGirlID;

	pPacketHead->SetIndex(nIndex);
	pPacketHead->SetPacketHead(EGS_LOGIN_S2GT2G_GIRLLOGIN_RES);
	sendlen = pPacketHead->GetLength();

	CGateServer::Instance().SendClientMsg(sendbuf, sendlen, nIndex);
}