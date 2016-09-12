#include "GameServer.h"

EQ_IMPLEMENT_CACHE(CGameServer, 100)
CGameServer::CGameServer() :m_nGameServerId(0), m_nGameServerPort(0), m_strGameServerIp("")
{
}

CGameServer::~CGameServer()
{
}

void CGameServer::SetGameSever(int nGameServerId, int nGameServerPort, string strGameServerIp)
{
	this->SetGameServerId(nGameServerId);
	this->SetGameServerPort(nGameServerPort);
	this->SetGameServerIp(strGameServerIp);
}

bool  CGameServer::UpdateHallRoomOnlineStatics(int nRoomID)
{
	HALLROOM_ONLINE_STATICS_MAP::iterator it;
	it = m_HallRoomOnlineStaticsMap.find(nRoomID);
	if (it == m_HallRoomOnlineStaticsMap.end())
	{
		HallRoomOnlineStatics* pHallRoomOnlineStatics = new HallRoomOnlineStatics();
		if (NULL == pHallRoomOnlineStatics)
		{
			return false;
		}
		m_HallRoomOnlineStaticsMap[nRoomID] = pHallRoomOnlineStatics;
		return  true;
	}
	else
	{
		HallRoomOnlineStatics* pHallRoomOnlineStatics = it->second;
		if (NULL == pHallRoomOnlineStatics)
		{
			return false;
		}

		pHallRoomOnlineStatics->nOnlineCounts++;

		return true;
	}
}