#pragma once
#ifndef __ROLE_ATTR_H__
#define __ROLE_ATTR_H__

#include "../../FrameWork/BaseDefine.h"

class  CRoleAttr
{
public:
	CRoleAttr();
	virtual ~CRoleAttr();

public:
	void InitialAttr();
	bool SetAttrNum(int nIndex, int nValue);
	int  GetAttrNum(int nIndex);
public:
	bool AddAttr(int nIndex, int nValue);
	bool DecAttr(int nIndex, int nValue);
private:
	int  m_nAttrList[EAttrNum_End];
};

class CRoleBase
{
public:
	CRoleBase();
	virtual ~CRoleBase();

public:
	inline bool SetAttrNum(int nIndex, int nValue) { return m_RoleAttr.SetAttrNum(nIndex, nValue); };
	inline int  GetAttrNum(int nIndex) { return m_RoleAttr.GetAttrNum(nIndex); };

public:
	bool UpdateAttr(int nIndex, int nValue, int nEOption);

public:
	bool AddChip(int nUnBindType, int nValue1, int nBindType, int nValue2)
	{
		if (AddUnBindChip(nValue1) && AddBindChip(nValue2))
		{
			return true;
		}
		return false;
	};
	bool AddPink(int nUnBindType, int nValue1, int nBindType, int nValue2)
	{
		if (AddUnBindPink(nValue1) && AddBindPink(nValue2))
		{
			return true;
		}
		return false;
	};

	bool DecChip(int nUnBindType, int nValue1, int nBindType, int nValue2)
	{
		if (DecUnBindChip(nValue1) && DecBindChip(nValue2))
		{
			return true;
		}
		return false;
	};
	bool DecPink(int nUnBindType, int nValue1, int nBindType, int nValue2)
	{
		if (DecUnBindPink(nValue1) && DecBindPink(nValue2))
		{
			return true;
		}
		return false;
	};

public:

	inline int  GetUnBindChipDiff(int nValue1)
	{
		if (CheckUnBindChip(nValue1))
		{
			return GetAttrNum(EAttrNum_nUnBindChip) - nValue1;
		}
		return 0;
	};

	inline int  GetBindChipDiff(int nValue1)
	{
		return abs((int)(nValue1 - GetAttrNum(EAttrNum_nUnBindChip)));
	};

	inline int  GetUnBindPinkDiff(int nValue1)
	{
		if (CheckUnBindPink(nValue1))
		{
			return GetAttrNum(EAttrNum_nUnBindPink) - nValue1;
		}
		return 0;
	};

	inline int  GetBindPinkDiff(int nValue1)
	{
		return abs((int)(nValue1 - GetAttrNum(EAttrNum_nUnBindPink)));
	};

	inline int GetUnBindChips()
	{
		return GetAttrNum(EAttrNum_nUnBindChip);
	}

	inline int GetBindChips()
	{
		return GetAttrNum(EAttrNum_nBindChip);
	}

	inline int GetTotalChips()
	{
		return GetAttrNum(EAttrNum_nUnBindChip) + GetAttrNum(EAttrNum_nBindChip);
	}
	inline int GetTotalPink()
	{
		return GetAttrNum(EAttrNum_nUnBindPink) + GetAttrNum(EAttrNum_nBindPink);
	}

public:
	inline bool  CheckChipByCostRuler(int nValue) { return (GetUnBindChipDiff(nValue) > 0) ? true : false; };
	inline bool  CheckPinkByCostRuler(int nValue) { return (GetUnBindPinkDiff(nValue) > 0) ? true : false; };

	bool         DecChipByCostRuler(int nValue, int& nUnbindChip, int& nBindChip);
	bool         DecPinkpByCostRuler(int nValue, int& nUnbindPink, int& nBindPink);
public:
	inline bool  AddUnBindChip(int nValue) { return UpdateAttr(EAttrNum_nUnBindChip, nValue, EUpdateOption_Add); };
	inline bool  AddBindChip(int nValue) { return UpdateAttr(EAttrNum_nBindChip, nValue, EUpdateOption_Add); };
	inline bool  AddUnBindPink(int nValue) { return UpdateAttr(EAttrNum_nUnBindPink, nValue, EUpdateOption_Add); };
	inline bool  AddBindPink(int nValue) { return UpdateAttr(EAttrNum_nBindPink, nValue, EUpdateOption_Add); };

	inline bool  DecUnBindChip(int nValue) { return UpdateAttr(EAttrNum_nUnBindChip, nValue, EUpdateOption_Dec); };
	inline bool  DecBindChip(int nValue) { return UpdateAttr(EAttrNum_nBindChip, nValue, EUpdateOption_Dec); }; ;
	inline bool  DecUnBindPink(int nValue) { return UpdateAttr(EAttrNum_nUnBindPink, nValue, EUpdateOption_Dec); };
	inline bool  DecBindPink(int nValue) { return UpdateAttr(EAttrNum_nBindPink, nValue, EUpdateOption_Dec); };

	inline bool  CheckUnBindChip(int nValue1) { return (GetAttrNum(EAttrNum_nUnBindChip) - nValue1 > 0) ? true : false; };
	inline bool  CheckUnBindPink(int nValue1) { return (GetAttrNum(EAttrNum_nUnBindPink) - nValue1 > 0) ? true : false; };
public:
	inline void  AddWinTimes() { UpdateAttr(EAttrNum_nWinTimes, 1, EUpdateOption_Add); };
	inline void  AddLostTimes() { UpdateAttr(EAttrNum_nLostTimes, 1, EUpdateOption_Add); };
	inline void  AddDrawTimes() { UpdateAttr(EAttrNum_nDrawTimes, 1, EUpdateOption_Add); };
	inline void  AddLoginTimes() { UpdateAttr(EAttrNum_nLoginTimes, 1, EUpdateOption_Add); }
public:
	inline void  UpdateMaxChip(int nChip) { (nChip > GetAttrNum(EAttrNum_nMaxChip)) ? SetAttrNum(EAttrNum_nMaxChip, nChip) : 0; }
	inline void  UpdateMaxPink(int nPink) { (nPink > GetAttrNum(EAttrNum_nMaxPink)) ? SetAttrNum(EAttrNum_nMaxPink, nPink) : 0; }

private:
	CRoleAttr               m_RoleAttr;
};

#endif//__ROLE_ATTR_H__
