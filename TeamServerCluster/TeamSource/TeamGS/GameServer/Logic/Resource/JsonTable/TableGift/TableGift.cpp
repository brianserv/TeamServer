#include "TableGift.h"

CTableGiftManager::CTableGiftManager(void)
{
}

CTableGiftManager::~CTableGiftManager(void)
{
}

bool CTableGiftManager::Init(const string strJsonTableName, const string strJsonTableData)
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
				TableGiftInfo Info;
				Info.m_nId = JsonValue[strJsonTableName][index]["id"].asInt();
				Info.m_nValue = JsonValue[strJsonTableName][index]["value"].asInt();
				Info.m_nNum = JsonValue[strJsonTableName][index]["num"].asInt();
				Info.m_nEffectLev = JsonValue[strJsonTableName][index]["effect"].asInt();

				if (Info.m_nId < 0 || Info.m_nValue < 0 || Info.m_nNum < 0 || Info.m_nEffectLev < 0)
				{
					g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CTableGiftManager::Init GiftConfig Exception !");
					break;
				}
				m_GiftInfoMap.insert(std::make_pair(Info.m_nId, Info));
			}
		}
		if (!m_GiftInfoMap.empty())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Gift Json Data Sucess !");
		}
	}
	return true;
}

bool CTableGiftManager::Clear()
{
	m_GiftInfoMap.clear();
	return true;
}
int CTableGiftManager::GetValue(const int nId)
{
	GiftInfoMap::iterator it = m_GiftInfoMap.find(nId);
	if (it != m_GiftInfoMap.end())
	{
		return it->second.m_nValue;
	}
	return 0;
}

int CTableGiftManager::GetNum(const int nId)
{
	GiftInfoMap::iterator it = m_GiftInfoMap.find(nId);
	if (it != m_GiftInfoMap.end())
	{
		return it->second.m_nNum;
	}
	return 0;
}

int CTableGiftManager::GetEffectLev(const int nId)
{
	GiftInfoMap::iterator it = m_GiftInfoMap.find(nId);
	if (it != m_GiftInfoMap.end())
	{
		return it->second.m_nEffectLev;
	}
	return 0;
}