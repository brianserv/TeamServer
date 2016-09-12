#include "Card.h"

BYTE g_sCardData[MAX_TEXAS_GAMEFULLCARD_NUM] =
{
	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,																					//方块 A - K ;
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,																					//梅花 A - K ;
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,																					//红桃 A - K ;
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,																					//黑桃 A - K ;
};

int  IRand(int nSize)
{
	if (nSize <= 0)
	{
		return 1;
	}
	return CRandomEnginee::Instance().Rand(nSize);
}

CCard::CCard(void)
{
	ResetCard();
	MakeCardName();
}

CCard::~CCard(void)
{
	m_CardDataVec.clear();
	m_CardNameMap.clear();
}

void CCard::ResetCard()
{
	m_CardDataVec.clear();
	for (int i = 0; i < MAX_TEXAS_GAMEFULLCARD_NUM; ++i)
	{
		m_CardDataVec.push_back(g_sCardData[i]);
	}
}

void CCard::MakeCardName()
{
	for (int i = 0; i < MAX_TEXAS_GAMEFULLCARD_NUM; ++i)
	{
		MakeCardName(g_sCardData[i]);
	}
}

void CCard::MakeCardName(BYTE num)
{
	switch ((int)num)
	{
	case 1:
		m_CardNameMap[num] = "F-A";
		break;
	case 2:
		m_CardNameMap[num] = "F-2";
		break;
	case 3:
		m_CardNameMap[num] = "F-3";
		break;
	case 4:
		m_CardNameMap[num] = "F-4";
		break;
	case 5:
		m_CardNameMap[num] = "F-5";
		break;
	case 6:
		m_CardNameMap[num] = "F-6";
		break;
	case 7:
		m_CardNameMap[num] = "F-7";
		break;
	case 8:
		m_CardNameMap[num] = "F-8";
		break;
	case 9:
		m_CardNameMap[num] = "F-9";
		break;

	case 10:
		m_CardNameMap[num] = "F-10";
		break;
	case 11:
		m_CardNameMap[num] = "F-J";
		break;
	case 12:
		m_CardNameMap[num] = "F-Q";
		break;
	case 13:
		m_CardNameMap[num] = "F-K";
		break;

		//--------------------------------
	case 17:
		m_CardNameMap[num] = "M-A";
		break;
	case 18:
		m_CardNameMap[num] = "M-2";
		break;
	case 19:
		m_CardNameMap[num] = "M-3";
		break;
	case 20:
		m_CardNameMap[num] = "M-4";
		break;
	case 21:
		m_CardNameMap[num] = "M-5";
		break;
	case 22:
		m_CardNameMap[num] = "M-6";
		break;
	case 23:
		m_CardNameMap[num] = "M-7";
		break;
	case 24:
		m_CardNameMap[num] = "M-8";
		break;
	case 25:
		m_CardNameMap[num] = "M-9";
		break;
	case 26:
		m_CardNameMap[num] = "M-10";
		break;
	case 27:
		m_CardNameMap[num] = "M-J";
		break;
	case 28:
		m_CardNameMap[num] = "M-Q";
		break;
	case 29:
		m_CardNameMap[num] = "M-K";
		break;
		//------------------------------------

	case 33:
		m_CardNameMap[num] = "R-A";
		break;
	case 34:
		m_CardNameMap[num] = "R-2";
		break;
	case 35:
		m_CardNameMap[num] = "R-3";
		break;
	case 36:
		m_CardNameMap[num] = "R-4";
		break;
	case 37:
		m_CardNameMap[num] = "R-5";
		break;
	case 38:
		m_CardNameMap[num] = "R-6";
		break;
	case 39:
		m_CardNameMap[num] = "R-7";
		break;
	case 40:
		m_CardNameMap[num] = "R-8";
		break;
	case 41:
		m_CardNameMap[num] = "R-9";
		break;
	case 42:
		m_CardNameMap[num] = "R-10";
		break;
	case 43:
		m_CardNameMap[num] = "R-J";
		break;
	case 44:
		m_CardNameMap[num] = "R-Q";
		break;
	case 45:
		m_CardNameMap[num] = "R-K";
		break;

		//------------------------------------

	case 49:
		m_CardNameMap[num] = "B-A";
		break;
	case 50:
		m_CardNameMap[num] = "B-2";
		break;
	case 51:
		m_CardNameMap[num] = "B-3";
		break;
	case 52:
		m_CardNameMap[num] = "B-4";
		break;
	case 53:
		m_CardNameMap[num] = "B-5";
		break;
	case 54:
		m_CardNameMap[num] = "B-6";
		break;
	case 55:
		m_CardNameMap[num] = "B-7";
		break;
	case 56:
		m_CardNameMap[num] = "B-8";
		break;
	case 57:
		m_CardNameMap[num] = "B-9";
		break;
	case 58:
		m_CardNameMap[num] = "B-10";
		break;
	case 59:
		m_CardNameMap[num] = "B-J";
		break;
	case 60:
		m_CardNameMap[num] = "B-Q";
		break;
	case 61:
		m_CardNameMap[num] = "B-K";
		break;
	}
}

