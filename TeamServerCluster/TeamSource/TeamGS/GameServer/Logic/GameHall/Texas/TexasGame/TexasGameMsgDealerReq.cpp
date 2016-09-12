#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

void  CTexasGame::ProcessMsg_Dealer_GameStartReq(GSGameStartReq& refGSGameStartReq)
{
	ProcessMsg_Dealer_GameStartRes();
}

void  CTexasGame::ProcessMsg_Dealer_DealCardReq(GSDealCardReq& refGSDealCardReq)
{
	OnGameRound_Dealer_DealCard(refGSDealCardReq.nCardValue);
}

void  CTexasGame::ProcessMsg_Dealer_GameCancelReq(GSGameCancelReq& refGSGameCancelReq)
{
	OnGameEnded_Cancel();
}