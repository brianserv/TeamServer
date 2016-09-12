#include "DBMessage.h"
#include "../Resource/DBResourceManager.h"

void CDBMessage::ProcessMsg_Load_RoleReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	LoadRoleReq* pLoadRoleReq = reinterpret_cast<LoadRoleReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pLoadRoleReq)
		return;

	ProcessMsg_Load_RoleRes(pDataInfo, nDataLen, pClient, pLoadRoleReq->nRoleId);
}
void CDBMessage::ProcessMsg_Load_RoleRes(char* pDataInfo, long nDataLen, void* pClient, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	LoadRoleRes *pLoadRoleRes = reinterpret_cast<LoadRoleRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pLoadRoleRes))
		return;

	CDBRoleInfo* pDBRoleInfo = CDBResourceManager::Instance().GetDBRoleInfo(nRoleId);
	if (NULL == pDBRoleInfo)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "LoadRoleRes Failure !");
		return;
	}

	pPacketHead->nSize = pPacketHead->GetHeadLength();
	pPacketHead->nSize += sizeof(LoadRoleRes);

	pLoadRoleRes->nRoleId = pDBRoleInfo->get_account_id();
	memcpy(pLoadRoleRes->sRoleName, pDBRoleInfo->get_account_name().c_str(), sizeof(pLoadRoleRes->sRoleName));
	memcpy(pLoadRoleRes->sPassword, pDBRoleInfo->get_account_password().c_str(), sizeof(pLoadRoleRes->sPassword));
	pLoadRoleRes->nPlatformId = pDBRoleInfo->get_account_platform_id();
	memcpy(pLoadRoleRes->sThirdId, pDBRoleInfo->get_account_third_id().c_str(), sizeof(pLoadRoleRes->sThirdId));
	memcpy(pLoadRoleRes->sThirdAccount, pDBRoleInfo->get_account_third_account().c_str(), sizeof(pLoadRoleRes->sThirdAccount));
	pLoadRoleRes->nSex = pDBRoleInfo->get_account_sex();
	pLoadRoleRes->nStatus = pDBRoleInfo->get_account_status();
	memcpy(pLoadRoleRes->sStatusReason, pDBRoleInfo->get_account_status_reason().c_str(), sizeof(pLoadRoleRes->sStatusReason));
	pLoadRoleRes->nLastLoginTime = pDBRoleInfo->get_account_last_login_time();
	pLoadRoleRes->nLoginTimes = pDBRoleInfo->get_account_login_times();
	pLoadRoleRes->nBanTime = pDBRoleInfo->get_account_ban_time();
	pLoadRoleRes->nExp = pDBRoleInfo->get_account_exp();
	pLoadRoleRes->nLevel = pDBRoleInfo->get_account_level();
	pLoadRoleRes->nUnbindChip = pDBRoleInfo->get_account_unbind_chip();
	pLoadRoleRes->nUnbindPink = pDBRoleInfo->get_account_unbind_pink();
	pLoadRoleRes->nBindChip = pDBRoleInfo->get_account_bind_chip();
	pLoadRoleRes->nBindPink = pDBRoleInfo->get_account_bind_pink();
	pLoadRoleRes->nMaxPink = pDBRoleInfo->get_account_max_pink();
	pLoadRoleRes->nMaxChip = pDBRoleInfo->get_account_max_chip();
	pLoadRoleRes->nHighestChip = pDBRoleInfo->get_account_highest_chip();
	pLoadRoleRes->nVipType = pDBRoleInfo->get_account_vip_type();
	pLoadRoleRes->nVipLevel = pDBRoleInfo->get_account_vip_level();
	pLoadRoleRes->nVipPoints = pDBRoleInfo->get_account_vip_points();
	pLoadRoleRes->nWinTimes = pDBRoleInfo->get_account_win_times();
	pLoadRoleRes->nLostTimes = pDBRoleInfo->get_account_lost_times();
	pLoadRoleRes->nDrawTimes = pDBRoleInfo->get_account_draw_times();

	string strdotSplit(",");
	vector<string> strMaxHandCardVec;
	strMaxHandCardVec = PARSE_STRINGS::ParseString::Split(pDBRoleInfo->get_account_max_cardtype(), strdotSplit);

	vector<int> nMaxHandCardVec;
	for (int index = 0; index < 5; index++)
	{
		nMaxHandCardVec.push_back(PARSE_STRINGS::stringToInt(strMaxHandCardVec[index]));
	}

	if (nMaxHandCardVec.size() == 5)
	{
		for (int index = 0; index < 5; index++)
		{
			pLoadRoleRes->sMaxCardType[index] = nMaxHandCardVec[index];
		}
	}

	pLoadRoleRes->nChatStatus = pDBRoleInfo->get_account_chat_status();
	pLoadRoleRes->nGiftSpend = pDBRoleInfo->get_account_gift_spend();
	pLoadRoleRes->nGiftMonth = pDBRoleInfo->get_account_gift_month();

	pPacketHead->SetPacketHead(ESDB_ROLE_DB2S_LOAD_ROLE_ACCOUNT_RES);
	sendlen = pPacketHead->GetLength();
	SendGameServerMsg(sendbuf, sendlen, pPacketHead, pClient);
}

