#pragma  once
#ifndef __HALL_MESSAGE_H__
#define __HALL_MESSAGE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CHallMessage : public CEQ_SingletonT<CHallMessage>
{
public:
	CHallMessage() {};
	virtual ~CHallMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__HALL_MESSAGE_H__