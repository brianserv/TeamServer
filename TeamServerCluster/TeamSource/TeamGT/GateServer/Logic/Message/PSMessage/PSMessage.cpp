#include "PSMessage.h"

void  CPSMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		ProcessMsg_TransferPlatformMsg(pDataInfo, nDataLen, pPacketHead);
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CCenterMessage::Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CPSMessage::ProcessMsg_TransferPlatformMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	CGateServer::Instance().SendGameServerMsg(pDataInfo, nDataLen, pPacketHead);
}