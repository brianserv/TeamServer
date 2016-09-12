#pragma  once
#ifndef __CENTER_MESSAGE_H__
#define __CENTER_MESSAGE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../../FrameWork/CenterServer.h"
#include "../../FrameWork/PlayerClient.h"

#include "../../Protocols/CommonProtocol.h"

class CCenterMessage : public CEQ_SingletonT<CCenterMessage>
{
public:
	CCenterMessage() {};
	virtual ~CCenterMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_RegisterReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_RegisterRes(char* pDataInfo, long nDataLen, int nIndex, int nServerId);
public:
	void ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_HeartBeatRes(char* pDataInfo, long nDataLen, int nIndex);
};

#endif//__CENTER_MESSAGE_H__