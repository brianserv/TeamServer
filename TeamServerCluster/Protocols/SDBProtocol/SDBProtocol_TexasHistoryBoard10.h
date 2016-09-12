#ifndef __SDB_PROTOCOL_TEXAS_HISTORYBOARD10_H__
#define __SDB_PROTOCOL_TEXAS_HISTORYBOARD10_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

// LOAD TEXAS_HISTORYBOARD REQ
typedef struct tagLoadTexasHistoryBoard10Req
{
	__UINT32	nRoomId;
}LoadTexasHistoryBoard10Req, *pLoadTexasHistoryBoard10Req;

// LOAD  TEXAS_HISTORYBOARD  RES
typedef struct tagLoadTexasHistoryBoard10Res
{
	__UINT32	nGameId;
	__UINT32	nRoomId;
	__UINT32	nServerId;
	__CHAR		sResult[21];
	__UINT32	nBoardCount;
}LoadTexasHistoryBoard10Res, *pLoadTexasHistoryBoard10Res;
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

// SAVE  TEXAS_HISTORYBOARD REQ
typedef struct tagSaveTexasHistoryBoard10Req
{
	int			nGameId;
	int			nRoomId;
	int			nServerId;
	__CHAR		sResult[21];
	int			nBoardCount;
}SaveTexasHistoryBoard10Req, *pSaveTexasHistoryBoard10Req;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDB_PROTOCOL_TEXAS_HISTORYBOARD10_H__