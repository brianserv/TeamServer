#pragma once


#ifndef  EQ_TIME_FILE
#define  EQ_TIME_FILE
#include "EQUtils.h"
#include "EQ_Singleton.h"

int EQ_WaitTimeOut(unsigned int nMilliseconds);

class CEQ_Time : public CEQ_SingletonT<CEQ_Time>
{
public:
	CEQ_Time();
	virtual ~CEQ_Time();

public:
	
	unsigned int   EQ_GetTime(){return (unsigned int)m_nTime;};
	int            EQ_GetYear(){return m_nYear;};
	int            EQ_GetMonth(){return m_nMon;};
	int            EQ_GetDay(){return m_nDay;};
	int            EQ_GetHour(){return m_nHour;};
	int            EQ_GetMin(){return m_nMin;};
	int            EQ_GetSec(){return m_nSec;};

public:
	unsigned int   EQ_SetTime();
	bool           EQ_IsCheckWait(time_t  nTime,int nWaitTime);

	unsigned long  EQ_GetTickCount();

	

private:
	time_t           m_nTime;
	int              m_nYear;
	int              m_nMon;
	int              m_nDay;
	int              m_nHour;
	int              m_nMin;
	int              m_nSec;
};


#endif
