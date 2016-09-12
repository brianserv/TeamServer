#pragma once
#ifndef __ROLE_H__
#define __ROLE_H__

#include "RoleAttr.h"

#include "../../FrameWork/BaseDefine.h"

#include "../Common/GameEnum.h"
#include "../Common/GameStructure.h"

typedef map<int, UpdatePlatformRoleBaseInfo> UpdatePlatformRoleBaseInfoMap;
class CRole : public CRoleBase
{
public:
	CRole();
	virtual ~CRole();
	EQ_DECLARE_CACHE(CRole)

public:
	void   SetIsOldRole(bool bIsOldRole) { m_bIsOldRole = bIsOldRole; };
	bool   GetIsOldRole() { return m_bIsOldRole; };

public:
	void  SetRoleId(int nRoleID) { m_nRoleId = nRoleID; };
	int GetRoleId() { return m_nRoleId; };

	void   SetRoleName(string strRoleName) { m_strRoleName = strRoleName; };
	string GetRoleName() { return m_strRoleName; };

	void   SetPassword(string strPassword) { m_strPassword = strPassword; };
	string GetPassword() { return m_strPassword; };

	void   SetThirdId(string strThirdId) { m_strThirdId = strThirdId; };
	string GetThirdId() { return m_strThirdId; };

	void   SetThirdAccount(string strThirdAccount) { m_strThirdAccount = strThirdAccount; };
	string GetThirdAccount() { return m_strThirdAccount; };

	void   SetStatusReason(string strStatusReason) { m_strStatusReason = strStatusReason; };
	string GetStatusReason() { return m_strStatusReason; };

	void   SetRoleMaxCardType(vector<int>& nMaxCardTypeVec) { m_nMaxCardTypeVec = nMaxCardTypeVec; };
	void   SetMaxCardType(vector<int>& nMaxCardTypeVec);
	vector<int>& GetMaxCardType() { return m_nMaxCardTypeVec; };

public:
	void   SetPlayerIndex(int nPlayerIndex) { m_nPlayerIndex = nPlayerIndex; };
	int    GetPlayerIndex() { return m_nPlayerIndex; };

	void   SetGateIndex(int nGateIndex) { m_nGateIndex = nGateIndex; };
	int    GetGateIndex() { return m_nGateIndex; };

	void   SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };
	bool   GetIsUsed() { return m_bIsUsed; };

	void  SetServerId(int nServerId) { m_nServerId = nServerId; };
	int   GetServerId() { return m_nServerId; };

	void  SetGameType(int nGameType) { m_GameType = nGameType; }
	int  GetGameType() { return m_GameType; }

	void SetRoomId(int nRoomId) { m_nRoomId = nRoomId; }
	int  GetRoomId() { return m_nRoomId; }
public:
	void   SetRoleBase(int nRoleId,
		int nPlatformId,
		int nSex,
		string strRoleName,
		string strPassword,
		string strThirdId,
		string strThirdAccount);

	void UpdateRoleBase(int nRoleId,
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

	void SetRolePlatformBase(int nRoleId,
		int nUnbindChip,
		int nUnbindPink,
		int nBindChip,
		int nBindPink,
		int nVipType,
		int nVipLevel);
public:
	void SetUpdatePlatformRoleBaseInfo(int nUnbindChip, int nBindChip, int nUnbindPink, int nBindPink);
	UpdatePlatformRoleBaseInfo& GetUpdatePlatformRoleBaseInfo(int index);
	void ReleaseUpdatePlatformRoleBaseInfo(int nIndex);
public:
	UpdatePlatformRoleBaseInfoMap m_UpdatePlatformRoleBaseInfoMap;

public:
	string Get_MD5_RoleIdToken(int nRoleId);
	void  Init_UpdatePlatformRoleBaseInfo();
public:
	void  DecChipByCostRulers(int nValue, int& nUnbindChip, int& nBindChip);
	void  DecPinkpByCostRulers(int nValue, int& nUnbindPink, int& nBindPink);
	void  AddUnBindChips(int nValue);
	void  AddBindChips(int nValue);
	void  AddUnBindPinks(int nValue);
	void  AddBindPinks(int nValue);

	void  DecUnBindChips(int nValue);
	void  DecBindChips(int nValue);
	void  DecUnBindPinks(int nValue);
	void  DecBindPinks(int nValue);

private:
	bool          m_bIsOldRole;
	int           m_nRoleId;
	int           m_nPlayerIndex;
	int           m_nGateIndex;
	bool          m_bIsUsed;

	string        m_strRoleName;
	string        m_strPassword;
	string        m_strThirdId;
	string        m_strThirdAccount;
	string        m_strStatusReason;
	vector<int>   m_nMaxCardTypeVec;
	int           m_nServerId;

	int           m_GameType;
	int           m_nRoomId;
};

#endif//__ROLE_H__
