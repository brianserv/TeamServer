#pragma  once
#ifndef __WEBFRAME_FILTER_H__
#define __WEBFRAME_FILTER_H_

#include "../../FrameWork/BaseDefine.h"

typedef vector<string> RESPONSE_FILTER_VEC;
class CWebFrameFilter :public CEQ_SingletonT<CWebFrameFilter>
{
public:
	CWebFrameFilter();
	virtual ~CWebFrameFilter();
public:
	bool ParseWebTextFrame(string strResponse, int nWebMarkId);
public:
	static int ParseWebTextFrame(string strResponse, std::vector<string>& strFilterResponse, string strSplit);
public:
	inline void SetFilterCommand(int nFilterCommand) { m_nFilterCommand = nFilterCommand; }
	inline int  GetFilterCommand() const { return m_nFilterCommand; }
	inline vector<string>& GetWebTextFrame_LeafVec() { return m_strResponseFilterVec; };

private:
	int m_nFilterCommand;
	RESPONSE_FILTER_VEC m_strResponseFilterVec;
};

#endif//__WEBFRAME_FILTER_H_