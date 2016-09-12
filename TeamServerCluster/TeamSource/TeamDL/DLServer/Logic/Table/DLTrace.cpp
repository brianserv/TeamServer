#include "DLTrace.h"

EQ_IMPLEMENT_CACHE(CDLTrace, 100)

CDLTrace::CDLTrace()
{
	m_nRoleId = 0;
	m_nCostType = 0;
	m_nUnbindChip = 0;
	m_nUnbindPink = 0;
	m_nBindChip = 0;
	m_nBindPink = 0;
	m_strDescribe = "";
}

CDLTrace::~CDLTrace()
{
}

void CDLTrace::SetTraceProperty(__INT32 nRoleId,
	int nCostType,
	__INT32 nUnbindChip,
	__INT32 nUnbindPink,
	__INT32 nBindChip,
	__INT32 nBindPink,
	string strDescribe)
{
	setRoleId(nRoleId);
	setCostType(nCostType);
	setUnBindChip(nUnbindChip);
	setUnBindPink(nUnbindPink);
	setBindChip(nBindChip);
	setBindPink(nBindPink);
	setDescribe(strDescribe);
}