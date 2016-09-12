#pragma  once

#ifndef __DB_HALL_ENTITY_MANAGER_H__
#define __DB_HALL_ENTITY_MANAGER_H__

#include "../../../FrameWork/BaseDefine.h"
#include "DBHallEntity.h"

typedef map<int, CDBHallEntity*> DBHallEntityMAP;

class CDBHallEntityManager : public CEQ_SingletonT<CDBHallEntityManager>
{
public:
	CDBHallEntityManager();
	virtual ~CDBHallEntityManager();
public:
	bool Create(CDBHallEntity* pGameHallEntity);
	void Release();
public:
	inline map<int, CDBHallEntity*> & GetDBHallEntityMap() { return m_DBHallEntityMAP; }
private:
	DBHallEntityMAP m_DBHallEntityMAP;
};

#endif//__DB_HALL_ENTITY_MANAGER_H__
