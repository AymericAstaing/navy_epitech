/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** PSU_minishell1_2018
*/

#include	<unistd.h>
#include	"navy.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}
