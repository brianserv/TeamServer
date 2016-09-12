#pragma once
#ifndef __DATABASE_APPLICATION_H__
#define __DATABASE_APPLICATION_H__

#include "EQ_DataType.h"
#include "EQ_Singleton.h"
#include "EQ_MultiThreads.h"

#include "../../Protocols/CommonProtocol.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class CDBApplication
{
public:
	CDBApplication();
	virtual ~CDBApplication();

public:
	void   Start(int nIndex);
	void   Stop();

protected:
	void   Run();

protected:

	void WorkingProc();
#if defined (WINDOWS_VESION)
	static DWORD WINAPI  WorkingThreadsProc(LPVOID lpParam);
#else
	static void* WorkingThreadsProc(void* Param);
#endif

private:
	CEQ_MultiThreads      m_workThreads;
	bool                  m_bStopThread;

protected:

	void  ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort);

private:
	int           m_nIndex;
	int           m_nRoleIndex;
};
#endif//__DATABASE_APPLICATION_H__