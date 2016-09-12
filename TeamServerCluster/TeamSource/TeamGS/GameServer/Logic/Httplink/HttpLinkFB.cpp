#include "HttpLinkFB.h"
#include "HttpLinkEvent.h"

#include "../../Logic/Role/RoleManager.h"

EQ_IMPLEMENT_CACHE(CHttpLinkFB, 100)
CHttpLinkFB::CHttpLinkFB()
{
}

CHttpLinkFB::~CHttpLinkFB()
{
}

void  CHttpLinkFB::Init()
{
	this->SetPlatformType(EPType_FB);

	const string STR_FB_PATH_TEST_GET_USERCURRENCY_GETS("/SundryInfo/GetUserCurrency?");
	m_FB_HttpEventMap[EFB_HEType_V2_GetRoleDataReq] = STR_FB_PATH_TEST_GET_USERCURRENCY_GETS;

	const string STR_FB_PATH_TEST_UPDATE_USERCURRENCY_GETS("/SundryInfo/update_usercurrency?");
	m_FB_HttpEventMap[EFB_HEType_V3_UpdateRoleDataReq] = STR_FB_PATH_TEST_UPDATE_USERCURRENCY_GETS;

	const string STR_FB_PATH_TEST_UPDATE_MAXCARDTYPE_GETS("/SundryInfo/update_usermaxcardtype?");
	m_FB_HttpEventMap[EFB_HEType_V4_UpdateMaxCardTypeReq] = STR_FB_PATH_TEST_UPDATE_MAXCARDTYPE_GETS;

	const string STR_FB_PATH_TEST_CREATEVIPROOM_GETS("/vip/create_vip_room?");
	m_FB_HttpEventMap[EFB_HEType_V5_CreateVipRoomRes] = STR_FB_PATH_TEST_CREATEVIPROOM_GETS;
}

string CHttpLinkFB::GetPath(const int nHttpEventType)
{
	FB_HTTPEVENT_MAP::iterator it;
	it = m_FB_HttpEventMap.find(nHttpEventType);
	if (it != m_FB_HttpEventMap.end())
	{
		return it->second;
	}
	string str("");
	return str;
}

void  CHttpLinkFB::HttpEventHandler(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex)
{
	if (strURL == "")
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "【LOG:FB:HTTPLINK:HttpEventHandler URL IS EMPTY】");
		return;
	}

	switch (nHttpEventType)
	{
	case EFB_HEType_V2_GetRoleDataReq:
		HttpEventHandler_V2_GetRoleDataReq(strURL, nHttpEventType, nRoleId, nIndex);
		break;

	case EFB_HEType_V3_UpdateRoleDataReq:
		HttpEventHandler_V3_UpdateRoleDataReq(strURL, nHttpEventType, nRoleId, nIndex);
		break;

	case EFB_HEType_V4_UpdateMaxCardTypeReq:
		HttpEventHandler_V4_UpdateMaxCardTypeReq(strURL, nHttpEventType, nRoleId, nIndex);
		break;

	case EFB_HEType_V5_CreateVipRoomRes:
		HttpEventHandler_V5_CreateVipRoomRes(strURL, nHttpEventType, nRoleId, nRoomId, nIndex);
		break;
	default:
		break;
	}
}

void  CHttpLinkFB::HttpEventHandler_V2_GetRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex)
{
	string strInfo_Uidkey("uid=");
	string strInfo_UidValue = PARSE_STRINGS::toString(nRoleId);

	string strContext(strInfo_Uidkey + strInfo_UidValue);
	/*g_CurlHttp.Curl_Http_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);*/
	//g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);
	if (g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext) != 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Curl_Https_Get Failure!", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	string strSplit(",");
	string strHttpContext("");
	string strPlatformID(PARSE_STRINGS::toString(EPType_FB));
	string strHttpEventType(PARSE_STRINGS::toString(nHttpEventType));
	string strRoleId(PARSE_STRINGS::toString(nRoleId));

	strHttpContext += strPlatformID;
	strHttpContext += strSplit;

	strHttpContext += strHttpEventType;
	strHttpContext += strSplit;

	strHttpContext += strRoleId;
	strHttpContext += strSplit;

	strHttpContext += strContext;

	CHttpLinkEvent::Instance().ProcessEvent_Response_MsgRegister(strHttpContext);
}

