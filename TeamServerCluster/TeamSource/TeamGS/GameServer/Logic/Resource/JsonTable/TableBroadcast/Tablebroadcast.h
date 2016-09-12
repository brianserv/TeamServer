#pragma once
#ifndef __TABLE_BROADCAST_H__
#define __TABLE_BROADCAST_H__

#include "../../../../FrameWork/BaseDefine.h"

class CTableBroadcastManager :public CEQ_SingletonT<CTableBroadcastManager>
{
public:
	CTableBroadcastManager(void);
	virtual ~CTableBroadcastManager(void);

	bool Init(const string strJsonTableName, const string strJsonTableData);
	bool Clear();
	int  GetCostType(const int nId);
	int  GetCostValue(const int nId);
	int  GetBroadCastType(const int nId);

private:
	struct TableBroadcastInfo
	{
		TableBroadcastInfo()
			:m_nId(0), m_nCostType(0), m_nCostValue(0), m_nBroadCastType(0) {}

		int   m_nId;
		int   m_nCostType;
		int   m_nCostValue;
		int   m_nBroadCastType;
	};
	typedef std::map<int, TableBroadcastInfo> BroadcastInfoMap;
	BroadcastInfoMap m_BroadcastInfoMap;
};

#endif//__TABLE_BROADCAST_H__
