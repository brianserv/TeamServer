#ifndef __CS_PROTOCOL_HALLROOM_H__
#define __CS_PROTOCOL_HALLROOM_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------
//HALLROOM

// Enter Room Req
typedef struct tagEnterRoomReq
{
	__UINT32 nRoleID;
	__UINT32 nGameType;
	__UINT32 nRoomID;
}EnterRoomReq, *pEnterRoomReq;

// Enter Room Res
typedef struct tagEnterRoomRes
{
}EnterRoomRes, *pEnterRoomRes;
//--------------------------------------------------------------------------------------------------

// Leave Room Req
typedef struct tagLeaveRoomReq
{
	__UINT32 nRoleID;
	__UINT32 nRoomID;
}LeaveRoomReq, *pLeaveRoomReq;

// Leave Room Res
typedef struct tagLeaveRoomRes
{
}LeaveRoomRes, *pLeaveRoomRes;
//--------------------------------------------------------------------------------------------------

// Sit Down Req
typedef struct tagSitDownReq
{
	__UINT32 nRoleID;
	__UINT32 nRoomID;
}SitDownReq, *pSitDownReq;

// Sit Down Res
typedef struct tagSitDownRes
{
}SitDownRes, *pSitDownRes;
//--------------------------------------------------------------------------------------------------

// Stand Up Req
typedef struct tagStandUpReq
{
	__UINT32 nRoleID;
	__UINT32 nRoomID;
}StandUpReq, *pStandUpReq;

// Stand Up Res
typedef struct tagStandUpRes
{
}StandUpRes, *pStandUpRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__CS_PROTOCOL_HALLROOM_H__