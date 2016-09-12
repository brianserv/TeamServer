#pragma  once
#ifndef __WB_MESSAGE_H__
#define __WB_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CWBMessage : public CEQ_SingletonT<CWBMessage>
{
public:
	CWBMessage() {};
	virtual ~CWBMessage() {};
public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__WB_MESSAGE_H__