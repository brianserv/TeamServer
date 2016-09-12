#include "WebSocketApplication.h"
#include "DataBuffer.h"

#include "../Logic/WebSocket/WebSocketWorker.h"

CWebSocketApplication::CWebSocketApplication()
{
}

CWebSocketApplication::~CWebSocketApplication()
{
}

void CWebSocketApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CWebSocketApplication::WorkingThreadsProc, this))
		return;
}

void CWebSocketApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CWebSocketApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CWebSocketApplication* pThis = (CWebSocketApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CWebSocketApplication::WorkingThreadsProc(void* Param)
{
	CWebSocketApplication* pThis = (CWebSocketApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CWebSocketApplication::WorkingProc()
{
	Run();
}

void CWebSocketApplication::Run()
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

void  CWebSocketApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = (PACKETHEAD*)(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
		CWebSocketWorker::Instance().WebSocketFrameHandler(pDataInfo, nDataLen, pPacketHead, pClient);
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CWebSocketApplication::Exception ");
	}
}