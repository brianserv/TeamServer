#pragma  once
#ifndef __GAME_GC_MESSAGE_H__
#define __GAME_GC_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../../../FrameWork/GameServer.h"
#include "../../Protocols/CommonProtocol.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//GC - GS
class CGCMessage : public CEQ_SingletonT<CGCMessage >
{
public:
	CGCMessage (){};
	virtual ~CGCMessage (){};

public:
	void ProcessMsg(char* pDataInfo,long nDataLen,void* pPacketHead,void* pClient);
	void SendCenterMsg(char* pDataInfo,long nDataLen);
};

#endif//__GAME_GC_MESSAGE_H__