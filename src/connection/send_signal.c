/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** send_signal.c
*/

#include	<signal.h>
#include 	"navy.h"
#include	"utils.h"

int	step_send(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == '0')
			kill(GAME.client_player.enemy_pid, SIGUSR1);
		else if (str[i] == '1')
			kill(GAME.client_player.enemy_pid, SIGUSR2);
		usleep(100);
	}
	return (0);
}

int	send_signal(int x, int y)
{
	char	*str = malloc((sizeof(char)) * 16);
	if (!str)
		return (ERROR);
	str = before_send_converter(x, y);
	step_send(str);
	return (SUCCESS);
}
