#pragma once
#ifndef  EQ_IPADDRESSES_FILE
#define  EQ_IPADDRESSES_FILE

#include "EQUtils.h"
#include "EQ_Singleton.h"

class CEQ_IPAddresses :public CEQ_SingletonT<CEQ_IPAddresses>
{
public:
	CEQ_IPAddresses();
	virtual ~CEQ_IPAddresses();
public:
	bool CheckIpValidation(string strIP);
	bool CheckPortValidation(int nPort);

private:
	bool CheckIpValidation_Sub(string strIPSub);
};

#endif//EQ_IPADDRESSES_FILE