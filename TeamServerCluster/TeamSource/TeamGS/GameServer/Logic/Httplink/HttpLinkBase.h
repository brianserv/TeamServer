#pragma  once
#ifndef __HTTP_LINK_BASE_H__
#define __HTTP_LINK_BASE_H__

#include "../../FrameWork/BaseDefine.h"

class CHttpLinkBase
{
public:
	CHttpLinkBase(){};
	virtual ~CHttpLinkBase(){};
public:
	inline void SetPlatformType(const int nPlatformType){ m_nPlatformType = nPlatformType;};
	inline int  GetPlatformType(){ return m_nPlatformType;};
private:
	int m_nPlatformType;
};

#endif//__HTTP_LINK_BASE_H__