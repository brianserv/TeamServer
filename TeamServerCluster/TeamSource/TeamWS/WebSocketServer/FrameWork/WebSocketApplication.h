#pragma once
#ifndef _WEBSOCKET_APPLICATION_H__
#define _WEBSOCKET_APPLICATION_H__

#include "BaseDefine.h"

class CWebSocketApplication : public CEQ_SingletonT<CWebSocketApplication>
{
public:
	CWebSocketApplication();
	virtual ~CWebSocketApplication();

public:
	void   Start();
	void   Stop();

protected:
	void   Run();

protected:

	void WorkingProc();
#if defined(WINDOWS_VESION)
	static DWORD WINAPI  WorkingThreadsProc(LPVOID lpParam);
#else
	static void* WorkingThreadsProc(void* Param);
#endif

private:
	CEQ_MultiThreads      m_workThreads;
	bool                  m_bStopThread;

protected:
	void  ProcessMsgInfo(char*pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort);
};

#endif