#include "HallClient.h"
#include "BaseDefine.h"
#include "DataBuffer.h"

#include "WebSocketServer.h"
#include "../../Protocols/CommonProtocol.h"

CHallClient::CHallClient()
{
	memset(m_szSrvIP, 0, sizeof(m_szSrvIP));
	m_bISSuccConnect = false;
	m_pRecvDataBuffer = NULL;
	m_nRemainLen = 0;
}

CHallClient::~CHallClient()
{
}

void  CHallClient::StartClient(char* pSrvIP, short nSrvPort)
{
	if (!InitParams(pSrvIP, nSrvPort))
		return;
	if (!m_workThreads.CreateThreads(1, (void*)CHallClient::WorkingThreadsProc, this))
		return;
}

void  CHallClient::StopClient()
{
	StopThread();
}

bool CHallClient::InitParams(char* pSrvIP, short nSrvPort)
{
	bool bFlag = true;
	m_bISSuccConnect = false;
	m_pRecvDataBuffer = new char[SERVER_MESSAGE_LEN_MAX];
	if (NULL == m_pRecvDataBuffer)
	{
		bFlag = false;
		return bFlag;
	}
	m_nRemainLen = 0;
	memset(m_szSrvIP, 0, sizeof(m_szSrvIP));
	EQ_SPRINTF(m_szSrvIP, sizeof(m_szSrvIP), "%s", pSrvIP);
	m_nSrvPort = nSrvPort;

	return bFlag;
}

int CHallClient::InitTcpSocket()
{
	if (!m_TCPSocket.Create(AF_INET, SOCK_STREAM, 0))
		return 1;

	if (!CEQ_Socket::SetNonblocking(m_TCPSocket.GetSocketId(), true))
		return 2;

	return 0;
}

bool CHallClient::ConnectSrv()
{
	bool          bFlag = false;
	int           nReValue = 0;
	unsigned int  nStart = 0;
	int           nRetryNum = 0;
	//
	if (m_bISSuccConnect)
		return true;
	nReValue = m_TCPSocket.Connect(m_szSrvIP, m_nSrvPort, true);
	nStart = CEQ_Time::Instance().EQ_GetTime();
	while (1)
	{
		nReValue = m_TCPSocket.Wait(500, CAN_CONNECT);
		if (nReValue == -1)
		{
			if ((nStart + 30) < CEQ_Time::Instance().EQ_GetTime())
			{
				nReValue = 0;
				break;
			}
			if (nRetryNum < 3)
			{
				m_TCPSocket.Close();
				EQ_WaitTimeOut(150);
				m_TCPSocket.Connect(m_szSrvIP, m_nSrvPort, true);
				nRetryNum++;
			}
			else
			{
				break;
			}
		}
		else
		{
			if ((nReValue & CAN_CONNECT) == CAN_CONNECT)
			{
				m_TCPSocket.SetSockBuff();
				m_bISSuccConnect = true;
				return true;
			}
			else
			{
				if ((nStart + 30) < CEQ_Time::Instance().EQ_GetTime())
				{
					nReValue = 0;
					break;
				}

				EQ_WaitTimeOut(100);
			}
		}
	}

	return bFlag;
}

void CHallClient::DisConnectSrv()
{
	m_bISSuccConnect = false;
	m_bIsRegister = false;
	m_TCPSocket.Close();
}

bool CHallClient::CheckISSuccConnect()
{
	if (!m_bISSuccConnect)
	{
		if (!ConnectSrv())
		{
			return false;
		}
		else
		{
			m_nRemainLen = 0;
			if (NULL != m_pRecvDataBuffer)
			{
				memset(m_pRecvDataBuffer, 0, SERVER_MESSAGE_LEN_MAX);
			}
		}
	}
	return true;
}

