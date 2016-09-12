#include "DLPvpGift.h"

EQ_IMPLEMENT_CACHE(CDLPvpGift, 100)

CDLPvpGift::CDLPvpGift()
{
	m_nFromRoleId = 0;
	m_nToRoleId = 0;
	m_strFromRoleName = "";
	m_strToRoleName = "";
	m_nPlatformId = 0;
	m_strFromThirdId = "";
	m_strToThirdId = "";
	m_strFromThirdAccount = "";
	m_strToThirdAccount = "";
	m_nGiftId = 0;
	m_nGiftPrice = 0;
	m_nUnbindChip = 0;
	m_nBindChip = 0;
	m_nServerId = 0;
	m_nRoomId = 0;
}
CDLPvpGift::~CDLPvpGift()
{
}

void CDLPvpGift::setPvpGiftProperty(int nFromRoleId,
	int nToRoleId,
	string strFromRoleName,
	string strToRoleName,
	int nPlatformId,
	string strFromThirdId,
	string strToThirdId,
	string strFromThirdAccount,
	string strToThirdAccount,
	int nGiftId,
	int nGiftPrice,
	int nUnbindChip,
	int nBindChip,
	int nServerId,
	int nRoomId)
{
	setFromRoleId(nFromRoleId);
	setToRoleId(nToRoleId);
	setFromRoleName(strFromRoleName);
	setToRoleName(strToRoleName);
	setPlatformId(nPlatformId);
	setFromThirdId(strFromThirdId);
	setToThirdId(strToThirdId);
	setFromThirdAccount(strFromThirdAccount);
	setToThirdAccount(strToThirdAccount);
	setGiftId(nGiftId);
	setGiftPrice(nGiftPrice);
	setUnBindChip(nUnbindChip);
	setBindChip(nBindChip);
	setServerId(nServerId);
	setRoomId(nRoomId);
}