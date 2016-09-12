#include "DLOnline.h"

EQ_IMPLEMENT_CACHE(CDLOnline, 100)

CDLOnline::CDLOnline()
{
	m_nServerId = 0;
	m_nGameType = 0;
	m_nRoomType = 0;
	m_nGameId = 0;
	m_nRoomId = 0;
	m_nGirlId = 0;
}

CDLOnline::~CDLOnline()
{
}

void CDLOnline::SetOnlineProperty(
	int nServerId,
	int nGameType,
	int nRoomType,
	int nGameId,
	int nRoomId,
	int nGirlId,
	int nOnlineUsersCount
	)
{
	setServerId(nServerId);
	setGameType(nGameType);
	setRoomType(nRoomType);
	setGameId(nGameId);
	setRoomId(nRoomId);
	setGirlId(nGirlId);
	setOnlineUsersCount(nOnlineUsersCount);
}