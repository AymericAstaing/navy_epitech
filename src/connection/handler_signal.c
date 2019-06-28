/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** handler_signal.c
*/

#include	<signal.h>
#include	"navy.h"

void	handler_signal(int sig, siginfo_t *siginfo, void *context)
{
	int	r_n = GAME.server_player.receive_nbr;
	char	sig_nbr = '0';

	(void)context;
	if (sig == SIGUSR2)
		sig_nbr = '1';
	if ((sig == SIGUSR1 || sig == SIGUSR2) && r_n == -1) {
		GAME.server_player.receive_nbr = 1;
		GAME.server_player.receivex[0] = sig_nbr;
	}
	if (r_n > 0) {
		if (r_n < 8)
			GAME.server_player.receivex[r_n - 0] = sig_nbr;
		else
			GAME.server_player.receivey[r_n - 8] = sig_nbr;
		GAME.server_player.receive_nbr = r_n + 1;
		if (GAME.server_player.receive_nbr > 16)
			GAME.server_player.receive_nbr = -1;
	}
	if (GAME.client_player.enemy_pid == 0)
		GAME.client_player.enemy_pid = siginfo->si_pid;
}
