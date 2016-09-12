#pragma once

#ifndef  EQ_NET_FILE
#define  EQ_NET_FILE
#include "EQUtils.h"


#define    CLIENTCONN_NUM_MAX                           10000                                       
#define    DISCONN_WAIT_TIMEOUT                         30                                          
#define    CLEANCONN_WAIT_TIMEOUT                       10                                          
#define    NETHEAD_DATA_OFFSET                          2
#define    NETHEAD_DATA_OFFLEN                          2


class CEQ_TcpClient
{
public:
	CEQ_TcpClient(){};
	virtual ~CEQ_TcpClient(){};

public:	
	
	virtual int  Send( char* pMessage , int nMessageLen, bool bClose = false ) = 0;

	
	virtual void  Close() = 0; 	

	
	virtual bool  GetPeerAddr(char* szIP,unsigned int & nNetAddr, int & nPort) = 0;

	
	virtual int GetLastIOError() = 0; 
};



class CEQ_TCPClientHandler
{
public:
	CEQ_TCPClientHandler(){};
	virtual ~CEQ_TCPClientHandler(){};

public:
	
	virtual void  OnRecvMessage(char* pNewMessage,int nMessageLen,unsigned int nRecvTickTime) = 0; 

	virtual void  OnDisconnect(int nErrorCode) = 0;    
};



class CEQ_TCPAcceptorHander
{
public:
	CEQ_TCPAcceptorHander(){};
	virtual ~CEQ_TCPAcceptorHander(){};

public:
	virtual CEQ_TCPClientHandler* EQ_OnAcceptEx(CEQ_TcpClient* pNewClient) = 0;  
};


enum  eNetIOErrorCode
{
	eIOSuccess                 = 0 ,           
	eIOSystemError             = 200001,      
	eIOSelfClose               = 200002,      
	eIOClosed                  = 200003,      
	eIOTimeOut                 = 200004,      
	eIOReadExc                 = 200005,      
	eIOPostRecvFailed          = 200006,      
	eIOPostSendFailed          = 200007,      
	eIOGetQCStatusFailed       = 200008,      
	eIONeedPostSendAgain       = 200009,      
	eIOServerClose             = 200010,      
	eIOListenPostRecvFailed    = 200011,      
	eIOErrorOPCode             = 200012,      
	eIOSendAfterSelfClose      = 200013,      
};

#endif
