#ifndef __SDL_PROTOCOL_BET_H__
#define __SDL_PROTOCOL_BET_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE BET REQ
typedef struct tagSaveBetReq
{
	__UINT32	nBoardId;
	__UINT32	nRoleId;
	__UINT32	nGameType;
	__UINT32	nGameId;
	__UINT32	nRoomId;
	__UINT32	nGirlId;
	__UINT32	nJackpot;
	__UINT32	nBonus;
	__CHAR		sJackpotDetail[32];
	__CHAR		sBonusDetail[32];
	__UINT32	nAnte;
	__UINT32	nFlop;
	__CHAR		sSumChipDetail[32];
	__CHAR		sChipDetail[32];
	__INT32	    nWinChip;
	__UINT32	nRewardBonus;
	__UINT32	nRewardJackpot;
	__UINT32	nTea;
	__UINT32	nServerId;
	__CHAR		sWinChipDetail[32];
	__CHAR		sBeforeChipDetail[32];
	__CHAR      sAfterChipDetail[32];
	__INT32     nTotalAmount;
}SaveBetReq, *pSaveBetReq;

//SAVE BET RES
typedef struct tagSaveBetRes
{
	__UINT32 nSaveStatus;
}SaveBetRes, *pSaveBetRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_BET_H__