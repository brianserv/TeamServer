#include "GameApplication.h"
#include "PlayerClient.h"
#include "GameServer.h"
#include "DataBuffer.h"

#include "../Logic/GameHall/Texas/TexasGame/TexasGameManager.h"

#include "../Logic/Role/RoleManager.h"
#include "../Logic/Message/GameMessage.h"

#include "../Logic/Message/DBMessage/DBMessage.h"

#include "../Logic/GameHall/GameHall.h"

CGameApplication::CGameApplication()
{
}

CGameApplication::~CGameApplication()
{
}

void CGameApplication::Start()
{
	if (!m_workThreads.CreateThreads(1, (void*)CGameApplication::WorkingThreadsProc, this))
		return;
}

void CGameApplication::Stop()
{
	m_bStopThread = false;
}

#if defined (WINDOWS_VESION)
DWORD CGameApplication::WorkingThreadsProc(LPVOID lpParam)
{
	CGameApplication* pThis = (CGameApplication*)lpParam;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return 0;
}
#else
void* CGameApplication::WorkingThreadsProc(void* Param)
{
	CGameApplication* pThis = (CGameApplication*)Param;
	if (pThis)
	{
		pThis->WorkingProc();
	}
	return NULL;
}
#endif

void CGameApplication::WorkingProc()
{
	Run();
}

void CGameApplication::Run()
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
			if (g_StartServer & g_ResourceLoadSucc & g_GameRoomBindSucc)
			{
				OnTimer();
				EQ_WaitTimeOut(1);
			}
		}
	}
}

void  CGameApplication::OnTimer()
{
	if (g_PrizePool)
	{
		OnReleaseRoleTimer();
		OnReleaseTexasGameTimer();
		OnTexasGameTimer();
	}
	else
	{
		CDBMessage::Instance().ProcessMsg_LoadPrizePoolReq();
	}
}
void  CGameApplication::OnReleaseRoleTimer()
{
	// Timer Release UnUsed Role
	CRoleManager::Instance().ReleaseRole();
}

void CGameApplication::OnTexasGameTimer()
{
	CTexasGameManager::Instance().OnTimer();
}

void  CGameApplication::OnReleaseTexasGameTimer()
{
	CGameHall::Instance().Release_Vip_TexasGame_Room();
}

void  CGameApplication::ProcessMsgInfo(char* pDataInfo, long nDataLen, void* pClient, char* pIp, int nPort)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if (NULL == pPacketHead)
		return;

	try
	{
		CGameMessage::Instance().ProcessMsg(pDataInfo, nDataLen, pPacketHead, pClient);
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGameApplication::Exception!");
	}
}