#include "DBLogClient.h"
#include "EQ_String.h"
#include "EQ_Time.h"
#include "BaseDefine.h"
#include "DataBuffer.h"

#include "GameServer.h"
#include "../../Protocols/CommonProtocol.h"

CDBLogClient::CDBLogClient()
{
	memset(m_szSrvIP, 0, sizeof(m_szSrvIP));
	m_bISSuccConnect = false;
	m_pRecvDataBuffer = NULL;
	m_nRemainLen = 0;
}

CDBLogClient::~CDBLogClient()
{
}

void  CDBLogClient::StartClient(char* pSrvIP, short nSrvPort)
{
	if (!InitParams(pSrvIP, nSrvPort))
		return;
	if (!m_workThreads.CreateThreads(1, (void*)CDBLogClient::WorkingThreadsProc, this))
		return;
}

void  CDBLogClient::StopClient()
{
	StopThread();
}

bool CDBLogClient::InitParams(char* pSrvIP, short nSrvPort)
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

int CDBLogClient::InitTcpSocket()
{
	if (!m_TCPSocket.Create(AF_INET, SOCK_STREAM, 0))
		return 1;

	if (!CEQ_Socket::SetNonblocking(m_TCPSocket.GetSocketId(), true))
		return 2;

	return 0;
}

bool CDBLogClient::ConnectSrv()
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

void CDBLogClient::DisConnectSrv()
{
	m_bISSuccConnect = false;
	m_bIsRegister = false;
	m_TCPSocket.Close();
}

bool CDBLogClient::CheckISSuccConnect()
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
DWORD CDBLogClient::WorkingThreadsProc(LPVOID lpParam)
{
	CDBLogClient* pThis = (CDBLogClient*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void*  CDBLogClient::WorkingThreadsProc(void* Param)
{
	CDBLogClient* pThis = (CDBLogClient*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CDBLogClient::WorkingProc()
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
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBLogClient::WorkingProc occour exception !");
	}

	ReleaseResource();
}

void CDBLogClient::StopThread()
{
	m_bStopThread = true;
}

void CDBLogClient::ReleaseResource()
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

void CDBLogClient::SendData(char* pSendDataInfo, long nSendDataLen)
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

void CDBLogClient::RecvAllData()
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
							pPacketHeader->GetLength(),
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

void CDBLogClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen, char* pSourceIP, short nSourcePort)
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
		case ESDL_PING_DL2S_HEARTBEAT_RES:
			Process_HeartBeatRes(pDataInfo, nDataLen);
		default:
			break;
		}

		CDataBuffer* pDataBuffer = new CDataBuffer(pDataInfo, nDataLen, this, pSourceIP, nSourcePort);
		if (NULL == pDataBuffer)
			return;

		g_RecvMsgLock.EQ_Lock();
		g_RecvMsg.push_back(pDataBuffer);
		g_RecvMsgLock.EQ_UnLock();
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameClient2::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}

void CDBLogClient::Process_HeartBeatReq()
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	DLHeartBeatReq* pDLHeartBeatReq = reinterpret_cast<DLHeartBeatReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pDLHeartBeatReq))
		return;

	pPacketHead->SetPacketHead(ESDL_PING_S2DL_HEARTBEAT_REQ);
	sendlen = pPacketHead->GetLength();
	CGameServer::Instance().SendDBLogMsg(sendbuf, sendlen, pPacketHead);
}

void CDBLogClient::Process_HeartBeatRes(char* pDataInfo, long nDataLen)
{
	DLHeartBeatRes* pDLHeartBeatRes = reinterpret_cast<DLHeartBeatRes*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pDLHeartBeatRes)
		return;

	m_bIsRegister = false;
}