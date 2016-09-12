#ifndef __SDL_PROTOCOL_PVGGIFT_H__
#define __SDL_PROTOCOL_PVGGIFT_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE PVGGIFT  REQ
typedef struct tagSavePVGGiftReq
{
	__UINT32	nRoleId;
	__CHAR		sRoleName[32];
	__UINT32	nGirlId;
	__CHAR		sGirlThirdId[32];
	__UINT32	nGiftId;
	__UINT32	nGiftNum;
	__UINT32	nGiftPrice;
	__UINT32	nType;
	__UINT32	nUnbindPink;
	__UINT32	nBindPink;
	__UINT32	nGameType;
	__UINT32	nGameId;
	__UINT32	nRoomId;
	__UINT32	nServerId;
	__UINT32	nRoomType;
	__UINT32	nEvenCount;
	__UINT32	nBroadcastType;
	__UINT32    nSaveType;
}SavePVGGiftReq, *pSavePVGGiftReq;

//SAVE PVGGIFT  RES
typedef struct tagSavePVGGiftRes
{
	__UINT32 nSaveStatus;
}SavePVGGiftRes, *pSavePVGGiftRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_PVGGIFT_H__