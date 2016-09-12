#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

#include "../../../../Logic/Message/GSMessage/GSMessage.h"

void CTexasGame::ProcessMsg_Dealer_GameStartRes()
{
	GSGameStartRes refGSGameStartRes;

	if (!CheckRole())
	{
		refGSGameStartRes.nGameStartResult = (int)EMSGT_Failure;
		CGSMessage::Instance().ProcessMsg_GameStartRes(refGSGameStartRes, m_nGirlId);
		return;
	}

	{
		m_bDealerStart = OnGameStart_Check();
		if (!m_bDealerStart)
		{
			refGSGameStartRes.nGameStartResult = (int)EMSGT_Failure;
			CGSMessage::Instance().ProcessMsg_GameStartRes(refGSGameStartRes, m_nGirlId);
			return;
		}
		refGSGameStartRes.nGameStartResult = (int)EMSGT_Success;
		CGSMessage::Instance().ProcessMsg_GameStartRes(refGSGameStartRes, m_nGirlId);

		OnGameStart_Manual();

		GirlStartGame();
	}
}