#ifndef __SDB_PROTOCOL_ROLE_H__
#define __SDB_PROTOCOL_ROLE_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

// LOAD ROLE REQ
typedef struct tagLoadRoleReq
{
	__UINT32 nRoleId;
}LoadRoleReq, *pLoadRoleReq;

// LOAD ROLE  RES
typedef struct tagLoadRoleRes
{
	__UINT32 nRoleId;
	__CHAR	 sRoleName[32];
	__CHAR	 sPassword[32];
	__UINT32 nPlatformId;
	__CHAR	 sThirdId[32];
	__CHAR	 sThirdAccount[32];
	__UINT32 nSex;
	__UINT32 nStatus;
	__CHAR  sStatusReason[100];
	__UINT32 nLastLoginTime;
	__UINT32 nLoginTimes;
	__UINT32 nBanTime;
	__UINT32 nExp;
	__UINT32 nLevel;
	__UINT32 nUnbindChip;
	__UINT32 nUnbindPink;
	__UINT32 nBindChip;
	__UINT32 nBindPink;
	__UINT32 nMaxPink;
	__UINT32 nMaxChip;
	__UINT32 nHighestChip;
	__UINT32 nVipType;
	__UINT32 nVipLevel;
	__UINT32 nVipPoints;
	__UINT32 nWinTimes;
	__UINT32 nLostTimes;
	__UINT32 nDrawTimes;
	__UINT32 sMaxCardType[5];
	__UINT32 nChatStatus;
	__UINT32 nGiftSpend;
	__UINT32 nGiftMonth;
}LoadRoleRes, *pLoadRoleRes;
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

// SAVE ROLE REQ
typedef struct tagSaveRoleReq
{
	__UINT32 nRoleId;
	__CHAR	 sRoleName[32];
	__CHAR	 sPassword[32];
	__UINT32 nPlatformId;
	__CHAR	 sThirdId[32];
	__CHAR	 sThirdAccount[32];
	__UINT32 nSex;
	__UINT32 nStatus;
	__CHAR  sStatusReason[100];
	__UINT32 nLastLoginTime;
	__UINT32 nLoginTimes;
	__UINT32 nBanTime;
	__UINT32 nExp;
	__UINT32 nLevel;
	__UINT32 nUnbindChip;
	__UINT32 nUnbindPink;
	__UINT32 nBindChip;
	__UINT32 nBindPink;
	__UINT32 nMaxPink;
	__UINT32 nMaxChip;
	__UINT32 nHighestChip;
	__UINT32 nVipType;
	__UINT32 nVipLevel;
	__UINT32 nVipPoints;
	__UINT32 nWinTimes;
	__UINT32 nLostTimes;
	__UINT32 nDrawTimes;
	__UINT32 sMaxCardType[5];
	__UINT32 nChatStatus;
	__UINT32 nGiftSpend;
	__UINT32 nGiftMonth;
}SaveRoleReq, *pSaveRoleReq;

//--------------------------------------------------------------------------------------------------
#pragma pack()

#endif//__SDB_PROTOCOL_ROLE_H__