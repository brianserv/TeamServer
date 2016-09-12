#pragma once
#include "EQNet.h"

class CBaseClient :
	public CEQ_TCPClientHandler
{
public:
	CBaseClient(CEQ_TcpClient *pClient)
		: m_pClient(pClient),m_nPeerNetAddr(0),m_nPeerPort(0)
	{
		memset(m_szPeerIp,0,16);
	};
public:
	virtual ~CBaseClient(void)
	{
		m_pClient = NULL;
	};

public:

	virtual void  PostMessage(char* pMessage,int nMessageLen ,bool bClose = false )
	{
		if (NULL != m_pClient)
		{
			m_pClient->Send(pMessage,nMessageLen,bClose);
		}
	};

public:
	unsigned int  GetPeerNetAddr() const { return m_nPeerNetAddr ; } ;
	char*         GetPeerNetAddr2() {return m_szPeerIp;};
	int           GetPeerPort()    const { return m_nPeerPort; } ;
	bool          GetPeerAddr()
	{
		if ( NULL != m_pClient)
		{
			return m_pClient->GetPeerAddr(m_szPeerIp,m_nPeerNetAddr,m_nPeerPort);
		}
		return false;
	}

private:
	CEQ_TcpClient*       m_pClient; 
	char                 m_szPeerIp[16];
	unsigned int         m_nPeerNetAddr ;
	int                  m_nPeerPort;
};