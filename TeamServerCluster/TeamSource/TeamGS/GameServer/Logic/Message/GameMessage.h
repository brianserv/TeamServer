#pragma once
#ifndef  __GAME_MESSAHE_H__
#define  __GAME_MESSAHE_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CGameMessage : public CEQ_SingletonT<CGameMessage>
{
public:
	CGameMessage() {};
	virtual ~CGameMessage() {};

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_CenterMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_GateMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_Web_Mobile_Client(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_NetGirlClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_PlatformClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_DBClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);

	void ProcessMsg_DLClient(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
public:
	void ProcessMsg_HGSMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_WSSMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
};
#endif//__GAME_MESSAHE_H__