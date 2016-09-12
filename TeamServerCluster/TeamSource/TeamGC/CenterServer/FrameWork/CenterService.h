#pragma once
#ifndef __CENTER_SERVICE_H__
#define __CENTER_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CCenterService :public CEQ_Service
{
public:
	CCenterService(char* pServiceName, char* pDisplayName);
	virtual ~CCenterService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};

#endif//__CENTER_SERVICE_H__