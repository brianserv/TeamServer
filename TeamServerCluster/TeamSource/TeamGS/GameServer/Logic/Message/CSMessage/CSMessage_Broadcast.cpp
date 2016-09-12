#include "CSMessage.h"

void  CCSMessage::ProcessMsg_BetBroadcastSync(BetBroadcastSync& refBetBroadcastSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	BetBroadcastSync* pBetBroadcastSync = reinterpret_cast<BetBroadcastSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pBetBroadcastSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}

	pBetBroadcastSync->nRoleID = refBetBroadcastSync.nRoleID;
	pBetBroadcastSync->nBetChips = refBetBroadcastSync.nBetChips;
	memcpy(pBetBroadcastSync->sUserName, refBetBroadcastSync.sUserName, sizeof(pBetBroadcastSync->sUserName));

	pTempPacketHead->SetPacketHead(ECS_BROADCAST_S2GT2C_BET_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());
}

void  CCSMessage::ProcessMsg_BrandBroadcastSync(BrandBroadcastSync& refBrandBroadcastSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	BrandBroadcastSync* pBrandBroadcastSync = reinterpret_cast<BrandBroadcastSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pBrandBroadcastSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}

	pBrandBroadcastSync->nRoleID = refBrandBroadcastSync.nRoleID;
	pBrandBroadcastSync->nGirlID = refBrandBroadcastSync.nGirlID;
	pBrandBroadcastSync->nCardKindType = refBrandBroadcastSync.nCardKindType;

	pTempPacketHead->SetPacketHead(ECS_BROADCAST_S2GT2C_BRAND_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());
}

void  CCSMessage::ProcessMsg_OnlineBroadcastSync(OnlineBroadcastSync& refOnlineBroadcastSync, int nRoleId)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	OnlineBroadcastSync* pOnlineBroadcastSync = reinterpret_cast<OnlineBroadcastSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pOnlineBroadcastSync))
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
	{
		return;
	}

	pOnlineBroadcastSync->nRoleID = refOnlineBroadcastSync.nRoleID;
	memcpy(pOnlineBroadcastSync->sThirdID, refOnlineBroadcastSync.sThirdID, sizeof(pOnlineBroadcastSync->sThirdID));
	memcpy(pOnlineBroadcastSync->sUserName, refOnlineBroadcastSync.sUserName, sizeof(pOnlineBroadcastSync->sUserName));

	pTempPacketHead->SetPacketHead(ECS_BROADCAST_S2GT2C_ONLINE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGameServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead, pRole->GetPlayerIndex(), pRole->GetGateIndex());
}