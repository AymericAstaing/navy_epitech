/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** show.c
*/

#include	"utils.h"
#include	"navy.h"

void	index_board(int num)
{
	my_putchar('\n');
	my_put_nbr(num);
	my_putchar('|');

}

void	show_enemy_grid(void)
{
	int	num = 2;
	int	pos = 0;

	my_putstr(top_board);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (GAME.server_player.e_boat_position[pos] == 0)
				my_putchar('.');
			else if (GAME.server_player.e_boat_position[pos] == 1)
				my_putchar('o');
			else
				my_putchar('x');
			if (IS_SPACE(j) == 1)
				write(1, " ", 1);
			pos++;
			if (j == MAX_LINE_COL && i != 7)
				index_board(num);
		}
		num++;
	}
	my_putchar('\n');
}

void	display_symbol(int pos_state)
{
	if (pos_state == FREE_POS)
		my_putchar('.');
	else if (pos_state == HIT_POS)
		my_putchar('x');
	else if (pos_state == MISSED_POS)
		my_putchar('o');
	else
		my_put_nbr(pos_state);
}

void	show_server_grid(void)
{
	int	num = 2;
	int	pos = 0;

	my_putstr(top_board);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			display_symbol(GAME.server_player.s_boat_position[pos]);
			if (IS_SPACE(j) == 1)
				write(1, " ", 1);
			pos++;
			if (j == 7 && i != 7)
				index_board(num);
		}
		num++;
	}
	my_putchar('\n');
}
