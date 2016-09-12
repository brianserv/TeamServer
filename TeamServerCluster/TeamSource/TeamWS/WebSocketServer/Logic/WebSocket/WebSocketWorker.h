#pragma  once
#ifndef __WEBSOCKET_HANDLE_H__
#define __WEBSOCKET_HANDLE_H__

#include "../../FrameWork/BaseDefine.h"

typedef vector<string> RESPONSE_VEC;
class CWebSocketWorker :public CEQ_SingletonT<CWebSocketWorker>
{
public:
	CWebSocketWorker();
	virtual ~CWebSocketWorker();
public:
	void WebSocketFrameHandler(int nWebMarkId);
	void WebSocketFrameHandler(const char* data, unsigned int length, void* pPacketHead, void* pClient);
public:
	void PushNotifications(string strPushNotifications);
	void PushNotifications(string strPushNotifications, int nWebMarkId);
public:
	void OnTimer();

private:
	RESPONSE_VEC m_strResponsevec;
};

#endif//__WEBSOCKET_HANDLE_H__