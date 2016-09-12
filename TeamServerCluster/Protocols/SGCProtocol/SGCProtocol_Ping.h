#ifndef __SGC_PROTOCOL_PING_H__
#define __SGC_PROTOCOL_PING_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//PING HEARTBEAT REQ
typedef struct tagGCHeartBeatReq
{
}GCHeartBeatReq, *pGCHeartBeatReq;

//PING HEARTBEAT RES
typedef struct tagGCHeartBeatRes
{
}GCHeartBeatRes, *pGCHeartBeatRes;
//--------------------------------------------------------------------------------------------------

//PING REGISTER REQ
typedef struct tagGCRegisterReq
{
	__UINT32 nGameServerID;
}GCRegisterReq, *pGCRegisterReq;

//PING REGISTER RES
typedef struct tagGCRegisterRes
{
	__UINT32 nGameServerID;
}GCRegisterRes, *pGCRegisterRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SGC_PROTOCOL_PING_H__