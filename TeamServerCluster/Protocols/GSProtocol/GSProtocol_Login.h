#ifndef __GS_PROTOCOL_LOGIN_H__
#define __GS_PROTOCOL_LOGIN_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//LOGIN REQ
typedef struct tagGSLoginReq
{
	__UINT32 nRoomID;
	__UINT32 nGirlID;
	__UINT32 nGirlRoleID;
	__CHAR   sGirlName[32];
	__CHAR   sGirlPassword[32];
	__CHAR   sGirlThirdId[32];
}GSLoginReq, *pGSLoginReq;

//LOGIN RES
typedef struct tagGSLoginRes
{
	__UINT32 nGirlID;
}GSLoginRes, *pGSLoginRes;
//--------------------------------------------------------------------------------------------------

//LOGOUT
typedef struct tagGSLogoutReq
{
	__UINT32 nRoomID;
	__UINT32 nGirlID;
}GSLogoutReq, *pGSLogoutReq;

#pragma pack()

#endif//__GS_PROTOCOL_LOGIN_H__