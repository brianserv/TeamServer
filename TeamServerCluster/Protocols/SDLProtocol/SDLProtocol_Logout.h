#ifndef __SDL_PROTOCOL_LOGOUT_H__
#define __SDL_PROTOCOL_LOGOUT_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE LOGOUT REQ
typedef struct tagSaveLogoutReq
{
	__UINT32	nRoleId;
	__CHAR		sRoleName[32];
	__UINT32	nPlatformId;
	__CHAR		sThirdId[32];
	__CHAR		sThirdAccount[32];
	__UINT32	nLoginTime;
	__UINT32	nLogoutTime;
	__UINT32	nServerId;
	__CHAR		sIp[32];
	__UINT32	nUnbindChip;
	__UINT32	nUnbindPink;
	__UINT32	nBindChip;
	__UINT32	nBindPink;
}SaveLogoutReq, *pSaveLogoutReq;

//SAVE LOGOUT  RES
typedef struct tagSaveLogoutRes
{
	__UINT32 nSaveStatus;
}SaveLogoutRes, *pSaveLogoutRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_LOGOUT_H__