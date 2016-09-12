#pragma once
#ifndef __DB_PRIZEPOOL_H__
#define __DB_PRIZEPOOL_H__

#include "../../FrameWork/BaseDefine.h"

class CDBPrizePoolInfo
{
public:
	CDBPrizePoolInfo();
	virtual ~CDBPrizePoolInfo();
	EQ_DECLARE_CACHE(CDBPrizePoolInfo)
public:
	inline void		set_Id(int id) { m_id = id; };
	inline void		set_prizepool_total_value(int prizepool_total_value) { m_prizepool_total_value = prizepool_total_value; };
	inline void		set_prizepool_pay_value(int prizepool_pay_value) { m_prizepool_pay_value = prizepool_pay_value; };
	inline void     set_prizepool_JackpotBonus_Init(int prizepool_JackpotBonus_Init) { m_prizepool_JackpotBonus_Init = prizepool_JackpotBonus_Init; }

public:
	inline int	get_Id() { return m_id; };
	inline int	get_prizepool_total_value() { return m_prizepool_total_value; };
	inline int  get_prizepool_pay_value() { return m_prizepool_pay_value; };
	inline int  get_prizepool_JackpotBonus_Init() { return m_prizepool_JackpotBonus_Init; }

public:
	void		setPrizePoolProperty(int id, int prizepool_total_value, int prizepool_pay_value, int prizepool_JackpotBonus_Init);
private:
	int		m_id;
	int		m_prizepool_total_value;
	int		m_prizepool_pay_value;
	int     m_prizepool_JackpotBonus_Init;
private:
	bool	m_bIsUpdata;
};

#endif//__DB_PRIZEPOOL_H__