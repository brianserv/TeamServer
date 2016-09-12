#ifndef __SDL_PROTOCOL_ROOM_H__
#define __SDL_PROTOCOL_ROOM_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE ROOM  REQ
typedef struct tagSaveRoomReq
{
	__UINT32	nRoleId;
	__CHAR		sRoleName[32];
	__UINT32	nPlatformId;
	__CHAR		sThirdId[32];
	__CHAR		sThirdAccount[32];
	__UINT32	nRoomId;
	__UINT32	nGirlId;
	__UINT32	nAction;
}SaveRoomReq, *pSaveRoomReq;

//SAVE ROOM  RES
typedef struct tagSaveRoomRes
{
	__UINT32 nSaveStatus;
}SaveRoomRes, *pSaveRoomRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_ROOM_H__