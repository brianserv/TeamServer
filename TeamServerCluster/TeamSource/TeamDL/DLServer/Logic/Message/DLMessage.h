#pragma once
#ifndef  DL_MESSAGE_H
#define  DL_MESSAGE_H

#include "../../FrameWork/BaseDefine.h"
#include "../../FrameWork/PlayerClient.h"
#include "../../Protocols/CommonProtocol.h"

#include "../Table/DLBet.h"
#include "../Table/DLGm.h"
#include "../Table/DLLogin.h"
#include "../Table/DLLogout.h"
#include "../Table/DLOnline.h"
#include "../Table/DLPvgGift.h"
#include "../Table/DLPvpGift.h"
#include "../Table/DLRoom.h"
#include "../Table/DLTrace.h"

class CDLMessage : public CEQ_SingletonT<CDLMessage>
{
public:
	CDLMessage() {};
	virtual ~CDLMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, void* pClient);
public:
	void ProcessMsg_Save_BetReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_CrossdayBetReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_GmReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_LoginReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_LogoutReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_OnlineReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_PvgGiftReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_PvpGiftReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_RoomReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Save_TraceReq(char* pDataInfo, long nDataLen, void* pClient);
};

#endif//DL_MESSAGE_H
