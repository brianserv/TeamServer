#pragma once
#ifndef __GIRL_MANAGER_H__
#define __GIRL_MANAGER_H__

#include "../../FrameWork/BaseDefine.h"

#include "Girl.h"

class CGirlManager : public CEQ_SingletonT<CGirlManager>
{
public:
	CGirlManager();
	virtual ~CGirlManager();

public:
	bool    CreateGirl(int nGirlId, int nGirlRoleId,
		string strGirlName, string strPassword,
		string strThirdId, int nCreateTime,
		int nPlayerIndex, int nGateIndex);

	bool    AddGirl(CGirl* pGirl);
	CGirl*  GetGirl(int nGirlId);
	void    Release();
public:
	string  GetGirlName(int nGirlId);
public:
	bool   EnterRooom(int nGirlId, int nGameType, int nRoomId);
	bool   LeaveRooom(int nGirlId, int nGameType, int nRoomId);

private:
	typedef map<int, CGirl*> GIRL_MAP;
	GIRL_MAP m_GirlMap;
};

#endif//__GIRL_MANAGER_H__