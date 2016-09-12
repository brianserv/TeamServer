#include "Role.h"
#include "../../Logic/Httplink/HttpLinkEvent.h"

#include "../../Logic/Message/CSMessage/CSMessage.h"

EQ_IMPLEMENT_CACHE(CRole, 100)

CRole::CRole() : CRoleBase()
{
}

CRole::~CRole()
{
	m_nRoleId = 0;
	m_nPlayerIndex = 0;
	m_nGateIndex = 0;
	m_GameType = 0;
	m_nRoomId = 0;
}

void  CRole::SetMaxCardType(vector<int>& nMaxCardTypeVec)
{
	m_nMaxCardTypeVec = nMaxCardTypeVec;

	// 平台链接 更新最大牌型
	CHttpLinkEvent::Instance().ProcessEvent_Request_MsgRegister(EPType_FB, EFB_HEType_V4_UpdateMaxCardTypeReq, m_nRoleId, 0, 0);
}

void  CRole::SetRoleBase(int nRoleId, int nPlatformId, int nSex,
	string strRoleName, string strPassword, string strThirdId,
	string strThirdAccount)
{
	//--------------------------------------------------------------------------------
	SetAttrNum(EAttrNum_nRoleId, nRoleId);
	SetAttrNum(EAttrNum_nPlatformId, nPlatformId);
	SetAttrNum(EAttrNum_nSex, nSex);
	SetAttrNum(EAttrNum_nStatus, 0);
	SetAttrNum(EAttrNum_nLastLoginTime, CEQ_Time::Instance().EQ_GetTime());
	SetAttrNum(EAttrNum_nLoginTimes, 0);
	SetAttrNum(EAttrNum_nBanTime, 0);
	SetAttrNum(EAttrNum_nExp, 0);
	SetAttrNum(EAttrNum_nLevel, 0);
	SetAttrNum(EAttrNum_nUnBindChip, 0);
	SetAttrNum(EAttrNum_nUnBindPink, 0);
	SetAttrNum(EAttrNum_nBindChip, 0);
	SetAttrNum(EAttrNum_nBindPink, 0);
	SetAttrNum(EAttrNum_nMaxPink, 0);
	SetAttrNum(EAttrNum_nMaxChip, 0);
	SetAttrNum(EAttrNum_nHighestChip, 0);
	SetAttrNum(EAttrNum_nVipType, 0);
	SetAttrNum(EAttrNum_nVipLevel, 0);
	SetAttrNum(EAttrNum_nVipPoints, 0);
	SetAttrNum(EAttrNum_nWinTimes, 0);
	SetAttrNum(EAttrNum_nLostTimes, 0);
	SetAttrNum(EAttrNum_nDrawTimes, 0);
	SetAttrNum(EAttrNum_nChatStatus, 0);
	SetAttrNum(EAttrNum_nGiftSpend, 0);
	//-------------------------------------------------------------------------------
	SetRoleName(strRoleName);
	SetPassword(strPassword);
	SetThirdId(strThirdId);
	SetThirdAccount(strThirdAccount);
	SetStatusReason("0");
}

