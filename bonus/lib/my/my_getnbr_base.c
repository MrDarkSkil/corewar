/*
** my_getnbr_base.c for libmy.a in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct 14 09:14:12 2015 Eric DESCHODT
** Last update Wed Mar 23 12:18:14 2016 Eric DESCHODT
*/

#include "my.h"

int	det_sign(char *str)
{
  char	sign;
  int	i;

  i = 1;
  if (str[0] == '+')
    sign = '+';
  else if (str[0] == '-')
    sign = '-';
  else
    return (1);
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == sign)
	sign = '+';
      else
	sign = '-';
      i++;
    }
  if (sign == '+')
    return (1);
  else
    return (-1);
}

int	check_str(char *str, char *base)
{
  int	i;
  int	j;

  j = 0;
  while (base[j + 1] != '\0')
    {
      i = j + 1;
      while(base[j] != base[i] && base[i] != '\0')
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

int	eval_nbr(int sign, char *str, char *base)
{
  int	i;
  int	nbr;
  int	pow;
  int	fix;

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
  return (nbr * sign);
}

int	my_getnbr_base(char *str, char *base)
{
  int	sign;
  int	i;

  i = 0;
  if (str[0] == 0 || base[0] == 0)
    return (0);
  sign = det_sign(str);
  while (str[i] == '-' || str[i] == '+')
    str++;
  if (check_str(str, base) == 0)
    return (eval_nbr(sign, str, base));
  else
    return (0);
}
