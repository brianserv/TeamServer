#ifndef __SDL_PROTOCOL_ONLINE_H__
#define __SDL_PROTOCOL_ONLINE_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE ONLINE  REQ
typedef struct tagSaveOnlineReq
{
	__UINT32	nServerId;
	__UINT32	nGameType;
	__UINT32	nRoomType;
	__UINT32	nGameId;
	__UINT32	nRoomId;
	__UINT32	nGirlId;
	__UINT32    nOnlineUsersCount;
}SaveOnlineReq, *pSaveOnlineReq;

//SAVE ONLINE  RES
typedef struct tagSaveOnlineRes
{
	__UINT32 nSaveStatus;
}SaveOnlineRes, *pSaveOnlineRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_ONLINE_H__