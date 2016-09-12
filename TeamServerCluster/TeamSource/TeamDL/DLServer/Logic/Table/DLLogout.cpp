#include "DLLogout.h"

EQ_IMPLEMENT_CACHE(CDLLogout, 100)

CDLLogout::CDLLogout()
{
}

CDLLogout::~CDLLogout()
{
}

void CDLLogout::SetLogoutProperty(int nRoleId,
	string strRoleName,
	int nPlatformId,
	string strThirdId,
	string strThirdAccount,
	int nLoginTime,
	int nLogoutTime,
	int nServerId,
	string strIp
	)
{
	setRoleId(nRoleId);
	setRoleName(strRoleName);
	setPlatformId(nPlatformId);
	setThirdId(strThirdId);
	setThirdAccount(strThirdAccount);
	setLoginTime(nLoginTime);
	setLogoutTime(nLogoutTime);
	setServerId(nServerId);
	setIp(strIp);
}