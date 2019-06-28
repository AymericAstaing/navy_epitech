/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** wait_server.c
*/

#include	"navy.h"
#include	"utils.h"
#include	"connection.h"

void	display_action_info(int state, int pos)
{
	if (state == 2) {
		GAME.server_player.e_boat_position[pos] = 2;
		my_putstr(info[HIT]);
	} else {
		GAME.server_player.e_boat_position[pos] = 1;
		my_putstr(info[MISSED]);
	}
	if (GAME.server_player.first != 1) {
		my_putstr(info[MY_POS]);
		show_server_grid();
		my_putstr(info[ENEMY_POS]);
		show_enemy_grid();
	}
	my_putstr(info[WAIT_ENEMY_ATTACK]);
}

int	action_signal(int type, int pos)
{
	if (type == 1) {
		check_hit(pos);
	} else if (IS_SHOT(type) == 1) {
		GAME.server_player.receive_nbr = -1;
		my_putstr(coordinate_to_str(pos));
		display_action_info(type, pos);
		wait_server();
	} else {
		show_all();
		my_putstr("\n\nI won\n");
	}
	return (SUCCESS);
}

int	wait_server(void)
{
	int	x = 0;
	int	y = 0;

	while (GAME.server_player.receive_nbr != MESSAGE_RECEIVED);
	x = get_str_from_binary(GAME.server_player.receivex);
	y = get_str_from_binary(GAME.server_player.receivey);
	if (x == HELLO_SIGNAL)
		return (SUCCESS);
	action_signal(x, y);
	return (SUCCESS);
}
