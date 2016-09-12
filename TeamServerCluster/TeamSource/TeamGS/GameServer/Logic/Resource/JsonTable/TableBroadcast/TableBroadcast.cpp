#include "TableBroadcast.h"

CTableBroadcastManager::CTableBroadcastManager(void)
{
}

CTableBroadcastManager::~CTableBroadcastManager(void)
{
}

bool CTableBroadcastManager::Init(const string strJsonTableName, const string strJsonTableData)
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
				TableBroadcastInfo Info;
				Info.m_nId = JsonValue[strJsonTableName][index]["id"].asInt();
				Info.m_nCostType = JsonValue[strJsonTableName][index]["cost"].asInt();
				Info.m_nCostValue = JsonValue[strJsonTableName][index]["value"].asInt();
				Info.m_nBroadCastType = JsonValue[strJsonTableName][index]["broadcast"].asInt();

				if (Info.m_nId < 0 || Info.m_nCostType < 0 || Info.m_nCostValue < 0 || Info.m_nBroadCastType < 0)
				{
					g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CTableBroadcastManager::Init BroadCast Config Exception !");
					break;
				}
				m_BroadcastInfoMap.insert(std::make_pair(Info.m_nId, Info));
			}
		}
		if (!m_BroadcastInfoMap.empty())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load BroadCast Json Data Sucess !");
		}
	}
	return true;
}

bool CTableBroadcastManager::Clear()
{
	m_BroadcastInfoMap.clear();
	return true;
}
int CTableBroadcastManager::GetCostType(const int nId)
{
	BroadcastInfoMap::iterator it = m_BroadcastInfoMap.find(nId);
	if (it != m_BroadcastInfoMap.end())
	{
		return it->second.m_nCostType;
	}
	return 0;
}

int CTableBroadcastManager::GetCostValue(const int nId)
{
	BroadcastInfoMap::iterator it = m_BroadcastInfoMap.find(nId);
	if (it != m_BroadcastInfoMap.end())
	{
		return it->second.m_nCostValue;
	}
	return 0;
}

int CTableBroadcastManager::GetBroadCastType(const int nId)
{
	BroadcastInfoMap::iterator it = m_BroadcastInfoMap.find(nId);
	if (it != m_BroadcastInfoMap.end())
	{
		return it->second.m_nBroadCastType;
	}
	return 0;
}