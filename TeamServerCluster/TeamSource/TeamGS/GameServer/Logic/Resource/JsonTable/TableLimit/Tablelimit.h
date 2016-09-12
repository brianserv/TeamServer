#pragma once
#ifndef __TABLE_LIMIT_H__
#define __TABLE_LIMIT_H__

#include "../../../../FrameWork/BaseDefine.h"

class CTableLimitManager :public CEQ_SingletonT<CTableLimitManager>
{
public:
	CTableLimitManager(void);
	virtual ~CTableLimitManager(void);

	bool Init(const string strJsonTableName, const string strJsonTableData);
	bool Clear();

	int  GetMinAnte(const int nId);
	int  GetMaxAnte(const int nId);
	int  GetChips(const int nId);

private:
	struct TableLimitInfo
	{
		TableLimitInfo()
			:m_nId(0), m_nMinAnte(0), m_nMaxAnte(0), m_nChips(0) {}

		int   m_nId;
		int   m_nMinAnte;
		int   m_nMaxAnte;
		int   m_nChips;
	};
	typedef std::map<int, TableLimitInfo> LimitInfoMap;
	LimitInfoMap m_LimitInfoMap;
};

#endif//__TABLE_LIMIT_H__
