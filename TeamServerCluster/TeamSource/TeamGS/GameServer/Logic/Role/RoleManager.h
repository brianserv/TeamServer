#pragma once
#ifndef __ROLE_MANAGER_H__
#define __ROLE_MANAGER_H__

#include "../../FrameWork/BaseDefine.h"

#include "Role.h"

class CRoleManager : public CEQ_SingletonT<CRoleManager>
{
public:
	CRoleManager();
	virtual ~CRoleManager();

public:
	bool AddRole(int nRoleId, int nServerId, int nPlatformId, int nSex,
		string strRoleName, string strPassword, string strThirdId,
		string strThirdAccount, int nPlayerIndex, int nGateIndex);

	CRole*  GetRole(int nRoleId);
	bool    SetDeleteRole(int nRoleId);
	void    ReleaseRole();

	bool UpdateRoleBase(int nRoleId,
		string strRoleName,
		string strPassword,
		int nPlatformId,
		string strThirdId,
		string strThirdAccount,
		int nSex,
		int nStatus,
		string strStatusReason,
		int nLastLoginTime,
		int nLoginTimes,
		int nBanTime,
		int nExp,
		int nLevel,
		int nUnbindChip,
		int nUnbindPink,
		int nBindChip,
		int nBindPink,
		int nMaxPink,
		int nMaxChip,
		int nHighestChip,
		int  nVipType,
		int  nVipLevel,
		int  nVipPoints,
		int  nWinTimes,
		int  nLostTimes,
		int  nDrawTimes,
		vector<int> nMaxCardTypeVec,
		int  nChatStatus,
		int nGiftSpend,
		int nGiftSpendMonth);

	bool SetRolePlatformBase(int nRoleId, int nUnbindChip, int nUnbindPink, int nBindChip, int nBindPink, int nVipType, int nVipLevel);
	bool SetRoleMaxCardType(int nRoleId, vector<int>& nMaxCardTypeVec);
public:

	UpdatePlatformRoleBaseInfo& GetUpdatePlatformRoleBaseInfo(int nRoleId, int nIndex);
	void ReleaseUpdatePlatformRoleBaseInfo(int nRoleId, int nIndex);
public:
	string Get_MD5_RoleIdToken(int nRoleId);
public:
	void SetGameType(int nRoleId, int nGameType);
	int  GetGameType(int nRoleId);

	void SetRoomId(int nRoleId, int nRoomId);
	int  GetRoomId(int nRoleId);
public:
	inline map<int, CRole*>& GetRoleMap() { return m_RoleMap; }

private:
	typedef map<int, CRole*> ROLE_MAP;
	ROLE_MAP m_RoleMap;
};

#endif//__ROLE_MANAGER_H__
