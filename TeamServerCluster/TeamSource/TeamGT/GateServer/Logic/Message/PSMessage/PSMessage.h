#pragma  once
#ifndef __GATE_PS_MESSAGE_H__
#define __GATE_PS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GateServer.h"
#include "../../Protocols/CommonProtocol.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//PLATFORM - GATE - GS
class CPSMessage : public CEQ_SingletonT<CPSMessage>
{
public:
	CPSMessage() {};
	virtual ~CPSMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_TransferPlatformMsg(char* pDataInfo, long nDataLen, void* pPacketHead);
public:
};

#endif//__GATE_PS_MESSAGE_H__