#if defined (WINDOWS_VESION)
DWORD CHallClient::WorkingThreadsProc(LPVOID lpParam)
{
	CHallClient* pThis = (CHallClient*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void*  CHallClient::WorkingThreadsProc(void* Param)
{
	CHallClient* pThis = (CHallClient*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CHallClient::WorkingProc()
{
	if (InitTcpSocket())
		return;
	try
	{
		m_bStopThread = false;
		m_bIsRegister = false;
		m_nRegisterTime = 0;
		m_nHeartBeatTime = 0;

		while (!m_bStopThread)
		{
			if ((!m_bIsRegister) && ((CEQ_Time::Instance().EQ_GetTime() - m_nHeartBeatTime) > 3))
			{
				Process_HeartBeatReq();
				m_nHeartBeatTime = CEQ_Time::Instance().EQ_GetTime();
			}
			RecvAllData();
			EQ_WaitTimeOut(1);
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameClient::WorkingProc occour exception !");
	}

	ReleaseResource();
}

void CHallClient::StopThread()
{
	m_bStopThread = true;
}

void CHallClient::ReleaseResource()
{
	DisConnectSrv();
	//
	if (NULL != m_pRecvDataBuffer)
	{
		delete[]m_pRecvDataBuffer;
		m_pRecvDataBuffer = NULL;
	}
	//
}

void CHallClient::SendData(char* pSendDataInfo, long nSendDataLen)
{
	int     nReValue = 0;
	if (NULL == pSendDataInfo || nSendDataLen <= 0)
		return;

	if (!CheckISSuccConnect())
	{
		return;
	}
	nReValue = m_TCPSocket.Send(pSendDataInfo, nSendDataLen, 0);
}

void CHallClient::RecvAllData()
{
	int        nShouldRecvLen = SERVER_MESSAGE_LEN_MAX - m_nRemainLen;
	int        nResult = 0;
	int        nWaitTime = 1;
	int        nRecvedLen = 0;
	int        nErrorValue = 0;
	char*      pRecvDataTemp = NULL;
	PACKETHEAD  *pPacketHeader = NULL;

	if (!CheckISSuccConnect())
	{
		return;
	}

	if ((nResult = m_TCPSocket.Wait(nWaitTime, CAN_REEQ)) >= 0)
	{
		if ((nResult & CAN_REEQ) == CAN_REEQ)
		{
			while ((nRecvedLen = m_TCPSocket.Receive(m_pRecvDataBuffer + m_nRemainLen, nShouldRecvLen, 0)) > 0)
			{
				m_nRemainLen += nRecvedLen;
				pRecvDataTemp = m_pRecvDataBuffer;
				while (m_nRemainLen >= sizeof(PACKETHEAD))
				{
					pPacketHeader = reinterpret_cast<PACKETHEAD*>(pRecvDataTemp);

					if (pPacketHeader->GetLength() < sizeof(PACKETHEAD)
						|| pPacketHeader->GetLength() > SERVER_MESSAGE_LEN_MAX)
					{
						DisConnectSrv();
						return;
					}

					if (pPacketHeader->GetLength() > m_nRemainLen)
					{
						g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CTcpClientSocketThread::RecvAllData can't recv alldata,RemoteIP:%s,AllLen:%ld,RecvedLen:%ld,RemailLen:%ld,ShouldLen:%ld",
							m_szSrvIP,
							pPacketHeader->nSize,
							nRecvedLen,
							m_nRemainLen,
							nShouldRecvLen);

						break;
					}

					ProcessClientMsgInfo(pRecvDataTemp, pPacketHeader->GetLength(), m_szSrvIP, m_nSrvPort);

					m_nRemainLen -= pPacketHeader->GetLength();
					pRecvDataTemp += pPacketHeader->GetLength();
				}

				if ((m_nRemainLen > 0) && (pRecvDataTemp != (char*)m_pRecvDataBuffer))
				{
					memmove(m_pRecvDataBuffer, pRecvDataTemp, m_nRemainLen);
				}

				nShouldRecvLen = SERVER_MESSAGE_LEN_MAX - m_nRemainLen;
			}

#if defined (WINDOWS_VESION)
			if (nRecvedLen == -1 || nRecvedLen == 0)
			{
				nErrorValue = WSAGetLastError();
				if (nErrorValue != 10035)
				{
					DisConnectSrv();
				}
			}
#else
			if (nRecvedLen == 0)
			{
				nErrorValue = errno;
				DisConnectSrv();
			}
			else if ((nRecvedLen < 0) && (!(errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN)))
			{
				nErrorValue = errno;
				DisConnectSrv();
			}
#endif
		}
	}
}

void CHallClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen, char* pSourceIP, short nSourcePort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
		switch (pPacketHead->nCmd)
		{
		case ESGT_PING_S2GT_HEARTBEAT_RES:
			Process_HeartBeatRes(pDataInfo, nDataLen);
			break;
		default:
			CWebSocketServer::Instance().SendClientMsg(pDataInfo, nDataLen, pPacketHead->GetIndex());
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameClient2::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}

void CHallClient::Process_HeartBeatReq()
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	GTHeartBeatReq* pGTHeartBeatReq = reinterpret_cast<GTHeartBeatReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pGTHeartBeatReq))
		return;

	pPacketHead->SetPacketHead(ESGT_PING_GT2S_HEARTBEAT_REQ);
	sendlen = pPacketHead->GetLength();
	SendData(sendbuf, sendlen);
}

void CHallClient::Process_HeartBeatRes(char* pDataInfo, long nDataLen)
{
	GTHeartBeatRes* pGTHeartBeatRes = reinterpret_cast<GTHeartBeatRes*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pGTHeartBeatRes)
		return;
	m_bIsRegister = false;
}
