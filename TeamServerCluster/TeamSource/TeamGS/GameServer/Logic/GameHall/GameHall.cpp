#include "GameHall.h"

#include "Texas/TexasGame/TexasGameManager.h"
#include "Texas/TexasRoom/TexasRoomManager.h"

CGameHall::CGameHall()
{
}

CGameHall::~CGameHall()
{
}

bool CGameHall::Init()
{
	//if (!Init_TexasGame())
	//{
	//	return false;
	//}
	if (!Init_TexasGameEx())
	{
		return false;
	}
	if (!Init_BaccaratGame())
	{
		return false;
	}
	return true;
}

bool CGameHall::Init_TexasGame()
{
	bool bRet = false;
	if (!CTexasGameManager::Instance().Init())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n "
			"CGameHall::Init_TexasGame()->CTexasGameManager::Instance().Init() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().Init() Success !");
	}
	if (!CTexasRoomManager::Instance().Init())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			"CGameHall::Init_TexasGame()->CTexasRoomManager::Instance().Init() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasRoomManager::Instance().Init() Success !");
	}
	if (!CTexasGameManager::Instance().GameRoomBind())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().GameRoomBind() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().GameRoomBind() Success !");
		g_GameRoomBindSucc = true;
	}

	bRet = true;
	return bRet;
}

bool CGameHall::Init_TexasGameEx()
{
	bool bRet = false;
	if (!CTexasGameManager::Instance().InitEx())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n "
			"CGameHall::Init_TexasGame()->CTexasGameManager::Instance().Init() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().Init() Success !");
	}
	if (!CTexasRoomManager::Instance().InitEx())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			"CGameHall::Init_TexasGame()->CTexasRoomManager::Instance().Init() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasRoomManager::Instance().Init() Success !");
	}
	if (!CTexasGameManager::Instance().GameRoomBind())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().GameRoomBind() Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Init_TexasGame()->CTexasGameManager::Instance().GameRoomBind() Success !");
		g_GameRoomBindSucc = true;
	}

	bRet = true;
	return bRet;
}

bool CGameHall::Create_Vip_TexasGame(TexasRoomVip& refTexasRoomVip)
{
	bool bRet = false;
	if (!CTexasGameManager::Instance().CreateGame(refTexasRoomVip.nRoomId, ERoomType_Vip))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasGameManager::Instance().CreateGame(ERoomType_Vip) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasGameManager::Instance().CreateGame(ERoomType_Vip) Success !");
	}
	if (!CTexasRoomManager::Instance().CreateRoom(refTexasRoomVip.nRoomId, ERoomType_Vip))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasRoomManager::Instance().CreateRoom(ERoomType_Vip) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasRoomManager::Instance().CreateRoom(ERoomType_Vip) Success !");
	}
	if (!CTexasGameManager::Instance().GameRoomBind(refTexasRoomVip.nRoomId))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasGameManager::Instance().GameRoomBind(ERoomType_Vip nRoomId) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasGameManager::Instance().GameRoomBind(ERoomType_Vip nRoomId) Success !");
	}

	if (!CTexasRoomManager::Instance().SetVipRoomInfo(refTexasRoomVip))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasRoomManager::Instance()SetVipRoomInfo(refTexasRoomVip) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Create_Vip_TexasGame(refTexasRoomVip)->CTexasRoomManager::Instance().SetVipRoomInfo(refTexasRoomVip) Success !");
	}
	bRet = true;
	return bRet;
}

bool  CGameHall::Release_Vip_TexasGame(int nRoomId)
{
	bool bRet = false;
	if (!CTexasGameManager::Instance().GameRoomUnBind(nRoomId))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n "
			"CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance()GameRoomUnBind(nRoomId) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance().GameRoomUnBind(nRoomId) Success !");
	}
	if (!CTexasRoomManager::Instance().ReleaseVipRoom(nRoomId))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			" CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance().ReleaseVipRoom(nRoomId) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance().ReleaseVipRoom(nRoomId) Success !");
	}
	if (!CTexasGameManager::Instance().Release_Vip_TexasGame(nRoomId))
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			" [File: %s \n Line:%d \n Function:%s] \n"
			"CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance()Release_Vip_TexasGame(nRoomId) Failure!",
			__FILE__, __LINE__, __FUNCTION__);
		return bRet;
	}
	else
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO,
			" CGameHall::Release_Vip_TexasGame(nRoomId)->CTexasRoomManager::Instance().Release_Vip_TexasGame(nRoomId) Success !");
	}
	bRet = true;
	return bRet;
}

bool  CGameHall::Supplementary_Vip_TexasGame_Chip(int nRoomId, int nUnbindChip)
{
	CTexasGameManager::Instance().Supplementary_Vip_TexasGame_Chip(nRoomId, nUnbindChip);
	return true;
}

bool CGameHall::Release_Vip_TexasGame_Room()
{
	CTexasRoomManager::Instance().ReleaseVipRoom();
	CTexasGameManager::Instance().Release_Vip_TexasGame();
	return true;
}

bool CGameHall::Init_BaccaratGame()
{
	return true;
}