void CRole::UpdateRoleBase(int nRoleId,
	string strRoleName,
	string strPassword,
	int nPlatformId,
	string strThirdId,
	string strThirdAccount,
	int nSex,
	int nStatus,
	string strStatusReason,
	int nLastLoginTime,
	int nLoginTimes,
	int nBanTime,
	int nExp,
	int nLevel,
	int nUnbindChip,
	int nUnbindPink,
	int nBindChip,
	int nBindPink,
	int nMaxPink,
	int nMaxChip,
	int nHighestChip,
	int  nVipType,
	int  nVipLevel,
	int  nVipPoints,
	int  nWinTimes,
	int  nLostTimes,
	int  nDrawTimes,
	vector<int> nMaxCardTypeVec,
	int  nChatStatus,
	int nGiftSpend,
	int nGiftSpendMonth)
{
	//------------------------------------------------------------------------------------
	SetAttrNum(EAttrNum_nRoleId, nRoleId);
	SetAttrNum(EAttrNum_nPlatformId, nPlatformId);
	SetAttrNum(EAttrNum_nSex, nSex);
	SetAttrNum(EAttrNum_nStatus, nStatus);
	SetAttrNum(EAttrNum_nLastLoginTime, nLastLoginTime);
	SetAttrNum(EAttrNum_nLoginTimes, nLoginTimes);
	SetAttrNum(EAttrNum_nBanTime, nBanTime);
	SetAttrNum(EAttrNum_nExp, nExp);
	SetAttrNum(EAttrNum_nLevel, nLevel);
	SetAttrNum(EAttrNum_nUnBindChip, nUnbindChip);
	SetAttrNum(EAttrNum_nUnBindPink, nUnbindPink);
	SetAttrNum(EAttrNum_nBindChip, nBindChip);
	SetAttrNum(EAttrNum_nBindPink, nBindPink);
	SetAttrNum(EAttrNum_nMaxPink, nMaxPink);
	SetAttrNum(EAttrNum_nMaxChip, nMaxChip);
	SetAttrNum(EAttrNum_nHighestChip, nHighestChip);
	SetAttrNum(EAttrNum_nVipType, nVipType);
	SetAttrNum(EAttrNum_nVipLevel, nVipLevel);
	SetAttrNum(EAttrNum_nVipPoints, nVipPoints);
	SetAttrNum(EAttrNum_nWinTimes, nWinTimes);
	SetAttrNum(EAttrNum_nLostTimes, nLostTimes);
	SetAttrNum(EAttrNum_nDrawTimes, nDrawTimes);
	SetAttrNum(EAttrNum_nChatStatus, nChatStatus);
	SetAttrNum(EAttrNum_nGiftSpend, nGiftSpend);
	SetAttrNum(EAttrNum_nGiftSpendMonth, nGiftSpendMonth);

	//-------------------------------------------------------------------------------
	SetRoleName(strRoleName);
	SetPassword(strPassword);
	SetThirdId(strThirdId);
	SetThirdAccount(strThirdAccount);
	SetStatusReason(strStatusReason);
	SetMaxCardType(nMaxCardTypeVec);
}

void CRole::SetRolePlatformBase(int nRoleId,
	int nUnbindChip,
	int nUnbindPink,
	int nBindChip,
	int nBindPink,
	int nVipType,
	int nVipLevel)
{
	//------------------------------------------------------------------------------------
	SetAttrNum(EAttrNum_nRoleId, nRoleId);
	SetAttrNum(EAttrNum_nUnBindChip, nUnbindChip);
	SetAttrNum(EAttrNum_nUnBindPink, nUnbindPink);
	SetAttrNum(EAttrNum_nBindChip, nBindChip);
	SetAttrNum(EAttrNum_nBindPink, nBindPink);
	SetAttrNum(EAttrNum_nVipType, nVipType);
	SetAttrNum(EAttrNum_nVipLevel, nVipLevel);
	//-------------------------------------------------------------------------------
}

void  CRole::SetUpdatePlatformRoleBaseInfo(int nUnbindChip, int nBindChip, int nUnbindPink, int nBindPink)
{
	int nSizeIndex = m_UpdatePlatformRoleBaseInfoMap.size();

	UpdatePlatformRoleBaseInfo Info;
	Info.nRoleId = m_nRoleId;

	Info.nUnBindChip = nUnbindChip;
	Info.nBindChip = nBindChip;
	Info.nUnBindPink = nUnbindPink;
	Info.nBindPink = nBindPink;

	Info.nServerId = m_nServerId;
	Info.nRoomId = m_nRoomId;

	Info.nUpdateType = 2;

	if (m_nRoomId > 0)
	{
		Info.nRoleState = 1;
	}
	else
	{
		Info.nRoleState = 0;
	}

	Info.strMd5RoleIdToken = Get_MD5_RoleIdToken(m_nRoleId);

	m_UpdatePlatformRoleBaseInfoMap[nSizeIndex] = Info;

	// 平台枚举-链接 后续考虑
	CHttpLinkEvent::Instance().ProcessEvent_Request_MsgRegister(EPType_FB, EFB_HEType_V3_UpdateRoleDataReq, m_nRoleId, 0, nSizeIndex);
}

