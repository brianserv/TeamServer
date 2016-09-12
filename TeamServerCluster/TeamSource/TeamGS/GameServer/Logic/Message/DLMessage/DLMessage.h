#pragma  once
#ifndef __GAME_DL_MESSAGE_H__
#define __GAME_DL_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../Protocols/CommonProtocol.h"

#include "../../Common/GameStructure.h"
#include "../../Role/RoleManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//DL - GS
class CDLMessage : public CEQ_SingletonT<CDLMessage >
{
public:
	CDLMessage() {};
	virtual ~CDLMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void SendDBLogMsg(char* pDataInfo, long nDataLen, void* pPacketHead);
public:
	void ProcessMsg_SaveLoginReq(int nRoleId, char* pIp);
	void ProcessMsg_SaveLogOutReq(int nRoleId, char* pIp);
public:
	void ProcessMsg_SaveTexasBetReq(int nRoleId, SaveBetReq& refSaveBetReq);
};

#endif//__GAME_DL_MESSAGE_H__
