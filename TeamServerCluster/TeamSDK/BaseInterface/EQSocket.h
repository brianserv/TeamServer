#pragma once

#ifndef  EQ_SOCKET_FILE
#define  EQ_SOCKET_FILE
#include "EQNet.h"

#if defined (_WIN32) || defined (_WIN64)
#pragma comment(lib, "ws2_32.lib")
#pragma  comment(lib,"mswsock.lib")
#else
#define    SOCKET        int
#endif

#define  MAXLEN          1024
#define  CAN_REEQ	     101
#define  CAN_WRITE       102
#define  CAN_CONNECT     103
#define  CAN_ACCEPT      104

class CEQ_Socket
{
public:
	CEQ_Socket();
	virtual ~CEQ_Socket();

public:
	
	static bool  InitNetIO();
	
	static void  ExitNetIO();
	
	static bool SetNonblocking(SOCKET fd,bool bIsNonblocking = true);
	
	static void CloseSocket(SOCKET fd);
	
	static bool GetIONetInfo(SOCKET fd,char* szIP,unsigned int & nNetAddr, int & nPort);
	
	static unsigned long INetAddr(const char* pIp);

	static char*  INetNToA(unsigned long nIP);

public:
	SOCKET GetSocketId(){return m_sock;}

public:
	
	bool   Create(int af, int type, int protocol);

	bool   Bind(int nProt, char* pAddress = NULL);
	
	bool   Listen(int nConnectionBacklog = 5);
	
	bool   Accept(SOCKET &socket, struct sockaddr *lpSockAddr, int *lpSockAddrLen);
	
	bool   Accept(CEQ_Socket & rConnectedSocket, struct sockaddr* lpSockAddr, int* lpSockAddrLen);
	
	int    Connect(char* pszHostAddress, unsigned int nHostPort, bool bBlock);
	
	int    Send(const void *lpBuf, int nBufLen, int nFlags);
	
	int    SendTo(const void *lpBuf, int nBufLen, unsigned long lDestIP, unsigned int nHostPort, int nFlags);
	
	int    SendTo(const void *lpBuf, int nBufLen, char* pAddress, unsigned int nHostPort, int nFlags);
	
	int    Receive(void *lpBuf, int nBufLen, int nFlags);
	
	int    ReceiveFrom(void *lpBuf, int nBufLen,  unsigned long &lIP, unsigned int &nSocketPort, int nFlags);

	void   Attach(SOCKET sock);
	
	bool   IsInvaild();

	int    Wait(long millis, int flag);
	
	void   Close();	

	void   SetSockBuff(long nSockRecvBufferLen = 5*1024*1024,long nSockSendBufferLen=5*1024*1024);
	
	void   GetSockName(unsigned long& lIP,unsigned int &nPort);

protected:
	SOCKET       m_sock;
};



#endif
