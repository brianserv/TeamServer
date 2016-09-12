#include "TableBetTea.h"

CTableBetTeaManager::CTableBetTeaManager(void)
{
}

CTableBetTeaManager::~CTableBetTeaManager(void)
{
}

bool CTableBetTeaManager::Init(const string strJsonTableName, const string strJsonTableData)
{
	if (strJsonTableName.empty() || strJsonTableData.empty())
	{
		return false;
	}
	Json::Reader JsonReader;
	Json::Value JsonValue;
	if (JsonReader.parse(strJsonTableData, JsonValue))
	{
		if (!JsonValue[strJsonTableName].isNull())
		{
			int nSize = JsonValue[strJsonTableName].size();

			for (int index = 0; index < nSize; index++)
			{
				TableBetTeaInfo Info;
				Info.m_nId = JsonValue[strJsonTableName][index]["id"].asInt();
				Info.m_nBetTeaMoney = JsonValue[strJsonTableName][index]["teamoney"].asInt();
				Info.m_nBetTeaPercent = JsonValue[strJsonTableName][index]["teapercent"].asInt();
				Info.m_nBetTeaSwitch = JsonValue[strJsonTableName][index]["enabled"].asInt();

				if (Info.m_nId < 0 || Info.m_nBetTeaMoney < 0 || Info.m_nBetTeaPercent < 0 || Info.m_nBetTeaSwitch < 0)
				{
					g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CTableBetTeaManager::Init Bet_tea Config Exception !");
					break;
				}
				m_BetTeaInfoMap.insert(std::make_pair(Info.m_nId, Info));
			}
		}
		if (!m_BetTeaInfoMap.empty())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Bet_tea Json Data Sucess !");
		}
	}
	return true;
}

bool CTableBetTeaManager::Clear()
{
	m_BetTeaInfoMap.clear();
	return true;
}
int CTableBetTeaManager::GetBetTeaMoney(const int nId)
{
	BetTeaInfoMap::iterator it = m_BetTeaInfoMap.find(nId);
	if (it != m_BetTeaInfoMap.end())
	{
		return it->second.m_nBetTeaMoney;
	}
	return 0;
}
int CTableBetTeaManager::GetBetTeaPercent(const int nId)
{
	BetTeaInfoMap::iterator it = m_BetTeaInfoMap.find(nId);
	if (it != m_BetTeaInfoMap.end())
	{
		return it->second.m_nBetTeaPercent;
	}
	return 0;
}
int CTableBetTeaManager::GetBetTeaSwitch(const int nId)
{
	BetTeaInfoMap::iterator it = m_BetTeaInfoMap.find(nId);
	if (it != m_BetTeaInfoMap.end())
	{
		return it->second.m_nBetTeaSwitch;
	}
	return 0;
}

bool CTableBetTeaManager::CheckBetTeaSwitch(const int nId)
{
	if (GetBetTeaSwitch(nId == 0))
	{
		return false;
	}
	return true;
}

int  CTableBetTeaManager::GetBetTea_WinChips(const int nId, const int nWinChips)
{
	return (GetBetTeaPercent(nId)*nWinChips / 100);
}