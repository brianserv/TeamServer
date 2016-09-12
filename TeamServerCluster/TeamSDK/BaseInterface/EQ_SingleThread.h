#pragma once

#ifndef  EQ_SINGLETHREEQ_FILE
#define  EQ_SINGLETHREEQ_FILE
#include "EQUtils.h"

#if defined (_WIN32) || defined (_WIN64)
#else
#define		HANDLE		pthread_t
#endif

unsigned long   GetCurrThreadID();

class CEQ_SingleThread
{
public:
	CEQ_SingleThread();
	virtual ~CEQ_SingleThread();

public:
	inline HANDLE  GetThreadHandle() { return m_hThread; };
	inline unsigned long   GetThreadId() { return m_nThreadID; };

public:
	bool  CreateThread(void* pStartAddress = NULL ,void* pParam = NULL ,unsigned long nCreationFlags = 0);
	bool  ResumeThread();
	void  CloseThreadHandle();

public:
	virtual void ThreadRun(){};

protected:
#if defined (_WIN32) || defined (_WIN64)
	static DWORD WINAPI  WorkingThreadProc(LPVOID Param);
#else
	static void* WorkingThreadProc(void* para);
#endif

private:
	unsigned long   m_nThreadID;
	HANDLE          m_hThread;
	
};


#endif
