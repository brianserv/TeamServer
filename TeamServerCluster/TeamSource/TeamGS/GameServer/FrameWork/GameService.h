#pragma once
#ifndef __GAME_SERVICE_H__
#define __GAME_SERVICE_H__

#include "EQUtils.h"
#include "EQ_Service.h"

class CGameService :public CEQ_Service
{
public:
	CGameService(char* pServiceName, char* pDisplayName);
	virtual ~CGameService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};

#endif//__GAME_SERVICE_H__
