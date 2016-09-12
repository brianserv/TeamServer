#pragma once
#ifndef __TABLEGAME_H__
#define __TABLEGAME_H__

#include "TextTable.h"
#include "ATCsvTable.h"

using namespace std;

template <typename T>
class CGameTable
{
public:
	CGameTable(void);
	~CGameTable(void);

	T * GetItem(int nId);
	T * GetItem(std::string strName);
	T * GetItemByIndex(int nIndex);

	int GetIntValue(std::string strKey)
	{
		T * pItem = GetItem(strKey);
		if (pItem)
			return atoi(pItem->m_strValue.c_str());
		return 0;
	}

	std::string GetStrValue(std::string strKey)
	{
		T * pItem = GetItem(strKey);
		if (pItem)
			return pItem->m_strValue;
		return "";
	}

	int GetItemCount() { return m_mapItem.size(); }
	T* GetFirst();
	T* GetNext();
	bool Init();
	bool Reload();
	bool Destroy();

	CGameTable * GetInstance()
	{
		if (_pInstance == NULL)
			_pInstance = new CGameTable();
		return _pInstance;
	};
private:
	bool _Inited;
	static CGameTable * _pInstance;
	typename map<int, T>::iterator m_iter;
	map<int, T> m_mapItem;
	map<std::string, T> m_mapNameItem;
};

template <typename T>
CGameTable<T> * CGameTable<T>::_pInstance = NULL;

template <typename T>
CGameTable<T>::CGameTable(void) :_Inited(false)
{
}

template <typename T>
CGameTable<T>::~CGameTable(void)
{
}

template <typename T>
bool CGameTable<T>::Init()
{
	string strCurrentDir(GetAppCurDir());
	string strResourcePath(strCurrentDir + T::s_strFileName);
	CATCsvTable csvTable(strResourcePath.c_str());

	//g_EQLog.WriteErrorLogInfo(LOGIC_LOG_INFO, "Table[%s] now Loadding !\n", T::s_strFileName.c_str());

	string strEmptyName("");
	if (csvTable.GetCSVName() == strEmptyName)
	{
		//g_EQLog.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Table[%s][File: %s \n Line:%d \n Function:%s] \n now Loadding !\n load Failure Cant Find CSV Files", T::s_strFileName.c_str(), __FILE__, __LINE__, __FUNCTION__);
		return false;
	}

	uint nIdx = csvTable.FindLineByString("ID");
	if (nIdx < 0)
		return false;

	csvTable.SetTitleLine(csvTable[nIdx]);

	uint nTotalLine = csvTable.GetLineNum();

	for (int i = nIdx + 1; i <= nTotalLine; i++)
	{
		T item;
		item.Clear();
		item.Load(csvTable[i]);

		m_mapItem.insert(std::make_pair(item.m_nId, item));

		std::string strName = csvTable[i]["Name"].Str();
		if (strName != "")
			m_mapNameItem.insert(std::make_pair(strName, item));
	}

	//g_EQLog.WriteErrorLogInfo(LOGIC_LOG_ERROR, "Table[%s][File: %s \n Line:%d \n Function:%s] \n Load Success !\n ", T::s_strFileName.c_str(), __FILE__, __LINE__, __FUNCTION__);
	return true;
}

template <typename T>
bool CGameTable<T>::Reload()
{
	m_mapItem.clear();
	m_mapNameItem.clear();
	Init();
	return true;
}

template <typename T>
bool CGameTable<T>::Destroy()
{
	m_mapItem.clear();
	return true;
}

template <typename T>
T * CGameTable<T>::GetItem(int nId)
{
	typename map<int, T>::iterator iter;
	iter = m_mapItem.find(nId);
	if (iter != m_mapItem.end())
		return &(iter->second);
	return NULL;
}

template <typename T>
T * CGameTable<T>::GetItem(std::string strName)
{
	typename map<std::string, T>::iterator iter;
	iter = m_mapNameItem.find(strName);
	if (iter != m_mapNameItem.end())
		return &(iter->second);
	return NULL;
}

template <typename T>
T * CGameTable<T>::GetItemByIndex(int nIndex)
{
	if (nIndex >= 0 && nIndex < (int)m_mapItem.size())
	{
		typename map<int, T>::iterator iter;
		iter = m_mapItem.begin();
		while (nIndex > 0)
		{
			iter++;
			nIndex--;
		}
		return &(iter->second);
	}
	return NULL;
}

template <typename T>
T * CGameTable<T>::GetFirst()
{
	m_iter = m_mapItem.begin();
	if (m_iter != m_mapItem.end())
		return &(m_iter->second);
	else
		return NULL;
}

template <typename T>
T * CGameTable<T>::GetNext()
{
	if (m_iter == m_mapItem.end())
		return NULL;

	++m_iter;
	if (m_iter != m_mapItem.end())
		return &(m_iter->second);
	else
		return NULL;
}

#endif//__TABLEGAME_H__
