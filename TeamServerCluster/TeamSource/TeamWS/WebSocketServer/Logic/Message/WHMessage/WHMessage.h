#pragma  once
#ifndef __WH_MESSAGE_H__
#define __WH_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CWHMessage : public CEQ_SingletonT<CWHMessage>
{
public:
	CWHMessage() {};
	virtual ~CWHMessage() {};
public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__WH_MESSAGE_H__