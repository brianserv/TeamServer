#pragma  once
#ifndef __PRIZEPOOL_MANAGER_H__
#define __PRIZEPOOL_MANAGER_H__

#include "../../FrameWork/BaseDefine.h"

class CPrizePoolManager : public CEQ_SingletonT<CPrizePoolManager>
{
public:
	CPrizePoolManager();
	virtual ~CPrizePoolManager();
public:
	inline void SetTotalValue(int nTotalValue)
	{
		m_nTotalValue = nTotalValue;
	}

	inline void SetPayValue(int nPayValue)
	{
		m_nPayValue = nPayValue;
	}

	inline void SetJackpotBonus_InitValue(int nJackpotBonus_InitValue)
	{
		m_nJackpotBonus_InitValue = nJackpotBonus_InitValue;
	}

	inline int GetTotalValue()
	{
		return m_nTotalValue;
	}

	inline int GetPayValue()
	{
		return m_nPayValue;
	}

	inline int GetJackpotBonus_InitValue()
	{
		return m_nJackpotBonus_InitValue;
	}

	inline void AddTotalValue(int nValue)
	{
		m_nTotalValue += nValue;
	}

	inline void AddPayValue(int nValue)
	{
		m_nPayValue += nValue;
	}
public:

	int m_nTotalValue;
	int m_nPayValue;
	int m_nJackpotBonus_InitValue;
};

#endif//__PRIZEPOOL_MANAGER_H__
