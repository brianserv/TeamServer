#include "DLPvgGift.h"

EQ_IMPLEMENT_CACHE(CDLPvgGift, 100)

CDLPvgGift::CDLPvgGift()
{
	m_nRoleId = 0;
	m_strRoleName = "";
	m_nGirlId = 0;
	m_strGirlThirdId = "";
	m_nGiftId = 0;
	m_nGiftNum = 0;
	m_nGiftPrice = 0;
	m_nType = 0;
	m_nUnbindPink = 0;
	m_nBindPink = 0;
	m_nGameType = 0;
	m_nGameId = 0;
	m_nRoomId = 0;
	m_nServerId = 0;
	m_nRoomType = 0;
	m_nEvenCount = 0;
	m_nBroadcastType = 0;
	m_nSaveType = 0;
}

CDLPvgGift::~CDLPvgGift()
{
}

void CDLPvgGift::SetpvgGiftProperty(
	int nRoleId,
	string strRoleName,
	int nGirlId,
	string strGirlThirdId,
	int nGiftId,
	int nGiftNum,
	int nGiftPrice,
	int nType,
	int nUnbindPink,
	int nBindPink,
	int nGameType,
	int nGameId,
	int nRoomId,
	int nServerId,
	int nRoomType,
	int nEvenCount,
	int nBroadcastType,
	int nSaveType
	)
{
	setRoleId(nRoleId);
	setRoleName(strRoleName);
	setGirlId(nGirlId);
	setGirlThirdId(strGirlThirdId);
	setGiftId(nGiftId);
	setGiftNum(nGiftNum);
	setGiftPrice(nGiftPrice);
	setType(nType);
	setUnBindPink(nUnbindPink);
	setBindPink(nBindPink);
	setGameType(nGameType);
	setGameId(nGameId);
	setRoomId(nRoomId);
	setServerId(nServerId);
	setRoomType(nRoomType);
	setEvenCount(nEvenCount);
	setBroadcastType(nBroadcastType);
	setSaveType(nSaveType);
}