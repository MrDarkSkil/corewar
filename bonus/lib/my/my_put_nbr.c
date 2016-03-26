/*
** my_put_nbr.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:28:57 2015 Eric DESCHODT
** Last update Wed Mar 23 12:20:07 2016 Eric DESCHODT
*/

#include "my.h"

void	aff_nbr(int nbr, int pow)
{
  if (nbr > 0)
    {
      aff_nbr(nbr / pow, pow);
      my_putchar(nbr % pow + 48);
    }
}

int	my_put_nbr(int nbr)
{
  int	execpt;

  execpt = 0;
  if (nbr == -2147483648)
    {
      nbr = nbr + 1;
      execpt = 1;
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  if (nbr == 0)
    {
      my_putchar('0');
      return (0);
    }
  aff_nbr(nbr, 10);
  if (execpt == 1)
    {
      my_putchar('\b');
      my_putchar((nbr % 10) + 49);
    }
  return (0);
}
