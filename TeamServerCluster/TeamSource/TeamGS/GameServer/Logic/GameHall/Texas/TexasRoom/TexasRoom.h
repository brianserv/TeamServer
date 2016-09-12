#pragma  once
#ifndef __TEXAS_ROOM_H__
#define __TEXAS_ROOM_H__

#include "../../../../FrameWork/BaseDefine.h"

#include "../TexasRole/TexasRole.h"

typedef map<int, CTexasRole*> TexasRoleMap;

class CTexasRoom
{
public:
	CTexasRoom();
	virtual ~CTexasRoom();
	EQ_DECLARE_CACHE(CTexasRoom)
public:
	bool Init();
	bool Clear();
public:
	inline void SetRoomId(int nRoomId) { m_nRoomId = nRoomId; };
	inline void SetRoomType(int nRoomType) { m_nRoomType = nRoomType; };
	inline void SetGirlId(int nGirlId) { m_nGirlId = nGirlId; };
public:
	inline void SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };
public:
	inline int  GetRoomId() { return m_nRoomId; };
	inline int  GetRoomType() { return m_nRoomType; };
	inline int  GetGirlId() { return m_nGirlId; };
public:
	inline bool  GetIsUsed() { return m_bIsUsed; }

	inline TexasRoleMap& GetTexasRoleMap() { return m_TexasRoleMap; };
public:
	CTexasRole* GetTexasRole(int nRoleId);

public:
	bool CheckGirl(int nGirlId);
	bool CheckRole(int nRoleId);
public:
	bool Girl_EnterRoom(int nGirlId);
	bool Girl_LeaveRoom(int nGirlId);
public:
	bool Role_EnterRoom(int nRoleId);
	bool Role_LeaveRoom(int nRoleId);
	bool Role_Sitdown(int nRoleId);
	bool Role_StandUp(int nRoleId);
public:
	void SetVipRoomInfo(TexasRoomVip& refTexasRoomVip);
	void Supplementary_Vip_TexasGame_Chip(int nUnbindChip);
	void Pay_Vip_TexasGame_Chip(int nUnbindChip);
public:

private:
	int m_nRoomId;
	int m_nRoomType;
private:
	int m_nGirlId;
private:
	bool m_bIsUsed;
private:
	TexasRoleMap m_TexasRoleMap;
	TexasRoomVip m_TexasRoomVip;
};
#endif//__TEXAS_ROOM_H__
