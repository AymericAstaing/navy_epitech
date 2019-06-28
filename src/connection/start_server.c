/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** start_server.c
*/

#include	"navy.h"
#include	"utils.h"
#include	"connection.h"

int	init_signal(void)
{
	struct sigaction	act;

	act.sa_sigaction = &handler_signal;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if ((sigaction(SIGUSR1, &act, NULL)) == -1
	|| (sigaction(SIGUSR2, &act, NULL)) == -1)
		return (ERROR);
	return (SUCCESS);
}

int	init_struct(void)
{
	GAME.server_player.server_pid = getpid();
	GAME.server_player.receive_nbr = -1;
	GAME.client_player.enemy_pid = 0;
	GAME.server_player.first = 1;
	GAME.server_player.receivex = malloc((sizeof(char)) * 8);
	GAME.server_player.receivey = malloc((sizeof(char)) * 8);
	GAME.server_player.e_boat_position = malloc((sizeof(int)) * 65);
	if (!GAME.server_player.receivex || !GAME.server_player.receivey ||
	!GAME.server_player.e_boat_position)
		return (ERROR);
	return (SUCCESS);
}

void	display_info(int state)
{
	if (state == WAITING) {
		my_putstr(info[MY_PID]);
		my_put_nbr(GAME.server_player.server_pid);
		my_putstr(info[WAITING_ENEMY]);
	} else if (state == CONNECTED) {
		my_putstr(info[ENEMY_CONCTD]);
		my_putstr(info[MY_POS]);
		show_server_grid();
		my_putstr(info[ENEMY_POS]);
		show_enemy_grid();
		GAME.server_player.receive_nbr = -1;
	}
}

int	start_server(void)
{
	if (!init_signal() || !init_struct())
		return (ERROR);
	display_info(WAITING);
	if (wait_server() == CONNECTED) {
		display_info(CONNECTED);
		attack();
	}
	return (SUCCESS);
}
