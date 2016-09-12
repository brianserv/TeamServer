#include "RoleAttr.h"

CRoleAttr::CRoleAttr()
{
	InitialAttr();
}

CRoleAttr::~CRoleAttr()
{
	InitialAttr();
}

void   CRoleAttr::InitialAttr()
{
	for (int i = 0; i < EAttrNum_End; i++)
	{
		m_nAttrList[i] = 0;
	}
}

bool CRoleAttr::SetAttrNum(int nIndex, int nValue)
{
	if (nIndex >= EAttrNum_End)
	{
		return false;
	}
	if (nValue < 0)
	{
		nValue = 0;
	}
	m_nAttrList[nIndex] = nValue;
	return true;
}

int CRoleAttr::GetAttrNum(int nIndex)
{
	if (nIndex >= EAttrNum_End)
	{
		return -1;
	}
	return m_nAttrList[nIndex];
}

bool CRoleAttr::AddAttr(int nIndex, int nValue)
{
	if (nIndex >= EAttrNum_End)
	{
		return false;
	}
	m_nAttrList[nIndex] += nValue;
	return true;
}

bool  CRoleAttr::DecAttr(int nIndex, int nValue)
{
	if (nIndex >= EAttrNum_End)
	{
		return false;
	}
	if (m_nAttrList[nIndex] - nValue < 0)
	{
		return false;
	}
	m_nAttrList[nIndex] -= nValue;
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CRoleBase::CRoleBase()
{
}

CRoleBase::~CRoleBase()
{
}

bool CRoleBase::UpdateAttr(int nIndex, int nValue, int nEOption)
{
	bool bRet = false;
	switch (nEOption)
	{
	case EUpdateOption_Add:
	{
		m_RoleAttr.AddAttr(nIndex, nValue);

		bRet = true;
	}
	break;
	case EUpdateOption_Dec:
	{
		m_RoleAttr.DecAttr(nIndex, nValue);

		bRet = true;
	}
	break;
	default:
		break;
	}
	return bRet;
}

bool  CRoleBase::DecChipByCostRuler(int nValue, int& nUnbindChip, int& nBindChip)
{
	if (CheckChipByCostRuler(nValue))
	{
		DecUnBindChip(nValue);

		nUnbindChip = nValue;
		nBindChip = 0;

		return true;
	}

	int nBindChipCost = GetBindChipDiff(nValue);
	nBindChip = nBindChipCost;
	DecBindChip(nBindChipCost);

	nUnbindChip = GetAttrNum(EAttrNum_nUnBindChip);
	SetAttrNum(EAttrNum_nUnBindChip, 0);

	return true;
}

bool  CRoleBase::DecPinkpByCostRuler(int nValue, int& nUnbindPink, int& nBindPink)
{
	if (CheckPinkByCostRuler(nValue))
	{
		DecUnBindPink(nValue);

		nUnbindPink = nValue;
		nBindPink = 0;

		return true;
	}
	int nBindPinkCost = GetBindPinkDiff(nValue);
	nBindPink = nBindPinkCost;
	DecBindPink(nBindPinkCost);

	nUnbindPink = GetAttrNum(EAttrNum_nUnBindPink);
	SetAttrNum(EAttrNum_nUnBindPink, 0);

	return true;
}