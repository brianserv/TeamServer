#pragma  once
#ifndef __WS_MESSAGE_H__
#define __WS_MESSAGE_H__

#include "../../../FrameWork/BaseDefine.h"
#include "../Protocols/CommonProtocol.h"

class CWSSMessage : public CEQ_SingletonT<CWSSMessage>
{
public:
	CWSSMessage() {};
	virtual ~CWSSMessage() {};
public:
	void ProcessMsg(std::vector<string>& strRefResponseVec, int nWebMarkId);
};

#endif//__WS_MESSAGE_H__