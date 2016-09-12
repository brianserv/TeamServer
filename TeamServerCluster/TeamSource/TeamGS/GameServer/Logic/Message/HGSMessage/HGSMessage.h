#pragma  once
#ifndef __HGS_MESSAGE_H__
#define __HGS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CHGSMessage : public CEQ_SingletonT<CHGSMessage>
{
public:
	CHGSMessage() {};
	virtual ~CHGSMessage() {};
public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__HGS_MESSAGE_H__