string CCard::GetCardName(BYTE num)
{
	CARDNAME_MAP::iterator it = m_CardNameMap.find(num);
	if (it == m_CardNameMap.end())
	{
		return "";
	}
	return it->second;
}

BYTE CCard::RandomCard()
{
	int nCardPos = IRand(m_CardDataVec.size());
	CARD_VEC::iterator iter = m_CardDataVec.begin();
	BYTE sCard = m_CardDataVec[nCardPos];
	m_CardDataVec.erase(iter + nCardPos);
	return sCard;
}

bool CCard::DeleteCard(int nCardNum)
{
	std::vector<BYTE>::iterator iter = m_CardDataVec.begin();
	size_t iter_Size = m_CardDataVec.size();
	for (size_t i = 0; i < iter_Size; ++i)
	{
		if (m_CardDataVec[i] == nCardNum)
		{
			m_CardDataVec.erase(iter + i);
			return true;
		}
	}
	return false;
}

void CCard::GetCardData(CARD_VEC& ValueListVec)
{
	ValueListVec = m_CardDataVec;
}

void CCard::SetCardData(CARD_VEC& ValueListVec)
{
	m_CardDataVec.clear();
	m_CardDataVec = ValueListVec;
}

BYTE CCard::GetCardType(BYTE cbCardData[], BYTE cbCardCount)
{
	//数据校验
	if (cbCardCount != MAX_TEXAS_CENTERCARD_NUM) return 0;

	//变量定义
	bool cbSameColor = true, bLineCard = true;
	BYTE cbFirstColor = GetCardColor(cbCardData[0]);
	BYTE cbFirstValue = GetCardLogicValue(cbCardData[0]);

	//牌形分析
	for (BYTE i = 1; i < cbCardCount; i++)
	{
		//数据分析
		if (GetCardColor(cbCardData[i]) != cbFirstColor) cbSameColor = false;
		if (cbFirstValue != (GetCardLogicValue(cbCardData[i]) + i)) bLineCard = false;

		//结束判断
		if ((cbSameColor == false) && (bLineCard == false)) break;
	}

	//最小同花顺
	if ((bLineCard == false) && (cbFirstValue == 14))
	{
		BYTE i = 1;
		for (i = 1; i < cbCardCount; i++)
		{
			BYTE cbLogicValue = GetCardLogicValue(cbCardData[i]);
			if ((cbFirstValue != (cbLogicValue + i + 8))) break;
		}
		if (i == cbCardCount)
			bLineCard = true;
	}

	//皇家同花顺
	if ((cbSameColor == true) && (bLineCard == true) && (GetCardLogicValue(cbCardData[1]) == 13))
		return ECK_RoyalFlush;

	//顺子类型
	if ((cbSameColor == false) && (bLineCard == true))
		return ECK_Straight;

	//同花类型
	if ((cbSameColor == true) && (bLineCard == false))
		return ECK_Flush;

	//同花顺类型
	if ((cbSameColor == true) && (bLineCard == true))
		return ECK_StraightFlush;

	//扑克分析
	tagAnalyseResult AnalyseResult;
	AnalysebCardData(cbCardData, cbCardCount, AnalyseResult);

	//类型判断
	if (AnalyseResult.cbFourCount == 1)
		return ECK_FourofaKind;
	if (AnalyseResult.cbLONGCount == 2)
		return ECK_TwoPairs;
	if ((AnalyseResult.cbLONGCount == 1) && (AnalyseResult.cbThreeCount == 1))
		return ECK_Fullhouse;
	if ((AnalyseResult.cbThreeCount == 1) && (AnalyseResult.cbLONGCount == 0))
		return ECK_Threeofakind;
	if ((AnalyseResult.cbLONGCount == 1) && (AnalyseResult.cbSignedCount == 3))
		return ECK_OnePair;

	return ECK_highcard;
}
BYTE CCard::GetCardLogicValue(BYTE cbCardData)
{
	//扑克属性
	BYTE bCardColor = GetCardColor(cbCardData);
	BYTE bCardValue = GetCardValue(cbCardData);

	//转换数值
	return (bCardValue == 1) ? (bCardValue + 13) : bCardValue;
}

