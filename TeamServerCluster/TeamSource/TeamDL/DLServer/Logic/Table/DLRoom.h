#ifndef __DL_ROOM_H__
#define __DL_ROOM_H__

#include "../../FrameWork/BaseDefine.h"

class CDLRoom
{
public:
	CDLRoom();
	virtual ~CDLRoom();
	EQ_DECLARE_CACHE(CDLRoom)

		inline void			setRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	inline void         setRoleName(string strRoleName) { m_strRoleName = strRoleName; };
	inline void			setPlatformId(int nPlatformId) { m_nPlatformId = nPlatformId; };
	inline void			setThirdId(string strThirdId) { m_strThirdId = strThirdId; };
	inline void			setThirdAccount(string strThirdAccount) { m_strThirdAccount = strThirdAccount; };
	inline void			setRoomId(int nRoomId) { m_nRoomId = nRoomId; };
	inline void			setGirlId(int nGirlId) { m_nGirlId = nGirlId; };
	inline void			setAction(int nAction) { m_nAction = nAction; };

public:
	inline int		getRoleId() { return m_nRoleId; };
	inline string		getRoleName() { return m_strRoleName; };
	inline int			getPlatformId() { return m_nPlatformId; };
	inline string		getThirdId() { return m_strThirdId; };
	inline string		getThirdAccount() { return m_strThirdAccount; };
	inline int			getRoomId() { return m_nRoomId; };
	inline int			getGirlId() { return m_nGirlId; };
	inline int			getAction() { return m_nAction; };

public:
	void		SetRoomProperty(int	nRoleId,
		string		strRoleName,
		int		nPlatformId,
		string		strThirdId,
		string		strThirdAccount,
		int		nRoomId,
		int		nGirlId,
		int		nAction);

private:
	int	m_nRoleId;
	string		m_strRoleName;
	int			m_nPlatformId;
	string		m_strThirdId;
	string		m_strThirdAccount;
	int			m_nRoomId;
	int			m_nGirlId;
	int			m_nAction;
};

#endif//__DL_ROOM_H__