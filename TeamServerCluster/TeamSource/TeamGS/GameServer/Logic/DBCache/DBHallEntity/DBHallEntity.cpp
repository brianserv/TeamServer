#include  "DBHallEntity.h"

EQ_IMPLEMENT_CACHE(CDBHallEntity, 100)
CDBHallEntity::CDBHallEntity()
{
}

CDBHallEntity::~CDBHallEntity()
{
}

void  CDBHallEntity::SetProperty(
	const int hall_server_id,
	const string hall_server_name,
	const int  hall_room_id,
	const int  hall_room_class,
	const int hall_room_type,
	const string hall_room_name,
	const int hall_room_game_id,
	const int hall_room_game_type,
	const string hall_room_game_name,
	const int hall_room_create_time)
{
	set_hall_server_id(hall_server_id);
	set_hall_server_name(hall_server_name);
	set_hall_room_id(hall_room_id);
	set_hall_room_class(hall_room_class);
	set_hall_room_type(hall_room_type);
	set_hall_room_name(hall_room_name);
	set_hall_room_game_id(hall_room_game_id);
	set_hall_room_game_type(hall_room_game_type);
	set_hall_room_game_name(hall_room_game_name);
	set_hall_room_create_time(hall_room_create_time);
}