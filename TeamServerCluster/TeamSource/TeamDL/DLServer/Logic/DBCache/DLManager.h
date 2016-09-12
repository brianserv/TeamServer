#pragma once
#ifndef  __DL_MANAGER_H__
#define  __DL_MANAGER_H__

#include "EQ_MySqlConnector.h"

#include "EQ_DataType.h"

class CDLManager
{
public:
	CDLManager();
	virtual ~CDLManager();

public:
	bool	Open(const char* szDBIP, const short nDBPort, const char* szDBName, const char* szAccount, const char* szPwd);
	bool    Execute(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql);
	bool    CheckRes(MYSQL* &mysql, MYSQL_RES *&res);
	void    FreeRes(MYSQL*mysql, MYSQL_RES *res);
	void    PrintError(MYSQL* mysql);
	void    Close();
public:

	MYSQL* GetMysql();
	MYSQL_RES * GetRes(MYSQL* mysql);
	MYSQL_ROW FetchRow(MYSQL_RES *res);
	int GetRows(MYSQL_RES *res);

	int GetIntValue(MYSQL_ROW  row, int nIndex);
	string GetStringValue(MYSQL_ROW  row, int nIndex);

public:
	bool   Execute(const char* szSql);

public:
	bool	SaveGmData(void* pDBLGGmInfo);
	bool	SaveLoginData(void *pDBLGLoginInfo);
	bool	SaveLogoutData(void *pDBLGLogoutInfo);
	bool	SaveOnlineData(void *pDBLGOnlineInfo);
	bool	SavePvgGiftData(void *pDBLGPvgGiftInfo);
	bool	SavePvpGiftData(void *pDBLGpvpGiftInfo);
	bool	SaveRoomData(void *pDBLGRoomInfo);
	bool	SaveBetData(void *pDBLGBetInfo);
	bool	SaveTraceData(void *pDBLGTraceInfo);

private:
	EQ_MySqlConnector m_DBConnect;
};

#endif//__DL_MANAGER_H__
