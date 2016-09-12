#pragma  once
#ifndef __HTTP_LINK_FB_H__
#define __HTTP_LINK_FB_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Common//GameEnum.h"

#include "HttpLinkBase.h"

class CHttpLinkFB :public CHttpLinkBase
{
public:
	CHttpLinkFB();
	virtual ~CHttpLinkFB();
	EQ_DECLARE_CACHE(CHttpLinkFB)
public:
	void Init();
	string GetPath(const int nHttpEventType);
	void HttpEventHandler(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex);

public:
	void HttpEventHandler_V2_GetRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex);
	void HttpEventHandler_V3_UpdateRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex);
	void HttpEventHandler_V4_UpdateMaxCardTypeReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex);
public:
	void HttpEventHandler_V5_CreateVipRoomRes(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex);

private:
	typedef std::map<int, string> FB_HTTPEVENT_MAP;
	FB_HTTPEVENT_MAP m_FB_HttpEventMap;
};

#endif//__HTTP_LINK_FB_H__