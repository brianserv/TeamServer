#ifndef __GS_PROTOCOL_TEXASGAME_H__
#define __GS_PROTOCOL_TEXASGAME_H__

#include "EQ_DataType.h"

#pragma pack(1)

//GAMESTART REQ
typedef struct tagGSGameStartReq
{
	__UINT32 nGirlID;
}GSGameStartReq, *pGSGameStartReq;

//GAMESTART RES
typedef struct tagGSGameStartRes
{
	__UINT32 nGameStartResult;
}GSGameStartRes, *pGSGameStartRes;

//DEALNOTICES SYNC
typedef struct tagGSDealNotesSync
{
	__UINT32 nDealerStatus;
}GSDealNotesSync, *pGSDealNotesSync;

//DEALCARD REQ
typedef struct tagGSDealCardReq
{
	__UINT32 nGirlID;
	__UINT32 nCardValue;
}GSDealCardReq, *pGSDealCardReq;

//GAMEEND SYNC
typedef struct tagGSGameEndSync
{
	__UINT32 nManualGameResultType;
}GSGameEndSync, *pGSGameEndSync;

//GAMECANCEL REQ
typedef struct tagGSGameCancelReq
{
	__UINT32 nGirlID;
}GSGameCancelReq, *pGSGameCancelReq;

#pragma pack()

#endif//__GS_PROTOCOL_TEXASGAME_H__
