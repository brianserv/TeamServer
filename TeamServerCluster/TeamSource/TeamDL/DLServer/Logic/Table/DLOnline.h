#ifndef __DL_ONLINE_H__
#define __DL_ONLINE_H__

#include "../../FrameWork/BaseDefine.h"

class CDLOnline
{
public:
	CDLOnline();
	virtual ~CDLOnline();
	EQ_DECLARE_CACHE(CDLOnline)

		inline void			setServerId(int nServerId) { m_nServerId = nServerId; };
	inline void			setGameType(int nGameType) { m_nGameType = nGameType; };
	inline void			setRoomType(int nRoomType) { m_nRoomType = nRoomType; };
	inline void			setGameId(int nGameId) { m_nGameId = nGameId; };
	inline void			setRoomId(int nRoomId) { m_nRoomId = nRoomId; };
	inline void			setGirlId(int nGirlId) { m_nGirlId = nGirlId; };
	inline void         setOnlineUsersCount(int nOnlineUsersCount) { m_nOnlineUsersCount = nOnlineUsersCount; };

public:
	inline int			getServerId() { return m_nServerId; };
	inline int			getGameType() { return m_nGameType; };
	inline int			getRoomType() { return m_nRoomType; };
	inline int			getGameId() { return m_nGameId; };
	inline int			getRoomId() { return m_nRoomId; };
	inline int			getGirlId() { return m_nGirlId; };
	inline int     getOnlineUsersCount() { return m_nOnlineUsersCount; };

public:
	void			SetOnlineProperty(int nServerId,
		int nGameType,
		int nRoomType,
		int nGameId,
		int nRoomId,
		int nGirlId,
		int nOnlineUsersCount);

private:
	int			m_nServerId;
	int			m_nGameType;
	int			m_nRoomType;
	int			m_nGameId;
	int			m_nRoomId;
	int			m_nGirlId;
	int    m_nOnlineUsersCount;
};

#endif//__DL_ONLINE_H__