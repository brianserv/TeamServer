#pragma once
#ifndef __GAME_STRUCTURE__H
#define __GAME_STRUCTURE__H

//UpdatePlatformRoleBaseInfo
typedef struct tagUpdatePlatformRoleBaseInfo
{
	tagUpdatePlatformRoleBaseInfo()
		:nServerId(0),
		nRoomId(0),
		nRoleId(0),
		nUnBindChip(0),
		nBindChip(0),
		nUnBindPink(0),
		nBindPink(0),
		nUpdateType(0),
		nRoleState(0),
		strMd5RoleIdToken("") {}

	int nRoleId;
	int nUnBindChip;
	int nBindChip;
	int nUnBindPink;
	int nBindPink;
	int nServerId;
	int nRoomId;
	int nUpdateType;
	int nRoleState;
	string strMd5RoleIdToken;
}UpdatePlatformRoleBaseInfo;

//TexasRoomVip
typedef struct tagTexasRoomVip
{
	tagTexasRoomVip() :nRoomId(0),
		nRoomOwnerAccountId(0),
		nRoomMaxCapacity(0),
		nEnterRoomChipLimit(0),
		nBetAnteLimit(0),
		nDealModeType(0),
		nUseChipCurrencyType(0),
		nVipPalyersStacks(0),
		nRoomIncome(0) {}
	int nRoomId;
	int nRoomOwnerAccountId;
	int nRoomMaxCapacity;
	int nEnterRoomChipLimit;
	int nBetAnteLimit;
	int nDealModeType;
	int nUseChipCurrencyType;
	int nVipPalyersStacks;
	int nRoomIncome;
}TexasRoomVip;

#endif //__GAME_STRUCTURE__H;
