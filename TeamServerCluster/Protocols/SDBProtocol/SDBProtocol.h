#ifndef __SDB_PROTOCOL_H__
#define __SDB_PROTOCOL_H__

// GS<->DB[GameServer<->DBServer]
//Protocol ID:40001-50000 - 1(Base :40000)
enum ESDB_PROTOCOL
{
	ESDB_BEGIN = 40000,
	////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------------------------------------------------------------------------
	//PING HEARTBEAT
	ESDB_PING_S2DB_HEARTBEAT_REQ = ESDB_BEGIN + 1,
	ESDB_PING_DB2S_HEARTBEAT_RES = ESDB_BEGIN + 2,

	//ROLE ACCOUNT
	ESDB_ROLE_S2DB_LOAD_ROLE_ACCOUNT_REQ = ESDB_BEGIN + 3,
	ESDB_ROLE_DB2S_LOAD_ROLE_ACCOUNT_RES = ESDB_BEGIN + 4,

	ESDB_ROLE_S2DB_SAVE_ROLE_ACCOUNT_REQ = ESDB_BEGIN + 5,

	//GIRL

	//----------------------------------------------------------------------------------------------
	//PRIZE POOL
	ESDB_PRIZEPOOL_S2DB_LOAD_PRIZEPOOL_REQ = ESDB_BEGIN + 6,
	ESDB_PRIZEPOOL_DB2S_LOAD_PRIZEPOOL_RES = ESDB_BEGIN + 7,

	ESDB_PRIZEPOOL_S2DB_SAVE_PRIZEPOOL_REQ = ESDB_BEGIN + 8,

	//----------------------------------------------------------------------------------------------
	//TEXASBOARD
	ESDB_TEXASBOARD_S2DB_LOAD_TEXASBOARD_REQ = ESDB_BEGIN + 9,
	ESDB_TEXASBOARD_DB2S_LOAD_TEXASBOARD_RES = ESDB_BEGIN + 10,

	ESDB_TEXASBOARD_S2DB_SAVE_TEXASBOARD_REQ = ESDB_BEGIN + 11,

	//----------------------------------------------------------------------------------------------
	//TEXASHISTORYBOARD
	ESDB_TEXASHISTORYBOARD_S2DB_LOAD_TEXASHISTORYBOARD_REQ = ESDB_BEGIN + 12,
	ESDB_TEXASHISTORYBOARD_DB2S_LOAD_TEXASHISTORYBOARD_RES = ESDB_BEGIN + 13,

	ESDB_TEXASHISTORYBOARD_S2DB_SAVE_TEXASHISTORYBOARD_REQ = ESDB_BEGIN + 14,

	////////////////////////////////////////////////////////////////////////////////////////////////
	ESDB_END = 50000,
};
#endif//__SDB_PROTOCOL_H__