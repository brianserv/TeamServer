#include "DLApplication.h"
#include "DataBuffer.h"

#include "../Logic/Message/DLMessage.h"

CDLApplication::CDLApplication()
{
}

CDLApplication::~CDLApplication()
{
}

void CDLApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CDLApplication::WorkingThreadsProc, this))
		return;
}

void CDLApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CDLApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CDLApplication* pThis = (CDLApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void*  CDLApplication::WorkingThreadsProc(void* Param)
{
	CDLApplication* pThis = (CDLApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CDLApplication::WorkingProc()
{
	Run();
}

void CDLApplication::Run()
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

void  CDLApplication::ProcessMsgInfo(char*   pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;
	try
	{
		if ((pPacketHead->nCmd > ESDL_BEGIN) && (pPacketHead->nCmd < ESDL_END))
		{
			CDLMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDLApplication::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}