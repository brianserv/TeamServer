#ifndef __SGT_PROTOCOL_H__
#define __SGT_PROTOCOL_H__

//GS<->GT[GameServer<->GateServer]
//Protocol ID:2001-10000-1 (Base :2000)
enum ESGT_PROTOCOL
{
	ESGT_BEGIN = 2000,
	////////////////////////////////////////////////////////////////////////////////////////////////
	//PING HEARTBEAT
	ESGT_PING_GT2S_HEARTBEAT_REQ = ESGT_BEGIN + 1,
	ESGT_PING_S2GT_HEARTBEAT_RES = ESGT_BEGIN + 2,

	ESGT_PING_GT2S_ROLE_DISCONNECT_SYNC = ESGT_BEGIN + 3,
	ESGT_PING_GT2S_GIRL_DISCONNECT_SYNC = ESGT_BEGIN + 4,
	////////////////////////////////////////////////////////////////////////////////////////////////
	ESGT_END = 2100,
};

#endif//__SGT_PROTOCOL_H__