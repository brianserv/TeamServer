#include "HallApplication.h"
#include "PlayerClient.h"
#include "HallServer.h"
#include "DataBuffer.h"

CHallApplication::CHallApplication()
{
}

CHallApplication::~CHallApplication()
{
}

void CHallApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CHallApplication::WorkingThreadsProc, this))
		return;
}

void CHallApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CHallApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CHallApplication* pThis = (CHallApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CHallApplication::WorkingThreadsProc(void* Param)
{
	CHallApplication* pThis = (CHallApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CHallApplication::WorkingProc()
{
	Run();
}

void CHallApplication::Run()
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

void  CHallApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
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