#pragma  once
#ifndef __TEXAS_ROLE_H__
#define __TEXAS_ROLE_H__

#include "../../../../FrameWork/BaseDefine.h"
#include "../../../../Logic/Role/RoleManager.h"

#include "../../../../Logic/Message/CSMessage/CSMessage.h"

class CTexasRole
{
public:
	CTexasRole();
	virtual ~CTexasRole();
	EQ_DECLARE_CACHE(CTexasRole)
public:
	bool Init();
	bool Clear();
	bool Reset();
public:
	bool SetRole(int nRoleId);
	bool CheckRole();

public:
	CRole* GetRole();

public:
	//ProcessMsg
	//Login

	//Role

	//HallRoom
	void ProcessMsg_EnterRoomRes(EnterRoomRes& refEnterRoomRes);
	void ProcessMsg_LeaveRoomRes(LeaveRoomRes& refLeaveRoomRes);
	void ProcessMsg_SitDownRes(SitDownRes& refSitDownRes);
	void ProcessMsg_StandUpRes(StandUpRes& refStandUpRes);

	//GameScene
	void ProcessMsg_GirlChangeSync(GirlChangeSync& refGirlChangeSync);
	void ProcessMsg_StartGameSync(GameStartSync& refSTGameStartSync);
	void ProcessMsg_DealCardSync(DealCardSync& refDealCardSync);
	void ProcessMsg_NoticeBetSync(NoticeBetSync refNoticeBetSync);
	void ProcessMsg_GameSettlementSync(GameSettlementSync& refGameSettlementSync);
	void ProcessMsg_GirlCancelGameSync(GirlCancelSync& refGirlCancelSync);

	//GameScene
	void ProcessMsg_CardListSync(CardListSync& refCardListSync);
	void ProcessMsg_RewardPoolSync(RewardPoolSync& refRewardPoolSync);
	void ProcessMsg_HistoryBoardSync(HistoryBoardInfoSync& refHistoryBoardInfoSync);

	//GameScene
	void ProcessMsg_BetRes(BetRes& refBetRes);
	void ProcessMsg_FoldRes(FoldRes& refFoldRes);
	void ProcessMsg_ReadyLeaveRoomRes(ReadyLeaveRoomRes& refReadyLeaveRoomRes);

	//Broadcast
	void ProcessMsg_BetBroadcastSync(BetBroadcastSync& refBetBroadcastSync);
	void ProcessMsg_BrandBroadcastSync(BrandBroadcastSync& refBrandBroadcastSync);
	void ProcessMsg_OnlineBroadcastSync(OnlineBroadcastSync& refOnlineBroadcastSync);

