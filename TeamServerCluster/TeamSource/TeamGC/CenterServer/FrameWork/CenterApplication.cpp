#include "CenterApplication.h"
#include "PlayerClient.h"
#include "CenterServer.h"
#include "DataBuffer.h"

CCenterApplication::CCenterApplication()
{
}

CCenterApplication::~CCenterApplication()
{
}

void CCenterApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CCenterApplication::WorkingThreadsProc, this))
		return;
}

void CCenterApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CCenterApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CCenterApplication* pThis = (CCenterApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CCenterApplication::WorkingThreadsProc(void* Param)
{
	CCenterApplication* pThis = (CCenterApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CCenterApplication::WorkingProc()
{
	Run();
}

void CCenterApplication::Run()
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

void  CCenterApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	try
	{
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CCenterApplication::Exception!");
	}
}