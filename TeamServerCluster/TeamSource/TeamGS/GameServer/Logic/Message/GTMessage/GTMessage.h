#pragma  once
#ifndef __GAME_GT_MESSAGE_H__
#define __GAME_GT_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../../FrameWork/PlayerClient.h"

#include "../../Protocols/CommonProtocol.h"
#include "../DLMessage/DLMessage.h"

#include "../../../Logic/Girl/GirlManager.h"
#include "../../../Logic/GameHall/Texas/TexasRoom/TexasRoomManager.h"
#include "../../../Logic/GameHall/Texas/TexasGame/TexasGameManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//GT - GS
class CGTMessage : public CEQ_SingletonT<CGTMessage >
{
public:
	CGTMessage() {};
	virtual ~CGTMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendGateMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex);
public:
	void ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, int nPlayerIndex, int nGateIndex);
public:
	void ProcessMsg_Ping_Role_DissconnectSync(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_Ping_Girl_DissconnectSync(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__GAME_GT_MESSAGE_H__