#include "Girl.h"

EQ_IMPLEMENT_CACHE(CGirl, 100)

CGirl::CGirl()
{
	m_nGirlRoleId = 0;
	m_nGirlID = 0;
	m_strGirlName = "";
	m_strPassword = "";
	m_strThirdId = "";
	m_nCreateTime = 0;
	m_nGameType = 0;
	m_nRoomID = 0;
}
CGirl::~CGirl()
{
}

void CGirl::SetGirlProperty(int nGirlId,
	int nGirlRoleId,
	string		strGirlName,
	string		strPassword,
	string		strThirdId,
	int	nCreateTime,
	int nPlayerIndex,
	int nGateIndex)
{
	setGirlId(nGirlId);
	setGirlRoleId(nGirlRoleId);
	setGirlName(strGirlName);
	setPassword(strPassword);
	setThirdId(strThirdId);
	setCreateTime(nCreateTime);
	setPlayerIndex(nPlayerIndex);
	setGateIndex(nGateIndex);
}