	void ProcessMsg_ErrorSync(int nErrorID);
public:
	void SetMaxHandCard(vector<int>& nMaxCardTypeVec);
	vector<int>& GetMaxHandCard();

public:
	inline void SetRoleId(int nRoleId) { m_nRoleId = nRoleId; }
	inline void SetRoomId(int nRoomId) { m_nRoomId = nRoomId; };
	inline void SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; }
	inline void SetIsSitdown(bool bIsSitdown) { m_bIsSitDown = bIsSitdown; }
	inline void SetIsSetFoldCard(bool bIsSetFoldCard) { m_bIsSetFoldCard = bIsSetFoldCard; }
	inline void SetIsSetCheckCard(bool bIsSetCheckCard) { m_bIsSetCheckCard = bIsSetCheckCard; }
	inline void SetIsSetAnteCard(bool bIsSetAnteCard) { m_bIsSetAnteCard = bIsSetAnteCard; }
	inline void SetIsSetBetResult(bool bIsSetBetResult) { m_bIsBetResultSucc = bIsSetBetResult; }

	inline void SetBet_Jackpot(int nBet_Jackpot) { m_nBet_Jackpot = nBet_Jackpot; }
	inline void SetBet_Bonus(int nBet_Bonus) { m_nBet_Bonus = nBet_Bonus; }
	inline void SetBet_Ante(int nBet_Ante) { m_nBet_Ante = nBet_Ante; }
	inline void SetBet_Flop(int nBet_Flop) { m_nBet_Flop = nBet_Flop; }
	inline void SetBet_Turn(int nBet_Turn) { m_nBet_Turn = nBet_Turn; }
	inline void SetBet_River(int nBet_River) { m_nBet_River = nBet_River; }

	inline void SetBet_Jackpot_UnBind(int nBet_Jackpot_Unbind) { m_nBet_Jackpot_Unbind = nBet_Jackpot_Unbind; }
	inline void SetBet_Bonus_UnBind(int nBet_Bonus_Unbind) { m_nBet_Bonus_Unbind = nBet_Bonus_Unbind; }
	inline void SetBet_Ante_Unbind(int nBet_Ante_Unbind) { m_nBet_Ante_Unbind = nBet_Ante_Unbind; }
	inline void SetBet_Flop_Unbind(int nBet_Flop_Unbind) { m_nBet_Flop_Unbind = nBet_Flop_Unbind; }
	inline void SetBet_Turn_Unbind(int nBet_Turn_Unbind) { m_nBet_Turn_Unbind = nBet_Turn_Unbind; }
	inline void SetBet_River_Unbind(int nBet_River_Unbind) { m_nBet_River_Unbind = nBet_River_Unbind; }

	inline void SetBet_Jackpot_Bind(int nBet_Jackpot_Bind) { m_nBet_Jackpot_Bind = nBet_Jackpot_Bind; }
	inline void SetBet_Bonus_Bind(int nBet_Bonus_Bind) { m_nBet_Bonus_Bind = nBet_Bonus_Bind; }
	inline void SetBet_Ante_Bind(int nBet_Ante_Bind) { m_nBet_Ante_Bind = nBet_Ante_Bind; }
	inline void SetBet_Flop_Bind(int nBet_Flop_Bind) { m_nBet_Flop_Bind = nBet_Flop_Bind; }
	inline void SetBet_Turn_Bind(int nBet_Turn_Bind) { m_nBet_Turn_Bind = nBet_Turn_Bind; }
	inline void SetBet_River_Bind(int nBet_River_Bind) { m_nBet_River_Bind = nBet_River_Bind; }

	inline void SetTotalBetTea(int nTotalBetTea) { m_nTotalBetTea = nTotalBetTea; }
	inline void SetTotalBetChips(int nTotalBetChips) { m_nTotalBetChips += nTotalBetChips; }
	inline void SetTotalLostWinChips(int nTotalLostWinChips) { m_nTotalLostWinChips += nTotalLostWinChips; }
	inline void SetWinChips(int nWinChips) { m_nWinChips = nWinChips; }
	inline void SetWinChips_Unbind(int nWinChips_Unbind) { m_nWinChips_Unbind = nWinChips_Unbind; }
	inline void SetWinChips_Bind(int nWinChips_Bind) { m_nWinChips_Bind = nWinChips_Bind; }

	inline void SetJackpot_RewardMultiples(int nJackpot_RewardMultiples) { m_nJackpot_RewardMultiples = nJackpot_RewardMultiples; }
	inline void SetBonus_RewardMultiples(int nBonus_RewardMultiples) { m_nBonus_RewardMultiples = nBonus_RewardMultiples; }

	inline void SetJackpot_RewardValue(int nJackpot_RewardValue) { m_nJackpot_RewardValue = nJackpot_RewardValue; }
	inline void SetBonus_RewardValue(int nBonus_RewardValue) { m_nBonus_RewardValue = nBonus_RewardValue; }
	inline void SetFormulaTotalAmount(int nFormulaTotalAmount) { m_nFormulaTotalAmount = nFormulaTotalAmount; }

	inline void SetBetBeforeChips_Unbind(int nBetBeforeChips_Unbind) { m_nBetBeforeChips_Unbind = nBetBeforeChips_Unbind; }
	inline void SetBetBeforeChips_Bind(int nBetBeforeChips_Bind) { m_nBetBeforeChips_Bind = nBetBeforeChips_Bind; }
	inline void SetBetBeforeChips_Total(int nBetBeforeChips_Total) { m_nBetBeforeChips_Total = nBetBeforeChips_Total; }
public:
	inline int GetRoleId() { return m_nRoleId; }
	inline int  GetRoomId() { return m_nRoomId; };
	inline bool GetIsSitdown() { return m_bIsSitDown; }
	inline bool GetIsUsed() { return m_bIsUsed; }

	inline int GetBet_Jackpot() { return m_nBet_Jackpot; }
	inline int GetBet_Bonus() { return m_nBet_Bonus; }
	inline int GetBet_Ante() { return m_nBet_Ante; }
	inline int GetBet_Flop() { return m_nBet_Flop; }
	inline int GetBet_Turn() { return m_nBet_Turn; }
	inline int GetBet_River() { return m_nBet_River; }
