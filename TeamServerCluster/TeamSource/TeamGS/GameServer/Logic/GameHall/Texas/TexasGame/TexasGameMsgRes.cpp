#include "TexasGame.h"
#include "../TexasRoom/TexasRoomManager.h"

void CTexasGame::ProcessMsg_EnterRoomRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			EnterRoomRes refEnterRoomRes;
			pTexasRole->ProcessMsg_EnterRoomRes(refEnterRoomRes);
		}
	}
}

void CTexasGame::ProcessMsg_LeaveRoomRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			LeaveRoomRes refLeaveRoomRes;
			pTexasRole->ProcessMsg_LeaveRoomRes(refLeaveRoomRes);
		}
	}
}

void CTexasGame::ProcessMsg_SitDownRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			SitDownRes refSitDownRes;
			pTexasRole->ProcessMsg_SitDownRes(refSitDownRes);
		}
	}
}

void CTexasGame::ProcessMsg_StandUpRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			StandUpRes refStandUpRes;
			pTexasRole->ProcessMsg_StandUpRes(refStandUpRes);
		}
	}
}

void CTexasGame::ProcessMsg_BetRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			BetRes refBetRes;
			refBetRes.nRoleID = nRoleId;
			refBetRes.nBetRoundID = m_nGameRounds;
			refBetRes.nRemainAnte = m_nVipRoomRemainBetAnte;
			if (pTexasRole->IsCheckBetResult())
			{
				refBetRes.nBetResult = 1;
			}
			else
			{
				refBetRes.nBetResult = 0;
			}
			pTexasRole->ProcessMsg_BetRes(refBetRes);
		}
	}
}

void CTexasGame::ProcessMsg_FoldRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			pTexasRole->SetRoleStatus((int)ERS_Fold);

			FoldRes refFoldRes;
			pTexasRole->ProcessMsg_FoldRes(refFoldRes);
		}
	}
}

void CTexasGame::ProcessMsg_ReadyLeaveRoomRes(int nRoleId)
{
	if (NULL != m_pTexasRoom)
	{
		CTexasRole* pTexasRole = m_pTexasRoom->GetTexasRole(nRoleId);
		if (NULL != pTexasRole)
		{
			ReadyLeaveRoomRes refReadyLeaveRoomRes;
			refReadyLeaveRoomRes.nRoleID = nRoleId;
			refReadyLeaveRoomRes.nRoleStatus = pTexasRole->GetRoleStatus();
			pTexasRole->ProcessMsg_ReadyLeaveRoomRes(refReadyLeaveRoomRes);
		}
	}
}