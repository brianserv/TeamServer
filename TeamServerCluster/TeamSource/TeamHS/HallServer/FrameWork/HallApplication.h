#pragma  once
#ifndef __BACKEND_APPLICATION_H__
#define __BACKEND_APPLICATION_H__

#include "EQ_DataType.h"
#include "EQ_Singleton.h"
#include "EQ_MultiThreads.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class CHallApplication : public CEQ_SingletonT<CHallApplication>
{
public:
	CHallApplication();
	virtual ~CHallApplication();

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

#endif//__BACKEND_APPLICATION_H__