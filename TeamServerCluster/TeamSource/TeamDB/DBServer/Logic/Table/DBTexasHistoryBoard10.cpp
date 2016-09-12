#include "DBTexasHistoryBoard10.h"

EQ_IMPLEMENT_CACHE(CDBTexasHistoryBoard10Info, 100)

CDBTexasHistoryBoard10Info::CDBTexasHistoryBoard10Info()
{
	m_bIsUpdata = false;
}
CDBTexasHistoryBoard10Info::~CDBTexasHistoryBoard10Info()
{
	m_bIsUpdata = false;
}

void CDBTexasHistoryBoard10Info::setDBTexasHistoryBoard10InfoProperty(
	int		board10_game_id,
	int		board10_room_id,
	int		board10_server_id,
	string	board10_result_detail,
	int		board10_board_count)
{
	set_board10_game_id(board10_game_id);
	set_board10_room_id(board10_room_id);
	set_board10_server_id(board10_server_id);
	set_board10_result_detail(board10_result_detail);
	set_board10_board_count(board10_board_count);
}