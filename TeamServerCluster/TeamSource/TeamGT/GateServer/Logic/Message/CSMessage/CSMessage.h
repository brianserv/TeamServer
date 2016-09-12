#pragma  once
#ifndef __GATE_CS_MESSAGE_H__
#define __GATE_CS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GateServer.h"
#include "../../../FrameWork/PlayerClient.h"
#include "../../Protocols/CommonProtocol.h"

#include "../../Role/RoleManager.h"
////////////////////////////////////////////////////////////////////////////////////////////////
//CLIENT - GATE - GS
class CCSMessage : public CEQ_SingletonT<CCSMessage >
{
public:
	CCSMessage() {};
	virtual ~CCSMessage() {};
public:
	bool Encrypt_MD5_Check(int nTokenId, const string strToken);

public:
	void ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_ClientErrorSync(int nErrorID, int nIndex);
public:
	void ProcessMsg_HeartBeatReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_HeartBeatRes(int nIndex, bool bClose);

public:
	void ProcessMsg_UserLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient);
	void ProcessMsg_TransferClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead);
public:
	void ProcessMsg_OnDisconnect(int nIndex);
};

#endif//__GATE_MESSAGE_H__