#ifndef __CS_PROTOCOL_BROADCAST_H__
#define __CS_PROTOCOL_BROADCAST_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------
// BetBroadcastSync
typedef struct tagBetBroadcastSync
{
	__UINT32 nRoleID;
	__UINT32 nBetChips;
	__CHAR sUserName[32];
}BetBroadcastSync, *pBetBroadcastSync;
//--------------------------------------------------------------------------------------------------

// BrandBroadcastSync
typedef struct tagBrandBroadcastSync
{
	__UINT32 nRoleID;
	__UINT32 nGirlID;
	__UINT32 nCardKindType;
}BrandBroadcastSync, *pBrandBroadcastSync;
//--------------------------------------------------------------------------------------------------

// OnlineBroadcastSync
typedef struct tagOnlineBroadcastSync
{
	__UINT32 nRoleID;
	__CHAR sThirdID[32];
	__CHAR sUserName[32];
}OnlineBroadcastSync, *pOnlineBroadcastSync;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__CS_PROTOCOL_BROADCAST_H__