//分析扑克
void CCard::AnalysebCardData(const BYTE cbCardData[], BYTE cbCardCount, tagAnalyseResult& AnalyseResult)
{
	//设置结果
	memset(&AnalyseResult, 0, sizeof(AnalyseResult));

	//扑克分析
	for (BYTE i = 0; i < cbCardCount; i++)
	{
		//变量定义
		BYTE cbSameCount = 1;
		BYTE cbSameCardData[4] = { cbCardData[i],0,0,0 };
		BYTE cbLogicValue = GetCardLogicValue(cbCardData[i]);

		//获取同牌
		for (int j = i + 1; j < cbCardCount; j++)
		{
			//逻辑对比
			if (GetCardLogicValue(cbCardData[j]) != cbLogicValue) break;

			//设置扑克
			cbSameCardData[cbSameCount++] = cbCardData[j];
		}

		//保存结果
		switch (cbSameCount)
		{
		case 1:		//单张
		{
			AnalyseResult.cbSignedLogicVolue[AnalyseResult.cbSignedCount] = cbLogicValue;
			memcpy(&AnalyseResult.cbSignedCardData[(AnalyseResult.cbSignedCount++)*cbSameCount], cbSameCardData, cbSameCount);
			break;
		}
		case 2:		//两张
		{
			AnalyseResult.cbLONGLogicVolue[AnalyseResult.cbLONGCount] = cbLogicValue;
			memcpy(&AnalyseResult.cbLONGCardData[(AnalyseResult.cbLONGCount++)*cbSameCount], cbSameCardData, cbSameCount);
			break;
		}
		case 3:		//三张
		{
			AnalyseResult.cbThreeLogicVolue[AnalyseResult.cbThreeCount] = cbLogicValue;
			memcpy(&AnalyseResult.cbThreeCardData[(AnalyseResult.cbThreeCount++)*cbSameCount], cbSameCardData, cbSameCount);
			break;
		}
		case 4:		//四张
		{
			AnalyseResult.cbFourLogicVolue[AnalyseResult.cbFourCount] = cbLogicValue;
			memcpy(&AnalyseResult.cbFourCardData[(AnalyseResult.cbFourCount++)*cbSameCount], cbSameCardData, cbSameCount);
			break;
		}
		}

		//设置递增
		i += cbSameCount - 1;
	}

	return;
}
//排列扑克
void CCard::SortCardList(BYTE cbCardData[], BYTE cbCardCount)
{
	//转换数值
	BYTE cbLogicValue[MAX_TEXAS_GAMEFULLCARD_NUM];
	for (BYTE i = 0; i < cbCardCount; i++)
		cbLogicValue[i] = GetCardLogicValue(cbCardData[i]);

	//排序操作
	bool bSorted = true;
	BYTE cbTempData, bLast = cbCardCount - 1;
	do
	{
		bSorted = true;
		for (BYTE i = 0; i < bLast; i++)
		{
			if ((cbLogicValue[i] < cbLogicValue[i + 1]) ||
				((cbLogicValue[i] == cbLogicValue[i + 1]) && (cbCardData[i] < cbCardData[i + 1])))
			{
				//交换位置
				cbTempData = cbCardData[i];
				cbCardData[i] = cbCardData[i + 1];
				cbCardData[i + 1] = cbTempData;
				cbTempData = cbLogicValue[i];
				cbLogicValue[i] = cbLogicValue[i + 1];
				cbLogicValue[i + 1] = cbTempData;
				bSorted = false;
			}
		}
		bLast--;
	} while (bSorted == false);

	return;
}

