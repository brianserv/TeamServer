#include "HttpLinkApplication.h"
#include "DataBuffer.h"

#include "../Logic/Resource/ResourceManager.h"
#include "../Logic/Httplink/HttpLinkEvent.h"

CHttpLinkApplication::CHttpLinkApplication()
{
}

CHttpLinkApplication::~CHttpLinkApplication()
{
}

void  CHttpLinkApplication::Start(int nIndex)
{
	if (!m_workThreads.CreateThreads(1, (void*)CHttpLinkApplication::WorkingThreadsProc, this))
		return;
}
void CHttpLinkApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CHttpLinkApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CHttpLinkApplication* pThis = (CHttpLinkApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CHttpLinkApplication::WorkingThreadsProc(void* Param)
{
	CHttpLinkApplication* pThis = (CHttpLinkApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CHttpLinkApplication::WorkingProc()
{
	Run();
}

void CHttpLinkApplication::Run()
{
	m_bStopThread = false;
	while (!m_bStopThread)
	{
		Run_Request();
		Run_Response();
	}
}

bool CHttpLinkApplication::Run_Request()
{
	vector<void*>  ReqMsg;
	if (g_Req_HttpMsg.size() > 0)
	{
		g_Req_HttpMsg_Lock.EQ_Lock();
		ReqMsg.swap(g_Req_HttpMsg);
		g_Req_HttpMsg_Lock.EQ_UnLock();

		while (ReqMsg.size() > 0)
		{
			CDataBuffer* pDateBuffer = reinterpret_cast<CDataBuffer*>(ReqMsg.front());
			ReqMsg.erase(ReqMsg.begin());

			if (NULL == pDateBuffer)
				continue;

			Process_Request(pDateBuffer->GetDataBuffer());

			SAFE_DELETE(pDateBuffer);
		}

		return true;
	}
	EQ_WaitTimeOut(1);
	return false;
}

bool CHttpLinkApplication::Run_Response()
{
	vector<void*>  ResMsg;
	if (g_Res_HttpMsg.size() > 0)
	{
		g_Res_HttpMsg_Lock.EQ_Lock();
		ResMsg.swap(g_Res_HttpMsg);
		g_Res_HttpMsg_Lock.EQ_UnLock();

		while (ResMsg.size() > 0)
		{
			CDataBuffer* pDateBuffer = reinterpret_cast<CDataBuffer*>(ResMsg.front());
			ResMsg.erase(ResMsg.begin());

			if (NULL == pDateBuffer)
				continue;

			Process_Response(pDateBuffer->GetDataBuffer());

			SAFE_DELETE(pDateBuffer);
		}
		return true;
	}
	EQ_WaitTimeOut(1);
	return false;
}

void CHttpLinkApplication::Process_Request(char* pDataInfo)
{
	CHttpLinkEvent::Instance().ProcessEvent_Request(string(pDataInfo));
}

void CHttpLinkApplication::Process_Response(char* pDataInfo)
{
	CHttpLinkEvent::Instance().ProcessEvent_Response(string(pDataInfo));
}