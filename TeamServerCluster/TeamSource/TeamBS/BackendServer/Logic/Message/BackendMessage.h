#pragma  once
#ifndef __BACKEND_MESSAGE_H__
#define __BACKEND_MESSAGE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CBackendMessage : public CEQ_SingletonT<CBackendMessage>
{
public:
	CBackendMessage() {};
	virtual ~CBackendMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__BACKEND_MESSAGE_H__