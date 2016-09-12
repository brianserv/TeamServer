#pragma once
#ifndef __ATCSVTABLE_H__
#define __ATCSVTABLE_H__


#include "../EQUtils.h"

typedef unsigned char	uchar;
typedef unsigned short 	ushort;
typedef unsigned int	uint;
typedef unsigned long 	ulong;


class  CATTableItem
{
public:
	CATTableItem() { m_strValue = ""; }
	CATTableItem(const string strValue) { m_strValue = strValue; }
	void SetValue(const string strValue){ m_strValue = strValue; }
	bool IsValid() const                { return m_strValue[0] != 0; }
	operator const       char*() const  { return m_strValue.c_str(); }
	const char*          Str() const    { return m_strValue.c_str(); }
	const char*          SafeStr()const { return m_strValue.c_str() ? m_strValue.c_str() : ""; }
	const bool           Bool() const   { return atoi(m_strValue.c_str()) != 0; }
	const char           Char() const   { return (char)m_strValue.c_str()[0]; }
	const uchar			 Byte() const   { return (uchar)atoi(m_strValue.c_str()); }
	const short          Short() const  { return (short)atoi(m_strValue.c_str()); }
	const ushort		 Word() const   { return (ushort)atoi(m_strValue.c_str()); }
	const int            Int() const    { return  atoi(m_strValue.c_str()); }
	const uint			 UInt() const   { return (uint)atoi(m_strValue.c_str()); }
	const long           Long() const   { return atol(m_strValue.c_str()); }
	const uint			 DWord() const  { return (uint)atol(m_strValue.c_str()); }
	const float          Float() const  { return (float)atof(m_strValue.c_str()); }
	const double         Double() const { return atof(m_strValue.c_str()); }
private:
	std::string			m_strValue;
};


class  CATTableLine
{
public:
	CATTableLine() : m_nTableID(0),m_nIndex(0)
	{
		SetValue("");
	}

	CATTableLine(uint nTableID,uint nIndex, std::string strValues) : m_nTableID(nTableID),m_nIndex(nIndex)
	{
		SetValue(strValues);
	}

	void SetValue(string strValues)
	{
		vector<string> vecValues;
		map<uint, string> mapTempValues;
		//assert(GetParamFromString(strValues, vecValues) > 0);
		SplitString(strValues, vecValues);

		m_mapItems.clear();

		m_nItemNum = vecValues.size();
		vector<string>::size_type idx = 0;
		for (; idx < m_nItemNum; ++idx)
		{
			AddItem(idx + 1, vecValues[idx]);
		}
	}


	void AddItem(int nIndex, std::string strValue)
	{
		map<uint, CATTableItem>::iterator iter = m_mapItems.find(nIndex);
		if (iter == m_mapItems.end())
			m_mapItems.insert(std::pair<uint, CATTableItem>(nIndex, CATTableItem(strValue)));
		else
			m_mapItems[nIndex].SetValue(strValue);
	}

	void AddItem(int nIndex,CATTableItem & item)
	{
		map<uint, CATTableItem>::iterator iter = m_mapItems.find(nIndex);
		if (iter == m_mapItems.end())
			m_mapItems.insert(std::pair<uint, CATTableItem>(nIndex, item));
		else
			m_mapItems[nIndex] = item;
	}

	void RemoveItem(int nIndex)
	{
		map<uint, CATTableItem>::iterator iter = m_mapItems.find(nIndex);
		if (iter != m_mapItems.end())
			m_mapItems.erase(iter);
	}

	int GetParamFromString(string & str, vector<string> &vecValues, char delim = ',')
	{
		char *token = strtok(const_cast<char *>(str.c_str()), &delim);
		while (token)
		{
			string strTemp = token;
			vecValues.push_back(strTemp);
			token = strtok(NULL, &delim);
		}

		return vecValues.size();
	}

	uint SplitString(string & strSrc, vector<string>& strDest,std::string strDelims = ",")
	{
		string delims = strDelims;
		std::string STR;
		if (delims.empty())
			delims = ",";

		std::string::size_type pos = 0, st=0 , LEN = strSrc.size();
		while (pos < LEN){
			st = strSrc.find(delims, pos);

			if (st == std::string::npos)
				st = LEN;

			if (st>=pos)
			{
				strDest.push_back(strSrc.substr(pos, st - pos));
				pos = st+1;
			}
		}
		return strDest.size();
	}


