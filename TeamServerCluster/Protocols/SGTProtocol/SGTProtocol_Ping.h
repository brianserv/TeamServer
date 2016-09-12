#ifndef __SGT_PROTOCOL_PING_H__
#define __SGT_PROTOCOL_PING_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//PING HEARTBEAT REQ
typedef struct tagGTHeartBeatReq
{
}GTHeartBeatReq, *pGTHeartBeatReq;

//PING HEARTBEAT RES
typedef struct tagGTHeartBeatRes
{
}GTHeartBeatRes, *pGTHeartBeatRes;
//--------------------------------------------------------------------------------------------------
//PING ROLE DISSCONNECT SYNC
typedef struct tagGTRoleDissconnectSync
{
	__UINT32 nRoleID;
}GTRoleDissconnectSync, *pGTRoleDissconnectSync;
//-------------------------------------------------------------------------------------------------
//PING GIRL DISSCONNECT SYNC
typedef struct tagGTGirlDissconnectSync
{
	__UINT32 nGirlID;
}GTGirlDissconnectSync, *pGTGirlDissconnectSync;

#pragma pack()

#endif//__SGT_PROTOCOL_PING_H__