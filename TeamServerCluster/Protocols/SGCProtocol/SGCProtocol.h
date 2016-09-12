#ifndef __SGC_PROTOCOL_H__
#define __SGC_PROTOCOL_H__

//GS<->GC[GameServer<->CenterServer]
//Protocol ID:1-2000-1 (Base :0)
enum ESGC_PROTOCOL
{
	ESGC_BEGIN = 0,
	////////////////////////////////////////////////////////////////////////////////////////////////
	ESGC_PING_S2GC_HEARTBEAT_REQ = ESGC_BEGIN + 1,

	ESGC_PING_GC2S_HEARTBEAT_RES = ESGC_BEGIN + 2,

	ESGC_PING_S2GC_REGISTER_REQ = ESGC_BEGIN + 3,

	ESGC_PING_GC2S_REGISTER_RES = ESGC_BEGIN + 4,

	ESGC_STATICS_S2GC_ONLINE_SYNC = ESGC_BEGIN + 5,
	////////////////////////////////////////////////////////////////////////////////////////////////
	ESGC_END = 2000,
};

#endif//__SGC_PROTOCOL_H__
