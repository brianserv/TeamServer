#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"
#include "../../../../Logic/Message/GSMessage/GSMessage.h"

void CTexasGame::ProcessMsg_Dealer_DealNoticeSync()
{
	GSDealNotesSync refGSDealNotesSync;
	refGSDealNotesSync.nDealerStatus = m_nDealerStatus;
	CGSMessage::Instance().ProcessMsg_DealNoticeSync(refGSDealNotesSync, m_nGirlId);
}
void CTexasGame::ProcessMsg_Dealer_GameEndSync()
{
	if (m_nGirlId > 0)
	{
		GSGameEndSync refGSGameEndSync;
		refGSGameEndSync.nManualGameResultType = m_nGameWinType;
		CGSMessage::Instance().ProcessMsg_GameEndSync(refGSGameEndSync, m_nGirlId);
	}
}