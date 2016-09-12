#ifndef __CS_PROTOCOL_LOGIN_H__
#define __CS_PROTOCOL_LOGIN_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//LOGIN REQ
typedef struct tagUserLoginReq
{
	__UINT32 nGServerID;
	__UINT32 nRoleID;
	__UINT32 nPlatformID;
	__UINT32 nSex;
	__CHAR sUserName[32];
	__CHAR sRoleToken[64];
	__CHAR sThirdID[32];
	__CHAR sThirdAccount[32];
}UserLoginReq, *pUserLoginReq;

//LOGIN RES
typedef struct tagUserLoginRes
{
}UserLoginRes, *pUserLoginRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__CS_PROTOCOL_LOGIN_H__