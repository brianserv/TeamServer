#pragma once
#ifndef __FLASH_POLICY_SERVICE_H__
#define __FLASH_POLICY_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CFlashPolicyService :public CEQ_Service
{
public:
	CFlashPolicyService(char* pServiceName, char* pDisplayName);
	virtual ~CFlashPolicyService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__FLASH_POLICY_SERVICE_H__