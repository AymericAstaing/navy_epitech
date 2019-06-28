/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** CPE_matchstick_2017
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"navy.h"

char	*my_realloc_str(char *str, int size)
{
	int	str_size = 0;
	char	*new_str = NULL;

	if (str == NULL)
		return (malloc(size));
	for (int i = 0; str[i]; i++)
		str_size++;
	if (size <= str_size)
		return (NULL);
	new_str = malloc((sizeof(char)) * size);
	new_str = str;
	return (new_str);
}

char	get_char(const int fd)
{
	static char	buff[READ_SIZE];
	static char	*str_buff;
	char		c;
	static int	l = 0;

	if (l == 0) {
		l = read(fd, buff, READ_SIZE);
		str_buff = (char*)&buff;
		if (l == 0)
			return (0);
	}
	c = *str_buff;
	str_buff++;
	l--;
	return (c);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*str = malloc(READ_SIZE + 1);
	int	l = 0;

	if (str == NULL)
		return (0);
	c = get_char(fd);
	while (c != '\n' && c != '\0') {
		str[l] = c;
		c = get_char(fd);
		l++;
		if (l % (READ_SIZE + 1) == 0)
			str = my_realloc_str(str, l + READ_SIZE + 1);
	}
	str[l] = 0;
	if (c == 0 && str[0] == 0)
		return (0);
	return (str);
}
