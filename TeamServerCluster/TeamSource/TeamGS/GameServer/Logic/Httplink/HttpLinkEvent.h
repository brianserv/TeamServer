#pragma  once
#ifndef __HTTP_LINK_EVENT_H__
#define __HTTP_LINK_EVENT_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Common/GameEnum.h"
#include "../Common/GameStructure.h"

class CHttpLinkEvent : public CEQ_SingletonT<CHttpLinkEvent>
{
public:
	CHttpLinkEvent();
	virtual ~CHttpLinkEvent();
public:
	void ProcessEvent_Request_MsgRegister(const int nPlatformId, const int nHttpEventType,
		const int nRoleId, const int nRoomId, const int nIndex);
	void ProcessEvent_Response_MsgRegister(const string strContext);
public:
	void ProcessEvent_Request(const string strContext);
	void ProcessEvent_Response(const string strContext);
	void ProcessEvent_Response_V2_GetRoleDataReq(const string strContext);
};

#endif//__HTTP_LINK_MANAGER_H__