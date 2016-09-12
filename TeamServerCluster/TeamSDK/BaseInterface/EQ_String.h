#pragma once

#ifndef  EQ_STRING_FILE
#define  EQ_STRING_FILE
#include "EQUtils.h"
#include "EQ_DataType.h"
#include "EQ_IPAddresses.h"

#if defined (_WIN32) || defined (_WIN64)

#define  EQ_SPRINTF            sprintf_s

#else

#define  EQ_SPRINTF            snprintf

#endif

extern     int   EQ_SplitToStr(char* pSrc, vector<string> & strDesList, const char cSplit);
extern     int   EQ_SplitToInt(char* pSrc, vector<int> & nDesList, const char cSplit);

namespace PARSE_STRINGS
{
	inline int stringToInt(const std::string &INstr)
	{
		int value;
		std::stringstream str(INstr);

		str >> value;
		return value;
	}
	inline long stringToLong(const std::string &INstr)
	{
		long value;
		std::stringstream str(INstr);

		str >> value;

		return value;
	}
	inline double stringToDouble(const std::string &INstr)
	{
		double value;
		std::stringstream str(INstr);

		str >> value;

		return value;
	}

	template<class T>
	inline T minimum(T x, T y)
	{
		return (x < y) ? x : y;
	}

	template<typename T>
	inline std::string toString(const T &arg)
	{
		std::stringstream ss;
		ss << arg;
		return ss.str();
	}

	template<class T>
	void swap(T* INleft, T* INright)
	{
		T temp = *INleft;
		*INleft = *INright;
		*INright = temp;
	}

	inline bool CheckIntString(string strIntString)
	{
		if (strIntString.empty())
			return false;

		const int nlen = strIntString.length();
		for (int i = 0; i < nlen; i++)
		{
			if (strIntString[i] == ' ')
				return false;

			if (strIntString[i] == ',' || strIntString[i] == '|' || strIntString[i] == ':' || strIntString[i] == '-')
				continue;

			if (strIntString[i] < '0' || strIntString[i] > '9')
				return false;
		}
		return true;
	}

	class StringUtil
	{
	public:
		template <char INsplitchar>
		static bool NotSplitchar(char INchar)
		{
			return (INchar != INsplitchar) ? true : false;
		}

		template <char INsplitchar>
		static bool Splitchar(char INchar)
		{
			return (INchar == INsplitchar) ? true : false;
		}

		template<char INsplitchar>
		static void Split(const string &s, vector<string>& OUTtargetVector)
		{
			typedef string::const_iterator iter;
			iter i = s.begin();
			iter j = s.end();
			while (i != s.end())
			{
				i = find_if(i, s.end(), NotSplitchar<INsplitchar>);
				iter  j = find_if(i, s.end(), Splitchar<INsplitchar>);
				// 获取字符串
				if (i != j)
				{
					OUTtargetVector.push_back(string(i, j));
					i = j;
				}
			}
		}
	};

	static __UINT32 gs_strat = 0;
	static __UINT32 gs_Index = 0;
	static __UINT32 gs_value = 0;
	class ParseString
	{
	public:
		static __UINT32 GetSubStr(string &INstrPropertyValue)
		{
			__UINT32 retPropertyValue;
			gs_Index = INstrPropertyValue.find_first_of('|', gs_strat);
			retPropertyValue = atoi((INstrPropertyValue.substr(gs_strat, gs_Index)).c_str());
			gs_strat = gs_Index + 1;

			return retPropertyValue;
		}

		static void ParseVerticleLine6(string INstrPropertyValue, __UINT32 &OUTintProperty1, __UINT32 &OUTintProperty2, __UINT32 &OUTintProperty3, __UINT32 &OUTintProperty4, __UINT32 &OUTintProperty5, __UINT32 &OUTintProperty6)
		{
			OUTintProperty1 = GetSubStr(INstrPropertyValue);
			OUTintProperty2 = GetSubStr(INstrPropertyValue);
			OUTintProperty3 = GetSubStr(INstrPropertyValue);
			OUTintProperty4 = GetSubStr(INstrPropertyValue);
			OUTintProperty5 = GetSubStr(INstrPropertyValue);
			OUTintProperty6 = GetSubStr(INstrPropertyValue);
		}

		static int ParseStringSplit(const std::string &INstringSplit, const std::string &INname)
		{
			vector<string> stringSplitVector;
			StringUtil::Split<'|'>(INstringSplit, stringSplitVector);
			for (gs_value = 0; gs_value < stringSplitVector.size(); ++gs_value)
			{
				if (INname.compare(stringSplitVector[gs_value].c_str()) == 0)
				{
					return gs_value;
				}
			}
		}

		static vector<string> Split(std::string INstringSplit, std::string INSplitPattern)
		{
			std::string::size_type pos;
			std::vector<std::string> result;
			INstringSplit += INSplitPattern;
			__UINT32 size = INstringSplit.size();
			for (__UINT32 index = 0; index < size; index++)
			{
				pos = INstringSplit.find(INSplitPattern, index);
				if (pos < size)
				{
					std::string str = INstringSplit.substr(index, pos - index);
					result.push_back(str);

					index = pos + INSplitPattern.size() - 1;
				}
			}
			return result;
		}

		static void SplitCharacter(char str[], std::vector<char*>& arr, char* split)
		{
			char* pStr = NULL;
			pStr = strtok(str, split);
			while (NULL != pStr)
			{
				arr.push_back(pStr);
				pStr = strtok(NULL, split);
			}
		}

		static void SplitInt(char str[], std::vector<int>& arr, char* split)
		{
			char* pStr = NULL;
			pStr = strtok(str, split);
			while (NULL != pStr)
			{
				arr.push_back(atoi(pStr));
				pStr = strtok(NULL, split);
			}
		}

		static string replace(const string& str, const string& src, const string& dest)
		{
			string ret;

			string::size_type pos_begin = 0;
			string::size_type pos = str.find(src);
			while (pos != string::npos)
			{
				ret.append(str.c_str() + pos_begin, pos - pos_begin);
				ret += dest;
				pos_begin = pos + src.length();
				pos = str.find(src, pos_begin);
			}
			if (pos_begin < str.length())
			{
				ret.append(str.begin() + pos_begin, str.end());
			}
			return ret;
		}

		static std::vector<std::string> splitEx(std::string str, std::string pattern)
		{
			std::vector<std::string> ret;
			if (pattern.empty()) return ret;
			size_t start = 0, index = str.find_first_of(pattern, 0);
			while (index != str.npos)
			{
				if (start != index)
					ret.push_back(str.substr(start, index - start));
				start = index + 1;
				index = str.find_first_of(pattern, start);
			}
			if (!str.substr(start).empty())
				ret.push_back(str.substr(start));
			return ret;
		}
	private:
		ParseString();
		~ParseString();
	};
}
#endif
