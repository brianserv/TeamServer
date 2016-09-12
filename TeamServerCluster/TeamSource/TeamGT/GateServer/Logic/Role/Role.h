#pragma  once
#ifndef __ROLE_H__
#define __ROLE_H__

#include "../../FrameWork/BaseDefine.h"

class CRole
{
public:
	CRole(int nRoleId, string strRoleName, string strPassword, int nIndex);
	virtual ~CRole();
	EQ_DECLARE_CACHE(CRole)

public:
	inline void SetRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	inline void	SetRoleName(string strRoleName) { m_strRoleName = strRoleName; };
	inline void	SetPassword(string strPassword) { m_strPassword = strPassword; };

	inline int GetRoleId() { return m_nRoleId; };
	inline string	GetRoleName() { return m_strRoleName; };
	inline string	GetPassword() { return m_strPassword; };

public:
	inline void  SetIndex(int nIndex) { m_nIndex = nIndex; };
	inline int   GetIndex() { return m_nIndex; };
	inline void  SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };
	inline bool  GetIsUsed() { return m_bIsUsed; };

public:
	void Clear();

private:
	int m_nRoleId;
	string	m_strRoleName;
	string	m_strPassword;
	int     m_nIndex;
	bool    m_bIsUsed;
};
#endif//__ROLE_H__