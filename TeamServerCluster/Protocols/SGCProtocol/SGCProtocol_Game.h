#ifndef __SGC_PROTOCOL_GAME_H__
#define __SGC_PROTOCOL_GAME_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//ONLINE UPDATE SYNC
typedef struct tagGCOnlineUpdateSync
{
	__UINT32 nRoomId;
}GCOnlineUpdateSync, *pGCOnlineUpdateSync;

//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SGC_PROTOCOL_GAME_H__