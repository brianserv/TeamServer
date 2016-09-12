#pragma  once
#ifndef __TEXAS_ROOM_MANAGER_H__
#define __TEXAS_ROOM_MANAGER_H__

#include "../../../../FrameWork/BaseDefine.h"
#include "TexasRoom.h"

typedef vector<int> GameRoomIdVec;
typedef map<int, CTexasRoom*> TexasRoomMap;

class CTexasRoomManager : public CEQ_SingletonT<CTexasRoomManager>
{
public:
	CTexasRoomManager();
	virtual ~CTexasRoomManager();
public:
	bool Init();
	bool InitEx();
	bool Clear();
	bool CreateRoom(int nRoomId, int nRoomType);
	bool ReleaseVipRoom(int nRoomId);
public:
	void ReleaseVipRoom();
public:
	inline TexasRoomMap& GetTexasRoomMap() { return m_TexasRoomMap; };
public:
	CTexasRoom* GetTexasRoom(int nRoomId);
public:
	bool CheckGirl(int nRoomId, int nGirlId);
public:
	bool Girl_EnterRoom(int nRoomId, int nGirlId);
	bool Girl_LeaveRoom(int nRoomId, int nGirlId);
public:
	bool Role_EnterRoom(int nRoomId, int nRoleId);
	bool Role_LeaveRoom(int nRoomId, int nRoleId);
	bool Role_Sitdown(int nRoomId, int nRoleId);
	bool Role_StandUp(int nRoomId, int nRoleId);

public:
	bool SetVipRoomInfo(TexasRoomVip& refTexasRoomVip);
private:
	GameRoomIdVec m_GameRoomIdVec;
	TexasRoomMap  m_TexasRoomMap;
};
#endif//__TEXAS_ROOM_MANAGER_H__
