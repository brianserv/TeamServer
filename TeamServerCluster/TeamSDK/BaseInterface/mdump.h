#pragma once
#if defined (_WIN32) || defined (_WIN64)

#include <stdlib.h>
//#include "dbghelp.h"
#include "imagehlp.h"

// based on dbghelp.h
typedef BOOL (WINAPI *MINIDUMPWRITEDUMP)(HANDLE hProcess, DWORD dwPid, HANDLE hFile, MINIDUMP_TYPE DumpType,
									CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
									CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
									CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam
									);

class MiniDumper
{
private:
	static LONG WINAPI TopLevelFilter( struct _EXCEPTION_POINTERS *pExceptionInfo );

public:
	MiniDumper( LPCSTR szDumpPath, LPCSTR szAppName, HWND hWnd = NULL );

	static HWND m_hWnd;
	static char m_szDumpName[_MAX_PATH + _MAX_FNAME];
};

//MiniDumper dump(NULL, "TDump");

#else
#endif

