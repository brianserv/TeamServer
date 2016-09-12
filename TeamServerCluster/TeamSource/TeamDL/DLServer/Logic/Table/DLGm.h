#ifndef __DL_GM_H__
#define __DL_GM_H__

#include "../../FrameWork/BaseDefine.h"

class CDLGm
{
public:
	CDLGm();
	virtual ~CDLGm();
	EQ_DECLARE_CACHE(CDLGm)

		inline void			setRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	inline void			setGmId(int nGmId) { m_GmId = nGmId; };
	inline void			setGmActionType(int nGmActionType) { m_GmActionType = nGmActionType; };
	inline void			setDescirbe(string strDescribe) { m_strDescribe = strDescribe; };

public:
	inline int		getRoleId() { return m_nRoleId; };
	inline int			getGmId() { return m_GmId; };
	inline int			getGmActionType() { return m_GmActionType; };
	inline string		getDescribe() { return m_strDescribe; };

public:
	void	SetGmProperty(int  nRoleId, int nGmId, int nGmActionType, string strDescribe);

private:
	int	m_nRoleId;
	int			m_GmId;
	int			m_GmActionType;
	string		m_strDescribe;
};

#endif// __DL_GM_H__