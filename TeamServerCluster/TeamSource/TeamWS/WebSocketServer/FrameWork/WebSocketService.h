#pragma once
#ifndef __WEBSOCKET_SERVICE__H
#define __WEBSOCKET_SERVICE__H

#include "EQUtils.h"
#include "EQ_Service.h"

class CWebSocketService :public CEQ_Service
{
public:
	CWebSocketService(char* pServiceName, char* pDisplayName);
	virtual ~CWebSocketService(void);
public:
	virtual void  OnStop();
	virtual void  OnIdle();
	virtual bool  OnStart(int nState = 0, int bLastNormalQuit = 1);
	virtual void  PostExceptionMessageEx(int nLevel, const char* szErrInfo, ...);
};


#endif//__WEBSOCKET_SERVICE__H