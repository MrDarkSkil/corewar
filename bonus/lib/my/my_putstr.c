/*
** my_putstr.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:32:59 2015 Eric DESCHODT
** Last update Wed Mar 23 12:20:18 2016 Eric DESCHODT
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  if (str != NULL)
    {
      i = 0;
      while (str[i] != 0)
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
  return (0);
}
