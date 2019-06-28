/*
** EPITECH PROJECT, 2017
** Utils
** File description:
** Get number
*/

#include	"navy.h"

int		is_digit(char c)
{
	if (c < '0' || c > '9')
		return (ERROR);
	return (SUCCESS);
}

int		my_getnbr(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int	nb = 0;

	if (str == NULL)
		return (ERROR);
	for (; str[i] && !(is_digit(str[i])); i++)
		sign = sign * (str[i] == LESS_SYMBOL ? -1 : 1);
	while (str[i] && is_digit(str[i])) {
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
