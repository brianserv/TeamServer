#pragma once

#ifndef  EQ_LOCK_FILE
#define  EQ_LOCK_FILE
#include "EQUtils.h"

class CEQ_Lock
{
public:
	CEQ_Lock();
	virtual ~CEQ_Lock();

public:
	void     EQ_Lock();
	void     EQ_UnLock();


private:

#if defined (_WIN32) || defined (_WIN64)
	CRITICAL_SECTION        m_CriticalSection;

#else
	pthread_mutex_t         m_Mutex;

#endif

};

////////////////////////////////////////////////////////////////////////////////////////////////////
class CEQ_AutoLock
{
public:
	CEQ_AutoLock(CEQ_Lock& Lock);
	virtual ~CEQ_AutoLock();
	
private:
	CEQ_Lock&     m_Lock;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
class CEQ_AutoLock2
{
public:
	CEQ_AutoLock2(CEQ_Lock* pLock);
	virtual ~CEQ_AutoLock2();

private:
	CEQ_Lock*     m_pLock;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
class CEQ_RWLock
{
public:
	CEQ_RWLock();
	virtual ~CEQ_RWLock();

public:
	void  EQ_ReadLock();
	void  EQ_UnReadLock();
	void  EQ_WriteLock();
	void  EQ_UnWriteLock();

private:
	volatile long        m_ulReadCount;

#if defined (_WIN32) || defined (_WIN64)
	CRITICAL_SECTION     m_CriticalSection;

#else
	pthread_rwlock_t    m_rwlock;

#endif
};


#define  EQ_AUTOLOCK(lock)    CEQ_AutoLock  aLock(lock);
#define  EQ_AUTOLOCK2(lock)   CEQ_AutoLock2 aLock(&lock);


#if defined (_WIN32) || defined (_WIN64)

class  CMSyncObject
{
public:
	CMSyncObject();
	~CMSyncObject();
public:
	//
	inline HANDLE GetHandle() { return m_handle ; };
	void Close();

	
	BOOL CreateEvent(BOOL bManualReset = FALSE, LPCTSTR lpName  = NULL);

	inline BOOL SetEvent() { return ::SetEvent(m_handle);};

	inline BOOL ResetEvent() { return ::ResetEvent(m_handle); };

	BOOL CreateSemaphore(LONG lInitialCount = 0,
		LONG lMaximumCount =  9999999,LPCTSTR lpName = NULL);

	BOOL OpenSemaphore(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCTSTR lpName);

	BOOL ReleaseSemaphore(LONG lReleaseCount = 1, LPLONG lpPreviousCount = NULL);
private:
	HANDLE m_handle;
};

#else
#endif


#endif
