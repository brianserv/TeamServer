#pragma once
#ifndef __CENTER_CLIENT_H__
#define __CENTER_CLIENT_H__

#include "EQSocket.h"
#include "EQ_DataType.h"
#include "EQ_MultiThreads.h"

class CCenterClient
{
public:
	CCenterClient();
	virtual ~CCenterClient();

public:
	void  StartClient(char* pSrvIP, short nSrvPort);
	void  StopClient();
	void  SendData(char* pSendDataInfo, long nSendDataLen);

protected:
	bool  InitParams(char* pSrvIP, short nSrvPort);
	int   InitTcpSocket();
	bool  ConnectSrv();
	void  DisConnectSrv();
	bool  CheckISSuccConnect();
	void  ReleaseResource();
	void  RecvAllData();
	void  StopThread();

protected:

	void WorkingProc();
#if defined (WINDOWS_VESION)
	static DWORD WINAPI  WorkingThreadsProc(LPVOID lpParam);
#else
	static void* WorkingThreadsProc(void* Param);
#endif

private:
	char                  m_szSrvIP[16];
	short                 m_nSrvPort;
	bool                  m_bISSuccConnect;
	CEQ_Socket            m_TCPSocket;
	char*                 m_pRecvDataBuffer;
	int                   m_nRemainLen;
	CEQ_MultiThreads      m_workThreads;
	bool                  m_bStopThread;

public:
	void ProcessClientMsgInfo(char*   pDataInfo, long nDataLen, char* pSourceIP, short nSourcePort);
public:
	void Process_RegisterReq();
	void Process_RegisterRes(char*   pDataInfo, long nDataLen);
public:
	void Process_HeartBeatReq();
	void Process_HeartBeatRes(char*   pDataInfo, long nDataLen);
private:
	bool                m_bIsRegister;
	unsigned int        m_nRegisterTime;
	unsigned int        m_nHeartBeatTime;
};

#endif//__CENTER_CLIENT_H__