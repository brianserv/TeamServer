#include "HttpLinkEvent.h"
#include "HttpLinkManager.h"

#include "../../FrameWork/DataBuffer.h"
#include "../../Logic/Resource/ResourceManager.h"

#include "../../Logic/Role/RoleManager.h"
#include "../../Logic/Message/CSMessage/CSMessage.h"

CHttpLinkEvent::CHttpLinkEvent()
{
}

CHttpLinkEvent::~CHttpLinkEvent()
{
}

void CHttpLinkEvent::ProcessEvent_Request_MsgRegister(const int nPlatformId, const int nHttpEventType,
	const int nRoleId, const int nRoomId, const int nIndex)
{
	string strPlatformId(PARSE_STRINGS::toString(nPlatformId));
	string strHttpEventType(PARSE_STRINGS::toString(nHttpEventType));
	string strRoleId(PARSE_STRINGS::toString(nRoleId));
	string strnRoomId(PARSE_STRINGS::toString(nRoomId));
	string strHttpEventIndex(PARSE_STRINGS::toString(nIndex));

	string strSplit(",");
	string strContext("");

	strContext += strPlatformId;
	strContext += strSplit;

	strContext += strHttpEventType;
	strContext += strSplit;

	strContext += strRoleId;
	strContext += strSplit;

	strContext += strnRoomId;
	strContext += strSplit;

	strContext += strHttpEventIndex;

	char* pResContext = NULL;
	pResContext = (char*)strContext.c_str();
	CDataBuffer* pDataBuffer = new CDataBuffer(pResContext, strContext.length());
	if (NULL == pDataBuffer)
		return;

	g_Req_HttpMsg_Lock.EQ_Lock();
	g_Req_HttpMsg.push_back(pDataBuffer);
	g_Req_HttpMsg_Lock.EQ_UnLock();
}

void CHttpLinkEvent::ProcessEvent_Response_MsgRegister(const string strContext)
{
	char* pResContext = NULL;
	pResContext = (char*)strContext.c_str();
	CDataBuffer* pDataBuffer = new CDataBuffer(pResContext, strContext.length());
	if (NULL == pDataBuffer)
		return;

	g_Res_HttpMsg_Lock.EQ_Lock();
	g_Res_HttpMsg.push_back(pDataBuffer);
	g_Res_HttpMsg_Lock.EQ_UnLock();
}

void CHttpLinkEvent::ProcessEvent_Request(const string strContext)
{
	stringstream ssStream(strContext);
	char sFliter;

	int nPlatformType;
	int nHttpEventType;
	int nRoleId;
	int nRoomId;
	int nIndex;

	ssStream >>
		nPlatformType >>
		sFliter >>
		nHttpEventType >>
		sFliter >>
		nRoleId >>
		sFliter >>
		nRoomId >>
		sFliter >>
		nIndex;

	if (nPlatformType == 0 && nHttpEventType == 0 && nRoleId == 0)
	{
		CResourceManager::Instance().Curl_Http_Get();
	}
	else
	{
		CRole *pRole = CRoleManager::Instance().GetRole(nRoleId);
		if (NULL != pRole && pRole->GetIsUsed())
		{
			CHttpLinkManager::Instance().HttpLinkHandler(nPlatformType,
				nHttpEventType, nRoleId, nRoomId, nIndex);
		}
	}
}

void CHttpLinkEvent::ProcessEvent_Response(const string strContext)
{
	stringstream ssStream(strContext);
	char sFliter;

	int nPlatformType;
	int nHttpEventType;
	int nRoleId;

	ssStream >> nPlatformType >> sFliter >> nHttpEventType >> sFliter >> nRoleId;
	switch (nHttpEventType)
	{
	case EFB_HEType_V2_GetRoleDataReq:
		ProcessEvent_Response_V2_GetRoleDataReq(strContext);
		break;
	default:
		break;
	}
}

void CHttpLinkEvent::ProcessEvent_Response_V2_GetRoleDataReq(const string strContext)
{
	stringstream ssStream(strContext);
	char sFliter;

	int nPlatformType;
	int nHttpEventType;
	int nRoleId;
	int nUnBindChip;
	int nBindChip;
	int nUnBindPink;
	int nBindPink;
	int nVipType;
	int nVipLevel;
	int nTicket;
	string strMaxCardType;

	ssStream >>
		nPlatformType >>
		sFliter >>
		nHttpEventType >>
		sFliter >>
		nRoleId >>
		sFliter >>
		nUnBindChip >>
		sFliter >>
		nBindChip >>
		sFliter >>
		nUnBindPink >>
		sFliter >>
		nBindPink >>
		sFliter >>
		nVipType >>
		sFliter >>
		nVipLevel >>
		sFliter >>
		nTicket >>
		sFliter >>
		strMaxCardType;

	if (!strMaxCardType.empty())
	{
		string strdotSplit("|");
		vector<string> strnMaxCardTypeVec;
		strnMaxCardTypeVec = PARSE_STRINGS::ParseString::Split(strMaxCardType, strdotSplit);

		vector<int> nMaxCardTypeVec;
		for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
		{
			nMaxCardTypeVec.push_back(PARSE_STRINGS::stringToInt(strnMaxCardTypeVec[index]));
		}

		CRoleManager::Instance().SetRoleMaxCardType(nRoleId, nMaxCardTypeVec);
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
		" 【LOG:HTTPLINK:HttpEventHandler_V2_GetRoleDataReq】："
		"nPlatformType = %d,nHttpEventType = %d,nRoleId = %d,"
		"nUnBindChip = %d,nBindChip = %d,nUnBindPink = %d,nBindPink = %d,nVipType = %d,nVipLevel = %d \n ,"
		"nTicket = %d ,strMaxCardType = %s\n ",
		nPlatformType, nHttpEventType, nRoleId,
		nUnBindChip, nBindChip, nUnBindPink, nBindPink, nVipType, nVipLevel,
		nTicket, strMaxCardType.c_str());

	CRoleManager::Instance().SetRolePlatformBase(nRoleId, nUnBindChip,
		nUnBindPink, nBindChip, nBindPink, nVipType, nVipLevel);

	CCSMessage::Instance().ProcessMsg_RoleInfoSync(nRoleId);
}