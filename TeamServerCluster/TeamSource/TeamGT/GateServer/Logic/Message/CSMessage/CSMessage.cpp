#include "CSMessage.h"

bool CCSMessage::Encrypt_MD5_Check(int nTokenId, const string strToken)
{
	string strMakeToken(PARSE_STRINGS::toString(nTokenId) + CONSTR_ROLE_TOKEN_KEY);

	char ary[1024];
	string strMd5Token;
	strMd5Token = md5_string((const unsigned char*)strMakeToken.c_str(), ary, strMakeToken.length());

	if (strToken == strMd5Token)
	{
		return true;
	}
	return false;
}

void  CCSMessage::ProcessMsg(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pPacketHead) || (NULL == pClient))
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	if (NULL == pTempPacketHead)
		return;

	try
	{
		switch (pTempPacketHead->nCmd)
		{
		case ECS_PING_C2GT_HEARTBEAT_REQ:
			ProcessMsg_HeartBeatReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		case ECS_LOGIN_C2GT2S_USERLOGIN_REQ:
			ProcessMsg_UserLoginReq(pDataInfo, nDataLen, pPacketHead, pClient);
			break;
		default:
			ProcessMsg_TransferClientMsg(pDataInfo, nDataLen, pPacketHead);
			break;
		}
	}
	catch (...)
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CGateMessage::CCSMessage Exception Cmd : %ld", pTempPacketHead->nCmd);
	}
}

void CCSMessage::ProcessMsg_ClientErrorSync(int nErrorID, int nPlayerIndex)
{
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	CSErrorInfoSync* pCSErrorInfoSync = reinterpret_cast<CSErrorInfoSync*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pCSErrorInfoSync))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(CSErrorInfoSync);

	pCSErrorInfoSync->nErrorID = nErrorID;

	pTempPacketHead->SetPacketHead(ECS_ERROR_S2GT2C_ERRORCODE_SYNC);
	sendlen = pTempPacketHead->GetLength();
	CGateServer::Instance().SendClientMsg(sendbuf, sendlen, pTempPacketHead->GetIndex());

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "C-S ERROR CODE:%d", nErrorID);
}

void CCSMessage::ProcessMsg_TransferClientMsg(char* pDataInfo, long nDataLen, void* pPacketHead)
{
	CGateServer::Instance().SendGameServerMsg(pDataInfo, nDataLen, pPacketHead);
}

void CCSMessage::ProcessMsg_OnDisconnect(int nIndex)
{
	if (nIndex >= 0)
	{
		CPlayerClient* pPlayerClient = reinterpret_cast<CPlayerClient*>(CGateServer::Instance().m_PlayerClientInfoVec[nIndex]->GetClient());
		if (NULL == pPlayerClient)
		{
			return;
		}
		pPlayerClient->OnDisconnect(0);
	}
}