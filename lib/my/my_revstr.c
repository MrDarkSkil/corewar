/*
** my_revstr.c for libmy.a in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct 14 09:27:08 2015 Eric DESCHODT
** Last update Wed Mar 23 12:20:29 2016 Eric DESCHODT
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	tmp;

  i = 0;
  j = 0;
  while (str[j] != 0)
    j++;
  j--;
  while (i < j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
    }
  return (str);
}
