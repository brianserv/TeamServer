#pragma once
#ifndef __DATE_BUFFER_H__
#define __DATE_BUFFER_H__

#include "BaseDefine.h"
#include "EQ_ObjPool.h"

class CDataBuffer
{
public:
	CDataBuffer(char* pDataBuf, int nBufLen, void* pClient = NULL, char* pIp = NULL, int nPort = 0);
	virtual ~CDataBuffer();
	EQ_DECLARE_CACHE(CDataBuffer)

public:
	char*  GetDataBuffer() { return m_szDataBuffer; };
	int    GetDataBufferLen() { return m_nDataBufferLen; };
	void*  GetClient() { return m_pClient; };
	char*  GetIp() { return m_szIp; };
	int    GetPort() { return m_nPort; };

private:
	char   m_szDataBuffer[SERVER_MESSAGE_LEN_MAX];
	int    m_nDataBufferLen;
	void*  m_pClient;
	char   m_szIp[16];
	int    m_nPort;
};
#endif//__DATE_BUFFER_H__