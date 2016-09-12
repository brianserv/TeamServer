#include "WebFrameFilter.h"

CWebFrameFilter::CWebFrameFilter()
{
}

CWebFrameFilter::~CWebFrameFilter()
{
}

bool  CWebFrameFilter::ParseWebTextFrame(string strResponse, int nWebMarkId)
{
	string strSplit("|");

	int nFilterCommand = ParseWebTextFrame(strResponse, m_strResponseFilterVec, strSplit);

	if (nFilterCommand <= 0)
		return  false;

	SetFilterCommand(nFilterCommand);
	return true;
}

int CWebFrameFilter::ParseWebTextFrame(string strResponse, std::vector<string>& strFilterResponse, string strSplit)
{
	if (!strResponse.empty())
	{
		CConvertCharString  ConvertCharStringObj;
		string strSubSplit("|");

#if defined (_WIN32) || defined (_WIN64)
		if (strcmp(strSplit.c_str(), strSubSplit.c_str()) == 0)
		{
			strFilterResponse = PARSE_STRINGS::ParseString::Split(strResponse, strSplit);
		}

		if (strFilterResponse[0].empty())
		{
			std::vector<string>::iterator it = strFilterResponse.begin() + 0;
			strFilterResponse.erase(it);
		}
		if (!strFilterResponse.empty())
		{
			return  PARSE_STRINGS::stringToInt(strFilterResponse[0]);
		}
#else
		if (strncasecmp(strSplit.c_str(), strSubSplit.c_str(), strlen(strSubSplit.c_str())) == 0)
		{
			strFilterResponse = PARSE_STRINGS::ParseString::Split(strResponse, strSplit);
		}

		if (strFilterResponse[0].empty())
		{
			std::vector<string>::iterator it = strFilterResponse.begin() + 0;
			strFilterResponse.erase(it);
		}
		if (!strFilterResponse.empty())
		{
			return  PARSE_STRINGS::stringToInt(strFilterResponse[0]);
		}
#endif
		return 0;
	}
	return 0;
}