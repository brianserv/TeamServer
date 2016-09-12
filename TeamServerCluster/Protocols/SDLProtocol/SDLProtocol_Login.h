#ifndef __SDL_PROTOCOL_LOGIN_H__
#define __SDL_PROTOCOL_LOGIN_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE LOGIN REQ
typedef struct tagSaveLoginReq
{
	__UINT32	nRoleId;
	__CHAR		sRoleName[32];
	__UINT32	nPlatformId;
	__CHAR		sThirdId[32];
	__CHAR		sThirdAccount[32];
	__UINT32	nLoginTime;
	__UINT32	nServerId;
	__CHAR		sIp[32];
	__UINT32	nStatus;
}SaveLoginReq, *pSaveLoginReq;

//SAVE LOGIN  RES
typedef struct tagSaveLoginRes
{
	__UINT32 nSaveStatus;
}SaveLoginRes, *pSaveLoginRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_LOGIN_H__