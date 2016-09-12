#include "DBTexasBoard.h"

EQ_IMPLEMENT_CACHE(CDBTexasBoardInfo, 100)

CDBTexasBoardInfo::CDBTexasBoardInfo()
{
}

CDBTexasBoardInfo::~CDBTexasBoardInfo()
{
}

void CDBTexasBoardInfo::SetTexasBoardProperty(
	int board_id,
	int	board_girl_id,
	string board_card,
	string board_showcard,
	int	board_server_id,
	int	board_game_id,
	int	board_room_id,
	int	board_sum_chip,
	int	board_rewardjackpot_type,
	int	board_rewardbonus_type,
	int	board_card_type,
	int	board_dealcard_type,
	int	board_result,
	int	board_end_status,
	int	board_start_time,
	int	board_end_time)
{
	set_board_id(board_id);
	set_board_girl_id(board_girl_id);
	set_board_card(board_card);
	set_board_showcard(board_showcard);
	set_board_server_id(board_server_id);
	set_board_game_id(board_game_id);
	set_board_room_id(board_room_id);
	set_board_sum_chip(board_sum_chip);
	set_board_rewardjackpot_type(board_rewardjackpot_type);
	set_board_rewardbonus_type(board_rewardbonus_type);
	set_board_card_type(board_card_type);
	set_board_dealcard_type(board_dealcard_type);
	set_board_result(board_result);
	set_board_end_status(board_end_status);
	set_board_start_time(board_start_time);
	set_board_end_time(board_end_time);
}