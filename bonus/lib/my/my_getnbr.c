/*
** my_getnbr.c for libmy.a in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct 14 09:19:37 2015 Eric DESCHODT
** Last update Wed Mar 23 12:18:28 2016 Eric DESCHODT
*/

#include "my.h"

int	det_signbis(char *str)
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
int	eval_nbrbis(int sign, char *str)
{
  int	i;
  int	nbr;
  int	pow;

  i = 0;
  nbr = 0;
  pow = 1;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    i++;
  i--;
  while (i >= 0)
    {
      nbr = nbr + (str[i] - 48) * pow;
      pow = pow * 10;
      i--;
    }
  return (nbr * sign);
}

int	my_getnbr(char *str)
{
  int	sign;
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  if (str[0] == 0)
    return (0);
  sign = det_signbis(str);
  while (str[i] == '-' || str[i] == '+')
    str++;
  i = 0;
  return (eval_nbrbis(sign, str));
}
