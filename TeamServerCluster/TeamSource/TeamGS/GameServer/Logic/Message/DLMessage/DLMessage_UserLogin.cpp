#include "DLMessage.h"

void CDLMessage::ProcessMsg_SaveLoginReq(int nRoleId, char* pIp)
{
	CRole* pRole = CRoleManager::Instance().GetRole(nRoleId);
	if (NULL == pRole || NULL == pIp)
	{
		// log
		return;
	}
	char sendbuf[SERVER_MESSAGE_LEN_MAX] = { 0 };
	int sendlen = 0;
	char* pTemp = sendbuf;
	if (NULL == pTemp)
		return;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pTemp);
	SaveLoginReq* pSaveLoginReq = reinterpret_cast<SaveLoginReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSaveLoginReq))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SaveLoginReq);

	pSaveLoginReq->nRoleId = pRole->GetRoleId();

	memcpy(pSaveLoginReq->sRoleName, pRole->GetRoleName().c_str(), sizeof(pSaveLoginReq->sRoleName));

	pSaveLoginReq->nPlatformId = pRole->GetAttrNum(EAttrNum_nPlatformId);

	memcpy(pSaveLoginReq->sThirdId, pRole->GetThirdId().c_str(), sizeof(pSaveLoginReq->sThirdId));

	memcpy(pSaveLoginReq->sThirdAccount, pRole->GetThirdAccount().c_str(), sizeof(pSaveLoginReq->sThirdAccount));

	pSaveLoginReq->nLoginTime = pRole->GetAttrNum(EAttrNum_nLastLoginTime);

	pSaveLoginReq->nServerId = pRole->GetServerId();

	memcpy(pSaveLoginReq->sIp, pIp, sizeof(pSaveLoginReq->sIp));

	pSaveLoginReq->nStatus = pRole->GetAttrNum(EAttrNum_nStatus);

	pTempPacketHead->SetPacketHead(ESDL_LOGIN_S2DL_SAVE_LOGIN_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBLogMsg(sendbuf, sendlen, pTempPacketHead);
}