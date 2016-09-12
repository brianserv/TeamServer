#pragma once

#ifndef  EQ_UniqueVector_FILE
#define  EQ_UniqueVector_FILE

#include "EQUtils.h"
#include "EQ_Singleton.h"


class CEQ_UniqueVector: public CEQ_SingletonT<CEQ_UniqueVector>
{
public:
	 vector<int> GetUniqueVec(string t)
	 {
		m_Vec.clear();
		stringstream ssStr(t);
		char sFliter;
		int nElement;
		while(ssStr)
		{
			ssStr>>nElement>>sFliter;
			m_Vec.push_back(nElement);
		}
		sort(m_Vec.begin(),m_Vec.end());
		m_Vec.erase(unique(m_Vec.begin(),m_Vec.end()),m_Vec.end());
		return m_Vec;
	}
public:
	 vector<int> m_Vec;
};

#endif//EQ_UniqueVector_FILE