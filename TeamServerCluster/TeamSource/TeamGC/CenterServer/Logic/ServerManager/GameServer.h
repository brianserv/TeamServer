#pragma once
#ifndef __GAMESERVER_H__
#define __GAMESERVER_H__

#include "../../FrameWork/BaseDefine.h"

typedef struct HallRoomOnlineStatics
{
	int nRoomId;
	int nOnlineCounts;
};

class CGameServer
{
public:
	CGameServer();
	virtual ~CGameServer();
	EQ_DECLARE_CACHE(CGameServer)
public:
	inline void SetGameServerId(int nGameServerId) { m_nGameServerId = nGameServerId; };
	inline void SetGameServerPort(int nGameServerPort) { m_nGameServerPort = nGameServerPort; };
	inline void SetGameServerIp(string strGameServerIp) { m_strGameServerIp = strGameServerIp; };

	inline int GetGameServerId() { return m_nGameServerId; };
	inline int GetGameServerPort() { return m_nGameServerPort; };
	inline string GetGameServerIp() { return m_strGameServerIp; };
public:
	inline std::map<int, HallRoomOnlineStatics*>& GetHallRoomOnlineStaticsMap() { return m_HallRoomOnlineStaticsMap; }
public:
	void SetGameSever(int nGameServerId, int nGameServerPort, string strGameServerIp);
	bool UpdateHallRoomOnlineStatics(int nRoomID);

private:
	int  m_nGameServerId;
	int  m_nGameServerPort;
	string m_strGameServerIp;

	typedef std::map<int, HallRoomOnlineStatics*> HALLROOM_ONLINE_STATICS_MAP;
	HALLROOM_ONLINE_STATICS_MAP m_HallRoomOnlineStaticsMap;
};

#endif//__GAMESERVER_H__