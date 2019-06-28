/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** task02
*/

#include	<unistd.h>
#include	"../include/navy.h"

void	my_putstr(char const *str)
{
	int	u = 0;

	for (int i = 0; str[i]; i++)
		u++;
	write(1, str, u);
}
