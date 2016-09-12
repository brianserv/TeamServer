#ifndef __CS_PROTOCOL_ERROR_H__
#define __CS_PROTOCOL_ERROR_H__

#include "EQ_DataType.h"

enum ECS_ERRORTYPE
{
	ECERT_BEGIN,

	ECERT_LOGIN_USERNAMEPASSWORD_ERROR = 1,

	ECERT_LOGIN_ROLENOTEXIST_ERROR = 2,

	ECERT_LOGIN_ROOMNOTEXIST_ERROR = 3,

	ECERT_CHIPS_CHIPSSHORT_ERROR = 4,

	ECERT_END,
};

#pragma pack(1)

typedef struct tagCSErrorInfoSync
{
	__UINT32  nErrorID;
}CSErrorInfoSync, *pCSErrorInfoSync;

#pragma pack()

#endif//__CS_PROTOCOL_ERROR_H__
