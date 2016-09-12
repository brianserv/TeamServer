#pragma once
#ifndef __GAMESERVER_MANAGER_H__
#define __GAMESERVER_MANAGER_H__

#include "GameServer.h"

class CGameServerManager : public CEQ_SingletonT<CGameServerManager>
{
public:
	CGameServerManager();
	virtual ~CGameServerManager();
public:
	bool RegisterServer(int nGameServerId, int nGameServerPort, string strGameServerIp);
	bool UnRegisterServer(int nGameServerId);
public:
	CGameServer* GetGameServer(int nGameServerId);
	bool  GetIsRegistedGameServer(int nGameServerId);

private:
	typedef std::map<int, CGameServer*> GAMESERVER_MAP;
	GAMESERVER_MAP m_GameServerMap;
};

#endif//__GAMESERVER_MANAGER_H__