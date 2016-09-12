#pragma once

class CEQ_Service
{
public:
	
	CEQ_Service(char* pServiceName, char* pDisplayName);
	virtual ~CEQ_Service(void);
public:
	
	bool RegisterService(int nArgc, char* pszArgv[]);
	
	
	virtual bool  OnStart(int nState = 0,int bLastNormalQuit = 1 )  =  0  ;


	
	virtual void  OnStop()   =  0  ;

	
	void SetIdleIntervalTime(int nTime); 
	
	virtual void  OnIdle()   =  0  ;

	
	virtual void  PostExceptionMessageEx(int nLevel,const char* szErrInfo,...)   =  0  ;
};
