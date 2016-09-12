#ifndef WIN_SERVICE_H
#define WIN_SERVICE_H

#if defined (_WIN32) || defined (_WIN64)

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x500
#endif
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <process.h>
#include <tchar.h>
#include "EQ_Service.h"

class CServiceModel  
{
	enum {eServiceNameLen = 128,};
public:
	CServiceModel();
	virtual ~CServiceModel();

	void SetServiceName(CEQ_Service* pMyService,LPCTSTR lpServiceName, LPCTSTR lpDisplayName);
	void SetIdleIntervalTime(DWORD dwTime);
	int  main(int argc, TCHAR* argv[]);

	static void WINAPI _ServiceControlHandler(DWORD dwContorlCode);
	static void WINAPI _ServiceMain(DWORD argc, TCHAR * argv[]);
	void WINAPI ServiceMain(DWORD argc, TCHAR* argv[]);
	void WINAPI ServiceControlHandler(DWORD dwContorlCode);

	void InstallService();
	void UninstallService();           
	BOOL RunService(TCHAR *szSvcName);

protected:

private:
	VOID ErrorHandler(DWORD dwErr);
	VOID TerminateSrv(DWORD dwErr);
	BOOL SendStatusToSCM(
		DWORD dwCurrentState,
		DWORD dwWin32ExitCode,
		DWORD dwServiceSpecificExitCode,
		DWORD dwCheckPoint,
		DWORD dwWaitHint
		);
	VOID StopService();
	BOOL InitService();
	VOID ResumeService();
	VOID PauseService();

	SERVICE_STATUS_HANDLE m_hServiceStatusHandle;
	HANDLE m_hTerminateEvent;
	TCHAR m_szServiceName[eServiceNameLen];
	TCHAR m_szDisplayName[eServiceNameLen];
	BOOL m_bPauseService ;
	BOOL m_bRunningService ;
	DWORD m_dwIdleIntervalTime;
	CEQ_Service* m_pMyService;

};

extern CServiceModel g_ServiceModel;

#else
#endif

#endif // WIN_SERVICE_H
