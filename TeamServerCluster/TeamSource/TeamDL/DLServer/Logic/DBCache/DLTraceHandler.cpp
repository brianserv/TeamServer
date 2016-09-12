#include "DLManager.h"

#include "../Table/DLTrace.h"

bool CDLManager::SaveTraceData(void *pDLTraceInfo)
{
	CDLTrace *pDLTrace = (CDLTrace *)pDLTraceInfo;
	if (NULL == pDLTrace)
	{
		return false;
	}
	char  szSql[MAX_SQL_STR_LENGTH] = { 0 };
	EQ_SPRINTF(szSql, sizeof(szSql), "call sp_save_trace(%d,%d,%d,%d,%d,%d,'%s');",
		pDLTrace->getRoleId(),
		pDLTrace->getCostType(),
		pDLTrace->getUnBindChip(),
		pDLTrace->getUnBindPink(),
		pDLTrace->getBindChip(),
		pDLTrace->getBindPink(),
		pDLTrace->getDescribe().c_str()
		);

	if (!Execute(szSql))
	{
		return false;
	}

	return true;
}