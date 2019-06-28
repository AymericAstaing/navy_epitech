/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** map.c
*/

#include	<sys/stat.h>
#include 	<fcntl.h>
#include 	<unistd.h>
#include 	"navy.h"
#include	"utils.h"

void	show_all(void)
{
	my_putstr(info[MY_POS]);
	show_server_grid();
	my_putstr(info[ENEMY_POS]);
	show_enemy_grid();
}

int	valid_line(char *str)
{
	if (str == NULL || my_strlen(str) != 7)
		return (ERROR);
	if (IS_DIGIT(str[1]))
		write(1, "caca", 4);
	if (!BOAT_NBR(str[0]) || str[1] != SEPARATOR_SYMBOL ||
	str[4] != SEPARATOR_SYMBOL || !IS_LETTER(str[2]) ||
	!IS_DIGIT(str[3]) || !IS_LETTER(str[5]) || !IS_DIGIT(str[6]))
		return (ERROR);
	return (SUCCESS);
}

int	store_data(char *str)
{
	int	res = ((str[3] - 49) * 8);
	int	i1 = str[2] - 64;
	int	nbr = (int)(str[0] - '0');
	int	j = (res + i1) - 1;

	if (str == NULL)
		return (ERROR);
	for (int i = 0; i < nbr; i++) {
		GAME.server_player.s_boat_position[j] = nbr;
		if (str[2] != str[5])
			j = j + 1;
		else
			j = j + 8;
	}
	return (SUCCESS);
}

int	store_positions(char *filepath)
{
	int		fd;
	char		*line;

	if (filepath == NULL)
		return (ERROR);
	GAME.server_player.s_boat_position = malloc((sizeof(int) * 65));
	if (!GAME.server_player.s_boat_position)
		return (ERROR);
	for (int i = 0; i < BOARD_SQUARE_NBR; i++)
		GAME.server_player.s_boat_position[i] = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	while ((line = get_next_line(fd))) {
		if (valid_line(line) == ERROR ||
		store_data(line) == ERROR)
			return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}
