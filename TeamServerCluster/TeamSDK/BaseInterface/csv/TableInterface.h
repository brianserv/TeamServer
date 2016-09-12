#pragma once
#ifndef __TABLE_INTERFACE_H__
#define __TABLE_INTERFACE_H__

#include "../../FrameWork/BaseDefine.h"

#include <limits>
#include "TableGame.h"

#define MAX_ROW_ARRAY_COUNT 10


class IRowElement
{
public:
	IRowElement(){};
	virtual ~IRowElement(){};

    virtual void Clear() = 0;
	virtual bool Load(CATTableLine & line) = 0;
};

#endif//__TABLE_INTERFACE_H__
