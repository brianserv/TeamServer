#pragma  once
#ifndef __GATE_GS_MESSAGE_H__
#define __GATE_GS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GateServer.h"
#include "../../../FrameWork/PlayerClient.h"
#include "../../Protocols/CommonProtocol.h"

#include "../../../Logic/Girl/GirlManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//GIRL CLIENT - GATE - GS
class CGSMessage : public CEQ_SingletonT<CGSMessage>
{
public:
	CGSMessage() {};
	virtual ~CGSMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_GirlClientErrorSync(int nErrorID, int nPlayerIndex);
public:
	void ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_HeartBeatRes(int nIndex, bool bClose);

public:
	void ProcessMsg_GirlLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_GirlLoginRes(GSLoginRes refGSLoginRes, int nIndex);
	void ProcessMsg_TransferGirlClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead);
public:
	void ProcessMsg_OnDisconnect(int nIndex);
};

#endif//__GATE_GS_MESSAGE_H__