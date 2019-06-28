/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** day01
*/

int	my_strlen (char *c)
{
	int	i = 0;

	while (*c++) {
		i = i + 1;
	}
	return (i);
}
