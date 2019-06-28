/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** my_int_to_str.c
*/

#include	<stdlib.h>

char	*my_int_to_str(int i)
{
	char const	digit[] = "0123456789";
	char	*str = malloc((sizeof(char)) * 16);
	int	shifter;
	if (i < 0) {
		*str++ = '-';
		i *= -1;
	}
	shifter = i;
	do {
		++str;
		shifter = shifter / 10;
	}
	while (shifter);
	*str = '\0';
	do {
		*--str = digit[i % 10];
		i = i / 10;
	}
	while (i);
	return (str);
}
