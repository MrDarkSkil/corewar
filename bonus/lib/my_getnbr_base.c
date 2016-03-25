/*
** my_getnbr_base.c for libmy.a in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct 14 09:14:12 2015 Eric DESCHODT
** Last update Mon Feb 29 09:35:13 2016 Eric DESCHODT
*/

#include "libgraph.h"

int	check_str(char *str, char *base)
{
  int	i;
  int	j;

  j = 0;
  while (base[j + 1] != '\0')
    {
      i = j + 1;
      while (base[j] != base[i] && base[i] != '\0')
	i++;
      if (base[i] != 0)
	return (1);
      j++;
    }
  j = 0;
  while(str[j] != '\0')
    {
      i = 0;
	while (base[i] != '\0' && str[j] != base[i])
	  i++;
	if (base[i] == '\0')
	  return (1);
	j++;
      }
  return (0);
}

int	find_base(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != c)
    i++;
  return (i);
}

unsigned int	eval_nbr(char *str, char *base)
{
  int		i;
  unsigned int	nbr;
  int		pow;
  int		fix;

  i = 0;
  while (base[i] != '\0')
    i++;
  fix = i;
  i = 0;
  nbr = 0;
  pow = 1;
  while (str[i] != '\0')
    i++;
  i--;
  while (i >= 0)
    {
      nbr = nbr + (find_base(str[i], base)) * pow;
      pow = pow * fix;
      i--;
    }
  return (nbr);
}

unsigned int	my_getnbr_base(char *str, char *base)
{
  if (str == NULL)
    return (0);
  if (str[0] == 0 || base[0] == 0)
    return (0);
  if (check_str(str, base) == 0)
    return (eval_nbr(str, base));
  else
    return (0);
}
