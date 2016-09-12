#pragma once
#ifndef __DATABASELG_SERVICE_H__
#define __DATABASELG_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CDLService :public CEQ_Service
{
public:
	CDLService(char* pServiceName, char* pDisplayName);
	virtual ~CDLService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};
#endif//__DATABASELG_SERVICE_H__