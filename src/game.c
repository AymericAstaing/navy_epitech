/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** game.c
*/

#include	"navy.h"
#include	"utils.h"
#include	"connection.h"

int	end(void)
{
	send_signal(4, 0);
	show_all();
	my_putstr(info[ENEMY_WON]);
	return (0);
}

int	check_end(void)
{
	int	e = 0;
	for (int i = 0; i < 64; i++) {
		if (GAME.server_player.s_boat_position[i] > 0)
			e++;
	}
	if (e == 0)
		return (1);
	return (0);
}

void	display_shoot_result(int result, int pos)
{
	if (result > 1) {
		send_signal(2, pos);
		GAME.server_player.s_boat_position[pos] = -1;
		my_putchar('\n');
		my_putstr(coordinate_to_str(pos));
		my_putstr(info[HIT]);
	} else {
		send_signal(3, pos);
		GAME.server_player.s_boat_position[pos] = -2;
		my_putchar('\n');
		my_putstr(coordinate_to_str(pos));
		my_putstr(info[MISSED]);
	}
}

int	check_hit(int pos)
{
	display_shoot_result(GAME.server_player.s_boat_position[pos], pos);
	GAME.server_player.receive_nbr = -1;
	if (GAME.server_player.first == 1)
		show_all();
	if (check_end() == 1) {
		end();
		return (0);
	}
	attack();
	return (0);
}

void	attack(void)
{
	char	*s;
	int	end = 0;

	my_putstr(info[ATTACK]);
	while (!end) {
		s = get_next_line(0);
		if (my_strlen(s) == 2 && IS_CORRECT_POS(s[0], s[1]) == 1) {
			send_signal(1, str_to_coordinate(s));
			end = SUCCESS;
		} else {
			my_putstr(info[WRONG_POS]);
			attack();
		}
	}
	wait_server();
}
