#include "DBMessage.h"

void CDBMessage::ProcessMsg_LoadRoleReq(int nRoleID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadRoleReq* pLoadRoleReq = reinterpret_cast<LoadRoleReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pLoadRoleReq))
		return;

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadRoleReq);

	pLoadRoleReq->nRoleId = nRoleID;

	pPacketHead->SetPacketHead(ESDB_ROLE_S2DB_LOAD_ROLE_ACCOUNT_REQ);
	sendlen = pPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pPacketHead);
}

void CDBMessage::ProcessMsg_LoadRoleRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	LoadRoleRes* pLoadRoleRes = reinterpret_cast<LoadRoleRes*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pLoadRoleRes))
		return;

	vector<int> nMaxCardTypeVec;
	for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
	{
		nMaxCardTypeVec.push_back(pLoadRoleRes->sMaxCardType[index]);
	}

	CRoleManager::Instance().UpdateRoleBase(pLoadRoleRes->nRoleId,
		(string)pLoadRoleRes->sRoleName,
		(string)pLoadRoleRes->sPassword,
		pLoadRoleRes->nPlatformId,
		(string)pLoadRoleRes->sThirdId,
		(string)pLoadRoleRes->sThirdAccount,
		pLoadRoleRes->nSex,
		pLoadRoleRes->nStatus,
		(string)pLoadRoleRes->sStatusReason,
		pLoadRoleRes->nLastLoginTime,
		pLoadRoleRes->nLoginTimes,
		pLoadRoleRes->nBanTime,
		pLoadRoleRes->nExp,
		pLoadRoleRes->nLevel,
		pLoadRoleRes->nUnbindChip,
		pLoadRoleRes->nUnbindPink,
		pLoadRoleRes->nBindChip,
		pLoadRoleRes->nBindPink,
		pLoadRoleRes->nMaxPink,
		pLoadRoleRes->nMaxChip,
		pLoadRoleRes->nHighestChip,
		pLoadRoleRes->nVipType,
		pLoadRoleRes->nVipLevel,
		pLoadRoleRes->nVipPoints,
		pLoadRoleRes->nWinTimes,
		pLoadRoleRes->nLostTimes,
		pLoadRoleRes->nDrawTimes,
		nMaxCardTypeVec,
		pLoadRoleRes->nChatStatus,
		pLoadRoleRes->nGiftSpend,
		pLoadRoleRes->nGiftMonth);
}

void CDBMessage::ProcessMsg_SaveRoleReq(int nRoleID)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SaveRoleReq* pSaveRoleReq = reinterpret_cast<SaveRoleReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSaveRoleReq))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleID);
	if (NULL == pRole)
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SaveRoleReq);

	pSaveRoleReq->nRoleId = pRole->GetAttrNum(EAttrNum_nRoleId);

	memcpy(pSaveRoleReq->sRoleName, pRole->GetRoleName().c_str(), sizeof(pSaveRoleReq->sRoleName));
	memcpy(pSaveRoleReq->sPassword, pRole->GetPassword().c_str(), sizeof(pSaveRoleReq->sPassword));

	pSaveRoleReq->nPlatformId = pRole->GetAttrNum(EAttrNum_nPlatformId);

	memcpy(pSaveRoleReq->sThirdId, pRole->GetThirdId().c_str(), sizeof(pSaveRoleReq->sThirdId));

	memcpy(pSaveRoleReq->sThirdAccount, pRole->GetThirdAccount().c_str(), sizeof(pSaveRoleReq->sThirdAccount));

	pSaveRoleReq->nSex = pRole->GetAttrNum(EAttrNum_nSex);
	pSaveRoleReq->nStatus = pRole->GetAttrNum(EAttrNum_nStatus);

	memcpy(pSaveRoleReq->sStatusReason, pRole->GetStatusReason().c_str(), sizeof(pSaveRoleReq->sStatusReason));

	pSaveRoleReq->nLastLoginTime = pRole->GetAttrNum(EAttrNum_nLastLoginTime);
	pSaveRoleReq->nLoginTimes = pRole->GetAttrNum(EAttrNum_nLoginTimes);
	pSaveRoleReq->nBanTime = pRole->GetAttrNum(EAttrNum_nBanTime);
	pSaveRoleReq->nExp = pRole->GetAttrNum(EAttrNum_nExp);
	pSaveRoleReq->nLevel = pRole->GetAttrNum(EAttrNum_nLevel);
	pSaveRoleReq->nUnbindChip = pRole->GetAttrNum(EAttrNum_nUnBindChip);
	pSaveRoleReq->nUnbindPink = pRole->GetAttrNum(EAttrNum_nUnBindPink);
	pSaveRoleReq->nBindChip = pRole->GetAttrNum(EAttrNum_nBindChip);
	pSaveRoleReq->nBindPink = pRole->GetAttrNum(EAttrNum_nBindPink);
	pSaveRoleReq->nMaxPink = pRole->GetAttrNum(EAttrNum_nMaxPink);
	pSaveRoleReq->nMaxChip = pRole->GetAttrNum(EAttrNum_nMaxChip);
	pSaveRoleReq->nHighestChip = pRole->GetAttrNum(EAttrNum_nHighestChip);
	pSaveRoleReq->nVipType = pRole->GetAttrNum(EAttrNum_nVipType);
	pSaveRoleReq->nVipLevel = pRole->GetAttrNum(EAttrNum_nVipLevel);
	pSaveRoleReq->nVipPoints = pRole->GetAttrNum(EAttrNum_nVipPoints);
	pSaveRoleReq->nWinTimes = pRole->GetAttrNum(EAttrNum_nWinTimes);
	pSaveRoleReq->nLostTimes = pRole->GetAttrNum(EAttrNum_nLostTimes);
	pSaveRoleReq->nDrawTimes = pRole->GetAttrNum(EAttrNum_nDrawTimes);

	vector<int> nMaxHandCardVec = pRole->GetMaxCardType();
	if (nMaxHandCardVec.size() == MAX_TEXAS_CENTERCARD_NUM)
	{
		for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
		{
			pSaveRoleReq->sMaxCardType[index] = nMaxHandCardVec[index];
		}
	}

	pSaveRoleReq->nChatStatus = pRole->GetAttrNum(EAttrNum_nChatStatus);
	pSaveRoleReq->nGiftSpend = pRole->GetAttrNum(EAttrNum_nGiftSpend);
	pSaveRoleReq->nGiftMonth = pRole->GetAttrNum(EAttrNum_nGiftSpendMonth);

	pTempPacketHead->SetPacketHead(ESDB_ROLE_S2DB_SAVE_ROLE_ACCOUNT_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBMsg(sendbuf, sendlen, pTempPacketHead);
}