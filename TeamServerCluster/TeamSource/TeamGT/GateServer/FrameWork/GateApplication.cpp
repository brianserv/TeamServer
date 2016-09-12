#include "GateApplication.h"
#include "PlayerClient.h"
#include "GateServer.h"
#include "DataBuffer.h"

#include "../Logic/Message/GateMessage.h"

CGateApplication::CGateApplication()
{
}

CGateApplication::~CGateApplication()
{
}

void CGateApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CGateApplication::WorkingThreadsProc, this))
		return;
}

void CGateApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CGateApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CGateApplication* pThis = (CGateApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CGateApplication::WorkingThreadsProc(void* Param)
{
	CGateApplication* pThis = (CGateApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CGateApplication::WorkingProc()
{
	Run();
}

void CGateApplication::Run()
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

void  CGateApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
		CGateMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGateApplication::Exception!:%d", pPacketHead->nCmd);
	}
}