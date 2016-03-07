/*
** my_memset.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Nov  3 14:16:58 2015 Eric DESCHODT
** Last update Fri Feb 12 13:07:56 2016 Eric DESCHODT
*/

#include "myprintf.h"

void		my_memset(char *str,
			  int size,
			  char c)
{
  int		i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
}
