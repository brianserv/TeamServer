#include "HttpLinkYY.h"
#include "HttpLinkEvent.h"

#include "../../Logic/Role/RoleManager.h"
EQ_IMPLEMENT_CACHE(CHttpLinkYY, 100)
CHttpLinkYY::CHttpLinkYY()
{
}

CHttpLinkYY::~CHttpLinkYY()
{
}

void CHttpLinkYY::Init()
{
	this->SetPlatformType(EPType_YY);

	const string STR_YY_PATH_TEST_GET_USERCURRENCY_GETS("/SundryInfo/GetUserCurrency?");
	m_YY_HttpEventMap[EYY_HEType_V1_GetRoleDataReq] = STR_YY_PATH_TEST_GET_USERCURRENCY_GETS;

	const string STR_YY_PATH_TEST_UPDATE_USERCURRENCY_GETS("/SundryInfo/update_usercurrency?");
	m_YY_HttpEventMap[EYY_HEType_V2_UpdateRoleDataReq] = STR_YY_PATH_TEST_UPDATE_USERCURRENCY_GETS;

	const string STR_YY_PATH_TEST_CREATEVIPROOM_GETS("/vip/create_vip_room?");
	m_YY_HttpEventMap[EYY_HEType_V3_CreateVipRoomRes] = STR_YY_PATH_TEST_CREATEVIPROOM_GETS;
}

string CHttpLinkYY::GetPath(const int nHttpEventType)
{
	YY_HTTPEVENT_MAP::iterator it;
	it = m_YY_HttpEventMap.find(nHttpEventType);
	if (it != m_YY_HttpEventMap.end())
	{
		return it->second;
	}
	string str("");
	return str;
}

void  CHttpLinkYY::HttpEventHandler(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex)
{
	if (strURL == "")
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			"【LOG:YY:HTTPLINK:HttpEventHandler URL IS EMPTY】：");
		return;
	}
	switch (nHttpEventType)
	{
	case EYY_HEType_V1_GetRoleDataReq:
		HttpEventHandler_V1_GetRoleDataReq(strURL, nHttpEventType, nRoleId, nIndex);
		break;

	case EYY_HEType_V2_UpdateRoleDataReq:
		HttpEventHandler_V2_UpdateRoleDataReq(strURL, nHttpEventType, nRoleId, nIndex);
		break;

	case EFB_HEType_V5_CreateVipRoomRes:
		HttpEventHandler_V3_CreateVipRoomRes(strURL, nHttpEventType, nRoleId, nRoomId, nIndex);
		break;
	default:
		break;
	}
}

void  CHttpLinkYY::HttpEventHandler_V1_GetRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex)
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

void  CHttpLinkYY::HttpEventHandler_V2_UpdateRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex)
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

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
		"【LOG:YY:HTTPLINK:HttpEventHandler_V2_UpdateRoleDataReq】："
		"nHttpEventType = %d,nRoleId = %d,"
		"nUnBindChip = %d,nBindChip = %d,nUnBindPink = %d,nBindPink = %d,"
		"nServerId = %d,nRoomId = %d,nUpdateType = %d,nRoleState = %d  \n ",
		nHttpEventType, Info.nRoleId,
		Info.nUnBindChip, Info.nBindChip, Info.nUnBindPink, Info.nBindPink,
		Info.nServerId, Info.nRoomId, Info.nUpdateType, Info.nRoleState);

	CRoleManager::Instance().ReleaseUpdatePlatformRoleBaseInfo(nRoleId, nIndex);
}

void CHttpLinkYY::HttpEventHandler_V3_CreateVipRoomRes(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex)
{
	string strInfo_UIdKey("accoutId=");
	string strInfo_VipRoomIdkey("&viproomid=");

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