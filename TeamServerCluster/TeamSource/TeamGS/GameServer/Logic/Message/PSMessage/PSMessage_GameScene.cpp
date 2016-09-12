#include "PSMessage.h"
#include "../../../Logic/GameHall/GameHall.h"
#include "../../../Logic/Httplink/HttpLinkEvent.h"

void CPSMessage::ProcessMsg_VipRoom_Create_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	VipRoom_CreateReq* pVipRoom_CreateReq = reinterpret_cast<VipRoom_CreateReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pVipRoom_CreateReq))
		return;

	TexasRoomVip refTexasRoomVip;
	refTexasRoomVip.nRoomId = pVipRoom_CreateReq->nRoomId;
	refTexasRoomVip.nRoomOwnerAccountId = pVipRoom_CreateReq->nRoomOwnerAccountId;
	refTexasRoomVip.nRoomMaxCapacity = pVipRoom_CreateReq->nRoomMaxCapacity;
	refTexasRoomVip.nEnterRoomChipLimit = pVipRoom_CreateReq->nEnterRoomChipLimit;
	refTexasRoomVip.nBetAnteLimit = pVipRoom_CreateReq->nBetAnteLimit;
	refTexasRoomVip.nDealModeType = pVipRoom_CreateReq->nDealModeType;
	refTexasRoomVip.nUseChipCurrencyType = pVipRoom_CreateReq->nUseChipCurrencyType;
	refTexasRoomVip.nVipPalyersStacks = pVipRoom_CreateReq->nVipPalyersStacks;
	refTexasRoomVip.nRoomIncome = pVipRoom_CreateReq->nRoomIncome;

	if (!CGameHall::Instance().Create_Vip_TexasGame(refTexasRoomVip))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[AccountID:%d|ProtocolID:%d]ProcessMsg_VipRoom_Create_Req Failure!",
			refTexasRoomVip.nRoomOwnerAccountId, EPS_VIPROOM_P2GT2S_CREATE_REQ);
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[AccountID:%d|ProtocolID:%d]ProcessMsg_VipRoom_Create_Req Success!",
			refTexasRoomVip.nRoomOwnerAccountId, EPS_VIPROOM_P2GT2S_CREATE_REQ);

		// HTTPLink CerateVipRoom Success
		CHttpLinkEvent::Instance().ProcessEvent_Request_MsgRegister(EPType_FB, EFB_HEType_V5_CreateVipRoomRes,
			refTexasRoomVip.nRoomOwnerAccountId, refTexasRoomVip.nRoomId, 0);
	}
}
void CPSMessage::ProcessMsg_VipRoom_Release_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	VipRoom_ReleaseReq* pVipRoom_ReleaseReq = reinterpret_cast<VipRoom_ReleaseReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pVipRoom_ReleaseReq))
		return;

	if (!CGameHall::Instance().Release_Vip_TexasGame(pVipRoom_ReleaseReq->nRoomId))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[RoomId:%d|ProtocolID:%d]ProcessMsg_VipRoom_Release_Req Failure!",
			pVipRoom_ReleaseReq->nRoomId, EPS_VIPROOM_P2GT2S_RELEASE_REQ);
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[RoomId:%d|ProtocolID:%d]ProcessMsg_VipRoom_Release_Req Success!",
			pVipRoom_ReleaseReq->nRoomId, EPS_VIPROOM_P2GT2S_RELEASE_REQ);
	}
}
void CPSMessage::ProcessMsg_VipRoom_AppendChip_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	VipRoom_AppendChipReq* pVipRoom_AppendChipReq = reinterpret_cast<VipRoom_AppendChipReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pVipRoom_AppendChipReq))
		return;
	if (!CGameHall::Instance().Supplementary_Vip_TexasGame_Chip(pVipRoom_AppendChipReq->nRoomId,
		pVipRoom_AppendChipReq->nAppendUnbindChip))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[RoomId:%d|ProtocolID:%d]ProcessMsg_VipRoom_AppendChip_Req Failure!",
			pVipRoom_AppendChipReq->nRoomId, EPS_VIPROOM_P2GT2S_APPENDCHIP_REQ);
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			"[RoomId:%d|ProtocolID:%d]ProcessMsg_VipRoom_AppendChip_Req Success!",
			pVipRoom_AppendChipReq->nRoomId, EPS_VIPROOM_P2GT2S_APPENDCHIP_REQ);
	}
}