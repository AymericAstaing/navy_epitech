/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** navy.h
*/

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int	start_server(void);
int	wait_server(void);
int	send_signal(int, int);
int	start_client(void);
void	handler_signal(int, siginfo_t *, void *);

#endif	/*MY_H_*/
