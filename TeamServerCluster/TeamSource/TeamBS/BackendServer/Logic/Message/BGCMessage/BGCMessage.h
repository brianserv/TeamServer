#pragma  once
#ifndef __BGC_MESSAGE_H__
#define __BGC_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CBGCMessage : public CEQ_SingletonT<CBGCMessage>
{
public:
	CBGCMessage() {};
	virtual ~CBGCMessage() {};
public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__BGC_MESSAGE_H__