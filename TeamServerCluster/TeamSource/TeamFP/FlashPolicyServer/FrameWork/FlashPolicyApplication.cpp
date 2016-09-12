#include "FlashPolicyApplication.h"
#include "FlashWebClient.h"
#include "FlashPolicyServer.h"
#include "DataBuffer.h"

CFlashPolicyApplication::CFlashPolicyApplication()
{
}

CFlashPolicyApplication::~CFlashPolicyApplication()
{
}

void CFlashPolicyApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CFlashPolicyApplication::WorkingThreadsProc, this))
		return;
}

void CFlashPolicyApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CFlashPolicyApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CFlashPolicyApplication* pThis = (CFlashPolicyApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CFlashPolicyApplication::WorkingThreadsProc(void* Param)
{
	CFlashPolicyApplication* pThis = (CFlashPolicyApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CFlashPolicyApplication::WorkingProc()
{
	Run();
}

void CFlashPolicyApplication::Run()
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

void  CFlashPolicyApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	try
	{
		CFlashWebClient *pFlashWebClient = reinterpret_cast<CFlashWebClient*>(pClient);
		if (NULL == pFlashWebClient)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "\r\nCant Find The Flash Web Client\r\n");
			return;
		}

		//Flash Policy
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "\r\n【Receive Flash Web Client Send Request】\r\n");

			char szSendBuf[512] = { 0 };
			sprintf(szSendBuf, "%s", "<?xml version=\"1.0\"?> <cross-domain-policy><allow-access-from domain=\"*\" to-ports=\"*\"/></cross-domain-policy>\0");
			string strSendBuf(szSendBuf);

			CFlashPolicyServer::Instance().SendClientMsg(szSendBuf, strSendBuf.length(), pFlashWebClient->GetIndex());

			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "\r\n【Send Response to Flash Web Client cross-domain-policy】:\r\n%s", szSendBuf);

			return;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CFlashPolicyApplication::Exception!");
	}
}