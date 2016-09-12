#include "TableLimit.h"

CTableLimitManager::CTableLimitManager(void)
{
}

CTableLimitManager::~CTableLimitManager(void)
{
}

bool CTableLimitManager::Init(const string strJsonTableName, const string strJsonTableData)
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
				TableLimitInfo Info;
				Info.m_nId = JsonValue[strJsonTableName][index]["id"].asInt();
				Info.m_nMinAnte = JsonValue[strJsonTableName][index]["antemin"].asInt();
				Info.m_nMaxAnte = JsonValue[strJsonTableName][index]["antemax"].asInt();
				Info.m_nChips = JsonValue[strJsonTableName][index]["chips"].asInt();

				if (Info.m_nId < 0 || Info.m_nMinAnte < 0 || Info.m_nMaxAnte < 0 || Info.m_nChips < 0)
				{
					g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "CTableLimitManager::Init LimitConfig Exception !");
					break;
				}
				m_LimitInfoMap.insert(std::make_pair(Info.m_nId, Info));
			}
		}
		if (!m_LimitInfoMap.empty())
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Limit Json Data Sucess !");
		}
	}
	return true;
}

bool CTableLimitManager::Clear()
{
	m_LimitInfoMap.clear();
	return true;
}
int CTableLimitManager::GetMinAnte(const int nId)
{
	LimitInfoMap::iterator it = m_LimitInfoMap.find(nId);
	if (it != m_LimitInfoMap.end())
	{
		return it->second.m_nMinAnte;
	}
	return 0;
}
int CTableLimitManager::GetMaxAnte(const int nId)
{
	LimitInfoMap::iterator it = m_LimitInfoMap.find(nId);
	if (it != m_LimitInfoMap.end())
	{
		return it->second.m_nMaxAnte;
	}
	return 0;
}
int CTableLimitManager::GetChips(const int nId)
{
	LimitInfoMap::iterator it = m_LimitInfoMap.find(nId);
	if (it != m_LimitInfoMap.end())
	{
		return it->second.m_nChips;
	}
	return 0;
}