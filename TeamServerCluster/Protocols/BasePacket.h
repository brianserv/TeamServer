#pragma once
#ifndef __PROTOCOLS_BASEPACKET_H__
#define __PROTOCOLS_BASEPACKET_H__

#include "EQ_DataType.h"

#pragma pack(1)

typedef struct  tagPacketHead
{
	tagPacketHead() :nCmd(0), nSize(0), nReserv(0) {}

	void SetIndex(int nIndex)
	{
		nReserv = nIndex;
	};

	int GetIndex()
	{
		return nReserv;
	};

	int GetLength()
	{
		int nLength = nSize + 8;

		return nLength;
	};

	int GetHeadLength()
	{
		int nHeadSize = sizeof(tagPacketHead);

		int nHeadLength = nHeadSize - 8;

		return nHeadLength;
	}

	void SetPacketHead(int nProtocolID)
	{
		nCmd = nProtocolID;
		nSize = GetLength();
	}

	int nCmd;
	int nSize;
	int nReserv;
}PACKETHEAD, *PPACKETHEAD;

#pragma pack()

#endif//__PROTOCOLS_BASEPACKET_H__
