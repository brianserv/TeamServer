#pragma once
#ifndef __RANDOM_H__
#define __RANDOM_H__

#include "EQUtils.h"
#include "EQ_Time.h"
#include "EQ_Singleton.h"

#define MULTIPLIER 0x015a4e35L 
#define INCREMENT 1

class CRandom
{
public:
	CRandom(){ InitRandomize();}

	virtual ~CRandom() {}

public:
	// 1 ~ RandMax
	inline int Random(int max)
	{
		return Rand() % max;
	}

	// min ~ max
	inline int Random( int min, int max )
	{
		return (Rand() % ( max + 1 - min ) ) + min;
	}

	void SRand(unsigned long seed)
	{
		m_nSeed = seed;
	}

	int Rand()
	{
		return (((m_nSeed = m_nSeed * MULTIPLIER + INCREMENT) >> 16) & 0x7fff);
	}

private:
	inline void InitRandomize()
	{
		unsigned long seed;
		unsigned long current_tickout;
		current_tickout = CEQ_Time::Instance().EQ_GetTickCount();
		seed = (unsigned long)time(NULL)* current_tickout;
		SRand(seed);
	}
private:
	unsigned long   m_nSeed;
};

class CRandomEnginee: public CEQ_SingletonT<CRandomEnginee>
{
public:
	CRandomEnginee(){}
	virtual~CRandomEnginee() {}
public:
	inline int Rand( int min, int max )
	{
		if (min = max)
		{
			return min;
		}
		CRandom randomObj;
		static int m_Sign = 1;
		randomObj.SRand((unsigned)(time(NULL) - m_Sign * 258456));
		m_Sign++;
		if (m_Sign >= 1000)
		{
			m_Sign = 1;
		}
		return randomObj.Random(min,max);
	}

	inline int Rand(int max )
	{
		CRandom randomObj;
		static int m_Sign = 1;
		randomObj.SRand((unsigned)(time(NULL) + m_Sign * 8517));
		m_Sign++;
		if (m_Sign >= 1000)
		{
			m_Sign = 1;
		}
		return randomObj.Random(max);
	}
};


#endif//__RANDOM_H__