#ifndef __PS_PROTOCOL_TEXAS_VIPROOM_H__
#define __PS_PROTOCOL_TEXAS_VIPROOM_H__

#include "EQ_DataType.h"

#pragma pack(1)

//VipRoom_CreateReq
typedef struct tagVipRoom_CreateReq
{
	__UINT32 nRoomId;
	__UINT32 nRoomOwnerAccountId;
	__UINT32 nRoomMaxCapacity;
	__UINT32 nEnterRoomChipLimit;
	__UINT32 nBetAnteLimit;
	__UINT32 nDealModeType;
	__UINT32 nUseChipCurrencyType;
	__UINT32 nVipPalyersStacks;
	__UINT32 nRoomIncome;
}VipRoom_CreateReq, *pVipRoom_CreateReq;

//VipRoom_ReleaseReq
typedef struct tagVipRoom_ReleaseReq
{
	__UINT32 nRoomId;
}VipRoom_ReleaseReq, *pVipRoom_ReleaseReq;

//VipRoom_AppendChipReq
typedef struct tagVipRoom_AppendChipReq
{
	__UINT32 nRoomId;
	__UINT32 nAppendUnbindChip;
}VipRoom_AppendChipReq, *pVipRoom_AppendChipReq;

#pragma pack()

#endif//__PS_PROTOCOL_TEXAS_VIPROOM_H__
