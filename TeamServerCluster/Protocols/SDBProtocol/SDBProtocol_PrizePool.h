#ifndef __SDB_PROTOCOL_PRIZEPOOL_H__
#define __SDB_PROTOCOL_PRIZEPOOL_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

// LOAD PRIZEPOOL REQ
typedef struct tagLoadPrizePoolReq
{
}LoadPrizePoolReq, *pLoadPrizePoolReq;

// LOAD PRIZEPOOL  RES
typedef struct tagLoadPrizePoolRes
{
	__UINT32		nTotalValue;
	__UINT32		nPayValue;
	__UINT32        nJackpotBonus_InitValue;
}LoadPrizePoolRes, *pLoadPrizePoolRes;
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

// SAVE PRIZEPOOL REQ
typedef struct tagSavePrizePoolReq
{
	__UINT32		nTotalValue;
	__UINT32		nPayValue;
	__UINT32        nJackpotBonus_InitValue;
}SavePrizePoolReq, *pSavePrizePoolReq;

//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDB_PROTOCOL_PRIZEPOOL_H__