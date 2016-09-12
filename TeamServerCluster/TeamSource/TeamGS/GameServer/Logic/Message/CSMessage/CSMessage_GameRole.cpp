#include "CSMessage.h"

void CCSMessage::ProcessMsg_RoleInfoSync(int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	RoleInfoSync* pRoleInfoSync = reinterpret_cast<RoleInfoSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pRoleInfoSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(RoleInfoSync);

	pRoleInfoSync->nRoleID = pRole->GetRoleId();
	pRoleInfoSync->nExp = pRole->GetAttrNum(EAttrNum_nExp);
	pRoleInfoSync->nLevel = pRole->GetAttrNum(EAttrNum_nLevel);
	pRoleInfoSync->nUnBindChip = pRole->GetAttrNum(EAttrNum_nUnBindChip);
	pRoleInfoSync->nUnBindPink = pRole->GetAttrNum(EAttrNum_nUnBindPink);
	pRoleInfoSync->nBindChip = pRole->GetAttrNum(EAttrNum_nBindChip);
	pRoleInfoSync->nBindPink = pRole->GetAttrNum(EAttrNum_nBindPink);
	pRoleInfoSync->nMaxPink = pRole->GetAttrNum(EAttrNum_nMaxPink);
	pRoleInfoSync->nMaxChip = pRole->GetAttrNum(EAttrNum_nMaxChip);
	pRoleInfoSync->nVipType = pRole->GetAttrNum(EAttrNum_nVipType);
	pRoleInfoSync->nVipLevel = pRole->GetAttrNum(EAttrNum_nVipLevel);
	pRoleInfoSync->nVipPoints = pRole->GetAttrNum(EAttrNum_nVipPoints);

	pTempPacketHead->SetPacketHead(ECS_ROLE_S2GT2C_ROLEINFO_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"[ClientID:%d|ProtocolID:%d]ProcessMsg_RoleInfoSync !", pRole->GetPlayerIndex(), ECS_ROLE_S2GT2C_ROLEINFO_SYNC);
}