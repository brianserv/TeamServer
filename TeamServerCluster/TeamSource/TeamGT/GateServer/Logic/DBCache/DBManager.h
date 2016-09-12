#pragma once
#ifndef  DB_MANAGER_H
#define  DB_MANAGER_H

#include "EQ_MySqlConnector.h"

#include "EQ_DataType.h"

class CDBManager
{
public:
	CDBManager();
	virtual ~CDBManager();

public:
	bool	Open(const char* szDBIP, const short nDBPort, const char* szDBName, const char* szAccount, const char* szPwd);
	bool    Execute(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql);
	bool    CheckRes(MYSQL* &mysql, MYSQL_RES *&res);
	void    FreeRes(MYSQL* mysql, MYSQL_RES *res);
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
	bool   QueryGirlProperty(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql);
public:
	bool   LoadGirlData();
private:
	EQ_MySqlConnector m_DBConnect;
};

#endif//DB_MANAGER_H
