#pragma  once
#ifndef __WSS_MESSAGE_H__
#define __WSS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CWSSMessage : public CEQ_SingletonT<CWSSMessage>
{
public:
	CWSSMessage() {};
	virtual ~CWSSMessage() {};
public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__WSS_MESSAGE_H__