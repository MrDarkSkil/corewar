/*
** my_strlen.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:34:59 2015 Eric DESCHODT
** Last update Wed Mar 23 12:20:38 2016 Eric DESCHODT
*/

#include "my.h"

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
