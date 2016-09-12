#include "DBClient.h"
#include "EQ_String.h"
#include "EQ_Time.h"
#include "BaseDefine.h"
#include "DataBuffer.h"

#include "GameServer.h"
#include "../../Protocols/CommonProtocol.h"

CDBClient::CDBClient()
{
	memset(m_szSrvIP, 0, sizeof(m_szSrvIP));
	m_bISSuccConnect = false;
	m_pRecvDataBuffer = NULL;
	m_nRemainLen = 0;
}

CDBClient::~CDBClient()
{
}

void  CDBClient::StartClient(char* pSrvIP, short nSrvPort)
{
	if (!InitParams(pSrvIP, nSrvPort))
		return;
	if (!m_workThreads.CreateThreads(1, (void*)CDBClient::WorkingThreadsProc, this))
		return;
}

void  CDBClient::StopClient()
{
	StopThread();
}

bool CDBClient::InitParams(char* pSrvIP, short nSrvPort)
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

int CDBClient::InitTcpSocket()
{
	if (!m_TCPSocket.Create(AF_INET, SOCK_STREAM, 0))
		return 1;

	if (!CEQ_Socket::SetNonblocking(m_TCPSocket.GetSocketId(), true))
		return 2;

	return 0;
}

bool CDBClient::ConnectSrv()
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

void CDBClient::DisConnectSrv()
{
	m_bISSuccConnect = false;
	m_bIsRegister = false;
	m_TCPSocket.Close();
}

bool CDBClient::CheckISSuccConnect()
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
DWORD CDBClient::WorkingThreadsProc(LPVOID lpParam)
{
	CDBClient* pThis = (CDBClient*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void*  CDBClient::WorkingThreadsProc(void* Param)
{
	CDBClient* pThis = (CDBClient*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CDBClient::WorkingProc()
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
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBClient::WorkingProc occour exception !");
	}

	ReleaseResource();
}

void CDBClient::StopThread()
{
	m_bStopThread = true;
}

void CDBClient::ReleaseResource()
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

void CDBClient::SendData(char* pSendDataInfo, long nSendDataLen)
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

void CDBClient::RecvAllData()
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

void CDBClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen, char* pSourceIP, short nSourcePort)
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
		case ESDB_PING_DB2S_HEARTBEAT_RES:
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

void CDBClient::Process_HeartBeatReq()
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;

	char* pTemp = sendbuf;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	DBHeartBeatReq* pDBHeartBeatReq = reinterpret_cast<DBHeartBeatReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pPacketHead) || (NULL == pDBHeartBeatReq))
		return;

	pPacketHead->SetPacketHead(ESDB_PING_S2DB_HEARTBEAT_REQ);
	sendlen = pPacketHead->GetLength();
	CGameServer::Instance().SendDBMsg(sendbuf, sendlen, pPacketHead);
}

void CDBClient::Process_HeartBeatRes(char* pDataInfo, long nDataLen)
{
	DBHeartBeatRes* pDBHeartBeatRes = reinterpret_cast<DBHeartBeatRes*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pDBHeartBeatRes)
		return;
	m_bIsRegister = false;
}