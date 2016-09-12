#pragma once

#ifndef  EQ_FILELOG_FILE
#define  EQ_FILELOG_FILE
#include "EQ_Lock.h"

#define       BASE_LOG_FATAL            100                          
#define       BASE_LOG_ERROR            200                          
#define       BASE_LOG_INFO             300                          
#define       BASE_LOG_WARNING          400                          
#define       BASE_LOG_DEBUG            500                          
#define       BASE_LOG_TRACE            600                          

#define       MAX_LOGBUFFER_SIZE        (5 * 1024)                   

class CEQ_FileLog
{
public:
	CEQ_FileLog();
	virtual ~CEQ_FileLog();

public:
	
	void SetLogLevel( int  nLogLevel) { m_nLogLevel = nLogLevel; };
	int  GetLogLevel(){return m_nLogLevel;}

public:
	bool    InitLogFile(char* pszLogDir,char* pszLogFileName,short nLogLevel);
	bool    WriteLogInfo(int  nLogLevel,char* pszLogInfo);

protected:
	void    CheckFileSize();

private:
	int                    m_nLogLevel;
	char                   m_chrLogDir[256];
	char                   m_chrFileName[126];
	char                   m_chrLogFileName[512];
	FILE*                  m_pFile;
	CEQ_Lock               m_Lock;
	int                    m_nFileSize;
};


#endif
