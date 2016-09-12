#include "DBPrizePool.h"

EQ_IMPLEMENT_CACHE(CDBPrizePoolInfo, 100)

CDBPrizePoolInfo::CDBPrizePoolInfo()
{
	m_bIsUpdata = false;
}

CDBPrizePoolInfo::~CDBPrizePoolInfo()
{
	m_bIsUpdata = false;
}

void CDBPrizePoolInfo::setPrizePoolProperty(int id, int prizepool_total_value, int prizepool_pay_value, int prizepool_JackpotBonus_Init)
{
	set_Id(id);
	set_prizepool_total_value(prizepool_total_value);
	set_prizepool_pay_value(prizepool_pay_value);
	set_prizepool_JackpotBonus_Init(prizepool_JackpotBonus_Init);
}