public:
	inline int GetBet_Jackpot_Unbind() { return m_nBet_Jackpot_Unbind; }
	inline int GetBet_Bonus_Unbind() { return m_nBet_Bonus_Unbind; }
	inline int GetBet_Ante_Unbind() { return m_nBet_Ante_Unbind; }
	inline int GetBet_Flop_Unbind() { return m_nBet_Flop_Unbind; }
	inline int GetBet_Turn_Unbind() { return m_nBet_Turn_Unbind; }
	inline int GetBet_River_Unbind() { return m_nBet_River_Unbind; }
public:
	inline int GetBet_Jackpot_Bind() { return m_nBet_Jackpot_Bind; }
	inline int GetBet_Bonus_Bind() { return m_nBet_Bonus_Bind; }
	inline int GetBet_Ante_Bind() { return m_nBet_Ante_Bind; }
	inline int GetBet_Flop_Bind() { return m_nBet_Flop_Bind; }
	inline int GetBet_Turn_Bind() { return m_nBet_Turn_Bind; }
	inline int GetBet_River_Bind() { return m_nBet_River_Bind; }
public:
	inline int GetRoundBet_Chips(int nRoundType) { return m_nRoundBet_Chips[nRoundType]; }

	inline int GetTotalBetTea() { return m_nTotalBetTea; };
	inline int GetTotalBetChips() { return m_nTotalBetChips; }
	inline int GetTotalLostWinChips() { return m_nTotalLostWinChips; }

	inline int GetWinChips() { return m_nWinChips; }
	inline int GetWinChips_Unbind() { return m_nWinChips_Unbind; }
	inline int GetWinChips_Bind() { return m_nWinChips_Bind; }
public:
	inline int GetJackpot_RewardMultiples() { return m_nJackpot_RewardMultiples; }
	inline int GetBonus_RewardMultiples() { return m_nBonus_RewardMultiples; }

	inline int GetJackpot_RewardValue() { return m_nJackpot_RewardValue; }
	inline int GetBonus_RewardValue() { return m_nBonus_RewardValue; }
	inline int GetFormulaTotalAmount() { return m_nFormulaTotalAmount; }

	inline int GetBetBeforeChips_Unbind() { return m_nBetBeforeChips_Unbind; }
	inline int GetBetBeforeChips_Bind() { return m_nBetBeforeChips_Bind; }
	inline int GetBetBeforeChips_Total() { return m_nBetBeforeChips_Total; }
public:
	inline string GetJackpotDetail() { return m_strJackpotDetail; }
	inline string GetBonusDetail() { return m_strBonusDetail; }
	inline string GetSumChipDetail() { return m_strSumChipDetail; }
	inline string GetChipDetail() { return m_strChipDetail; }
	inline string GetWinChipDetail() { return m_strWinChipDetail; }
	inline string GetBeforeChipDetail() { return m_strBeforeChipDetail; }
	inline string GetAfterChipDetail() { return m_strAfterChipDetail; }

public:
	inline void SetRoleStatus(int nRoleStatus) { m_nRoleStatus = nRoleStatus; }
	inline void AddTotalBetTea(int nBetTea) { m_nTotalBetTea += nBetTea; };
	inline void SetRoundBet_Chips(int nRoundType, int nRoundBet_Chips) { m_nRoundBet_Chips[nRoundType] = nRoundBet_Chips; }
	inline void SetRoundBet_Mark(int nRoundType) { m_bRoundBetMark[nRoundType] = true; }
public:
	inline int GetRoleStatus() { return m_nRoleStatus; }
	inline bool IsFoldCheck() { return  ((GetRoleStatus() != (int)ERS_Fold) ? true : false); }
	inline bool IsSetFoldCard() { return ((m_bIsSetFoldCard == true) ? true : false); }
	inline bool IsSetCheckCard() { return ((m_bIsSetCheckCard == true) ? true : false); }
	inline bool IsSetAnteCard() { return ((m_bIsSetAnteCard == true) ? true : false); }
	inline bool IsCheckBet()
	{
		/*	return ((m_nBet_Ante > 0) ? true : false);*/
		if (m_nBet_Ante > 0)
		{
			return true;
		}
		return false;
	}
	inline bool IsCheckBetResult() { return (m_bIsBetResultSucc == true) ? true : false; }

