#pragma  once
#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__
#include "../../FrameWork/BaseDefine.h"

class CResourceManager : public CEQ_SingletonT<CResourceManager>
{
public:
	CResourceManager();
	virtual ~CResourceManager();

	bool Init();
	bool Clear();
	bool Curl_Http_Get();
	string GetJsonData(const string strJsonTableName, string &strJsonData);
	bool LoadGameResource(const string strJsonTableName, const string strJsonData);

private:
	int m_nResourceCount;
	typedef std::map<string, string> JsonDomainDirMAP;
	JsonDomainDirMAP m_JsonDomainDirMap;
};

#endif//__RESOURCE_MANAGER_H__
