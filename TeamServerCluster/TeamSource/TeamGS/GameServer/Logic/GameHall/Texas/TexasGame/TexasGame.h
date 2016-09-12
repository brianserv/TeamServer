#pragma  once
#ifndef __TEXAS_GAME_H__
#define __TEXAS_GAME_H__

#include "../../../../FrameWork/BaseDefine.h"

#include "../../../../Logic/Card/Card.h"
#include "../../../../Logic/Girl/GirlManager.h"
#include "../../../../Logic/PrizePool/PrizePool.h"

#include "CommonProtocol.h"

typedef vector<int> TexasCardVec;
typedef vector<int> HistoryWinVec;

class CTexasRoom;
class CTexasGame
{
public:
	CTexasGame();
	virtual ~CTexasGame();
	EQ_DECLARE_CACHE(CTexasGame)
public:
	bool Init();
	bool Clear();
	bool Reset();
public:
	//Role
	//HallRoom
	//Req
	void ProcessMsg_EnterRoomReq(EnterRoomReq& refEnterRoomReq);
	void ProcessMsg_LeaveRoomReq(LeaveRoomReq& refLeaveRoomReq);
	void ProcessMsg_SitDownReq(SitDownReq& refSitDownReq);
	void ProcessMsg_StandUpReq(StandUpReq& refStandUpReq);
	void ProcessMsg_BetReq(BetReq& refBetReq);
	void ProcessMsg_FoldReq(FoldReq& refFoldReq);
	void ProcessMsg_ReadyLeaveRoomReq(ReadyLeaveRoomReq& refReadyLeaveRoomReq);

	//Res
	void ProcessMsg_EnterRoomRes(int nRoleId);
	void ProcessMsg_LeaveRoomRes(int nRoleId);
	void ProcessMsg_SitDownRes(int nRoleId);
	void ProcessMsg_StandUpRes(int nRoleId);
	void ProcessMsg_ReadyLeaveRoomRes(int nRoleId);

	//GameScene
	void ProcessMsg_GirlChangeSync(int nRoleId);
	void ProcessMsg_StartGameSync();
	void ProcessMsg_DealCardSync();
	void ProcessMsg_NoticeBetSync_GameStart();
	void ProcessMsg_NoticeBetSync_GameBet();

	void ProcessMsg_GameResultsSettlementSync();
	void ProcessMsg_GameCancelSync();

	//GameScene ExtraSync
	void ProcessMsg_CardListSync();
	void ProcessMsg_PrizePoolSync();

	//GameScene
	void ProcessMsg_BetRes(int nRoleId);
	void ProcessMsg_FoldRes(int nRoleId);

	//Broadcast
	void ProcessMsg_BetBroadcastSync(int nRoleId);
	void ProcessMsg_BrandBroadcastSync();
	void ProcessMsg_OnlineBroadcastSync();
	void ProcessMsg_AutoFoldSync();

	//HistoryBoard
	void ProcessMsg_HistoryBoardSync(int nRoleId);
public:
	//Girl
	//Req
	void ProcessMsg_Dealer_GameStartReq(GSGameStartReq& refGSGameStartReq);
	void ProcessMsg_Dealer_DealCardReq(GSDealCardReq& refGSDealCardReq);
	void ProcessMsg_Dealer_GameCancelReq(GSGameCancelReq& refGSGameCancelReq);

	//Res
	void ProcessMsg_Dealer_GameStartRes();

	//Dealer Sync
	void ProcessMsg_Dealer_DealNoticeSync();
	void ProcessMsg_Dealer_GameEndSync();

public:
	bool OnGameRound_Reset();
	bool GameRoomBind();
	bool GameRoomUnBind();
	bool CheckRoom();
	bool CheckGirl();
	bool CheckRole();
	bool CheckEnterRoomChips(int nRoleId);

