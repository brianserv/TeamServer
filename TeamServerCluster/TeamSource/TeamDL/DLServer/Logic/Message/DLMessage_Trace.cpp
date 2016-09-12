#include "DLMessage.h"

void  CDLMessage::ProcessMsg_Save_TraceReq(char* pDataInfo, long nDataLen, void* pClient)
{
	if ((NULL == pDataInfo) || (nDataLen <= 0) || (NULL == pClient))
		return;

	SaveTraceReq* pSaveTraceReq = reinterpret_cast<SaveTraceReq*>(pDataInfo + sizeof(PACKETHEAD));
	if (NULL == pSaveTraceReq)
		return;

	CDLTrace* pDLTrace = new CDLTrace();
	if (NULL == pDLTrace)
	{
		return;
	}

	pDLTrace->SetTraceProperty(pSaveTraceReq->nRoleId,
		pSaveTraceReq->nCostType,
		pSaveTraceReq->nUnbindChip,
		pSaveTraceReq->nUnbindPink,
		pSaveTraceReq->nBindChip,
		pSaveTraceReq->nBindPink,
		(string)pSaveTraceReq->sDescribe);

	if (!g_DLManager.SaveTraceData(pDLTrace))
	{
		SAFE_DELETE(pDLTrace);
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "SaveTraceReq Failure !");
		return;
	}
	SAFE_DELETE(pDLTrace);
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "SaveTraceReq Success !");
}