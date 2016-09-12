#pragma  once
#ifndef __GAME_DB_MESSAGE_H__
#define __GAME_DB_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../Protocols/CommonProtocol.h"

#include "../../Role/RoleManager.h"
#include "../../../Logic/GameHall/Texas/TexasGame/TexasGameManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//DB - GS
class CDBMessage : public CEQ_SingletonT<CDBMessage >
{
public:
	CDBMessage() {};
	virtual ~CDBMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendDBMsg(char* pDataInfo, long nDataLen, void* pPacketHead);
public:

	//-----------------------------------------------------------------------------------------------------
	void ProcessMsg_LoadRoleReq(int nRoleID);
	void ProcessMsg_LoadPrizePoolReq();
	void ProcessMsg_LoadTexasBoardReq(LoadTexasBoardReq& refLoadTexasBoardReq);
	void ProcessMsg_LoadTexasHistoryBoardReq(LoadTexasHistoryBoard10Req& refLoadTexasHistoryBoard10Req);
	//-----------------------------------------------------------------------------------------------------
	void ProcessMsg_LoadRoleRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_LoadPrizePoolRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_LoadTexasBoardRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_LoadTexasHistoryBoardRes(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	//------------------------------------------------------------------------------------------------------
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ProcessMsg_SaveRoleReq(int nRoleID);
	void ProcessMsg_SavePrizePoolReq();
	void ProcessMsg_SaveTexasBoardReq(SaveTexasBoardReq& refSaveTexasBoardReq);
	void ProcessMsg_SaveTexasHistoryBoardReq(SaveTexasHistoryBoard10Req& refSaveTexasHistoryBoard10Req);
	//------------------------------------------------------------------------------------------------------
};

#endif//__GAME_DB_MESSAGE_H__