UpdatePlatformRoleBaseInfo&  CRole::GetUpdatePlatformRoleBaseInfo(int index)
{
	UpdatePlatformRoleBaseInfoMap::iterator it = m_UpdatePlatformRoleBaseInfoMap.find(index);
	if (it != m_UpdatePlatformRoleBaseInfoMap.end())
	{
		return it->second;
	}
}

void CRole::ReleaseUpdatePlatformRoleBaseInfo(int nIndex)
{
	UpdatePlatformRoleBaseInfoMap::iterator it, itRemove;
	it = m_UpdatePlatformRoleBaseInfoMap.begin();
	while (it != m_UpdatePlatformRoleBaseInfoMap.end())
	{
		if (it->first == nIndex)
		{
			itRemove = it;
			it++;
			m_UpdatePlatformRoleBaseInfoMap.erase(itRemove);
			continue;
		}
		it++;
	}
}

string CRole::Get_MD5_RoleIdToken(int nRoleId)
{
	string strMakeToken(PARSE_STRINGS::toString(nRoleId) + CONSTR_ROLE_TOKEN_KEY);

	char ary[1024];
	string strMd5Token;
	strMd5Token = md5_string((const unsigned char*)strMakeToken.c_str(), ary, strMakeToken.length());

	return strMd5Token;
}

void  CRole::Init_UpdatePlatformRoleBaseInfo()
{
}

void  CRole::DecChipByCostRulers(int nValue, int& nUnbindChip, int& nBindChip)
{
	if (nValue <= 0)
		return;

	DecChipByCostRuler(nValue, nUnbindChip, nBindChip);

	SetUpdatePlatformRoleBaseInfo((-1)*nUnbindChip, (-1)*nBindChip, 0, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::DecPinkpByCostRulers(int nValue, int& nUnbindPink, int& nBindPink)
{
	if (nValue <= 0)
		return;

	DecPinkpByCostRuler(nValue, nUnbindPink, nBindPink);

	SetUpdatePlatformRoleBaseInfo(0, 0, (-1)*nUnbindPink, (-1)*nBindPink);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::AddUnBindChips(int nValue)
{
	if (nValue <= 0)
		return;

	AddUnBindChip(nValue);

	SetUpdatePlatformRoleBaseInfo(nValue, 0, 0, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::AddBindChips(int nValue)
{
	if (nValue <= 0)
		return;

	AddBindChip(nValue);

	SetUpdatePlatformRoleBaseInfo(0, nValue, 0, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::AddUnBindPinks(int nValue)
{
	if (nValue <= 0)
		return;

	AddUnBindPink(nValue);

	SetUpdatePlatformRoleBaseInfo(0, 0, nValue, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::AddBindPinks(int nValue)
{
	if (nValue <= 0)
		return;

	AddBindPink(nValue);

	SetUpdatePlatformRoleBaseInfo(0, 0, 0, nValue);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::DecUnBindChips(int nValue)
{
	if (nValue <= 0)
		return;

	DecUnBindChip(nValue);

	SetUpdatePlatformRoleBaseInfo((-1)*nValue, 0, 0, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::DecBindChips(int nValue)
{
	if (nValue <= 0)
		return;

	DecBindChips(nValue);

	SetUpdatePlatformRoleBaseInfo(0, (-1)*nValue, 0, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::DecUnBindPinks(int nValue)
{
	if (nValue <= 0)
		return;

	DecUnBindPink(nValue);

	SetUpdatePlatformRoleBaseInfo(0, 0, (-1)*nValue, 0);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}

void  CRole::DecBindPinks(int nValue)
{
	if (nValue <= 0)
		return;

	DecBindPink(nValue);

	SetUpdatePlatformRoleBaseInfo(0, 0, 0, (-1)*nValue);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(m_nRoleId);
}