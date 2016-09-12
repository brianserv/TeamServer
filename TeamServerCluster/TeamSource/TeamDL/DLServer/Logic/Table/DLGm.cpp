#include "DLGm.h"

EQ_IMPLEMENT_CACHE(CDLGm, 100)
CDLGm::CDLGm()
{
	m_nRoleId = 0;
	m_GmId = 0;
	m_GmActionType = 0;
	m_strDescribe = "";
}

CDLGm::~CDLGm()
{
}

void CDLGm::SetGmProperty(int nRoleId, int nGmid, int nGmActionType, string strDescribe)
{
	setRoleId(nRoleId);
	setGmId(nGmid);
	setGmActionType(nGmActionType);
	setDescirbe(m_strDescribe);
}