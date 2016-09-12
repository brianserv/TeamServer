#ifndef __GS_PROTOCOL_ERROR_H__
#define __GS_PROTOCOL_ERROR_H__

#include "EQ_DataType.h"

enum EGS_ERRORTYPE
{
	EGERT_BEGIN,

	EGERT_LOGIN_USERNAMEPASSWORD_ERROR = 1,
	EGERT_LOGIN_GIRLID_ERROR = 2,

	EGERT_END,
};

#pragma pack(1)

typedef struct tagGSErrorInfoSync
{
	__UINT32  nErrorID;
}GSErrorInfoSync, *pGSErrorInfoSync;

#pragma pack()

#endif//__GS_PROTOCOL_ERROR_H__
