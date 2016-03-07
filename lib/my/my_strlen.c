/*
** my_strlen.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:34:59 2015 Eric DESCHODT
** Last update Fri Feb 19 14:50:49 2016 Eric DESCHODT
*/

#include "myprintf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	i++;
    }
  return (i);
}
