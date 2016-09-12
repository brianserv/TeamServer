﻿#ifndef __GS_PROTOCOL_H__
#define __GS_PROTOCOL_H__

//GIRL CLIENT - GATE - GS
//Protocol ID:[20001-30000](Base :20000)
enum EGS_PROTOCOL
{
	EGS_BEGIN = 20000,
	////////////////////////////////////////////////////////////////////////////////////////////////

	//GIRL CLIENT HeartBeat
	EGS_PING_G2GT_HEARTBEAT_REQ = EGS_BEGIN + 1,
	EGS_PING_GT2G_HEARTBEAT_RES = EGS_BEGIN + 2,

	//GIRL CLIENT LOGIN
	EGS_LOGIN_G2GT2S_GIRLLOGIN_REQ = EGS_BEGIN + 3,
	EGS_LOGIN_S2GT2G_GIRLLOGIN_RES = EGS_BEGIN + 4,

	//GIRL CLIENT LOGOUT
	EGS_LOGIN_G2GT2S_GIRLLOGOUT_REQ = EGS_BEGIN + 5,

	//TEXASGAME _GAMESTART
	EGS_TEXASGAME_G2GT2S_GAMESTART_REQ = EGS_BEGIN + 6,
	EGS_TEXASGAME_S2GT2G_GAMESTART_RES = EGS_BEGIN + 7,

	//TEXASGAME DEALNOTICE
	ECS_TEXASGAME_S2GT2C_DEALNOTICE_SYNC = EGS_BEGIN + 8,

	//TEXASGAME DEALCARD
	EGS_TEXASGAME_G2GT2S_DEALCARD_REQ = EGS_BEGIN + 9,

	//TEXASGAME GAMEEND
	ECS_TEXASGAME_S2GT2C_GAMEEND_SYNC = EGS_BEGIN + 10,

	//TEXASGAME GAMECACEL
	EGS_TEXASGAME_G2GT2S_GAMECANCEL_REQ = EGS_BEGIN + 11,

	////////////////////////////////////////////////////////////////////////////////////////////////
	EGS_ERROR_S2GT2G_ERRORCODE_SYNC = EGS_BEGIN + 9999,

	////////////////////////////////////////////////////////////////////////////////////////////////
	EGS_END = 30000,
};

#endif//__GS_PROTOCOL_H__
