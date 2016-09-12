#pragma  once
#ifndef __WEB_MESSAGE_H__
#define __WEB_MESSAGE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CWebMessage : public CEQ_SingletonT<CWebMessage>
{
public:
	CWebMessage() {};
	virtual ~CWebMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__WEB_MESSAGE_H__