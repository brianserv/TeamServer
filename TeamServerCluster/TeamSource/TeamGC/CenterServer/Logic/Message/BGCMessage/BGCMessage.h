#pragma  once
#ifndef __BGC_MESSAGE_H__
#define __BGC_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"

#include "../../Protocols/CommonProtocol.h"

class CBGCMessage : public CEQ_SingletonT<CBGCMessage>
{
public:
	CBGCMessage() {};
	virtual ~CBGCMessage() {};
};

#endif//__BGC_MESSAGE_H__