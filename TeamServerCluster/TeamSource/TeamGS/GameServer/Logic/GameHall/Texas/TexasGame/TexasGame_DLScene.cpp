#include "TexasGame.h"

#include "../TexasRoom/TexasRoomManager.h"
#include "../../../../Logic/Message/DLMessage/DLMessage.h"

void CTexasGame::SaveTexasBet_DL()
{
	SaveBetReq refSaveBetReq;

	refSaveBetReq.nBoardId = m_nTexasBoardId;

	refSaveBetReq.nGameType = (int)EGameType_Texas;
	refSaveBetReq.nGameId = m_nRoomId;
	refSaveBetReq.nRoomId = m_nRoomId;
	refSaveBetReq.nGirlId = m_nGirlId;
	refSaveBetReq.nServerId = CGameServer::Instance().GetServerId();

	TexasRoleMap refMap = m_pTexasRoom->GetTexasRoleMap();
	TexasRoleMap::iterator it = refMap.begin();
	TexasRoleMap::iterator it_end = refMap.end();
	for (; it != it_end; ++it)
	{
		CTexasRole* pTexasRole = it->second;
		if (NULL != pTexasRole)
		{
			if (pTexasRole->GetIsSitdown() && pTexasRole->IsCheckBet())
			{
				refSaveBetReq.nRoleId = pTexasRole->GetRoleId();
				refSaveBetReq.nJackpot = pTexasRole->GetBet_Jackpot();
				refSaveBetReq.nBonus = pTexasRole->GetBet_Bonus();
				refSaveBetReq.nAnte = pTexasRole->GetBet_Ante();
				refSaveBetReq.nFlop = pTexasRole->GetBet_Flop();
				refSaveBetReq.nWinChip = pTexasRole->GetWinChips();
				refSaveBetReq.nRewardBonus = pTexasRole->GetBonus_RewardValue();
				refSaveBetReq.nRewardJackpot = pTexasRole->GetJackpot_RewardValue();
				refSaveBetReq.nTea = pTexasRole->GetTotalBetTea();
				refSaveBetReq.nTotalAmount = pTexasRole->GetFormulaTotalAmount();

				memcpy(refSaveBetReq.sJackpotDetail, pTexasRole->GetJackpotDetail().c_str(), sizeof(refSaveBetReq.sJackpotDetail));
				memcpy(refSaveBetReq.sBonusDetail, pTexasRole->GetBonusDetail().c_str(), sizeof(refSaveBetReq.sBonusDetail));
				memcpy(refSaveBetReq.sSumChipDetail, pTexasRole->GetSumChipDetail().c_str(), sizeof(refSaveBetReq.sSumChipDetail));
				memcpy(refSaveBetReq.sChipDetail, pTexasRole->GetChipDetail().c_str(), sizeof(refSaveBetReq.sChipDetail));
				memcpy(refSaveBetReq.sWinChipDetail, pTexasRole->GetWinChipDetail().c_str(), sizeof(refSaveBetReq.sWinChipDetail));
				memcpy(refSaveBetReq.sBeforeChipDetail, pTexasRole->GetBeforeChipDetail().c_str(), sizeof(refSaveBetReq.sBeforeChipDetail));
				memcpy(refSaveBetReq.sAfterChipDetail, pTexasRole->GetAfterChipDetail().c_str(), sizeof(refSaveBetReq.sAfterChipDetail));

				CDLMessage::Instance().ProcessMsg_SaveTexasBetReq(pTexasRole->GetRoleId(), refSaveBetReq);
			}
		}
	}
}