void  CHttpLinkFB::HttpEventHandler_V3_UpdateRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex)
{
	UpdatePlatformRoleBaseInfo Info;
	Info = CRoleManager::Instance().GetUpdatePlatformRoleBaseInfo(nRoleId, nIndex);

	string strInfo_UIdKey("accoutId=");
	string strInfo_UnBindChipKey("&unbindMoney=");
	string strInfo_BindChipKey("&bindMoney=");
	string strInfo_UnBindPinkKey("&unbindPink=");
	string strInfo_BindPinkKey("&bindPink=");
	string strInfo_ServerIdKey("&spaceId=");
	string strInfo_RoomIdKey("&roomId=");
	string strInfo_UpdateTypeKey("&type=");
	string strInfo_RoleStateKey("&flag=");
	string strInfo_Md5RoleIdTokenKey("&md5=");

	string strInfo_UIdValue(PARSE_STRINGS::toString(Info.nRoleId));
	string strInfo_UnBindChipValue(PARSE_STRINGS::toString(Info.nUnBindChip));
	string strInfo_BindChipValue(PARSE_STRINGS::toString(Info.nBindChip));
	string strInfo_UnBindPinkValue(PARSE_STRINGS::toString(Info.nUnBindPink));
	string strInfo_BindPinkValue(PARSE_STRINGS::toString(Info.nBindPink));
	string strInfo_ServerIdValue(PARSE_STRINGS::toString(Info.nServerId));
	string strInfo_RoomIdValue(PARSE_STRINGS::toString(Info.nRoomId));
	string strInfo_UpdateTypeValue(PARSE_STRINGS::toString(Info.nUpdateType));
	string strInfo_RoleStateValue(PARSE_STRINGS::toString(Info.nRoleState));

	//key-value
	strInfo_UIdKey += strInfo_UIdValue;
	strInfo_UnBindChipKey += strInfo_UnBindChipValue;
	strInfo_BindChipKey += strInfo_BindChipValue;
	strInfo_UnBindPinkKey += strInfo_UnBindPinkValue;
	strInfo_BindPinkKey += strInfo_BindPinkValue;
	strInfo_ServerIdKey += strInfo_ServerIdValue;
	strInfo_RoomIdKey += strInfo_RoomIdValue;
	strInfo_UpdateTypeKey += strInfo_UpdateTypeValue;
	strInfo_RoleStateKey += strInfo_RoleStateValue;
	strInfo_Md5RoleIdTokenKey += Info.strMd5RoleIdToken;

	//Connect Key - value
	string strContext("");
	strContext += strInfo_UIdKey;
	strContext += strInfo_UnBindChipKey;
	strContext += strInfo_BindChipKey;
	strContext += strInfo_UnBindPinkKey;
	strContext += strInfo_BindPinkKey;
	strContext += strInfo_ServerIdKey;
	strContext += strInfo_RoomIdKey;
	strContext += strInfo_UpdateTypeKey;
	strContext += strInfo_RoleStateKey;
	strContext += strInfo_Md5RoleIdTokenKey;

	/*g_CurlHttp.Curl_Http_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);*/
	//g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);

	if (g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext) != 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Curl_Https_Get Failure!", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	CRoleManager::Instance().ReleaseUpdatePlatformRoleBaseInfo(nRoleId, nIndex);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"【LOG:FB:HTTPLINK:HttpEventHandler_V2_UpdateRoleDataReq】："
		"nHttpEventType = %d,nRoleId = %d,"
		"nUnBindChip = %d,nBindChip = %d,nUnBindPink = %d,nBindPink = %d,"
		"nServerId = %d,nRoomId = %d,nUpdateType = %d,nRoleState = %d  \n ",
		nHttpEventType, Info.nRoleId,
		Info.nUnBindChip, Info.nBindChip, Info.nUnBindPink, Info.nBindPink,
		Info.nServerId, Info.nRoomId, Info.nUpdateType, Info.nRoleState);
}

void CHttpLinkFB::HttpEventHandler_V5_CreateVipRoomRes(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex)
{
	string strInfo_UIdKey("accoutId=");
	string strInfo_VipRoomIdkey("&roomid=");

	string strInfo_UIdValue(PARSE_STRINGS::toString(nRoleId));
	string strInfo_VipRoomIdValue = PARSE_STRINGS::toString(nRoomId);

	//key-value
	strInfo_UIdKey += strInfo_UIdValue;
	strInfo_VipRoomIdkey += strInfo_VipRoomIdValue;

	//Connect Key - value
	string strContext("");
	strContext += strInfo_UIdKey;
	strContext += strInfo_VipRoomIdkey;

	/*g_CurlHttp.Curl_Http_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);*/
	//g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);
	if (g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext) != 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Curl_Https_Get Failure!", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
}

void CHttpLinkFB::HttpEventHandler_V4_UpdateMaxCardTypeReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex)
{
	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole)
		return;

	int sMaxCardType[MAX_TEXAS_CENTERCARD_NUM];
	vector<int> nMaxHandCardVec = pRole->GetMaxCardType();
	if (nMaxHandCardVec.size() < MAX_TEXAS_CENTERCARD_NUM)
		return;

	string strMaxCardType("");
	string strSplit(",");
	for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
	{
		strMaxCardType += PARSE_STRINGS::toString(nMaxHandCardVec[index]);
		strMaxCardType += strSplit;
	}

	string strInfo_UIdKey("uid=");
	string strInfo_UIdValue(PARSE_STRINGS::toString(nRoleId));

	string strInfo_MaxCardTypeKey("&account_max_cardtype=");
	string strInfo_MaxCardTypeValue(strMaxCardType);

	//key-value
	strInfo_UIdKey += strInfo_UIdValue;
	strInfo_MaxCardTypeKey += strInfo_MaxCardTypeValue;

	//Connect Key - value
	string strContext("");
	strContext += strInfo_UIdKey;
	strContext += strInfo_MaxCardTypeKey;

	/*g_CurlHttp.Curl_Http_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);*/
	//g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext);
	if (g_CurlHttp.Curl_Https_Get((strURL + GetPath(nHttpEventType) + strContext), strContext) != 0)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Curl_Https_Get Failure!", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	string strPath = GetPath(nHttpEventType);

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		"【LOG:FB:HTTPLINK:HttpEventHandler_V4_UpdateMaxCardTypeReq】："
		"nHttpEventType = %d,nRoleId = %d,"
		"account_max_cardtype = %s",
		nHttpEventType, nRoleId,
		strMaxCardType.c_str());
}