/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** navy.h
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char	*my_strcpy(char *, char const *);
char	*my_strcat(char *, char *);
int	my_strlen (char *);
void	my_putchar(char);
char	*before_send_converter(int, int);
char	*coordinate_to_str(int);
void	my_putstr(char const *);
char	*return_binary(char);
int	my_put_nbr(int);
char	*my_strdup(char *);
char	*my_int_to_str(int);
int	str_to_coordinate(char*);
int	my_getnbr(const char *);

#endif	/*MY_H_*/
