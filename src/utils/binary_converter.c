/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** return_binaire.c
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"utils.h"

char	*my_add_to_str(char *str1, char *str2)
{
	char	*strcopie;
	int	s1;
	int	s2;
	int	n;
	int	i;

	n = 0;
	i = 0;
	s1 = my_strlen(str1);
	s2 = my_strlen(str2);
	if ((strcopie = malloc(sizeof(char) * (s1 + s2) + 2)) == NULL)
		return (NULL);
	while (str1[i] != '\0')
		strcopie[n++] = str1[i++];
	i = 0;
	while (str2[i] != '\0')
		strcopie[n++] = str2[i++];
	strcopie[n] = '\0';
	return (strcopie);
}

char	*my_get_nbr_base(int nb, char *base)
{
	char	*binaire;
	int	n;
	int	result;
	int	diviseur;
	int	size_base;

	n = 0;
	diviseur = 1;
	binaire = malloc(sizeof(char) * 8);
	size_base = my_strlen(base);
	if (nb < 0)
		nb = -nb;
	while ((nb / diviseur) >= size_base)
		diviseur = diviseur * size_base;
	while (diviseur > 0) {
		result = (nb / diviseur) % size_base;
		binaire[n++] = base[result];
		diviseur = diviseur / size_base;
	}
	binaire[n] = '\0';
	return (binaire);
}

char	*format_binary(char *binary)
{
	int	i = my_strlen(binary);
	char	*save;
	int	n;
	int	compt = 0;

	n = 8 - i;
	save = malloc(sizeof(char) * n + 1);
	if (i < 8) {
		while (compt < n) {
			save[compt++] = '0';
		}
	}
	return (save);
}

char	*return_binary(char nb)
{
	char	base[] = "01";
	char	*str1;
	char	*str2;
	char	*final;
	int	i;

	str2 = NULL;
	str1 = my_get_nbr_base(nb, base);
	str2 = format_binary(str1);
	i = my_strlen(str2);
	str2[i] = '\0';
	final = my_add_to_str(str2, str1);
	return (final);
}