	int GetMaxBetWaitTime();
	int GetNoticeBetRoundId();

public:
	void OnTimer();
public:
	bool OnGameStart();
	bool OnGameStart_Auto();
	bool OnGameStart_Manual();
	bool OnGameStart_Check();
public:
	bool OnGameEnded();
	bool OnGameEnded_Auto();
	bool OnGameEnded_Manual();
	bool OnGameEnded_Cancel();
	bool OnGameEnded_Check();

public:
	void OnGameRound();
	void OnGameRound_FirstRound();
	void OnGameRound_ExtraRound();

	void OnGameRound_RoundMode();
	void OnGameRound_Auto();
	void OnGameRound_Manual();
	void OnGameRound_Deal(int nCard);
	void OnGameRound_DealCard(int nCard);
	void OnGameRound_Dealer_DealCard(int nCard);
	void OnGameRound_SetCard(int nCardDealType, int nCard);
	void OnGameRound_SetRound();
	void OnGameRound_Showdown();
	void OnGameRound_GameCancel();

	void OnGameRound_NoticeBet();
	void OnGameRound_Dealer_GameRound();
	void OnGameRound_Dealer_GameReStart();

public:
	void OnGameRound_Bet(BetReq& refBetReq);
	void OnGameRound_VipRoom_Bet(BetReq& refBetReq);
	void OnGameRound_Fold(FoldReq& refFoldReq);
public:
	void OnGameRound_GameResultsSettlement();
public:
	int  GetProduceCardNum();
	void SetHistoryWin();
	void SetHistoryWin(vector<int>& refHistoryWinVec);
	void SetRoleCenterCard(BYTE sCard[]);
	void SetGirlCenterCard(BYTE sCard[]);;

public:
	bool CheckPrizePool_Additional();
	void UpdatePrizePool_Add(int nVal);
	void UpdatePrizePool_Dec(int nVal);
	void UpdatePrizePool_Additional();
	void UpdatePrizePool(int nVal, int nEOption);
	void UpdatePrizePool();
	void UpdateGameChips();
	void UpdateGameVipRoomChips();
public:
	void ResetGameRole();
	void SetMaxHandCard(BYTE sCard[]);
public:
	//DB Scene
	void UpdatePrizePool_DB();
	void SaveTexasBoard_DB();
	void SaveTexasHistoryBoard10_DB();
public:
	void SaveTexasBet_DL();
public:
	void Supplementary_Vip_TexasGame_Chip(int nUnbindChip);
public:
	inline bool CheckCountDown_TurnTime(unsigned int nAimTime)
	{
		return ((CEQ_Time::Instance().EQ_GetTime() - m_nCoutDown_TurnTime) > nAimTime) ? true : false;
	}
	inline bool CheckCountDown_TurnTime()
	{
		return ((CEQ_Time::Instance().EQ_GetTime() - m_nCoutDown_TurnTime) >= MAX_TEXAS_GAMESTART_INTERVAL) ? true : false;
	}

	inline bool CheckTimeRange_Minute(unsigned int nCurrentTime, unsigned int nAimTime)
	{
		return ((nCurrentTime - nAimTime) < EQ_MINUTE) ? false : true;
	}
	inline bool CheckGameStatus_GameRun() { return  (m_nGameStatus == (int)EGS_GameRun) ? false : true; }

	inline bool CheckVipRoomLimitBetAnte(int nVal, int nLimitMaxAnte)
	{
		return ((m_nVipRoomLimitBetAnte + nVal) <= nLimitMaxAnte) ? true : false;
	}

	inline bool CheckGameRoundSwitch(int nGameRoundSwitch) { return m_bGameRoundSwitch[nGameRoundSwitch]; }

	inline bool CheckGameRounds_FirstRound() { return (m_nGameRounds == 0) ? false : true; }
	inline void GirlEnterGame(int nGirlId) { SetGirlId(nGirlId); }
	inline void GirlLeaveGame(int nGirlId) { SetGirlId(0); }
	inline void GirlStartGame() { m_bManualModel = true; }
	inline void GirlEndGame() { m_bManualModel = false; }
public:
	inline void SetStartTime() { m_nStartTime = CEQ_Time::Instance().EQ_GetTime(); }
	inline void SetEndTime() { m_nEndTime = CEQ_Time::Instance().EQ_GetTime(); }

