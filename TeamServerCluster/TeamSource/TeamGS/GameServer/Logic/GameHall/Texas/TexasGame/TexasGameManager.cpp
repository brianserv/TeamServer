#include "TexasGameManager.h"
#include "../../../DBCache/DBHallEntity/DBHallEntityManager.h"

CTexasGameManager::CTexasGameManager()
{
}
CTexasGameManager::~CTexasGameManager()
{
	Clear();
}

bool CTexasGameManager::Init()
{
	Clear();

	m_GameRoomIdVec = CEQ_UniqueVector::Instance().GetUniqueVec(CConfigFile::Instance().m_szTexasRoomId);
	GameRoomIdVec::iterator it = m_GameRoomIdVec.begin();
	for (; it != m_GameRoomIdVec.end(); ++it)
	{
		if (!CreateGame(*it, ERoomType_Common))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Game[GameRoomId:%d] Failure !", *it);
			return false;
		}
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Game[GameRoomId:%d] Success !", *it);
	}
	return true;
}

bool CTexasGameManager::InitEx()
{
	DBHallEntityMAP& refDBHallEntityMAP = CDBHallEntityManager::Instance().GetDBHallEntityMap();
	DBHallEntityMAP::iterator it = refDBHallEntityMAP.begin();
	DBHallEntityMAP::iterator it_end = refDBHallEntityMAP.end();
	for (; it != it_end; ++it)
	{
		if (!CreateGame(it->first, ERoomType_Common))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Game[GameRoomId:%d] Failure !", it->first);
			return false;
		}
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "TexasGame Init Create Game[GameRoomId:%d] Success !", it->first);
	}
	return true;
}

bool CTexasGameManager::Clear()
{
	m_GameRoomIdVec.clear();
	m_TexasGameMap.clear();
	return true;
}

bool  CTexasGameManager::CreateGame(int nGameRoomId, int nGameRoomType)
{
	CTexasGame* pTexasGame = new CTexasGame();
	if (NULL == pTexasGame)
	{
		return false;
	}
	pTexasGame->SetIsUsed(true);
	pTexasGame->SetRoomId(nGameRoomId);
	pTexasGame->SetRoomType(nGameRoomType);

	m_TexasGameMap[nGameRoomId] = pTexasGame;
	return true;
}

bool  CTexasGameManager::GameRoomBind()
{
	TexasGameMap::iterator it = m_TexasGameMap.begin();
	TexasGameMap::iterator it_end = m_TexasGameMap.end();
	for (; it != it_end; ++it)
	{
		CTexasGame* pTexasGame = it->second;
		if (NULL != pTexasGame)
		{
			if (!pTexasGame->GameRoomBind())
			{
				return false;
			}
		}
	}
	return true;
}

bool CTexasGameManager::GameRoomBind(int nGameRoomId)
{
	CTexasGame* pTexasGame = GetTexasGame(nGameRoomId);
	if (NULL == pTexasGame)
	{
		return false;
	}
	if (!pTexasGame->GameRoomBind())
	{
		return false;
	}
	return true;
}

bool CTexasGameManager::GameRoomUnBind(int nGameRoomId)
{
	CTexasGame* pTexasGame = GetTexasGame(nGameRoomId);
	if (NULL == pTexasGame)
	{
		return false;
	}
	if (!pTexasGame->GameRoomUnBind())
	{
		return false;
	}
	return true;
}

bool CTexasGameManager::Release_Vip_TexasGame(int nGameRoomId)
{
	CTexasGame* pTexasGame = GetTexasGame(nGameRoomId);
	if (NULL == pTexasGame)
	{
		return false;
	}
	pTexasGame->SetIsUsed(false);
	return true;
}

void  CTexasGameManager::Release_Vip_TexasGame()
{
	TexasGameMap::iterator it, itRemove;
	it = m_TexasGameMap.begin();
	while (it != m_TexasGameMap.end())
	{
		CTexasGame* pTexasGame = it->second;
		if (NULL != pTexasGame &&  pTexasGame->GetRoomType() == (int)ERoomType_Vip && !pTexasGame->GetIsUsed())
		{
			itRemove = it;
			it++;
			m_TexasGameMap.erase(itRemove);
			delete  pTexasGame;
			pTexasGame = NULL;
			continue;
		}
		it++;
	}
}

void CTexasGameManager::Supplementary_Vip_TexasGame_Chip(int nRoomId, int nUnbindChip)
{
	CTexasGame* pTexasGame = GetTexasGame(nRoomId);
	if (NULL != pTexasGame)
	{
		pTexasGame->Supplementary_Vip_TexasGame_Chip(nUnbindChip);
	}
}

CTexasGame*  CTexasGameManager::GetTexasGame(int nGameRoomId)
{
	TexasGameMap::iterator it = m_TexasGameMap.find(nGameRoomId);
	if (it == m_TexasGameMap.end())
	{
		return NULL;
	}
	return it->second;
}

GameRoomIdVec& CTexasGameManager::GetGameRoomIdVec()
{
	return m_GameRoomIdVec;
}

void CTexasGameManager::OnTimer()
{
	TexasGameMap::iterator it = m_TexasGameMap.begin();
	TexasGameMap::iterator it_end = m_TexasGameMap.end();
	for (; it != it_end; ++it)
	{
		CTexasGame* pTexasGame = it->second;
		if (NULL != pTexasGame)
		{
			pTexasGame->OnTimer();
		}
	}
}

void CTexasGameManager::SetTexasGameBoardID(int nGameRoomId, int nGameBoardId)
{
	CTexasGame* pTexasGame = GetTexasGame(nGameRoomId);
	if (NULL != pTexasGame)
	{
		pTexasGame->SetTexasBoardId(nGameBoardId);
	}
}

void CTexasGameManager::SetTexasHistoryWin(int nGameRoomId, vector<int>& refHistoryWinVec)
{
	CTexasGame* pTexasGame = GetTexasGame(nGameRoomId);
	if (NULL != pTexasGame)
	{
		pTexasGame->SetHistoryWin(refHistoryWinVec);
	}
}