#pragma once
#include "EQ_FileLog.h"

#define       LOGIC_LOG_FATAL            10                           //致命错误，程序无法正常运行
#define       LOGIC_LOG_ERROR            20                           //一般错误
#define       LOGIC_LOG_INFO             30                           //显示程序各个部分正常启动的信息
#define       LOGIC_LOG_WARNING          40                           //警告，程序可以正常运行
#define       LOGIC_LOG_DEBUG            50                           //调试信息，判断问题所在
#define       LOGIC_LOG_TRACE            60                           //更详细的信息

class CEQ_Log : 
	public CEQ_FileLog
{
public:
	CEQ_Log();
	virtual ~CEQ_Log();

public:
	void   WriteErrorLogInfo(int  nLogLevel,char*  pszFormat,...);
	void   WriteErrorLogInfo2(int  nLogLevel,char*  pszFormat, va_list args);
};