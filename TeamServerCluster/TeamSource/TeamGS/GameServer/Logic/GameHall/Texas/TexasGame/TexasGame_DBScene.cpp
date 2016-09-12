#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"
#include "../../../../Logic/Message/DBMessage/DBMessage.h"

void CTexasGame::UpdatePrizePool_DB()
{
	CDBMessage::Instance().ProcessMsg_SavePrizePoolReq();
}

void CTexasGame::SaveTexasBoard_DB()
{
	SaveTexasBoardReq refSaveTexasBoardReq;
	refSaveTexasBoardReq.nBoardId = m_nTexasBoardId;
	refSaveTexasBoardReq.nGirlId = m_nGirlId;

	refSaveTexasBoardReq.nServerId = CGameServer::Instance().GetServerId();
	refSaveTexasBoardReq.nGameId = m_nRoomId;
	refSaveTexasBoardReq.nRoomId = m_nRoomId;
	refSaveTexasBoardReq.nSumChip = m_nTotalWinLostChips_Game;
	refSaveTexasBoardReq.nRewardJackpotType = m_nJackpotType;
	refSaveTexasBoardReq.nRewardBonusType = m_nBonusType;

	refSaveTexasBoardReq.nDealcardType = m_nCardDealType;
	refSaveTexasBoardReq.nResult = m_nGameWinType;
	refSaveTexasBoardReq.nEndStatus = m_nGameStatus;
	refSaveTexasBoardReq.nStartTime = m_nStartTime;
	refSaveTexasBoardReq.nEndTime = m_nEndTime;

	string strWinCard("");
	string strFullCard("");
	string strSplit(",");
	switch (m_nGameWinType)
	{
	case EGWT_TIE:
	case EGWT_GIRL:
	{
		refSaveTexasBoardReq.nCardType = GetGirlCardKindType();

		for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
		{
			strWinCard += PARSE_STRINGS::toString(m_nGirlCenterCard[index]);
			strWinCard += strSplit;
		}

		memcpy(refSaveTexasBoardReq.strCard, strWinCard.c_str(), sizeof(refSaveTexasBoardReq.strCard));
	}
	break;
	case EGWT_ROLE:
	{
		refSaveTexasBoardReq.nCardType = GetRoleCardKindType();
		for (int index = 0; index < MAX_TEXAS_CENTERCARD_NUM; index++)
		{
			strWinCard += PARSE_STRINGS::toString(m_nRoleCenterCard[index]);
			strWinCard += strSplit;
		}

		memcpy(refSaveTexasBoardReq.strCard, strWinCard.c_str(), sizeof(refSaveTexasBoardReq.strCard));
	}
	break;
	}

	for (int index = 0; index < MAX_TEXAS_DEALERCARD_NUM; index++)
	{
		strFullCard += PARSE_STRINGS::toString(m_nGameCardVec[index]);
		strFullCard += strSplit;
	}
	memcpy(refSaveTexasBoardReq.strShowCard, strFullCard.c_str(), sizeof(refSaveTexasBoardReq.strShowCard));

	CDBMessage::Instance().ProcessMsg_SaveTexasBoardReq(refSaveTexasBoardReq);
}

void CTexasGame::SaveTexasHistoryBoard10_DB()
{
	if (m_nHistoryWinVec.size() < TEXAS_HISTORY_BOARD_NUM)
		return;

	{
		SaveTexasHistoryBoard10Req refSaveTexasHistoryBoard10Req;
		refSaveTexasHistoryBoard10Req.nGameId = m_nRoomId;
		refSaveTexasHistoryBoard10Req.nRoomId = m_nRoomId;
		refSaveTexasHistoryBoard10Req.nServerId = CGameServer::Instance().GetServerId();

		string strHistoryWinResult("");
		string strSplit(",");
		for (int index = 0; index < TEXAS_HISTORY_BOARD_NUM; index++)
		{
			strHistoryWinResult += PARSE_STRINGS::toString(m_nHistoryWinVec[index]);
			strHistoryWinResult += strSplit;
		}

		memcpy(refSaveTexasHistoryBoard10Req.sResult, strHistoryWinResult.c_str(), sizeof(refSaveTexasHistoryBoard10Req.sResult));

		refSaveTexasHistoryBoard10Req.nBoardCount = TEXAS_HISTORY_BOARD_NUM;

		CDBMessage::Instance().ProcessMsg_SaveTexasHistoryBoardReq(refSaveTexasHistoryBoard10Req);
	}
}