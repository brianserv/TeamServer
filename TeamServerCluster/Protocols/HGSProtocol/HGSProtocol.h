#ifndef __HGS_PROTOCOL_H__
#define __HGS_PROTOCOL_H__

//HS - GS
//Protocol ID:[2500-5000](Base :2500)
enum EHGS_PROTOCOL
{
	EHGS_BEGIN = 2500,
	////////////////////////////////////////////////////////////////////////////////////////////////
	//PING HEARTBEAT
	EHGS_PING_H2GS_HEARTBEAT_REQ = EHGS_BEGIN + 1,
	EHGS_PING_GS2H_HEARTBEAT_RES = EHGS_BEGIN + 2,

	////////////////////////////////////////////////////////////////////////////////////////////////
	EHGS_END = 5000,
};

#endif//__HGS_PROTOCOL_H__
