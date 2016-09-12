#pragma  once
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
	bool             CreateRole(int nRoleId, string strRoleName, string strPassword, int nIndex);
	CRole*           GetRole(int nRoleId);
	bool             GetIndex(int nRoleId, int & nIndex);
	bool             DisConnectRole(int nRoleId);

public:
	typedef map<int, CRole*> ROLE_MAP;
	ROLE_MAP m_RoleMap;
};
#endif//__ROLE_MANAGER_H__