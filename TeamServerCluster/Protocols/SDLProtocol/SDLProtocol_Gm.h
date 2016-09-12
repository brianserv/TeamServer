#ifndef __SDL_PROTOCOL_GM_H__
#define __SDL_PROTOCOL_GM_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE GM REQ
typedef struct tagSaveGmReq
{
	__UINT32	nRoleId;
	__UINT32	nGmId;
	__UINT32	nGmActionType;
	__CHAR		sDescribe[32];
}SaveGmReq, *pSaveGmReq;

//SAVE GM  RES
typedef struct tagSaveGmRes
{
	__UINT32 nSaveStatus;
}SaveGmRes, *pSaveGmRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_GM_H__