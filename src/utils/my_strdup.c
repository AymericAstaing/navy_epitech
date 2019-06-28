/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** minishell1
*/

#include	"navy.h"
#include	"utils.h"
#include	<stdlib.h>

char	*my_strdup(char *str)
{
	char	*s;

	if ((s = malloc(my_strlen(str))) == 0) {
		return (0);
	}
	my_strcpy(s, str);
	return (s);
}
