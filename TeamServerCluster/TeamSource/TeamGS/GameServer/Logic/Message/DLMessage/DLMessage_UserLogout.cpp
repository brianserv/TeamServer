#include "DLMessage.h"

void CDLMessage::ProcessMsg_SaveLogOutReq(int nRoleId, char* pIp)
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
	SaveLogoutReq* pSaveLogoutReq = reinterpret_cast<SaveLogoutReq*>(pTemp + sizeof(PACKETHEAD));
	if ((NULL == pTempPacketHead) || (NULL == pSaveLogoutReq))
		return;

	pTempPacketHead->nSize = pTempPacketHead->GetHeadLength();
	pTempPacketHead->nSize += sizeof(SaveLogoutReq);

	pSaveLogoutReq->nRoleId = pRole->GetRoleId();

	memcpy(pSaveLogoutReq->sRoleName, pRole->GetRoleName().c_str(), sizeof(pSaveLogoutReq->sRoleName));

	pSaveLogoutReq->nPlatformId = pRole->GetAttrNum(EAttrNum_nPlatformId);

	memcpy(pSaveLogoutReq->sThirdId, pRole->GetThirdId().c_str(), sizeof(pSaveLogoutReq->sThirdId));
	memcpy(pSaveLogoutReq->sThirdAccount, pRole->GetThirdAccount().c_str(), sizeof(pSaveLogoutReq->sThirdAccount));

	pSaveLogoutReq->nLoginTime = pRole->GetAttrNum(EAttrNum_nLastLoginTime);

	pSaveLogoutReq->nLogoutTime = CEQ_Time::Instance().EQ_GetTime();

	pSaveLogoutReq->nServerId = pRole->GetServerId();
	memcpy(pSaveLogoutReq->sIp, pIp, sizeof(pSaveLogoutReq->sIp));

	pSaveLogoutReq->nUnbindChip = pRole->GetAttrNum(EAttrNum_nUnBindChip);
	pSaveLogoutReq->nUnbindPink = pRole->GetAttrNum(EAttrNum_nUnBindPink);
	pSaveLogoutReq->nBindChip = pRole->GetAttrNum(EAttrNum_nBindChip);
	pSaveLogoutReq->nBindPink = pRole->GetAttrNum(EAttrNum_nBindPink);

	pTempPacketHead->SetPacketHead(ESDL_LOGOUT_S2DL_SAVE_LOGOUT_REQ);
	sendlen = pTempPacketHead->GetLength();
	SendDBLogMsg(sendbuf, sendlen, pTempPacketHead);
}