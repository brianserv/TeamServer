#pragma  once
#ifndef __GAME_CS_MESSAGE_H__
#define __GAME_CS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../../FrameWork/PlayerClient.h"

#include "../../Protocols/CommonProtocol.h"

#include "../../Role/RoleManager.h"
#include "../../../Logic/GameHall/Texas/TexasGame/TexasGameManager.h"

#include "../DBMessage/DBMessage.h"
#include "../DLMessage/DLMessage.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//CLIENT - GATE - GS
class CCSMessage : public CEQ_SingletonT<CCSMessage >
{
public:
	CCSMessage() {};
	virtual ~CCSMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex);
	void ProcessMsg_ClientErrorInfoSync(int nErrorID, int nPlayerIndex, int nGateIndex);
public:
	void ProcessMsg_UserLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_UserLoginRes(UserLoginRes& refUserLoginRes, int nRoleId);
public:
	void ProcessMsg_RoleInfoSync(int nRoleId);
public:
	void ProcessMsg_EnterRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_EnterRoomRes(EnterRoomRes& refEnterRoomRes, int nRoleId);

	void ProcessMsg_LeaveRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_LeaveRoomRes(LeaveRoomRes& refLeaveRoomRes, int nRoleId);

	void ProcessMsg_SitDownReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_SitDownRes(SitDownRes& refSitDownRes, int nRoleId);

	void ProcessMsg_StandUpReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_StandUpRes(StandUpRes& refStandUpRes, int nRoleId);
public:
	void ProcessMsg_GirlChangeSync(GirlChangeSync& refGirlChangeSync, int nRoleId);

	void ProcessMsg_StartGameSync(GameStartSync& refSTGameStartSync, int nRoleId);

	void ProcessMsg_DealCardSync(DealCardSync& refDealCardSync, int nRoleId);

	void ProcessMsg_NoticeBetSync(NoticeBetSync& refNoticeBetSync, int nRoleId);

	void ProcessMsg_BetReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_BetRes(BetRes& refBetRes, int nRoleId);

	void ProcessMsg_FoldReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_FoldRes(FoldRes& refFoldRes, int nRoleId);

	void ProcessMsg_GameSettlementSync(GameSettlementSync& refGameSettlementSync, int nRoleId);

	void ProcessMsg_GirlCancelGameSync(GirlCancelSync& refGirlCancelSync, int nRoleId);

public:
	void ProcessMsg_BetBroadcastSync(BetBroadcastSync& refBetBroadcastSync, int nRoleId);

	void ProcessMsg_BrandBroadcastSync(BrandBroadcastSync& refBrandBroadcastSync, int nRoleId);

	void ProcessMsg_OnlineBroadcastSync(OnlineBroadcastSync& refOnlineBroadcastSync, int nRoleId);

	void ProcessMsg_CardListSync(CardListSync& refCardListSync, int nRoleId);

	void ProcessMsg_RewardPoolSync(RewardPoolSync& refRewardPoolSync, int nRoleId);

	void ProcessMsg_HistoryBoardSync(HistoryBoardInfoSync& refHistoryBoardInfoSync, int nRoleId);

	void ProcessMsg_ReadyLeaveRoomReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_ReadyLeaveRoomRes(ReadyLeaveRoomRes& refReadyLeaveRoomRes, int nRoleId);
};

#endif//__GAME_CS_MESSAGE_H__