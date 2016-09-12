/*
 * EQ_MySqlConnector.h
 *
 *  Created on: May 28, 2015
 *      Author: kspines
 */

#ifndef EQ_MYSQLCONNECTOR_H_
#define EQ_MYSQLCONNECTOR_H_


#include "mysql.h"

#include "EQUtils.h"

class EQ_MySqlConnector
{
public:
	EQ_MySqlConnector();
	virtual ~EQ_MySqlConnector();

public:
	static MYSQL* Init(MYSQL* pConnect);
	static MYSQL* Connect(MYSQL* pConnect,const char* szDBIP,const short nDBPort,const char* szDBName,
		const char* szAccount,const char* szPwd);
	static int GetProtocolInfo(MYSQL* pConnect);

	static const char* GetState(MYSQL* pConnect);
	static const char* GetServerInfo(MYSQL* pConnect);
	static const char* GetHostInfo(MYSQL* pConnect);
	static const char* GetClientInfo(MYSQL* pConnect);
	static const char* GetOutErrors(MYSQL* pConnect);

public:
	int	Open(const char* szDBIP,const short nDBPort,const char* szDBName, const char* szAccount,
		const char* szPwd);

	const bool PingMysql(MYSQL* pConnect,unsigned int nCurTime);
	void    GetMysqlLastError(int & nRetValue,string & strError);

public:
	MYSQL*  GetConnectObj(){ return &m_connect; };
	void    Close(){ mysql_close(&m_connect); };

private:
	MYSQL	       m_connect;
	string         m_strError;
	int            m_nRetValue;
};

#endif /* EQ_MYSQLCONNECTOR_H_ */
