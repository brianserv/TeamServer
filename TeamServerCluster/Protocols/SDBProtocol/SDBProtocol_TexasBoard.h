#ifndef __SDB_PROTOCOL_TEXAS_BOARD_H__
#define __SDB_PROTOCOL_TEXAS_BOARD_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

// LOAD TEXAS_BOARD REQ
typedef struct tagLoadTexasBoardReq
{
	__UINT32	nServerId;
	__UINT32	nRoomId;
}LoadTexasBoardReq, *pLoadTexasBoardReq;

// LOAD TEXAS_BOARD  RES
typedef struct tagLoadTexasBoardRes
{
	__UINT32  nRoomId;
	__UINT32  nBoardId;
}LoadTexasBoardRes, *pLoadTexasBoardRes;
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

// SAVE TEXAS_BOARD REQ
typedef struct tagSaveTexasBoardReq
{
	__UINT32    nBoardId;
	__UINT32	nGirlId;
	__CHAR		strCard[32];
	__CHAR      strShowCard[32];
	__UINT32	nServerId;
	__UINT32	nGameId;
	__UINT32	nRoomId;
	__UINT32	nSumChip;
	__UINT32	nRewardJackpotType;
	__UINT32	nRewardBonusType;
	__UINT32	nCardType;
	__UINT32	nDealcardType;
	__UINT32	nResult;
	__UINT32	nEndStatus;
	__UINT32	nStartTime;
	__UINT32	nEndTime;
}SaveTexasBoardReq, *pSaveTexasBoardReq;

//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDB_PROTOCOL_TEXAS_BOARD_H__