#ifndef __SDL_PROTOCOL_PVPGIFT_H__
#define __SDL_PROTOCOL_PVPGIFT_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE PVPGIFT  REQ
typedef struct tagSavePVPGiftReq
{
	__UINT32	nFromRoleId;
	__UINT32	nToRoleId;
	__CHAR		sFromRoleName[32];
	__CHAR		sToRoleName[32];
	__UINT32	nPlatformId;
	__CHAR		sFromThirdId[32];
	__CHAR		sToThirdId[32];
	__CHAR		sFromThirdAccount[32];
	__CHAR		sToThirdAccount[32];
	__UINT32	nGiftId;
	__UINT32	nGiftPrice;
	__UINT32	nUnbindChip;
	__UINT32	nBindChip;
	__UINT32	nServerId;
	__UINT32	nRoomId;
}SavePVPGiftReq, *pSavePVPGiftReq;

//SAVE PVPGIFT  RES
typedef struct tagSavePVPGiftRes
{
	__UINT32 nSaveStatus;
}SavePVPGiftRes, *pSavePVPGiftRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_PVPGIFT_H__