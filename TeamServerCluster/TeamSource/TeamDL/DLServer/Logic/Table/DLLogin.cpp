#include "DLLogin.h"

EQ_IMPLEMENT_CACHE(CDLLogin, 100)

CDLLogin::CDLLogin()
{
	m_nRoleId = 0;
	m_strRoleName = "";
	m_nPlatformId = 0;
	m_strThirdId = "";
	m_strThirdAccount = "";
	m_nLoginTime = 0;
	m_nServerId = 0;
	m_strIp = "";
	m_nStatus = 0;
}

CDLLogin::~CDLLogin()
{
}

void CDLLogin::SetLoginProperty(
	int nRoleId,
	string strRoleName,
	int nPlatformId,
	string strThirdId,
	string strThirdAccount,
	int nLoginTime,
	int nServerId,
	string strIp,
	int nStatus
	)
{
	setRoleId(nRoleId);
	setRoleName(strRoleName);
	setPlatformId(nPlatformId);
	setThirdId(strThirdId);
	setThirdAccount(strThirdAccount);
	setLoginTime(nLoginTime);
	setServerId(nServerId);
	setIp(strIp);
	setStatus(nStatus);
}