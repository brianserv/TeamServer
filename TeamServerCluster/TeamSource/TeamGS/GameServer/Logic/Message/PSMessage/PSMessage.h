#pragma  once
#ifndef __GATE_PS_MESSAGE_H__
#define __GATE_PS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../../FrameWork/PlayerClient.h"

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
public:
	void ProcessMsg_VipRoom_Create_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_VipRoom_Release_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_VipRoom_AppendChip_Req(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__GATE_PS_MESSAGE_H__
