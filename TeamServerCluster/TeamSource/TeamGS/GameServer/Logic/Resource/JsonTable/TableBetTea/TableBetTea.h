#pragma once
#ifndef __TABLE_BETTEA_H__
#define __TABLE_BETTEA_H__

#include "../../../../FrameWork/BaseDefine.h"

class CTableBetTeaManager :public CEQ_SingletonT<CTableBetTeaManager>
{
public:
	CTableBetTeaManager(void);
	virtual ~CTableBetTeaManager(void);

	bool Init(const string strJsonTableName, const string strJsonTableData);
	bool Clear();
	int  GetBetTeaMoney(const int nId);
	int  GetBetTeaPercent(const int nId);
	int  GetBetTeaSwitch(const int nId);
public:
	bool CheckBetTeaSwitch(const int nId);
	int  GetBetTea_WinChips(const int nId, const int nWinChips);

private:
	struct TableBetTeaInfo
	{
		TableBetTeaInfo()
			:m_nId(0), m_nBetTeaMoney(0), m_nBetTeaPercent(0), m_nBetTeaSwitch(0) {}

		int   m_nId;
		int   m_nBetTeaMoney;
		int   m_nBetTeaPercent;
		int   m_nBetTeaSwitch;
	};
	typedef std::map<int, TableBetTeaInfo> BetTeaInfoMap;
	BetTeaInfoMap m_BetTeaInfoMap;
};

#endif//__TABLE_BETTEA_H__
