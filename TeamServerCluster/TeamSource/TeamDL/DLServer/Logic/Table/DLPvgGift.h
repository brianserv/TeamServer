#ifndef __DL_PVGGIFT_H__
#define __DL_PVGGIFT_H__

#include "../../FrameWork/BaseDefine.h"

class CDLPvgGift
{
public:
	CDLPvgGift();
	virtual ~CDLPvgGift();
	EQ_DECLARE_CACHE(CDLPvgGift)

		inline void			setRoleId(int nRoleId) { m_nRoleId = nRoleId; };
	inline void         setRoleName(string strRoleName) { m_strRoleName = strRoleName; };
	inline void			setGirlId(int nGirlId) { m_nGirlId = nGirlId; };
	inline void			setGirlThirdId(string strGirlThirdId) { m_strGirlThirdId = strGirlThirdId; };
	inline void			setGiftId(int nGiftId) { m_nGiftId = nGiftId; };
	inline void			setGiftNum(int nGiftNum) { m_nGiftNum = nGiftNum; };
	inline void			setGiftPrice(int nGiftPrice) { m_nGiftPrice = nGiftPrice; };
	inline void			setType(int nType) { m_nType = nType; };
	inline void			setUnBindPink(int nUnbindPink) { m_nUnbindPink = nUnbindPink; };
	inline void			setBindPink(int nbindPink) { m_nBindPink = nbindPink; };
	inline void			setGameType(int nGameType) { m_nGameType = nGameType; };
	inline void			setGameId(int nGameId) { m_nGameId = nGameId; };
	inline void			setRoomId(int nRoomId) { m_nRoomId = nRoomId; };
	inline void			setServerId(int nServerId) { m_nServerId = nServerId; };
	inline void			setRoomType(int nRoomType) { m_nRoomType = nRoomType; };
	inline void			setEvenCount(int nEvenCount) { m_nEvenCount = nEvenCount; };
	inline void			setBroadcastType(int nBroadcastType) { m_nBroadcastType = nBroadcastType; };
	inline void			setSaveType(int nSaveType) { m_nSaveType = nSaveType; };
public:
	inline int		getRoleId() { return m_nRoleId; };
	inline string		getRoleName() { return m_strRoleName; };
	inline int			getGirlId() { return m_nGirlId; };
	inline string		getGirlThirdId() { return m_strGirlThirdId; };
	inline int			getGiftId() { return m_nGiftId; };
	inline int			getGiftNum() { return m_nGiftNum; };
	inline int		getGiftPrice() { return m_nGiftPrice; };
	inline int			getType() { return m_nType; };
	inline int		getUnbindPink() { return m_nUnbindPink; };
	inline int		getBindPink() { return m_nBindPink; };
	inline int			getGameType() { return m_nGameType; };
	inline int			getGameId() { return m_nGameId; };
	inline int			getRoomId() { return m_nRoomId; };
	inline int			getServerId() { return m_nServerId; };
	inline int			getRoomType() { return m_nRoomType; };
	inline int			getEvenCount() { return m_nEvenCount; };
	inline int			getBroadcastType() { return m_nBroadcastType; };
	inline int			getSaveType() { return m_nSaveType; };
public:
	void			SetpvgGiftProperty(int	nRoleId,
		string		strRoleName,
		int			nGirlId,
		string		strGirlThirdId,
		int			nGiftId,
		int			nGiftNum,
		int	nGiftPrice,
		int			nType,
		int	nUnbindPink,
		int	nBindPink,
		int			nGameType,
		int			nGameId,
		int			nRoomId,
		int			nServerId,
		int			nRoomType,
		int			nEvenCount,
		int			nBroadcastType,
		int			nSaveType);

private:
	int	m_nRoleId;
	string		m_strRoleName;
	int			m_nGirlId;
	string		m_strGirlThirdId;
	int			m_nGiftId;
	int			m_nGiftNum;
	int	m_nGiftPrice;
	int			m_nType;
	int	m_nUnbindPink;
	int	m_nBindPink;
	int			m_nGameType;
	int			m_nGameId;
	int			m_nRoomId;
	int			m_nServerId;
	int			m_nRoomType;
	int			m_nEvenCount;
	int			m_nBroadcastType;
	int			m_nSaveType;
};

#endif//__DL_PVGGIFT_H__