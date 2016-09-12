#ifndef __CS_PROTOCOL_ROLE_H__
#define __CS_PROTOCOL_ROLE_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------
//ROLE

// Role Info Sync
typedef struct tagRoleInfoSync
{
	__UINT32 nRoleID;
	__UINT32 nExp;
	__UINT32 nLevel;
	__UINT32 nUnBindChip;
	__UINT32 nUnBindPink;
	__UINT32 nBindChip;
	__UINT32 nBindPink;
	__UINT32 nMaxPink;
	__UINT32 nMaxChip;
	__UINT32 nVipType;
	__UINT32 nVipLevel;
	__UINT32 nVipPoints;
}RoleInfoSync, *pRoleInfoSync;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__CS_PROTOCOL_ROLE_H__