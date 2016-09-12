#pragma  once

#ifndef _DB_HALL_ENTITY_H__
#define _DB_HALL_ENTITY_H__

#include "../../../FrameWork/BaseDefine.h"

class CDBHallEntity
{
public:
	CDBHallEntity();
	virtual ~CDBHallEntity();
	EQ_DECLARE_CACHE(CDBHallEntity)
public:
	inline void    set_hall_server_id(const int hall_server_id) { m_hall_server_id = hall_server_id; };
	inline void    set_hall_server_name(const string hall_server_name) { m_hall_server_name = hall_server_name; };
	inline void    set_hall_room_id(const int hall_room_id) { m_hall_room_id = hall_room_id; };
	inline void    set_hall_room_class(const int hall_room_class) { m_hall_room_class = hall_room_class; };
	inline void    set_hall_room_type(const int hall_room_type) { m_hall_room_type = hall_room_type; };
	inline void    set_hall_room_name(const string hall_room_name) { m_hall_room_name = hall_room_name; };
	inline void    set_hall_room_game_id(const int hall_room_game_id) { m_hall_room_game_id = hall_room_game_id; };
	inline void    set_hall_room_game_type(const int hall_room_game_type) { m_hall_room_game_type = hall_room_game_type; };
	inline void    set_hall_room_game_name(const string hall_room_game_name) { m_hall_room_game_name = hall_room_game_name; };
	inline void    set_hall_room_create_time(const int hall_room_create_time) { m_hall_room_create_time = hall_room_create_time; };

	inline int     get_hall_server_id() const { return m_hall_server_id; };
	inline string  get_hall_server_name() const { return m_hall_server_name; };
	inline int     get_hall_room_id() const { return m_hall_room_id; };
	inline int     get_hall_room_class() const { return m_hall_room_class; };
	inline int     get_hall_room_type() const { return m_hall_room_type; };
	inline string  get_hall_room_name() const { return m_hall_room_name; };
	inline int     get_hall_room_game_id() const { return m_hall_room_game_id; };
	inline int     get_hall_room_game_type() const { return m_hall_room_game_type; };
	inline string  get_hall_room_game_name() const { return m_hall_room_game_name; };
	inline int     get_hall_room_create_time() const { return m_hall_room_create_time; };
public:
	void   SetProperty(
		const int hall_server_id,
		const string hall_server_name,
		const int  hall_room_id,
		const int  hall_room_class,
		const int hall_room_type,
		const string hall_room_name,
		const int hall_room_game_id,
		const int hall_room_game_type,
		const string hall_room_game_name,
		const int hall_room_create_time);

private:
	int m_hall_server_id;
	string m_hall_server_name;
	int  m_hall_room_id;
	int  m_hall_room_class;
	int m_hall_room_type;
	string m_hall_room_name;
	int m_hall_room_game_id;
	int m_hall_room_game_type;
	string m_hall_room_game_name;
	int m_hall_room_create_time;
};

#endif//_DB_HALL_ENTITY_H__
