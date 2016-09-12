#pragma  once
#ifndef __HTTP_LINK_YY_H__
#define __HTTP_LINK_YY_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Common//GameEnum.h"

#include "HttpLinkBase.h"

class CHttpLinkYY :public CHttpLinkBase
{
public:
	CHttpLinkYY();
	virtual ~CHttpLinkYY();
	EQ_DECLARE_CACHE(CHttpLinkYY)
public:
	void Init();
	string GetPath(const int nHttpEventType);

	void HttpEventHandler(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex);
public:
	void HttpEventHandler_V1_GetRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex);
	void HttpEventHandler_V2_UpdateRoleDataReq(string strURL, const int nHttpEventType, int nRoleId, const int nIndex);
public:
	void HttpEventHandler_V3_CreateVipRoomRes(string strURL, const int nHttpEventType, int nRoleId, int nRoomId, const int nIndex);
private:
	typedef std::map<int, string> YY_HTTPEVENT_MAP;
	YY_HTTPEVENT_MAP m_YY_HttpEventMap;
};

#endif//__HTTP_LINK_YY_H__