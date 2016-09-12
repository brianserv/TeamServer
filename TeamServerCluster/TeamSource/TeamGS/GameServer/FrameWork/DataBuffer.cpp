#include "DataBuffer.h"

EQ_IMPLEMENT_CACHE(CDataBuffer, 100)
CDataBuffer::CDataBuffer(char* pDataBuf, int nBufLen, void* pClient, char* pIp, int nPort)
{
	memset(m_szDataBuffer, 0, sizeof(m_szDataBuffer));
	memcpy(m_szDataBuffer, pDataBuf, nBufLen);
	m_nDataBufferLen = nBufLen;
	m_pClient = pClient;

	if (NULL != pIp)
	{
		memset(m_szIp, 0, sizeof(m_szIp));
		memcpy(m_szIp, pIp, sizeof(m_szIp));
		m_nPort = nPort;
	}
}

CDataBuffer::~CDataBuffer()
{
	memset(m_szDataBuffer, 0, sizeof(m_szDataBuffer));
	m_nDataBufferLen = 0;

	if (NULL != m_pClient)
	{
		m_pClient = NULL;
	}

	if (NULL != m_szIp)
	{
		memset(m_szIp, 0, sizeof(m_szIp));
		m_nPort = 0;
	}
}