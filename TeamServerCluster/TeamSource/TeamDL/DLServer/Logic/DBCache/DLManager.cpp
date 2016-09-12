#include "DLManager.h"
#include "../../FrameWork/BaseDefine.h"

CDLManager::CDLManager()
{
}

CDLManager::~CDLManager()
{
}

bool  CDLManager::Open(const char* szDBIP, const short nDBPort, const char* szDBName, const char* szAccount, const char* szPwd)
{
	return g_dbEngine.Open(szDBIP, nDBPort, szDBName, szAccount, szPwd);
}

bool CDLManager::Execute(MYSQL* &mysql, MYSQL_RES *&res, const char* szSql)
{
	return g_dbEngine.Execute(mysql, res, szSql);
}

MYSQL* CDLManager::GetMysql()
{
	return g_dbEngine.GetMysql();
}

MYSQL_RES* CDLManager::GetRes(MYSQL* mysql)
{
	return g_dbEngine.GetRes(mysql);
}

MYSQL_ROW CDLManager::FetchRow(MYSQL_RES *res)
{
	return g_dbEngine.FetchRow(res);
}

bool CDLManager::CheckRes(MYSQL* &mysql, MYSQL_RES *&res)
{
	return g_dbEngine.CheckRes(mysql, res);
}

int CDLManager::GetRows(MYSQL_RES *res)
{
	return g_dbEngine.GetRows(res);
}

void CDLManager::FreeRes(MYSQL* mysql, MYSQL_RES *res)
{
	g_dbEngine.FreeRes(mysql, res);
}

void CDLManager::PrintError(MYSQL* mysql)
{
	g_dbEngine.PrintError(mysql);
}
void CDLManager::Close()
{
	g_dbEngine.Close();
}

bool  CDLManager::Execute(const char* szSql)
{
	return g_dbEngine.Execute(szSql);
}

int CDLManager::GetIntValue(MYSQL_ROW row, int nIndex)
{
	return g_dbEngine.GetIntValue(row, nIndex);
}

string CDLManager::GetStringValue(MYSQL_ROW  row, int nIndex)
{
	return g_dbEngine.GetStringValue(row, nIndex);
}