#pragma once
#ifndef __CARD_H__
#define __CARD_H__

#include "../../FrameWork/BaseDefine.h"

#define		LOGIC_MASK_COLOR			0xF0;			                        																		// 花色掩码;
#define		LOGIC_MASK_VALUE			0x0F;			                        																		// 数值掩码;

enum ECardKind																																			// 扑克类型;
{
	ECK_highcard = 1,																																	//单牌类型	150
	ECK_OnePair = 2,																																	//对子类型	250
	ECK_TwoPairs = 3,																																	//两对类型	250
	ECK_Threeofakind = 4,																																//三条类型	149
	ECK_Straight = 5,																																	//顺子类型	50
	ECK_Flush = 6,																																		//同花类型	50
	ECK_Fullhouse = 7,																																	//葫芦类型	45
	ECK_FourofaKind = 8,																																//四条类型	35
	ECK_StraightFlush = 9,																																//同花顺型	20
	ECK_RoyalFlush = 10,																																//皇家同花顺1
};

struct tagAnalyseResult																																	// 分析扑克结构;
{
	BYTE 	cbFourCount;																																//四张数目
	BYTE 	cbThreeCount;																																//三张数目
	BYTE 	cbLONGCount;																																//两张数目
	BYTE	cbSignedCount;																																//单张数目
	BYTE 	cbFourLogicVolue[1];																														//四张列表
	BYTE 	cbThreeLogicVolue[1];																														//三张列表
	BYTE 	cbLONGLogicVolue[2];																														//两张列表
	BYTE 	cbSignedLogicVolue[5];																														//单张列表
	BYTE	cbFourCardData[MAX_TEXAS_CENTERCARD_NUM];																											//四张列表
	BYTE	cbThreeCardData[MAX_TEXAS_CENTERCARD_NUM];																											//三张列表
	BYTE	cbLONGCardData[MAX_TEXAS_CENTERCARD_NUM];																											//两张列表
	BYTE	cbSignedCardData[MAX_TEXAS_CENTERCARD_NUM];																											//单张数目
};

class CCard
{
public:
	CCard(void);
	~CCard(void);
public:
	typedef std::vector<BYTE> CARD_VEC;
	CARD_VEC	m_CardDataVec;

	typedef std::map<BYTE, string> CARDNAME_MAP;
	CARDNAME_MAP m_CardNameMap;

public:
	void Clear();

	void ResetCard();																																	// 重置卡牌;

	void MakeCardName();
	void MakeCardName(BYTE num);

	string GetCardName(BYTE num);
	BYTE RandomCard();																																	// 产生卡牌;
	bool DeleteCard(int nCardNum);																														// 干掉卡牌;

	void GetCardData(CARD_VEC& ValueListVec);

	void SetCardData(CARD_VEC& ValueListVec);

public:
	BYTE GetCardValue(BYTE sCardData) { return sCardData & LOGIC_MASK_VALUE; };																		// 获取数值;

	BYTE GetCardColor(BYTE sCardData) { return sCardData & LOGIC_MASK_COLOR; };																		// 获取花色;

	BYTE GetCardType(BYTE cbCardData[], BYTE cbCardCount);																							 // 根据数目获取卡牌类型;

	BYTE GetCardLogicValue(BYTE cbCardData);																											 // 获取逻辑数值;

	void AnalysebCardData(const BYTE cbCardData[], BYTE cbCardCount, tagAnalyseResult & AnalyseResult); 											 // 分析扑克;

	void SortCardList(BYTE cbCardData[], BYTE cbCardCount);																							 // 排列扑克;

	BYTE CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount);																		 // 对比扑克;

	BYTE FiveFromSeven(std::vector<int> &cbHandCardData, std::vector<int> &cbCenterCardData,
		BYTE cbLastCardData[], BYTE cbLastCardCount);																								 // 7选5;(不包含玩家手牌);

	BYTE FiveFromSevenWithHand(std::vector<int>&cbHandCardData, std::vector<int> &cbCenterCardData,
		BYTE cbLastCardData[], BYTE cbLastCardCount);																								 // 7选5;(包含玩家手牌);

	int BonusReward(std::vector<int> &sHandCard, std::vector<int> &sGirlCard);

	int JackPotReward(BYTE sJackPotKind);
};

#endif //__CARD_H__
