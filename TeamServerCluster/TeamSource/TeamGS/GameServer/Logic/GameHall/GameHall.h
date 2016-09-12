#pragma  once

#ifndef __GAME_HALL_H__

#define __GAME_HALL_H__

#include "../../FrameWork/BaseDefine.h"

class CGameHall : public CEQ_SingletonT<CGameHall>
{
public:
	CGameHall();
	virtual ~CGameHall();

public:

	bool Init();

	bool Init_TexasGame();
	bool Init_TexasGameEx();
	bool Create_Vip_TexasGame(TexasRoomVip& refTexasRoomVip);
	bool Release_Vip_TexasGame(int nRoomId);
	bool Supplementary_Vip_TexasGame_Chip(int nRoomId, int nUnbindChip);
public:
	bool Release_Vip_TexasGame_Room();

	bool Init_BaccaratGame();
};

#endif//__GAME_HALL_H__
