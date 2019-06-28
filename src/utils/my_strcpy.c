/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01
*/

#include	"navy.h"

char	*my_strcpy(char *dest, char const *src)
{
	int	a = 0;

	while (src[a]) {
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