	CATTableItem operator[](int nIndex)
	{
		map<uint, CATTableItem>::iterator iter = m_mapItems.find(nIndex);
		if (iter != m_mapItems.end())
			return iter->second;

		return CATTableItem("");
	}

	CATTableItem operator[](std::string strKey)
	{
		map<uint, map<std::string, uint> >::iterator iter = s_mmapTitles.find(m_nTableID);
		if (iter != s_mmapTitles.end())
		{
			map<std::string, uint> & mapTitles = iter->second;

			map<std::string, uint>::iterator iter1 = mapTitles.find(strKey);

			if (iter1!= mapTitles.end())
			{
				map<uint, CATTableItem>::iterator iter2 = m_mapItems.find(iter1->second);
				if (iter2 != m_mapItems.end())
					return iter2->second;
			}
		}
		return CATTableItem("");
	}


	uint GetItemNum(){ return m_nItemNum; }

	static map<uint ,map<std::string, uint> >	s_mmapTitles;

private:
	uint										m_nTableID;
	map<uint, CATTableItem>						m_mapItems;
	uint										m_nIndex;
	uint										m_nItemNum;
};


class CATCsvTable
{
public:
	CATCsvTable() :m_nLineNum(0){ m_nTableID = s_nSeedID++; }
	CATCsvTable(const char *path):m_nLineNum(0)
	{
		m_nTableID = s_nSeedID++;
		LoadTableFile(path);
	}
	~CATCsvTable(){}

	bool LoadTableFile(const char *path);
	bool SaveTableFile(const char *path = NULL);

	CATTableLine & AddLine(int nIndex, std::string strValue)
	{
		map<uint, CATTableLine>::iterator iter = m_mapLines.find(nIndex);
		if (iter == m_mapLines.end())
			m_mapLines.insert(std::pair<uint, CATTableLine>(nIndex, CATTableLine(m_nTableID,nIndex,strValue)));
		else
			m_mapLines[nIndex].SetValue(strValue);
		
		return m_mapLines[nIndex];
	}

	CATTableLine & AddLine(int nIndex, CATTableLine & item)
	{
		map<uint, CATTableLine>::iterator iter = m_mapLines.find(nIndex);
		if (iter == m_mapLines.end())
			m_mapLines.insert(std::pair<uint, CATTableLine>(nIndex, item));
		else
			m_mapLines[nIndex] = item;

		return m_mapLines[nIndex];
	}

	void RemoveLine(int nIndex)
	{
		map<uint, CATTableLine>::iterator iter = m_mapLines.find(nIndex);
		if (iter != m_mapLines.end())
			m_mapLines.erase(iter);
	}

	void SetTitleLine(CATTableLine  line)
	{
		map<uint, map<std::string, uint> >::iterator iter = CATTableLine::s_mmapTitles.find(m_nTableID);

		if (iter == CATTableLine::s_mmapTitles.end())
			CATTableLine::s_mmapTitles.insert(std::pair<uint, map<std::string, uint> >(m_nTableID, map<std::string, uint>()));

		iter = CATTableLine::s_mmapTitles.find(m_nTableID);

		if (iter != CATTableLine::s_mmapTitles.end())
		{
			map<std::string, uint> & mapTitles = iter->second;
			uint nLen = line.GetItemNum();
			for (uint i = 1; i <= nLen; i++)
			{
				mapTitles.insert(std::pair<std::string,uint>(line[i].Str(),i));
			}
		}

	}

	bool GetIntValue(uint uiRow, uint uiCol, int &riValue);
	bool GetFloatValue(uint uiRow, uint uiCol, float &rfValue);
	string GetStringValue(uint uiRow, uint uiCol);

	uint GetLineNum(){ return m_nLineNum; }
	
	CATTableLine operator[](int nIndex)
	{
		map<uint, CATTableLine>::iterator iter = m_mapLines.find(nIndex);
		if (iter != m_mapLines.end())
			return iter->second;

		return CATTableLine(m_nTableID,nIndex,"");
	}

	uint FindLineByString(const char* szString);
	uint SplitString(const string & strSrc, const std::string& strDelims, vector<string>& strDest);

public:
	string GetCSVName(){ return m_CSVName;};

	static uint						s_nSeedID;
private:
	uint							m_nTableID;
	map<uint, CATTableLine>			m_mapLines;
	string							m_CSVName;

	uint							m_nLineNum;
};


#endif//__ATCSVTABLE_H__