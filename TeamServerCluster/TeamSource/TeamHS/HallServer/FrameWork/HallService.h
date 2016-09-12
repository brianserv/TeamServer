#pragma once
#ifndef __BACKEND_SERVICE_H__
#define __BACKEND_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CHallService :public CEQ_Service
{
public:
	CHallService(char* pServiceName, char* pDisplayName);
	virtual ~CHallService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__BACKEND_SERVICE_H__