	inline void SetCountDown_TurnTime() { m_nCoutDown_TurnTime = CEQ_Time::Instance().EQ_GetTime(); }
public:
	inline void SetIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };
public:
	inline void SetRoomId(int nRoomId) { m_nRoomId = nRoomId; }
	inline void SetRoomType(int nRoomType) { m_nRoomType = nRoomType; }
	inline void SetGirlId(int nGirlId) { m_nGirlId = nGirlId; }
	inline void SetTexasBoardId(int nTexasBoardId) { m_nTexasBoardId = nTexasBoardId; }
	inline void SetGameStatus(int nGameStatus) { m_nGameStatus = nGameStatus; }
	inline void SetGameWinType(int nGameWinType) { m_nGameWinType = nGameWinType; }
	inline void SetCardDealType(int nCardDealType) { m_nCardDealType = nCardDealType; }
	inline void SetDealerStatus(int nDealerStatus) { m_nDealerStatus = nDealerStatus; }
	inline void SetRoleCardKindType(int nRoleCardKindType) { m_nRoleCardKindType = nRoleCardKindType; }
	inline void SetGirlCardKindType(int nGirlCardKindType) { m_nGirlCardKindType = nGirlCardKindType; }
	inline void SetBonusType(int nBonusType) { m_nBonusType = nBonusType; }
	inline void SetJackpotType(int nJackpotType) { m_nJackpotType = nJackpotType; };
public:
	inline void SetTotal_Bet_Jackpot(int nTotal_Bet_Jackpot) { m_nTotal_Bet_Jackpot = nTotal_Bet_Jackpot; }
	inline void SetTotal_Bet_Bonus(int nTotal_Bet_Bonus) { m_nTotal_Bet_Bonus = nTotal_Bet_Bonus; }
	inline void SetTotal_Reward_Jackpot(int nTotal_Reward_Jackpot) { m_nTotal_Reward_Jackpot = nTotal_Reward_Jackpot; }
	inline void SetTotal_Reward_Bonus(int nTotal_Reward_Bonus) { m_nTotal_Reward_Bonus = nTotal_Reward_Bonus; }

	inline void SetVipRoomRemainBetAnte(int nVipRoomRemainBetAnte) { m_nVipRoomRemainBetAnte = nVipRoomRemainBetAnte; }
	inline void SetVipRoomLimitBetAnte(int nVipRooLimitBetAnte) { m_nVipRoomLimitBetAnte = nVipRooLimitBetAnte; }
	inline void SetTotalLostWinChips_Game(int nTotalLostWinChips_Game) { m_nTotalWinLostChips_Game = nTotalLostWinChips_Game; }
	inline void SetGameRoundSwitch(int nGameRoundSwitch) { m_bGameRoundSwitch[nGameRoundSwitch] = true; }
public:
	inline int  GetCurrentTime() { return CEQ_Time::Instance().EQ_GetTime(); }

public:
	inline bool GetIsUsed() { return m_bIsUsed; }
public:
	inline int  GetRoomId() { return m_nRoomId; }
	inline int  GetRoomType() { return m_nRoomType; }
	inline int  GetGirlId() { return m_nGirlId; }
	inline int  GetTexasBoardId() { return m_nTexasBoardId; }
	inline int  GetGameStatus() { return m_nGameStatus; }
	inline int  GetGameWinType() { return m_nGameWinType; }
	inline int  GetCardDealType() { return m_nCardDealType; }
	inline int  GetManualDealNoticeType() { return m_nDealerStatus; }
	inline int  GetHistoryWinCount() { return m_nHistoryWinVec.size(); }
	inline int  GetRoleCardKindType() { return m_nRoleCardKindType; }
	inline int  GetGirlCardKindType() { return m_nGirlCardKindType; }
	inline int  GetBonusType() { return m_nBonusType; }
	inline int  GetJackpotType() { return m_nJackpotType; }

	inline int GetTotal_Bet_Jackpot() { return m_nTotal_Bet_Jackpot; }
	inline int GetTotal_Bet_Bonus() { return m_nTotal_Bet_Bonus; }
	inline int GetTotal_Reward_Jackpot() { return m_nTotal_Reward_Jackpot; }
	inline int GetTotal_Reward_Bonus() { return m_nTotal_Reward_Bonus; }

	inline int GetRemainBetAnte() { return m_nVipRoomRemainBetAnte; }
	inline int GetTotalLostWinChips_Game() { return m_nTotalWinLostChips_Game; }
	inline int GetTotalLostWinChips_Role() { return m_nTotalWinLostChips_Role; }
	inline int GetVipRoomRemainBetAnte() { return m_nVipRoomRemainBetAnte; }
	inline int GetVipRoomLimitBetAnte() { return m_nVipRoomLimitBetAnte; }

