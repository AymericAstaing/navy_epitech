/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** main.c
*/

#include	"navy.h"
#include	"utils.h"
#include	"connection.h"

int	display_help(char *arg)
{
	int	i = 0;

	if (arg == NULL || my_strlen(arg) != 2)
		return (ERROR);
	if (arg[0] == 45 && arg[1] == 104) {
		i = 1;
		my_putstr(help);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc <= 1 || argc > 3)
		return (EXIT_FAILURE);
	if (display_help(argv[1]) == SUCCESS)
			return (EXIT_SUCCESS);
	if (argc == IS_SERVER) {
		if (store_positions(argv[1]) == ERROR)
			return (ERROR);
		if (start_server() == ERROR)
			return (C_EXIT_ERROR);
	} else if (argc == IS_CLIENT) {
		if (store_positions(argv[2]) == ERROR)
			return (ERROR);
		GAME.client_player.enemy_pid = my_getnbr(argv[1]);
		if (start_client() == ERROR)
			return (C_EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}
