#ifndef __SDL_PROTOCOL_PING_H__
#define __SDL_PROTOCOL_PING_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//PING HEARTBEAT REQ
typedef struct tagDLHeartBeatReq
{
}DLHeartBeatReq, *pDLHeartBeatReq;

//PING HEARTBEAT RES
typedef struct tagDLHeartBeatRes
{
}DLHeartBeatRes, *pDLHeartBeatRes;
//--------------------------------------------------------------------------------------------------

//Test Structure Array
typedef struct tagDLTest_SeatRankInfo
{
	__UINT32 nRoleID;
	__CHAR  sThirdID[32];
	__CHAR  sRoleName[32];
	__INT32	nChips;
	__INT32 nJackPot;
	__INT32 nBonus;
	__INT32 nTotalBet;
	__INT32 nGiftID;
}DLTest_SeatRankInfo, *pDLTest_SeatRankInfo;

typedef struct tagDLTest_SeatRankReq
{
	int nCount;
	DLTest_SeatRankInfo Info[6];
}DLTest_SeatRankReq, *pDLTest_SeatRankReq;

#pragma pack()

#endif//__SDL_PROTOCOL_PING_H__