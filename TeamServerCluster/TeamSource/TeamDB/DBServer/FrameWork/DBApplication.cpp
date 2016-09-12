#include "DBApplication.h"
#include "DataBuffer.h"

#include "../Logic/Resource/DBResourceManager.h"
#include "../Logic/Message/DBMessage.h"

CDBApplication::CDBApplication()
{
}

CDBApplication::~CDBApplication()
{
}

void CDBApplication::Start(int nIndex)
{
	if (!m_workThreads.CreateThreads(1, (void*)CDBApplication::WorkingThreadsProc, this))
		return;
	m_nIndex = nIndex;
	m_nRoleIndex = 0;
}

void CDBApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CDBApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CDBApplication* pThis = (CDBApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void*  CDBApplication::WorkingThreadsProc(void* Param)
{
	CDBApplication* pThis = (CDBApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CDBApplication::WorkingProc()
{
	Run();
}

void CDBApplication::Run()
{
	m_bStopThread = false;
	while (!m_bStopThread)
	{
		if (0 == m_nIndex)
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
		else
		{
			// timer DB save
			CDBResourceManager::Instance().SaveDBData(m_nIndex, m_nRoleIndex);
			EQ_WaitTimeOut(60000 * 2);
		}
	}
}

void  CDBApplication::ProcessMsgInfo(char*   pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;
	try
	{
		if ((pPacketHead->nCmd > ESDB_BEGIN) && (pPacketHead->nCmd < ESDB_END))
		{
			CDBMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CDBApplication::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}