#pragma  once
#ifndef __GAME_GS_MESSAGE_H__
#define __GAME_GS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../../FrameWork/PlayerClient.h"
#include "../../Protocols/CommonProtocol.h"

#include "../../../Logic/GameHall/Texas/TexasGame/TexasGameManager.h"
#include "../../../Logic/GameHall/Texas/TexasRoom/TexasRoomManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//GIRL CLIENT - GATE - GS
class CGSMessage : public CEQ_SingletonT<CGSMessage>
{
public:
	CGSMessage() {};
	virtual ~CGSMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendGirlClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead, int nPlayerIndex, int nGateIndex);
	void ProcessMsg_GirlClientErrorSync(int nErrorID, int nPlayerIndex, int nGateIndex);

public:
	void ProcessMsg_GirlLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_GameStartReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_GameStartRes(GSGameStartRes& refGSGameStartRes, int nGirlID);

	void ProcessMsg_DealNoticeSync(GSDealNotesSync& refGSDealNotesSync, int nGirlID);

	void ProcessMsg_DealCardReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_GameEndSync(GSGameEndSync& refGSGameEndSync, int nGirlID);

	void ProcessMsg_GameCancelReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};

#endif//__GAME_GS_MESSAGE_H__