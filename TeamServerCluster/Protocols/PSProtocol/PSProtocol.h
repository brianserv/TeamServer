#ifndef __PS_PROTOCOL_H__
#define __PS_PROTOCOL_H__

//Protocol ID:30001-40000-1(Base :30000)
enum EPS_PROTOCOL
{
	EPS_BEGIN = 30000,
	////////////////////////////////////////////////////////////////////////////////////////////////

	EPS_VIPROOM_P2GT2S_CREATE_REQ = EPS_BEGIN + 1,
	EPS_VIPROOM_P2GT2S_RELEASE_REQ = EPS_BEGIN + 2,
	EPS_VIPROOM_P2GT2S_APPENDCHIP_REQ = EPS_BEGIN + 3,
	////////////////////////////////////////////////////////////////////////////////////////////////
	EPS_END = 40000
};
#endif//__PS_PROTOCOL_H__