void CDBMessage::ProcessMsg_Save_RoleReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveRoleReq* pSaveRoleReq = reinterpret_cast<SaveRoleReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveRoleReq)
		return;

	string strMaxCardType("");
	string strSplit(",");
	for (int index = 0; index < 5; index++)
	{
		strMaxCardType += PARSE_STRINGS::toString(pSaveRoleReq->sMaxCardType[index]);
		strMaxCardType += strSplit;
	}

	CDBRoleInfo *pDBRoleInfoTemp = NULL;
	CDBRoleInfo *pDBRoleInfo = CDBResourceManager::Instance().GetDBRoleInfo(pSaveRoleReq->nRoleId);
	if (NULL == pDBRoleInfo)
	{
		pDBRoleInfo = new CDBRoleInfo();
		if (NULL == pDBRoleInfo)
			return;

		pDBRoleInfo->SetRoleProperty(
			pSaveRoleReq->nRoleId,
			(string)pSaveRoleReq->sRoleName,
			(string)pSaveRoleReq->sPassword,
			pSaveRoleReq->nPlatformId,
			(string)pSaveRoleReq->sThirdId,
			(string)pSaveRoleReq->sThirdAccount,
			pSaveRoleReq->nSex,
			pSaveRoleReq->nStatus,
			(string)pSaveRoleReq->sStatusReason,
			pSaveRoleReq->nLastLoginTime,
			pSaveRoleReq->nLoginTimes,
			pSaveRoleReq->nBanTime,
			pSaveRoleReq->nExp,
			pSaveRoleReq->nLevel,
			pSaveRoleReq->nUnbindChip,
			pSaveRoleReq->nUnbindPink,
			pSaveRoleReq->nBindChip,
			pSaveRoleReq->nBindPink,
			pSaveRoleReq->nMaxPink,
			pSaveRoleReq->nMaxChip,
			pSaveRoleReq->nHighestChip,
			pSaveRoleReq->nVipType,
			pSaveRoleReq->nVipLevel,
			pSaveRoleReq->nVipPoints,
			pSaveRoleReq->nWinTimes,
			pSaveRoleReq->nLostTimes,
			pSaveRoleReq->nDrawTimes,
			strMaxCardType,
			pSaveRoleReq->nChatStatus,
			pSaveRoleReq->nGiftSpend,
			pSaveRoleReq->nGiftMonth,
			pDBRoleInfo->get_account_create_time());

		if (!CDBResourceManager::Instance().AddDBRoleInfo(pDBRoleInfo))
		{
			SAFE_DELETE(pDBRoleInfo);
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveRoleReq Failure !");
			return;
		}
		if (!g_DBManager[0].SaveRoleInfo(pDBRoleInfo))
		{
			SAFE_DELETE(pDBRoleInfo);
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveRoleReq Failure !");
			return;
		}
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveRoleReq Success !");
		return;
	}
	pDBRoleInfo->SetRoleProperty(
		pSaveRoleReq->nRoleId,
		(string)pSaveRoleReq->sRoleName,
		(string)pSaveRoleReq->sPassword,
		pSaveRoleReq->nPlatformId,
		(string)pSaveRoleReq->sThirdId,
		(string)pSaveRoleReq->sThirdAccount,
		pSaveRoleReq->nSex,
		pSaveRoleReq->nStatus,
		(string)pSaveRoleReq->sStatusReason,
		pSaveRoleReq->nLastLoginTime,
		pSaveRoleReq->nLoginTimes,
		pSaveRoleReq->nBanTime,
		pSaveRoleReq->nExp,
		pSaveRoleReq->nLevel,
		pSaveRoleReq->nUnbindChip,
		pSaveRoleReq->nUnbindPink,
		pSaveRoleReq->nBindChip,
		pSaveRoleReq->nBindPink,
		pSaveRoleReq->nMaxPink,
		pSaveRoleReq->nMaxChip,
		pSaveRoleReq->nHighestChip,
		pSaveRoleReq->nVipType,
		pSaveRoleReq->nVipLevel,
		pSaveRoleReq->nVipPoints,
		pSaveRoleReq->nWinTimes,
		pSaveRoleReq->nLostTimes,
		pSaveRoleReq->nDrawTimes,
		strMaxCardType,
		pSaveRoleReq->nChatStatus,
		pSaveRoleReq->nGiftSpend,
		pSaveRoleReq->nGiftMonth,
		pDBRoleInfo->get_account_create_time());

	if (!g_DBManager[0].SaveRoleInfo(pDBRoleInfo))
	{
		SAFE_DELETE(pDBRoleInfo);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveRoleReq Failure !");
		return;
	}
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveRoleReq Success !");
}