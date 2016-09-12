#ifndef __SDL_PROTOCOL_TRACE_H__
#define __SDL_PROTOCOL_TRACE_H__

#include "EQ_DataType.h"

#pragma pack(1)

//--------------------------------------------------------------------------------------------------

//SAVE TRACE  REQ
typedef struct tagSaveTraceReq
{
	__INT32  nRoleId;
	__INT32  nCostType;
	__INT32	 nUnbindChip;
	__INT32	 nUnbindPink;
	__INT32	 nBindChip;
	__INT32	 nBindPink;
	__CHAR   sDescribe[100];
}SaveTraceReq, *pSaveTraceReq;

//SAVE TRACE  RES
typedef struct tagSaveTraceRes
{
	__UINT32 nSaveStatus;
}SaveTraceRes, *pSaveTraceRes;
//--------------------------------------------------------------------------------------------------

#pragma pack()

#endif//__SDL_PROTOCOL_TRACE_H__