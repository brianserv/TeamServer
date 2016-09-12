#ifndef __DL_PVPGIFT_H__
#define __DL_PVPGIFT_H__

#include "../../FrameWork/BaseDefine.h"

class CDLPvpGift
{
public:
	CDLPvpGift();
	virtual ~CDLPvpGift();
	EQ_DECLARE_CACHE(CDLPvpGift)

		inline void			setFromRoleId(int nFromRoleId) { m_nFromRoleId = nFromRoleId; };
	inline void			setToRoleId(int nToRoleId) { m_nToRoleId = nToRoleId; };
	inline void         setFromRoleName(string strFromRoleName) { m_strFromRoleName = strFromRoleName; };
	inline void         setToRoleName(string strToRoleName) { m_strToRoleName = strToRoleName; };
	inline void			setPlatformId(int nPlatformId) { m_nPlatformId = nPlatformId; };
	inline void			setFromThirdId(string strFromThirdId) { m_strFromThirdId = strFromThirdId; };
	inline void			setToThirdId(string strToThirdId) { m_strToThirdId = strToThirdId; };
	inline void			setFromThirdAccount(string strFromThirdAccount) { m_strFromThirdAccount = strFromThirdAccount; };
	inline void			setToThirdAccount(string strToThirdAccount) { m_strToThirdAccount = strToThirdAccount; };
	inline void			setGiftId(int nGiftId) { m_nGiftId = nGiftId; };
	inline void			setGiftPrice(int nGiftPrice) { m_nGiftPrice = nGiftPrice; };
	inline void			setUnBindChip(int nUnbindChip) { m_nUnbindChip = nUnbindChip; };
	inline void			setBindChip(int nbindChip) { m_nBindChip = nbindChip; };
	inline void			setServerId(int nServerId) { m_nServerId = nServerId; };
	inline void			setRoomId(int nRoomId) { m_nRoomId = nRoomId; };

public:
	inline int		getFromRoleId() { return m_nFromRoleId; };
	inline int		getToRoleId() { return m_nToRoleId; };
	inline string		getFromRoleName() { return m_strFromRoleName; };
	inline string		getToRoleName() { return m_strToRoleName; };
	inline int			getPlatformId() { return m_nPlatformId; };
	inline string		getFromThirdId() { return m_strFromThirdId; };
	inline string		getToThirdId() { return m_strFromThirdId; };
	inline string		getFromThirdAccount() { return m_strFromThirdAccount; };
	inline string		getToThirdAccount() { return m_strToThirdAccount; };
	inline int			getGiftId() { return m_nGiftId; };
	inline int		getGiftPrice() { return m_nGiftPrice; };
	inline int		getUnbindChip() { return m_nUnbindChip; };
	inline int		getBindChip() { return m_nBindChip; };
	inline int			getServerId() { return m_nServerId; };
	inline int			getRoomId() { return m_nRoomId; };

public:
	void			setPvpGiftProperty(int	nFromRoleId,
		int	nToRoleId,
		string		strFromRoleName,
		string		strToRoleName,
		int			nPlatformId,
		string		strFromThirdId,
		string		strToThirdId,
		string		strFromThirdAccount,
		string		strToThirdAccount,
		int			nGiftId,
		int	nGiftPrice,
		int	nUnbindChip,
		int	nBindChip,
		int			nServerId,
		int			nRoomId);
private:
	int	m_nFromRoleId;
	int	m_nToRoleId;
	string		m_strFromRoleName;
	string		m_strToRoleName;
	int			m_nPlatformId;
	string		m_strFromThirdId;
	string		m_strToThirdId;
	string		m_strFromThirdAccount;
	string		m_strToThirdAccount;
	int			m_nGiftId;
	int	m_nGiftPrice;
	int	m_nUnbindChip;
	int	m_nBindChip;
	int			m_nServerId;
	int			m_nRoomId;
};

#endif //__DL_PVPGIFT_H__