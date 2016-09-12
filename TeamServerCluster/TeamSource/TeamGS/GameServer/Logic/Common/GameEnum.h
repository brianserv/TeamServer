#pragma once
#ifndef __GAME_ENUM__H
#define __GAME_ENUM__H

enum EPlatformType
{
	EPType_Begin,

	EPType_YY = 1,
	EPType_FB = 2,

	EType_Mobile = 3,

	EPType_End
};

enum EFB_HttpEventType
{
	EFB_HEType_Begin,

	EFB_HEType_V1 = 1,

	EFB_HEType_V2_GetRoleDataReq = 2,

	EFB_HEType_V3_UpdateRoleDataReq = 3,

	EFB_HEType_V4_UpdateMaxCardTypeReq = 4,

	EFB_HEType_V5_CreateVipRoomRes = 5,

	EFB_HEType_End
};

enum EYY_HttpEventType
{
	EYY_HEType_Begin,

	EYY_HEType_V1 = 1,

	EYY_HEType_V1_GetRoleDataReq = 2,

	EYY_HEType_V2_UpdateRoleDataReq = 3,

	EYY_HEType_V3_CreateVipRoomRes = 4,

	EYY_HEType_End
};

enum  EAttrNum
{
	EAttrNum_Begin,

	EAttrNum_nRoleId,
	EAttrNum_nPlatformId,
	EAttrNum_nSex,
	EAttrNum_nStatus,
	EAttrNum_nLastLoginTime,
	EAttrNum_nLoginTimes,
	EAttrNum_nBanTime,
	EAttrNum_nExp,
	EAttrNum_nLevel,
	EAttrNum_nUnBindChip,
	EAttrNum_nUnBindPink,
	EAttrNum_nBindChip,
	EAttrNum_nBindPink,
	EAttrNum_nMaxPink,
	EAttrNum_nMaxChip,
	EAttrNum_nHighestChip,
	EAttrNum_nVipType,
	EAttrNum_nVipLevel,
	EAttrNum_nVipPoints,
	EAttrNum_nWinTimes,
	EAttrNum_nLostTimes,
	EAttrNum_nDrawTimes,
	EAttrNum_nChatStatus,
	EAttrNum_nGiftSpend,
	EAttrNum_nGiftSpendMonth,
	EAttrNum_nServerId,

	EAttrNum_End
};

enum EUpdateOption
{
	EUpdateOption_Begin,

	EUpdateOption_Add = 1,
	EUpdateOption_Dec = 2,

	EUpdateOption_End
};

enum EGameWinType
{
	EGWT_Begin,

	EGWT_TIE = 0,
	EGWT_GIRL = 1,
	EGWT_ROLE = 2,
	EGWT_FOLD = 3,

	EGWT__End,
};

enum EGameType
{
	EGameType_Begin,

	EGameType_Texas = 1,
	EGameType_Baccarat = 2,

	EGameType_End
};

enum ERoomType
{
	ERoomType_Begin,

	ERoomType_Common = 1,

	ERoomType_Vip = 2,

	ERoomType_Activity = 3,

	ERoomType_End
};

enum ERoundType
{
	ERT_Begin,

	ERT_Ante = 0,
	ERT_Flop = 1,
	ERT_Turn = 2,
	ERT_River = 3,

	ERT_End
};

enum EGameStatus
{
	EGS_Begin,

	EGS_GameReady = 1,
	EGS_GameRun = 2,
	EGS_GameCancel = 3,

	EGS_End
};

enum ERoleStatus
{
	ERS_Begin,

	ERS_Ready = 1,
	ERS_Game = 2,
	ERS_Fold = 3,

	ERS_End
};

enum EBonusRewardKind
{
	EBK_Begin,

	EBK_First = 3,
	EBK_Second = 5,
	EBK_Third = 10,
	EBK_Fourth = 15,
	EBK_Fifth = 20,
	EBK_Sixth = 25,
	EBK_Seventh = 30,
	EBK_Eighth = 100,

	EBK_End
};

enum EJackPotRewardKind
{
	EJK_Begin,

	EJK_First = 4,
	EJK_Second = 10,
	EJK_Third = 16,
	EJK_Fourth = 20,
	EJK_Fifth = 100,
	EJK_Sixth = 200,

	EJK_End,
};

enum EBetType
{
	EBetType_Begin,

	EBetType_Ante = 1,
	EBetType_Call = 2,
	EBetType_Check = 3,

	EBetType_End
};

enum EGameResultType
{
	EGRT_TIE = -1,
	EGRT_LOSE = 0,
	EGRT_WIN = 1,
	EGRT_FOLD = 2,
	EGRT_GIRLCANCEL = 3
};

enum ECardDealType
{
	ECDT_Begin,

	ECDT_Hand = 0,
	ECDT_Center = 1,
	ECDT_GIRL = 2,

	ECDT_End,
};

enum ECardNumType
{
	ECNT_Begin,

	ECNT_0 = 0,
	ECNT_1 = 1,
	ECNT_2 = 2,
	ECNT_3 = 3,
	ECNT_4 = 4,
	ECNT_5 = 5,
	ECNT_6 = 6,
	ECNT_7 = 7,
	ECNT_8 = 8,
	ECNT_9 = 9,

	ECNT__End
};

enum EDealModeType
{
	EDMT_Begin,

	EDMT_AutoMode = 0,
	EDMT_GirlMode = 1,

	EDMT_End
};

enum EBetResultType
{
	EBRT_Begin,

	EBRT_Failure = 0,
	EBRT_Success = 1,

	EBRT_End
};

enum EBetBroadcastType
{
	EBCT_Begin,

	EBCT_Gift = 1,
	EBCT_Bet = 2,

	EBCT_End
};

enum ECurrencyType
{
	ECT_Begin,

	ECT_Unbind = 0,

	ECT_Bind = 1,

	ECT_End
};

enum EManualDealNoticeType
{
	EMDNT_Ante = 1,
	EMDNT_Flop = 2,
	EMDNT_Turn = 3,
	EMDNT_River = 4,
	EMDNT_ReStart = 5,
};

enum EManualStartGameType
{
	EMSGT_Begin,

	EMSGT_Failure = 0,
	EMSGT_Success = 1,

	EMSGT_End
};

#endif //__GAME_ENUM__H
