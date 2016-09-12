#include "GTMessage.h"

void CGTMessage::ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GTHeartBeatReq *pGTHeartBeatReq = reinterpret_cast<GTHeartBeatReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pGTHeartBeatReq)
		return;

	ProcessMsg_Ping_HeartBeatRes(pDataInfo, nDataLen, pTempPacketHead->GetIndex(), pPlayerClient->GetIndex());
}

void CGTMessage::ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, int nPlayerIndex, int nGateIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GTHeartBeatRes* pGTHeartBeatRes = reinterpret_cast<GTHeartBeatRes*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGTHeartBeatRes))
		return;

	pPacketHead->SetPacketHead(ESGT_PING_S2GT_HEARTBEAT_RES);

	sendlen = pPacketHead->GetLength();
	SendGateMsg(sendbuf, sendlen, pPacketHead, nPlayerIndex, nGateIndex);
}

void  CGTMessage::ProcessMsg_Ping_Role_DissconnectSync(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GTRoleDissconnectSync *pGTRoleDissconnectSync = reinterpret_cast<GTRoleDissconnectSync*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPlayerClient || NULL == pPacketHead || NULL == pGTRoleDissconnectSync)
		return;

	CRole* pRole = CRoleManager::Instance().GetRole(pGTRoleDissconnectSync->nRoleID);
	if (NULL == pRole)
	{
		return;
	}

	CDBMessage::Instance().ProcessMsg_SaveRoleReq(pGTRoleDissconnectSync->nRoleID);
	CDLMessage::Instance().ProcessMsg_SaveLogOutReq(pGTRoleDissconnectSync->nRoleID, pPlayerClient->GetPeerNetAddr2());

	CTexasRoomManager::Instance().Role_LeaveRoom(pRole->GetRoomId(), pRole->GetRoleId());
	CRoleManager::Instance().SetDeleteRole(pGTRoleDissconnectSync->nRoleID);
}

void  CGTMessage::ProcessMsg_Ping_Girl_DissconnectSync(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;
	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	GTGirlDissconnectSync *pGTGirlDissconnectSync = reinterpret_cast<GTGirlDissconnectSync*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pPacketHead || NULL == pGTGirlDissconnectSync)
		return;

	CGirl* pGirl = CGirlManager::Instance().GetGirl(pGTGirlDissconnectSync->nGirlID);
	if (NULL != pGirl)
	{
		CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pGirl->getRoomID());
		if (NULL == pTexasGame)
		{
			return;
		}
		pTexasGame->GirlEndGame();
		pTexasGame->GirlLeaveGame(pGirl->getGirlId());

		if (!CGirlManager::Instance().LeaveRooom(pGirl->getGirlId(), pGirl->getGameType(), pGirl->getRoomID()))
			return;

		if (!CTexasRoomManager::Instance().Girl_LeaveRoom(pGirl->getRoomID(), pGirl->getGirlId()))
			return;
	}
}