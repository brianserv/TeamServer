#ifndef __DL_LOGIN_H__
#define __DL_LOGIN_H__

#include "../../FrameWork/BaseDefine.h"

class CDLLogin
{
public:
	CDLLogin();
	virtual ~CDLLogin();
	EQ_DECLARE_CACHE(CDLLogin)

		inline void			setRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	inline void         setRoleName(string strRoleName) { m_strRoleName = strRoleName; };
	inline void			setPlatformId(int nPlatformId) { m_nPlatformId = nPlatformId; };
	inline void			setThirdId(string strThirdId) { m_strThirdId = strThirdId; };
	inline void			setThirdAccount(string strThirdAccount) { m_strThirdAccount = strThirdAccount; };
	inline void			setLoginTime(int nLoginTime) { m_nLoginTime = nLoginTime; };
	inline void			setServerId(int nServerId) { m_nServerId = nServerId; };
	inline void			setIp(string strIp) { m_strIp = strIp; };
	inline void			setStatus(int nStatus) { m_nStatus = nStatus; };

public:
	inline int		getRoleId() { return m_nRoleId; };
	inline string		getRoleName() { return m_strRoleName; };
	inline int			getPlatformId() { return m_nPlatformId; };
	inline string		getThirdId() { return m_strThirdId; };
	inline string		getThirdAccount() { return m_strThirdAccount; };
	inline int			getLoginTime() { return m_nLoginTime; };
	inline int			getServerId() { return m_nServerId; };
	inline string		getIp() { return m_strIp; };
	inline int			getStatus() { return m_nStatus; };

public:
	void		SetLoginProperty(int nRoleId,
		string strRoleName,
		int nPlatformId,
		string strThirdId,
		string strThirdAccount,
		int nLoginTime,
		int nServerId,
		string strIp,
		int nStatus);

private:
	int	m_nRoleId;
	string		m_strRoleName;
	int			m_nPlatformId;
	string		m_strThirdId;
	string		m_strThirdAccount;
	int			m_nLoginTime;
	int			m_nServerId;
	string		m_strIp;
	int			m_nStatus;
};

#endif//__DL_LOGIN_H__