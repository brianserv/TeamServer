#include "TexasRole.h"

void CTexasRole::ProcessMsg_EnterRoomRes(EnterRoomRes& refEnterRoomRes)
{
   CCSMessage::Instance().ProcessMsg_EnterRoomRes(refEnterRoomRes,this->GetRoleId());
}

void CTexasRole::ProcessMsg_LeaveRoomRes(LeaveRoomRes& refLeaveRoomRes)
{
   CCSMessage::Instance().ProcessMsg_LeaveRoomRes(refLeaveRoomRes,this->GetRoleId());
}

void CTexasRole::ProcessMsg_SitDownRes(SitDownRes& refSitDownRes)
{
   CCSMessage::Instance().ProcessMsg_SitDownRes(refSitDownRes,this->GetRoleId());
}
void CTexasRole::ProcessMsg_StandUpRes(StandUpRes& refStandUpRes)
{
   CCSMessage::Instance().ProcessMsg_StandUpRes(refStandUpRes,this->GetRoleId());
}


void CTexasRole::ProcessMsg_BetRes(BetRes& refBetRes)
{ 
   CCSMessage::Instance().ProcessMsg_BetRes(refBetRes,this->GetRoleId());
}

void CTexasRole::ProcessMsg_FoldRes(FoldRes& refFoldRes)
{
   CCSMessage::Instance().ProcessMsg_FoldRes(refFoldRes,this->GetRoleId());
}

void CTexasRole::ProcessMsg_ReadyLeaveRoomRes(ReadyLeaveRoomRes& refReadyLeaveRoomRes)
{
   CCSMessage::Instance().ProcessMsg_ReadyLeaveRoomRes(refReadyLeaveRoomRes,this->GetRoleId());
}

