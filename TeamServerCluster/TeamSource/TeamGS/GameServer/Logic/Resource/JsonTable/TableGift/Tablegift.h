#pragma once
#ifndef __TABLE_GIFT_H__
#define __TABLE_GIFT_H__

#include "../../../../FrameWork/BaseDefine.h"

class CTableGiftManager :public CEQ_SingletonT<CTableGiftManager>
{
public:
	CTableGiftManager(void);
	virtual ~CTableGiftManager(void);

	bool Init(const string strJsonTableName, const string strJsonTableData);
	bool Clear();
	int  GetValue(const int nId);
	int  GetNum(const int nId);
	int  GetEffectLev(const int nId);

private:
	struct TableGiftInfo
	{
		TableGiftInfo()
			:m_nId(0), m_nValue(0), m_nNum(0), m_nEffectLev(0) {}

		int   m_nId;
		int   m_nValue;
		int   m_nNum;
		int   m_nEffectLev;
	};
	typedef std::map<int, TableGiftInfo> GiftInfoMap;
	GiftInfoMap m_GiftInfoMap;
};

#endif//__TABLE_GIFT_H__
