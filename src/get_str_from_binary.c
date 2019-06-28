/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** get_str_from_binary.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "navy.h"

int	my_power_rec(int nb, int p)
{
	if (p == 0)
		return (1);
	else if (p > 1)
		nb = nb * my_power_rec(nb, p - 1);
	return (nb);
}

int	get_str_from_binary(char *str)
{
	int	n = 7;
	int	new = 0;
	int	power = 0;

	while (n >= 0) {
		if (str[n] == '0') {
			new = new + (my_power_rec(2, power) * 0);
		}
		if (str[n] == '1') {
			new = new + my_power_rec(2, power);
		}
		n--;
		power++;
	}
	return (new);
}