public:
	inline void AddTexasBoardId() { m_nTexasBoardId++; }
	inline void AddCardNum() { m_nCardNum++; }
	inline void AddGameRounds() { m_nGameRounds++; }
public:
	inline void AddTotal_Bet_Jackpot(int nBet_Jackpot) { m_nTotal_Bet_Jackpot += nBet_Jackpot; }
	inline void AddTotal_Bet_Bonus(int nBet_Bonus) { m_nTotal_Bet_Bonus += nBet_Bonus; }
	inline void AddTotal_Reward_Jackpot(int nReward_Jackpot) { m_nTotal_Reward_Jackpot += nReward_Jackpot; }
	inline void AddTotal_Reward_Bonus(int nReward_Bonus) { m_nTotal_Reward_Bonus += nReward_Bonus; }

	inline void AddVipRoomLimitBetAnte(int nVal) { m_nVipRoomLimitBetAnte += nVal; }
	inline void AddTotalLostWinChips_Role(int nTotalLostWinChips_Game) { m_nTotalWinLostChips_Role += nTotalLostWinChips_Game; }
public:
	inline void DecVipRoomRemainBetAnte(int nVal) { (m_nVipRoomRemainBetAnte - nVal >= 0) ? (m_nVipRoomRemainBetAnte -= nVal) : true; }

public:
	inline void ResetCardNum() { m_nCardNum = 0; }
	inline void RestGameRounds() { m_nGameRounds = 0; }
	inline void ResetGameStatus() { m_nGameStatus = (int)EGS_GameReady; }
private:
	TexasCardVec  m_nHandCardVec;
	TexasCardVec  m_nCenterCardVec;
	TexasCardVec  m_nGirlCardVec;
	TexasCardVec  m_nGameCardVec;
	HistoryWinVec m_nHistoryWinVec;

private:
	CCard        m_Card;
	CTexasRoom*  m_pTexasRoom;
private:
	bool         m_bIsUsed;
	bool         m_bDealerStart;
private:
	int          m_nRoomId;
	int          m_nRoomType;
	int          m_nGirlId;
	int          m_nTexasBoardId;
private:
	unsigned int m_nStartTime;
	unsigned int m_nEndTime;
	unsigned int m_nCoutDown_TurnTime;
	unsigned int m_nMaxBetWaitTime;
private:
	bool         m_bManualModel;
private:
	int          m_nGameStatus;
	int          m_nGameRounds;
	int          m_nGameWinType;
	int          m_nCardDealType;
	int          m_nDealerStatus;
	int          m_nCardValue;
	int          m_nCardNum;
private:
	int          m_nMaxBetCount;
	int          m_nHistoryWinCount;
	int          m_nRoleCardKindType;
	int          m_nGirlCardKindType;
	int          m_nBonusType;
	int          m_nJackpotType;
	vector<int>  m_nRoleCenterCard;
	vector<int>  m_nGirlCenterCard;
private:
	int m_nTotal_Bet_Jackpot;
	int m_nTotal_Bet_Bonus;

	int m_nTotal_Reward_Jackpot;
	int m_nTotal_Reward_Bonus;

	int m_nVipRoomRemainBetAnte;
	int m_nVipRoomLimitBetAnte;

	int m_nTotalWinLostChips_Game;
	int m_nTotalWinLostChips_Role;
private:
	bool m_bGameRoundSwitch[5];
};
#endif//__TEXAS_GAME_H__
