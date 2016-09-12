#pragma  once
#ifndef __TEXAS_GAME_MANAGER_H__
#define __TEXAS_GAME_MANAGER_H__

#include "../../../../FrameWork/BaseDefine.h"
#include "TexasGame.h"

typedef vector<int> GameRoomIdVec;
typedef map<int, CTexasGame*> TexasGameMap;

class CTexasGameManager : public CEQ_SingletonT<CTexasGameManager>
{
public:
	CTexasGameManager();
	virtual ~CTexasGameManager();
public:
	bool Init();
	bool InitEx();
	bool Clear();
	bool CreateGame(int nGameRoomId, int nGameRoomType);
	bool GameRoomBind();
	bool GameRoomBind(int nGameRoomId);
	bool GameRoomUnBind(int nGameRoomId);
public:
	bool Release_Vip_TexasGame(int nGameRoomId);
public:
	void Release_Vip_TexasGame();

public:
	void Supplementary_Vip_TexasGame_Chip(int nRoomId, int nUnbindChip);

public:
	CTexasGame* GetTexasGame(int nGameRoomId);
	GameRoomIdVec& GetGameRoomIdVec();

public:
	void OnTimer();
public:
	void SetTexasGameBoardID(int nGameRoomId, int nGameBoardId);
	void SetTexasHistoryWin(int nGameRoomId, vector<int>& refHistoryWinVec);
private:
	GameRoomIdVec m_GameRoomIdVec;
	TexasGameMap  m_TexasGameMap;
};
#endif//__TEXAS_GAME_MANAGER_H__
