/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** coordinate.c
*/

#include 	"navy.h"
#include	"utils.h"

char	itc(int n)
{
	return (n + 48);
}

int	str_to_coordinate(char *str)
{
	return (((((int)(str[1] - '0')) - 1) * 8) + (str[0] - 65));
}

char	*coordinate_to_str(int	coordinate)
{
	int	nbr_line = 0;
	int	step = 8;
	char	letter;
	char	*coor = malloc(sizeof(char) * 2);

	if (coordinate == 0)
		return ("A1");
	nbr_line = coordinate / 8;
	step = nbr_line * 8;
	letter = ((coordinate - step) + 65);
	coor[0] = letter;
	return (my_strcat(coor, my_int_to_str(nbr_line + 1)));
}