//对比扑克
BYTE CCard::CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount)
{
	//获取类型
	BYTE cbNextType = GetCardType(cbNextData, cbCardCount); //荷官牌型
	BYTE cbFirstType = GetCardType(cbFirstData, cbCardCount);//玩家牌型

	//类型判断
	//大
	if (cbFirstType > cbNextType)
		return 2;

	//小
	if (cbFirstType < cbNextType)
		return 1;

	//简单类型
	switch (cbFirstType)
	{
	case ECK_highcard:			//单牌
	{
		//对比数值
		BYTE i = 0;
		for (i = 0; i < cbCardCount; i++)
		{
			BYTE cbNextValue = GetCardLogicValue(cbNextData[i]);
			BYTE cbFirstValue = GetCardLogicValue(cbFirstData[i]);

			//大
			if (cbFirstValue > cbNextValue)
				return 2;
			//小
			else if (cbFirstValue < cbNextValue)
				return 1;
			//等
			else
				continue;
		}
		//平
		if (i == cbCardCount)
			return 0;
	}
	case ECK_OnePair:		//对子
	case ECK_TwoPairs:		//两对
	case ECK_Threeofakind:		//三条
	case ECK_FourofaKind:		//铁支
	case ECK_Fullhouse:			//葫芦
	{
		//分析扑克
		tagAnalyseResult AnalyseResultNext;
		tagAnalyseResult AnalyseResultFirst;
		AnalysebCardData(cbNextData, cbCardCount, AnalyseResultNext);
		AnalysebCardData(cbFirstData, cbCardCount, AnalyseResultFirst);

		//四条数值
		if (AnalyseResultFirst.cbFourCount > 0)
		{
			BYTE cbNextValue = AnalyseResultNext.cbFourLogicVolue[0];
			BYTE cbFirstValue = AnalyseResultFirst.cbFourLogicVolue[0];

			//比较四条
			if (cbFirstValue != cbNextValue)return (cbFirstValue > cbNextValue) ? 2 : 1;

			//比较单牌
			cbFirstValue = AnalyseResultFirst.cbSignedLogicVolue[0];
			cbNextValue = AnalyseResultNext.cbSignedLogicVolue[0];
			if (cbFirstValue != cbNextValue)return (cbFirstValue > cbNextValue) ? 2 : 1;
			else return 0;
		}

		//三条数值
		if (AnalyseResultFirst.cbThreeCount > 0)
		{
			BYTE cbNextValue = AnalyseResultNext.cbThreeLogicVolue[0];
			BYTE cbFirstValue = AnalyseResultFirst.cbThreeLogicVolue[0];

			//比较三条
			if (cbFirstValue != cbNextValue)return (cbFirstValue > cbNextValue) ? 2 : 1;

			//葫芦牌型
			if (ECK_Fullhouse == cbFirstType)
			{
				//比较对牌
				cbFirstValue = AnalyseResultFirst.cbLONGLogicVolue[0];
				cbNextValue = AnalyseResultNext.cbLONGLogicVolue[0];
				if (cbFirstValue != cbNextValue)return (cbFirstValue > cbNextValue) ? 2 : 1;
				else return 0;
			}
			else //三条带单
			{
				//比较单牌

				//散牌数值
				BYTE i = 0;
				for (i = 0; i < AnalyseResultFirst.cbSignedCount; i++)
				{
					BYTE cbNextValue = AnalyseResultNext.cbSignedLogicVolue[i];
					BYTE cbFirstValue = AnalyseResultFirst.cbSignedLogicVolue[i];
					//大
					if (cbFirstValue > cbNextValue)
						return 2;
					//小
					else if (cbFirstValue < cbNextValue)
						return 1;
					//等
					else continue;
				}
				if (i == AnalyseResultFirst.cbSignedCount)
					return 0;
			}
		}

		//对子数值
		BYTE i = 0;
		for (i = 0; i < AnalyseResultFirst.cbLONGCount; i++)
		{
			BYTE cbNextValue = AnalyseResultNext.cbLONGLogicVolue[i];
			BYTE cbFirstValue = AnalyseResultFirst.cbLONGLogicVolue[i];
			//大
			if (cbFirstValue > cbNextValue)
				return 2;
			//小
			else if (cbFirstValue < cbNextValue)
				return 1;
			//平
			else
				continue;
		}

		//比较单牌
		{
			//散牌数值
			for (i = 0; i < AnalyseResultFirst.cbSignedCount; i++)
			{
				BYTE cbNextValue = AnalyseResultNext.cbSignedLogicVolue[i];
				BYTE cbFirstValue = AnalyseResultFirst.cbSignedLogicVolue[i];
				//大
				if (cbFirstValue > cbNextValue)
					return 2;
				//小
				else if (cbFirstValue < cbNextValue)
					return 1;
				//等
				else continue;
			}
			//平
			if (i == AnalyseResultFirst.cbSignedCount)
				return 0;
		}
		break;
	}
	case ECK_Straight:		//顺子
	case ECK_StraightFlush:	//同花顺
	{
		//数值判断
		BYTE cbNextValue = GetCardLogicValue(cbNextData[0]);
		BYTE cbFirstValue = GetCardLogicValue(cbFirstData[0]);

		bool bFirstmin = (cbFirstValue == (GetCardLogicValue(cbFirstData[1]) + 9));
		bool bNextmin = (cbNextValue == (GetCardLogicValue(cbNextData[1]) + 9));

		//大小顺子
		if ((bFirstmin == true) && (bNextmin == false))
		{
			return 1;
		}
		//大小顺子
		else if ((bFirstmin == false) && (bNextmin == true))
		{
			return 2;
		}
		//等同顺子
		else
		{
			//平
			if (cbFirstValue == cbNextValue)return 0;
			return (cbFirstValue > cbNextValue) ? 2 : 1;
		}
	}
	case ECK_Flush:		//同花
	{
		//散牌数值
		int CompareCount = 0;
		for (BYTE i = 0; i < cbCardCount; i++)
		{
			BYTE cbNextValue = GetCardLogicValue(cbNextData[i]);
			BYTE cbFirstValue = GetCardLogicValue(cbFirstData[i]);
			CompareCount = i;
			if (cbFirstValue == cbNextValue)continue;
			return (cbFirstValue > cbNextValue) ? 2 : 1;
		}
		//平
		if (CompareCount == cbCardCount) return 0;
	}
	}

	return  0;
}

