#pragma  once
#ifndef __DBRESOURCE_MANAGER_H__
#define __DBRESOURCE_MANAGER_H__

#include "../Table/DBRole.h"
#include "../Table/DBTexasBoard.h"
#include "../Table/DBTexasHistoryBoard10.h"
#include "../Table/DBPrizePool.h"

#define DB_SAVEROLE_NUM_MAX 100

class CDBResourceManager : public CEQ_SingletonT<CDBResourceManager>
{
public:
	CDBResourceManager();
	virtual  ~CDBResourceManager();

public:
	void Clear();
	void Release();
public:
	bool AddDBRoleInfo(CDBRoleInfo* pDBRoleInfo);
	CDBRoleInfo*GetDBRoleInfo(int nRoleId);
	void ReleaseDBRoleMap();
public:
	bool AddDBTexasBoardInfo(CDBTexasBoardInfo* pDBTexasBoardInfo);
	int GetDBTexasBoardInfo_BoardID(int nServerId, int nRoomID);
	void ReleaseDBTexasBoardMap();

public:
	bool AddDBTexasHistoryBoard10Info(CDBTexasHistoryBoard10Info* pDBTexasHistoryBoard10Info);
	CDBTexasHistoryBoard10Info*GetDBTexasHistoryBoard10Info(int nRoomId);
	void ReleaseDBTexasHistoryBoard10Map();

public:
	bool AddDBPrizePoolInfo(CDBPrizePoolInfo* pDBPrizePoolInfo);
	CDBPrizePoolInfo*GetDBPrizePoolInfo(int nPrizePoolID);
	void ReleaseDBPrizePoolMap();
public:
	void SaveDBData(int nIndex, int & nRoleIndex);
	void SaveRoleData(int nIndex, int & nRoleIndex);
private:
	typedef map<int, CDBRoleInfo*>  DBRoleInfoMap;
	DBRoleInfoMap m_DBRoleInfoMap;
	typedef std::vector<CDBRoleInfo*> DBRoleInfoVec;
	DBRoleInfoVec m_DBRoleInfoVec;
private:
	typedef multimap<int, CDBTexasBoardInfo*>  DBTexasBoardInfoMap;
	DBTexasBoardInfoMap m_DBTexasBoardInfoMap;
private:
	typedef map<int, CDBTexasHistoryBoard10Info*>  DBTexasHistoryBoard10InfoMap;
	DBTexasHistoryBoard10InfoMap m_DBTexasHistoryBoard10InfoMap;

private:
	typedef map<int, CDBPrizePoolInfo*>  DBPrizePoolInfoMap;
	DBPrizePoolInfoMap mDBPrizePoolInfoMap;
};
#endif//__DBRESOURCE_MANAGER_H__