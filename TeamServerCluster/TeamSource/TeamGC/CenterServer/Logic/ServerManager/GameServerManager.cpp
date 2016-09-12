#include "GameServerManager.h"

CGameServerManager::CGameServerManager()
{
}

CGameServerManager::~CGameServerManager()
{
}

bool CGameServerManager::RegisterServer(int nGameServerId, int nGameServerPort, string strGameServerIp)
{
	if (!GetIsRegistedGameServer(nGameServerId))
	{
		return false;
	}

	CGameServer* pGameServer = new CGameServer();
	if (NULL == pGameServer)
	{
		return false;
	}
	pGameServer->SetGameSever(nGameServerId, nGameServerPort, strGameServerIp);
	m_GameServerMap[nGameServerId] = pGameServer;
	return true;
}

bool CGameServerManager::UnRegisterServer(int nGameServerId)
{
	m_GameServerMap.erase(nGameServerId);
	return true;
}

CGameServer* CGameServerManager::GetGameServer(int nGameServerId)
{
	GAMESERVER_MAP::iterator it;
	it = m_GameServerMap.find(nGameServerId);
	if (it != m_GameServerMap.end())
	{
		CGameServer* pGameServer = it->second;
		if (NULL == pGameServer)
		{
			return NULL;
		}
		return pGameServer;
	}
	return NULL;
}
bool  CGameServerManager::GetIsRegistedGameServer(int nGameServerId)
{
	CGameServer* pGameServer = GetGameServer(nGameServerId);
	if (NULL != pGameServer)
	{
		return false;
	}
	return true;
}