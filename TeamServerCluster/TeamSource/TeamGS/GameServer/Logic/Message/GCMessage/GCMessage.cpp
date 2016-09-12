#include "GCMessage.h"

void  CGCMessage ::ProcessMsg(char* pDataInfo,long nDataLen,void* pPacketHead,void* pClient)
{
	if((NULL == pDataInfo) || (nDataLen <= 0)  || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		
	}
	catch(...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,"CCenterMessage::Exception Cmd : %ld",pTempPacketHead->nCmd);
	}
}

void CGCMessage ::SendCenterMsg(char* pDataInfo,long nDataLen)
{
	g_CenterClient.SendData(pDataInfo,nDataLen);
}
