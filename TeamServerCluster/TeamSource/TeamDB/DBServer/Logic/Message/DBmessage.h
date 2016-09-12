#pragma once
#ifndef  DB_MESSAGE_H
#define  DB_MESSAGE_H

#include "../../FrameWork/BaseDefine.h"
#include "../../FrameWork/PlayerClient.h"
#include "../../Protocols/CommonProtocol.h"

#include "../Table/DBRole.h"
#include "../Table/DBPrizePool.h"
#include "../Table/DBTexasBoard.h"
#include "../Table/DBTexasHistoryBoard10.h"

#include "../Resource/DBResourceManager.h"

class CDBMessage : public CEQ_SingletonT<CDBMessage>
{
public:
	CDBMessage() {};
	virtual ~CDBMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendGameServerMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

public:
	void ProcessMsg_Ping_HeartBeatReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Ping_HeartBeatRes(char* pDataInfo, long nDataLen, void* pClient);

public:
	void ProcessMsg_Load_RoleReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Load_RoleRes(char* pDataInfo, long nDataLen, void* pClient, int nRoleId);

	void ProcessMsg_Save_RoleReq(char* pDataInfo, long nDataLen, void* pClient);
	//---------------------------------------------------------------------------
public:
	void ProcessMsg_Load_PrizePoolReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Load_PrizePoolRes(char* pDataInfo, long nDataLen, void* pClient);

	void ProcessMsg_Save_PrizePoolReq(char* pDataInfo, long nDataLen, void* pClient);
	//---------------------------------------------------------------------------------
public:
	void ProcessMsg_Load_TexasBoardReq(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Load_TexasBoardRes(char* pDataInfo, long nDataLen, void* pClient, int nBoardID, int nRoomID);

	void ProcessMsg_Save_TexasBoardReq(char* pDataInfo, long nDataLen, void* pClient);
	//----------------------------------------------------------------------------------
public:
	void ProcessMsg_Load_TexasHistoryBoard10Req(char* pDataInfo, long nDataLen, void* pClient);
	void ProcessMsg_Load_TexasHistoryBoard10Res(char* pDataInfo, long nDataLen, void* pClient, int nRoomId);

	void ProcessMsg_Save_TexasHistoryBoard10Req(char* pDataInfo, long nDataLen, void* pClient);
	//-------------------------------------------------------------------------------------------
};
#endif//DB_MESSAGE_H