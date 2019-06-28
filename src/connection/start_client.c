/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** start_client.c
*/

#include	<stdlib.h>
#include	"navy.h"
#include	"utils.h"
#include	"connection.h"

int	init_signal_client(void)
{
	struct sigaction act;

	act.sa_sigaction = &handler_signal;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if ((sigaction(SIGUSR1, &act, NULL)) == -1
	|| (sigaction(SIGUSR2, &act, NULL)) == -1)
		return (84);
	return (0);
}

int	init_struct_client(void)
{
	GAME.server_player.server_pid = getpid();
	GAME.server_player.receive_nbr = -1;
	GAME.server_player.receivex = malloc((sizeof(char) * 8));
	GAME.server_player.receivey = malloc((sizeof(char) * 8));
	GAME.server_player.e_boat_position = malloc((sizeof(int)) * 65);
	if (!GAME.server_player.receivex || !GAME.server_player.receivey ||
	!GAME.server_player.e_boat_position)
		return (ERROR);
	return (SUCCESS);
}

int	start_client(void)
{
	init_signal_client();
	init_struct_client();
	send_signal(0, 6);
	my_putstr(info[MY_PID]);
	my_put_nbr(GAME.server_player.server_pid);
	my_putstr(info[SUCCESS_CONCTD]);
	my_putstr(info[MY_POS]);
	show_server_grid();
	my_putstr(info[ENEMY_POS]);
	show_enemy_grid();
	my_putstr(info[WAIT_ENEMY_ATTACK]);
	wait_server();
	return (SUCCESS);
}
