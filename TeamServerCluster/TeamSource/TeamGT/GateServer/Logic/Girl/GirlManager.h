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
	bool    CreateGirl(int nGirlId, int nGirlRoleId, string strGirlName, string strPassword, string strThirdId, int nCreateTime, int nPlayerIndex);
	bool    AddGirl(CGirl* pGirl);
	CGirl*  GetGirl(int nGirlId);
	void    Release();
public:
	bool   CheckGirl(int nGirlId, string strGirlName, string strPassword);
	bool   CheckGirlName(int &nGirlId, string strGirlName, string strPassword);
private:
	typedef map<int, CGirl*> GIRL_MAP;
	GIRL_MAP m_GirlMap;
};

#endif//__GIRL_MANAGER_H__