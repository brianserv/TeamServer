#include "GSMessage.h"

void CGSMessage::ProcessMsg_GirlLoginReq(char* pDataInfo, long nDataLen, void* pPacketHead, void* pClient)
{
	CPlayerClient* pPlayerClient = (CPlayerClient*)pClient;

	PACKETHEAD* pTempPacketHead = reinterpret_cast<PACKETHEAD*>(pPacketHead);

	GSLoginReq* pGirlLoginReq = reinterpret_cast<GSLoginReq*>(pDataInfo + sizeof(PACKETHEAD));
	if ((NULL == pPlayerClient) || (NULL == pTempPacketHead) || (NULL == pGirlLoginReq))
		return;

	if (!CGirlManager::Instance().CreateGirl(
		pGirlLoginReq->nGirlID,
		pGirlLoginReq->nGirlRoleID,
		pGirlLoginReq->sGirlName,
		pGirlLoginReq->sGirlPassword,
		pGirlLoginReq->sGirlThirdId, 0,
		pTempPacketHead->GetIndex(),
		pPlayerClient->GetIndex()))
		return;

	if (!CGirlManager::Instance().EnterRooom(pGirlLoginReq->nGirlID, (int)EGameType_Texas, pGirlLoginReq->nRoomID))
		return;

	if (!CTexasRoomManager::Instance().Girl_EnterRoom(pGirlLoginReq->nRoomID, pGirlLoginReq->nGirlID))
		return;

	CTexasGame* pTexasGame = CTexasGameManager::Instance().GetTexasGame(pGirlLoginReq->nRoomID);
	if (NULL == pTexasGame)
	{
		return;
	}
	pTexasGame->GirlEnterGame(pGirlLoginReq->nGirlID);
}