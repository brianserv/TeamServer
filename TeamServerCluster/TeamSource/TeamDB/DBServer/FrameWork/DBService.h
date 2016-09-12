#pragma once
#ifndef __DATABASE_SERVICE_H__
#define __DATABASE_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CDBService :public CEQ_Service
{
public:
	CDBService(char* pServiceName, char* pDisplayName);
	virtual ~CDBService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__DATABASE_SERVICE_H__