BYTE CCard::FiveFromSeven(std::vector<int> &cbHandCardData, std::vector<int> &cbCenterCardData, BYTE cbLastCardData[], BYTE cbLastCardCount)
{
	// 	//临时变量
	BYTE cbTempCardData[MAX_TEXAS_HANDCARD_NUM + MAX_TEXAS_CENTERCARD_NUM], cbTempLastCardData[MAX_TEXAS_CENTERCARD_NUM];
	memset(cbTempCardData, 0, sizeof(cbTempCardData));
	memset(cbTempLastCardData, 0, sizeof(cbTempLastCardData));

	int i = 0;
	for (; i < cbHandCardData.size(); ++i)
	{
		cbTempCardData[i] = (BYTE)cbHandCardData[i];
	}

	for (; i < cbHandCardData.size() + cbCenterCardData.size(); ++i)
	{
		cbTempCardData[i] = (BYTE)cbCenterCardData[i - cbHandCardData.size()];
	}

	//排列扑克
	SortCardList(cbTempCardData, MAX_TEXAS_HANDCARD_NUM + MAX_TEXAS_CENTERCARD_NUM);

	memcpy(cbLastCardData, cbTempCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
	BYTE cbCardKind = GetCardType(cbLastCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
	BYTE cbTempCardKind = 0;

	//组合算法
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				for (int l = k + 1; l < 6; l++)
				{
					for (int m = l + 1; m < 7; m++)
					{
						//获取数据
						cbTempLastCardData[0] = cbTempCardData[i];
						cbTempLastCardData[1] = cbTempCardData[j];
						cbTempLastCardData[2] = cbTempCardData[k];
						cbTempLastCardData[3] = cbTempCardData[l];
						cbTempLastCardData[4] = cbTempCardData[m];

						//获取牌型
						cbTempCardKind = GetCardType(cbTempLastCardData, MAX_TEXAS_CENTERCARD_NUM);

						//牌型大小
						if (CompareCard(cbTempLastCardData, cbLastCardData, MAX_TEXAS_CENTERCARD_NUM) == 2)
						{
							cbCardKind = cbTempCardKind;
							memcpy(cbLastCardData, cbTempLastCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
						}
					}
				}
			}
		}
	}

	return cbCardKind;
}

