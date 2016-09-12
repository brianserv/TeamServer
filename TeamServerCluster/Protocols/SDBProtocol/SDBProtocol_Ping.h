#ifndef __SDB_PROTOCOL_PING_H__
#define __SDB_PROTOCOL_PING_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//PING HEARTBEAT REQ
typedef struct tagDBHeartBeatReq
{
}DBHeartBeatReq, *pDBHeartBeatReq;

//PING HEARTBEAT RES
typedef struct tagDBHeartBeatRes
{
}DBHeartBeatRes, *pDBHeartBeatRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDB_PROTOCOL_PING_H__