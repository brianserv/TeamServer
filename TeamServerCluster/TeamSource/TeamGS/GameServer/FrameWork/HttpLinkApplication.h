#pragma once
#ifndef __HTTPLINK_APPLICATION_H__
#define __HTTPLINK_APPLICATION_H__

#include "EQ_DataType.h"
#include "EQ_Singleton.h"
#include "EQ_MultiThreads.h"
#include "EQ_Lock.h"

class CHttpLinkApplication : public CEQ_SingletonT<CHttpLinkApplication>
{
public:
	CHttpLinkApplication();
	virtual ~CHttpLinkApplication();

public:
	void   Start(int nIndex);

	void   Stop();
protected:
	void   Run();
public:

	bool Run_Request();
	bool Run_Response();
public:
	void Process_Request(char* pDataInfo);
	void Process_Response(char* pDataInfo);
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
};
#endif//__HTTPLINK_APPLICATION_H__
