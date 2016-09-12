#include "DLRoom.h"

EQ_IMPLEMENT_CACHE(CDLRoom, 100)

CDLRoom::CDLRoom()
{
	m_nRoleId = 0;
	m_strRoleName = "";
	m_nPlatformId = 0;
	m_strThirdId = "";
	m_strThirdAccount = "";
	m_nRoomId = 0;
	m_nGirlId = 0;
	m_nAction = 0;
}

CDLRoom::~CDLRoom()
{
}

void CDLRoom::SetRoomProperty(int nRoleId,
	string strRoleName,
	int nPlatformId,
	string strThirdId,
	string strThirdAccount,
	int nRoomId,
	int nGirlId,
	int nAction)
{
	setRoleId(nRoleId);
	setRoleName(strRoleName);
	setPlatformId(nPlatformId);
	setThirdId(strThirdId);
	setThirdAccount(strThirdAccount);
	setRoomId(nRoomId);
	setGirlId(nGirlId);
	setAction(nAction);
}