#pragma once

#ifndef  EQ_LIST_FILE
#define  EQ_LIST_FILE
#include "EQUtils.h"


class CEQ_Linker
{
public:
	CEQ_Linker()
	{
		m_pPrev = NULL;
		m_pNext = NULL;
	}

	~CEQ_Linker()
	{
	}

	virtual void EQ_InitLinker(){};
	virtual void EQ_EndLinker(){};

public:
	CEQ_Linker* m_pPrev;
	CEQ_Linker* m_pNext;
};


class CEQ_List
{
public:
	CEQ_List();
	virtual ~CEQ_List();

public:
	int          EQ_Size(){return m_nNum;};
	CEQ_Linker*  EQ_begin(){return m_pFirst;};
	CEQ_Linker*  EQ_end(){return m_pLast;};
	CEQ_Linker*  EQ_Curr(){return m_pCurrLinker;};
	void         EQ_BeginList(){ m_pCurrLinker = m_pFirst;};
	

public:
	void          EQ_Clear();
	void          EQ_Push(CEQ_Linker* linker);
	bool          EQ_Erase(CEQ_Linker* linker);
	CEQ_Linker*   EQ_Pop();
	CEQ_Linker*   EQ_Next();

private:
	CEQ_Linker*      m_pFirst;
	CEQ_Linker*      m_pLast;
	CEQ_Linker*      m_pCurrLinker;
	int              m_nNum;
};



#endif