#include "BackendApplication.h"
#include "PlayerClient.h"
#include "BackendServer.h"
#include "DataBuffer.h"

CBackendApplication::CBackendApplication()
{
}

CBackendApplication::~CBackendApplication()
{
}

void CBackendApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CBackendApplication::WorkingThreadsProc, this))
		return;
}

void CBackendApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CBackendApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CBackendApplication* pThis = (CBackendApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CBackendApplication::WorkingThreadsProc(void* Param)
{
	CBackendApplication* pThis = (CBackendApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CBackendApplication::WorkingProc()
{
	Run();
}

void CBackendApplication::Run()
{
	m_bStopThread = false;
	while (!m_bStopThread)
	{
		vector<void*>  RecvMsg;
		if (g_RecvMsg.size() > 0)
		{
			g_RecvMsgLock.EQ_Lock();
			RecvMsg.swap(g_RecvMsg);
			g_RecvMsgLock.EQ_UnLock();

			while (RecvMsg.size() > 0)
			{
				CDataBuffer* pDateBuffer = reinterpret_cast<CDataBuffer*>(RecvMsg.front());
				RecvMsg.erase(RecvMsg.begin());

				if (NULL == pDateBuffer)
					continue;

				ProcessMsgInfo(pDateBuffer->GetDataBuffer(), pDateBuffer->GetDataBufferLen(), pDateBuffer->GetClient(),
					pDateBuffer->GetIp(), pDateBuffer->GetPort());

				SAFE_DELETE(pDateBuffer);
			}
		}
		else
		{
			EQ_WaitTimeOut(1);
		}
	}
}

void  CBackendApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGateApplication::Exception!:%d", pPacketHead->nCmd);
	}
}