BYTE CCard::FiveFromSevenWithHand(std::vector<int>&cbHandCardData, std::vector<int> &cbCenterCardData, BYTE cbLastCardData[], BYTE cbLastCardCount)
{
	BYTE cbTempCenterCardData[MAX_TEXAS_CENTERCARD_NUM];	 //中间5牌数据
	BYTE cbTempLastCardData[MAX_TEXAS_CENTERCARD_NUM];	 //最后需要返回的牌数据 将最大的牌型返回给参数3;//前两个始终不变
	BYTE cbTempCardData[MAX_TEXAS_CENTERCARD_NUM];		 //为了保证手牌始终不变
	memset(cbTempCenterCardData, 0, sizeof(cbTempCenterCardData));
	memset(cbTempLastCardData, 0, sizeof(cbTempLastCardData));
	memset(cbTempCardData, 0, sizeof(cbTempCardData));

	int i = 0;
	int k = cbCenterCardData.size();
	for (; i < cbHandCardData.size(); ++i)
	{
		cbTempLastCardData[i] = (BYTE)cbHandCardData[i];
	}
	for (int j = 0; j < cbCenterCardData.size(); ++j)
	{
		cbTempCenterCardData[j] = (BYTE)cbCenterCardData[j];
	}
	//把中心的五张牌做个排序;
	SortCardList(cbTempCenterCardData, MAX_TEXAS_CENTERCARD_NUM);
	//第一次
	for (; i < cbCenterCardData.size(); ++i)
	{
		cbTempLastCardData[i] = (BYTE)cbTempCenterCardData[i - cbHandCardData.size()];
	}

	memcpy(cbLastCardData, cbTempLastCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);

	SortCardList(cbLastCardData, MAX_TEXAS_CENTERCARD_NUM);
	BYTE cbCardKind = GetCardType(cbLastCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
	BYTE cbTempCardKind = 0;

	for (int l = 0; l < 3; l++)
	{
		for (int m = l + 1; m < 4; m++)
		{
			for (int n = m + 1; n < 5; n++)
			{
				//再次获取牌的数据

				cbTempLastCardData[2] = cbTempCenterCardData[l];
				cbTempLastCardData[3] = cbTempCenterCardData[m];
				cbTempLastCardData[4] = cbTempCenterCardData[n];
				//每次获取的牌数据都是无序的 所以重新进行排序
				memcpy(cbTempCardData, cbTempLastCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
				SortCardList(cbTempCardData, MAX_TEXAS_CENTERCARD_NUM);
				//获取牌型
				cbTempCardKind = GetCardType(cbTempCardData, MAX_TEXAS_CENTERCARD_NUM);

				if (CompareCard(cbTempCardData, cbLastCardData, MAX_TEXAS_CENTERCARD_NUM) == 2)
				{
					cbCardKind = cbTempCardKind;
					memcpy(cbLastCardData, cbTempCardData, sizeof(BYTE)*MAX_TEXAS_CENTERCARD_NUM);
				}
			}
		}
	}
	return cbCardKind;
}

int CCard::BonusReward(std::vector<int> &sHandCard, std::vector<int> &sGirlCard)
{
	int nBonus = 0;
	//双方底牌都是一对A
	if (GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 1
		&& GetCardValue((BYTE)sGirlCard[0]) == 1 && GetCardValue((BYTE)sGirlCard[1]) == 1)
	{
		nBonus = EBK_Eighth;//100
	}
	//玩家手牌是一对A
	else if (GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 1)
	{
		nBonus = EBK_Seventh;//30
	}
	//高对子
	else if (GetCardValue((BYTE)sHandCard[0]) == GetCardValue((BYTE)sHandCard[1])
		&& GetCardValue((BYTE)sHandCard[0]) > 10)
	{
		nBonus = EBK_Third;//10
	}
	//低对子
	else if (GetCardValue((BYTE)sHandCard[0]) == GetCardValue((BYTE)sHandCard[1])
		&& GetCardValue((BYTE)sHandCard[0]) <= 10)
	{
		nBonus = EBK_First;//3
	}

	//玩家手牌是同花A和K
	if (GetCardColor((BYTE)sHandCard[0]) == GetCardColor((BYTE)sHandCard[1]))
	{
		if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 13)
			|| (GetCardValue((BYTE)sHandCard[0]) == 13 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Sixth;//25
		}
		//同花a-q
		else if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 12)
			|| (GetCardValue((BYTE)sHandCard[0]) == 12 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Fifth;//20
		}
		//同花 a-j
		else if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 11)
			|| (GetCardValue((BYTE)sHandCard[0]) == 11 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Fifth;//20
		}
	}
	else
	{
		//a-k unsuited A-K(不同花色）
		if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 13)
			|| (GetCardValue((BYTE)sHandCard[0]) == 13 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Fourth;//15
		}
		//a-q  unsuited A-Q(不同花色）
		else if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 12)
			|| (GetCardValue((BYTE)sHandCard[0]) == 12 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Second;//5
		}
		//a-j / unsuited  A-J (不同花色）
		else if ((GetCardValue((BYTE)sHandCard[0]) == 1 && GetCardValue((BYTE)sHandCard[1]) == 11)
			|| (GetCardValue((BYTE)sHandCard[0]) == 11 && GetCardValue((BYTE)sHandCard[1]) == 1))
		{
			nBonus = EBK_Second;//5
		}
	}
	return nBonus;
}

int CCard::JackPotReward(BYTE sJackPotKind)
{
	//enum ECardKind																																			// 扑克类型;
	//{
	//	ECK_Straight = 5,																																	//顺子类型	50
	//	ECK_Flush = 6,																																		//同花类型	50
	//	ECK_Fullhouse = 7,																																	//葫芦类型	45
	//	ECK_FourofaKind = 8,																																//四条类型	35
	//	ECK_StraightFlush = 9,																																//同花顺型	20
	//	ECK_RoyalFlush = 10,																																//皇家同花顺1
	//};
	int nJackpot = 0;

	switch (sJackPotKind)
	{
	case ECK_Straight:
		nJackpot = EJK_First;// 4
		break;
	case ECK_Flush:
		nJackpot = EJK_Second;//10
		break;
	case ECK_Fullhouse:
		nJackpot = EJK_Third;//16
		break;
	case ECK_FourofaKind:
		nJackpot = EJK_Fourth;//20
		break;
	case ECK_StraightFlush:
		nJackpot = EJK_Fifth;//100
		break;
	case ECK_RoyalFlush:
		nJackpot = EJK_Sixth;//200
		break;

	default:
		break;
	}
	return nJackpot;
}