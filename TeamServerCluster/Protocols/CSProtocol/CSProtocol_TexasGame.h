#ifndef __CS_PROTOCOL_TEXAS_GAME_H__
#define __CS_PROTOCOL_TEXAS_GAME_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------
// GirlChange Sync
typedef struct tagGirlChangeSync
{
	__UINT32 nRoleID;
	__UINT32 nGirlID;
}GirlChangeSync, *pGirlChangeSync;
//--------------------------------------------------------------------------------------------------

// GameStart Sync
typedef struct tagGameStartSync
{
}GameStartSync, *pGameStartSync;
//--------------------------------------------------------------------------------------------------

// DealCard Sync
typedef struct tagDealCardSync
{
	__UINT32 nRoleID;
	__UINT32 nCardOrderID;
	__UINT32 nCardType;
	__UINT32 nCardValue;
}DealCardSync, *pDealCardSync;
//--------------------------------------------------------------------------------------------------

// NoticeBet Sync
typedef struct tagNoticeBetSync
{
	__UINT32 nRoleID;
	__UINT32 nBetRoundID;
	__UINT32 nBetMaxWaitTime;
}NoticeBetSync, *pNoticeBetSync;
//-------------------------------------------------------------------------------------------------

// Bet Req
typedef struct tagBetReq
{
	__UINT32 nRoleID;
	__UINT32 nBetType;
	__UINT32 nBetJackpotType;
	__UINT32 mBetBonusType;
	__UINT32 nBetChips;
}BetReq, *pBetReq;

// Bet Res
typedef struct tagBetRes
{
	__UINT32 nRoleID;
	__UINT32 nBetRoundID;
	__UINT32 nRemainAnte;
	__UINT32 nBetResult;
}BetRes, *pBetRes;
//-------------------------------------------------------------------------------------------------

// Fold Req
typedef struct tagFoldReq
{
	__UINT32 nRoleID;
}FoldReq, *pFoldReq;

// Fold Res
typedef struct tagFoldRes
{
}FoldRes, *pFoldRes;
//-------------------------------------------------------------------------------------------------

// GameSettlement Sync
typedef struct tagGameSettlementSync
{
	__UINT32 nRoleID;
	__INT32 nLostWinType;
	__UINT32 nRoleCardKindType;
	__UINT32 nGirlCardKindType;
	__INT32  nLostWinChips;
	__UINT32 nJackpotType;
	__UINT32 nBonusType;
	__UINT32 nJackpotRewardValue;
	__UINT32 nBonusRewardValue;
}GameSettlementSync, *pGameSettlementSync;

//-------------------------------------------------------------------------------------------------

//GirlCancel Sync
typedef struct tagGirlCancelSync
{
}GirlCancelSync, *pGirlCancelSync;

//------------------------------------------------------------------------------------------------

//CardListSync
typedef struct tagCardListSync
{
	__UINT32 nRoleID;
	__UINT32 nCardNum;
	__UINT32 nCardListInfo[9];
}CardListSync, *pCardListSync;

//Reward Pool Sync
typedef struct tagRewardPoolSync
{
	__UINT32 nRoleID;
	__UINT32 nCurRewardPool;
}RewardPoolSync, *pRewardPoolSync;

// ReadyLeave Room Req
typedef struct tagReadyLeaveRoomReq
{
	__UINT32 nRoleID;
}ReadyLeaveRoomReq, *pReadyLeaveRoomReq;

// ReadyLeave Room Res
typedef struct tagReadyLeaveRoomRes
{
	__UINT32 nRoleID;
	__UINT32 nRoleStatus;
}ReadyLeaveRoomRes, *pReadyLeaveRoomRes;

//HistoryBoardInfo
typedef struct tagHistoryBoardInfoSync
{
	__UINT32 nRoleID;
	__UINT32 nHistoryBoardNum;
	__UINT32 nHistoryBoardInfo[10];
}HistoryBoardInfoSync, *pHistoryBoardInfoSync;

#pragma pack()

#endif//__CS_PROTOCOL_TEXAS_GAME_H__