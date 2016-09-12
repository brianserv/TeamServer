#pragma  once
#ifndef __HTTP_LINK_MANAGER_H__
#define __HTTP_LINK_MANAGER_H__

#include "../../FrameWork/BaseDefine.h"
#include "../Common/GameEnum.h"

#include "HttpLinkYY.h"
#include "HttpLinkFB.h"

class CHttpLinkManager : public CEQ_SingletonT<CHttpLinkManager>
{
public:
	CHttpLinkManager();
	virtual ~CHttpLinkManager();

public:
	bool Init();

	void CreateHttplink();
	void CreateHttplink(const int nPlatformType);
	void CreateHttpLinkYY();
	void CreateHttpLinkFB();
public:
	void SetHttpLinkYY(CHttpLinkYY* pHttpLinkYY);
	void SetHttpLinkFB(CHttpLinkFB* pHttpLinkFB);

	void SetPlatformDomain(const int nPlatformType, const string strYYDomain, const string strFBDomain);
	string GetPlatformDomain(const int nPlatformType);

public:
	CHttpLinkYY* GetHttpLinkYY();
	CHttpLinkFB* GetHttpLinkFB();

public:
	void StartHttplink(int nPlatformID, int nHttpEventID, int nRoleId);

	void HttpLinkHandler(const int nPlatformType, const int nHttpEventType,
		const int nRoleId, const int nRoomId, const int nIndex);
private:

	typedef std::vector<int> PLATFORM_VEC;
	PLATFORM_VEC m_PlatformVec;

	typedef std::map<int, string> PLATFORM_MAP;
	PLATFORM_MAP m_PlatformMap;

private:
	CHttpLinkYY* m_pHttpLinkYY;
	CHttpLinkFB* m_pHttpLinkFB;
};

#endif//__HTTP_LINK_MANAGER_H__