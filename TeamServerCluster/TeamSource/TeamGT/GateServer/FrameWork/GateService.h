#pragma once
#ifndef __GATE_SERVICE_H__
#define __GATE_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CGateService :public CEQ_Service
{
public:
	CGateService(char* pServiceName, char* pDisplayName);
	virtual ~CGateService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__GATE_SERVICE_H__