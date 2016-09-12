#include "PlayerClient.h"
#include "GateServer.h"

#include "DataBuffer.h"

#include "../Logic/Role/RoleManager.h"
#include "../Logic/Message/CSMessage/CSMessage.h"
#include "../Logic/Message/GSMessage/GSMessage.h"

EQ_IMPLEMENT_CACHE(CPlayerClient, 1000)
CPlayerClient::CPlayerClient(CEQ_TcpClient *pClient)
	:CBaseClient(pClient)
{
	m_nIndex = -1;
	m_nRoleId = 0;
	m_bIsGirl = false;
}

CPlayerClient::~CPlayerClient()
{
	m_nIndex = 0;
	m_nRoleId = 0;
	m_bIsGirl = false;
}

void  CPlayerClient::OnRecvMessage(char* pNewMessage, int nMessageLen, unsigned int nRecvTickTime)
{
	ProcessClientMsgInfo(pNewMessage, nMessageLen);
}

void  CPlayerClient::OnDisconnect(int nErrorCode)
{
#if defined (WINDOWS_VESION)
	OnDisconnect_Windows();
#else
	OnDisconnect_Linux();
#endif
}

void  CPlayerClient::SendMessageData(char*   pDataInfo, long nDataLen, bool bClose)
{
	PostMessage(pDataInfo, nDataLen, bClose);
}

void  CPlayerClient::ProcessClientMsgInfo(char*   pDataInfo, long nDataLen)
{
	if (NULL == pDataInfo || nDataLen <= 0)
		return;

	PACKETHEAD* pPacketHead = reinterpret_cast<PACKETHEAD*>(pDataInfo);
	if ((NULL == pPacketHead))
		return;

	try
	{
		CDataBuffer* pDataBuffer = new CDataBuffer(pDataInfo, nDataLen, this, GetPeerNetAddr2(), GetPeerPort());
		if (NULL == pDataBuffer)
			return;

		g_RecvMsgLock.EQ_Lock();
		g_RecvMsg.push_back(pDataBuffer);
		g_RecvMsgLock.EQ_UnLock();
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CPlayerClient::Exception Cmd : %ld", pPacketHead->nCmd);
	}
}

void  CPlayerClient::OnDisconnect_Windows()
{
#if defined (WINDOWS_VESION)
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!");
	if (this->IsCheckGirl())
	{
		if (m_nGirlId <= 0)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nGirlId <= 0)");
			//CGSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
			CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			return;
		}
		//CGSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		g_GameClient.Process_GirlDisconnectReq(m_nGirlId);
	}
	else
	{
		if (m_nRoleId <= 0)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nRoleId <= 0)");
			CCSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
			CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			return;
		}
		CCSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		CRoleManager::Instance().DisConnectRole(m_nRoleId);
		g_GameClient.Process_RoleDisconnectReq(m_nRoleId);
	}
	CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
#else
#endif
}

void  CPlayerClient::OnDisconnect_Linux()
{
#if defined (WINDOWS_VESION)
#else
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!");
	if (this->IsCheckGirl())
	{
		if (m_nGirlId <= 0)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nGirlId <= 0)");
			//CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			CGSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		}
		else
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nGirlId > 0)");

			CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			g_GameClient.Process_GirlDisconnectReq(m_nGirlId);
			//CGSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		}
	}
	else
	{
		if (m_nRoleId <= 0)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nRoleId <= 0)");
			CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			CCSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		}
		else
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "OnDisconnect!!!(m_nRoleId > 0)");
			CGateServer::Instance().DelPlayerClientInfo(this, m_nIndex);
			g_GameClient.Process_RoleDisconnectReq(m_nRoleId);
			CRoleManager::Instance().DisConnectRole(m_nRoleId);
			CCSMessage::Instance().ProcessMsg_HeartBeatRes(m_nIndex, true);
		}
	}
#endif
}