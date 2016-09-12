#include "ResourceManager.h"

#include "JsonTable/TableBetTea/TableBetTea.h"
#include "JsonTable/TableGift/TableGift.h"
#include "JsonTable/TableLimit/TableLimit.h"
#include "JsonTable/TableBroadcast/TableBroadcast.h"

const string cSTR_JSON = "/json/";
const string cSTR_BET = "bet";
const string cSTR_GIFT = "gift";
const string cSTR_LIMIT = "limit";
const string cSTR_BROADCAST = "broadcast";

CResourceManager::CResourceManager()
	:m_nResourceCount(0)
{
	Init();
}

CResourceManager::~CResourceManager() {}

bool CResourceManager::Init()
{
	m_JsonDomainDirMap[cSTR_BET] = cSTR_JSON + cSTR_BET;
	m_JsonDomainDirMap[cSTR_GIFT] = cSTR_JSON + cSTR_GIFT;
	m_JsonDomainDirMap[cSTR_LIMIT] = cSTR_JSON + cSTR_LIMIT;
	m_JsonDomainDirMap[cSTR_BROADCAST] = cSTR_JSON + cSTR_BROADCAST;

	return true;
}

bool CResourceManager::Clear()
{
	CTableBetTeaManager::Instance().Clear();
	CTableGiftManager::Instance().Clear();
	CTableLimitManager::Instance().Clear();
	CTableBroadcastManager::Instance().Clear();

	return true;
}

bool  CResourceManager::Curl_Http_Get()
{
	Clear();

	string strHttpResponseJsonData("");
	string strJsonConfigDomain(CConfigFile::Instance().m_szJsonConfigDomain);
	if (strJsonConfigDomain == "")
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR,
			"【LOG:Curl_Http_Get JsonConfigDomain URL IS EMPTY】：");
		return false;
	}

	JsonDomainDirMAP::iterator it = m_JsonDomainDirMap.begin();
	JsonDomainDirMAP::iterator itEnd = m_JsonDomainDirMap.end();
	for (; it != itEnd; ++it)
	{
		//g_CurlHttp.Curl_Http_Get(strJsonConfigDomain + it->second, strHttpResponseJsonData);
		//g_CurlHttp.Curl_Https_Get(strJsonConfigDomain + it->second, strHttpResponseJsonData);
		if (g_CurlHttp.Curl_Https_Get(strJsonConfigDomain + it->second, strHttpResponseJsonData) != 0)
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, " [File: %s \n Line:%d \n Function:%s] \n [Error]:Curl_Https_Get Failure!", __FILE__, __LINE__, __FUNCTION__);
			continue;
		}
		if (!strHttpResponseJsonData.empty())
		{
			LoadGameResource(it->first, GetJsonData(it->first, strHttpResponseJsonData));
		}
	}
	return true;
}

string CResourceManager::GetJsonData(const string strJsonTableName, string &strJsonData)
{
	string strJsonTableData("");
	strJsonTableData += HTTP_JSON_TABLE_BRACE_LEFT;

	strJsonTableData += strJsonTableName;

	strJsonTableData += HTTP_JSON_TABLE_COLON_MIDDLE;

	strJsonTableData += strJsonData;

	strJsonTableData += HTTP_JSON_TABLE_BRACE_RIGHT;

	strJsonData = strJsonTableData;

	return strJsonData;
}

bool CResourceManager::LoadGameResource(const string strJsonTableName, const string strJsonData)
{
	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "[->->LoadGameResource:%s.json!]", strJsonTableName.c_str());
	if (strJsonTableName == cSTR_BET)
	{
		if (!CTableBetTeaManager::Instance().Init(strJsonTableName, strJsonData))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Bet Json Data Failure !");
		}
		++m_nResourceCount;
	}
	else if (strJsonTableName == cSTR_GIFT)
	{
		if (!CTableGiftManager::Instance().Init(strJsonTableName, strJsonData))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Gift Json Data Failure !");
		}
		++m_nResourceCount;
	}
	else if (strJsonTableName == cSTR_LIMIT)
	{
		if (!CTableLimitManager::Instance().Init(strJsonTableName, strJsonData))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load Limit Json Data Failure !");
		}
		++m_nResourceCount;
	}
	else if (strJsonTableName == cSTR_BROADCAST)
	{
		if (!CTableBroadcastManager::Instance().Init(strJsonTableName, strJsonData))
		{
			g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Load BroadCast Json Data Failure !");
		}
		++m_nResourceCount;
	}

	if (m_nResourceCount == m_JsonDomainDirMap.size())
	{
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "[->->GameResource Json Data Load Success!]");
		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_ERROR, "________________________GameResource Json Load Success __________________________");

		m_nResourceCount = 0;

		g_ResourceLoadSucc = true;
	}
	return true;
}