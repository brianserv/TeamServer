#include "DBManager.h"
#include "../../FrameWork/BaseDefine.h"

CDBManager::CDBManager()
{
}

CDBManager::~CDBManager()
{
}

bool  CDBManager::Open(const char* szDBIP, const short nDBPort, const char* szDBName, const char* szAccount, const char* szPwd)
{
	return g_dbEngine.Open(szDBIP, nDBPort, szDBName, szAccount, szPwd);
}

bool CDBManager::Execute(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
{
	return g_dbEngine.Execute(mysql, res, szSql);
}

MYSQL* CDBManager::GetMysql()
{
	return g_dbEngine.GetMysql();
}

MYSQL_RES* CDBManager::GetRes(MYSQL* mysql)
{
	return g_dbEngine.GetRes(mysql);
}

MYSQL_ROW CDBManager::FetchRow(MYSQL_RES *res)
{
	return g_dbEngine.FetchRow(res);
}

bool CDBManager::CheckRes(MYSQL* &mysql, MYSQL_RES *&res)
{
	return g_dbEngine.CheckRes(mysql, res);
}

int CDBManager::GetRows(MYSQL_RES *res)
{
	return g_dbEngine.GetRows(res);
}

void CDBManager::FreeRes(MYSQL* mysql, MYSQL_RES *res)
{
	g_dbEngine.FreeRes(mysql, res);
}

void CDBManager::PrintError(MYSQL* mysql)
{
	g_dbEngine.PrintError(mysql);
}
void CDBManager::Close()
{
	g_dbEngine.Close();
}

bool  CDBManager::Execute(const char* szSql)
{
	return g_dbEngine.Execute(szSql);
}

int CDBManager::GetIntValue(MYSQL_ROW row, int nIndex)
{
	return g_dbEngine.GetIntValue(row, nIndex);
}

string CDBManager::GetStringValue(MYSQL_ROW  row, int nIndex)
{
	return g_dbEngine.GetStringValue(row, nIndex);
}