public:
	inline bool Check_FoldCard() { return ((m_nBet_Flop == 0) ? true : false); }

public:

	void Process_Reward_Bonus(int nReward_Bonus);

	void Process_Reward_Jackpot(int nReward_Jackpot);

	void Process_GameResults(int nGameWinType, int nRoleCardKindType);
	void Process_GameResults_TotalAmount(int nGameWinType);
	void Proxess_GameResults_Detail();

	void Process_GameResults_FoldCard();

	void Process_GameResults_TieWin();

	void Process_GameResults_RoleWin(int nRoleCardKindType);

	void Process_GameResults_GirlWin();

	void Process_SetBetBefore();

	void Process_SetBet_Ante(BetReq& refBetReq);
	void Process_SetBet_Flop(BetReq& refBetReq);
	void Process_SetBet_Turn(BetReq& refBetReq);
	void Process_SetBet_River(BetReq& refBetReq);
	void Process_SetBet_Ante_Bonus(BetReq& refBetReq);
	void Process_SetBet_Ante_JackPot(BetReq& refBetReq);
	void Process_SetBet(int nRoomType, int nGameRounds, int &nMaxBetCount, BetReq& refBetReq);

public:
	bool Process_Bet_Ante(BetReq& refBetReq);
	bool Process_VipRoom_Bet_Ante(BetReq& refBetReq);
	bool Process_Bet_AnteInterface(int m_nRoomType, int &nMaxBetCount, BetReq& refBetReq);
public:

	bool Process_BetShort(int nChips);
	bool Process_Bet_Ante_Limit(int nChips);
	bool Process_Bet_Ante_Broadcast(int &nMaxBetCount, int nChips);
	bool Process_Bet_RepeatBetCheck(int nGameRounds);
public:
	void Process_GameCancel();

public:
	string GetThirdId();
	string GetUserName();
private:
	CRole*   m_pRole;
private:
	int  m_nRoleId;
	int  m_nRoomId;
private:
	bool m_bIsUsed;
	bool m_bIsSitDown;
	bool m_bIsSetFoldCard;
	bool m_bIsSetCheckCard;
	bool m_bIsSetAnteCard;
	bool m_bIsBetResultSucc;

private:
	int m_nRoleStatus;
private:
	int m_nBet_Jackpot;
	int m_nBet_Bonus;
	int m_nBet_Ante;
	int m_nBet_Flop;
	int m_nBet_Turn;
	int m_nBet_River;
private:
	int m_nBet_Jackpot_Unbind;
	int m_nBet_Bonus_Unbind;
	int m_nBet_Ante_Unbind;
	int m_nBet_Flop_Unbind;
	int m_nBet_Turn_Unbind;
	int m_nBet_River_Unbind;
private:
	int m_nBet_Jackpot_Bind;
	int m_nBet_Bonus_Bind;
	int m_nBet_Ante_Bind;
	int m_nBet_Flop_Bind;
	int m_nBet_Turn_Bind;
	int m_nBet_River_Bind;
private:
	int m_nRoundBet_Chips[MAX_TEXAS_BETROUND_NUM];

private:
	int m_nTotalBetTea;
	int m_nTotalBetChips;
	int m_nTotalLostWinChips;
	int m_nWinChips;
	int m_nWinChips_Unbind;
	int m_nWinChips_Bind;
private:
	int m_nJackpot_RewardMultiples;
	int m_nBonus_RewardMultiples;

	int m_nJackpot_RewardValue;
	int m_nBonus_RewardValue;

	int m_nFormulaTotalAmount;

private:
	int m_nBetBeforeChips_Unbind;
	int m_nBetBeforeChips_Bind;
	int m_nBetBeforeChips_Total;
private:
	string m_strJackpotDetail;
	string m_strBonusDetail;
	string m_strSumChipDetail;
	string m_strChipDetail;
	string m_strWinChipDetail;
	string m_strBeforeChipDetail;
	string m_strAfterChipDetail;
private:
	bool m_bRoundBetMark[MAX_TEXAS_BETROUND_NUM];
};
#endif//__TEXAS_ROLE_H__
