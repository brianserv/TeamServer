#pragma  once
#ifndef __GATE_MESSAGE_H__
#define __GATE_MESSAGE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CGateMessage : public CEQ_SingletonT<CGateMessage >
{
public:
	CGateMessage() {};
	virtual ~CGateMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_Web_Mobile_Client(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_NetGirlClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_PlatformClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__GATE_MESSAGE_H__