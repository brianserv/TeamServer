#pragma once

#ifndef  EQ_OBJPOOL_FILE
#define  EQ_OBJPOOL_FILE
#include "EQ_Lock.h"

struct ObjNode
{
	bool  bUsed;
	void* pObj;

};
class CCache 
{
public:
	CCache(int nObjSize,int nIncreDegrees = 0);
	~CCache();

	void* allocObj();
	void  freeObj(void *p);
public:
	bool  allocCache(int nObjNum);
	void  freeCache();
	int   getUsedObjNum();
	int   getObjNum();
private:

	CEQ_Lock  m_lock;

	int  m_nObjSize; 
	
	int  m_nObjNum;
	
	int  m_nIncreDegrees;
	
	std::queue<ObjNode*> m_idleObj;
	
	std::queue<void*>    m_cacheQueue;
};
#define EQ_DECLARE_CACHE(type) \
private:	\
	static CCache type_pool; \
public:	\
	void *operator new(size_t) {	\
	return type_pool.allocObj();	\
}	\
	void operator delete(void *p) {	\
	type_pool.freeObj(p);	\
}\
	static bool InitCache(int nObjNum)\
{\
	return  type_pool.allocCache(nObjNum);\
}\
	static int getUsedObjNum()\
{\
	return type_pool.getUsedObjNum(); \
}\
	static int getObjNum()\
{\
	return type_pool.getObjNum(); \
}

//
#define EQ_IMPLEMENT_CACHE(type, num)	\
	CCache type::type_pool(sizeof(type),num);

#endif