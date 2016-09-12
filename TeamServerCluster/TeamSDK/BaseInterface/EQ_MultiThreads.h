#pragma once

#ifndef  EQ_MULTITHREEQS_FILE
#define  EQ_MULTITHREEQS_FILE
#include "EQ_SingleThread.h"

class CEQ_MultiThreads
{
public:
	CEQ_MultiThreads();
	virtual ~CEQ_MultiThreads();

public:
	inline int GetThreadsNum() { return m_nThreadsNum; };

public:
	bool CreateThreads(int nThreadsNum,void* pStartAddress = NULL ,void* pParam = NULL ,
		unsigned long nCreationFlags = 0);
	bool ResumeThread();
	void CloseThreadsHandle();

private:
	int                     m_nThreadsNum; 
	CEQ_SingleThread*       m_pArrThreads; 
};


#endif