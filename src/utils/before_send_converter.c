/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** before_send_converter.c
*/

#include	<stdio.h>
#include	"utils.h"

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
   
   count = 0;
   pointer = (char*)malloc(32);
   
   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (c = 15 ; c >= 0 ; c--)
   {
      d = n >> c;
     
      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
     
      count++;
   }
   *(pointer+count) = '\0';
   
   return  pointer;
}

char	*before_send_converter(int type, int data)
{
	char	*str = malloc((sizeof(char)) * 16);
	char	*x;
	char	*y;

	x = return_binary(type);
	y = return_binary(data);
	str = my_strcat(x, y);
	return (str);
}
