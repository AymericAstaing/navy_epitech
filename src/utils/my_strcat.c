/*
** EPITECH PROJECT, 2018
** rb_strcat.c
** File description:
** day03
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"navy.h"

char	*my_strcat(char *dest, char *src)
{
	int	k = 0;
	int	end = 0;
	if (dest == NULL || src == NULL) {
		write(2,  "Error: rb_strcat: dest has a NULL value\n", 40);
		return (NULL);
	}
	for (int i = 0; dest[i] != '\0'; i++)
		k++;
	for (int j = 0; src[j] != '\0'; j++) {
		dest[k] = src[j];
		k++;
		end = k;
	}
	dest[end] = '\0';
	return (dest);
}
