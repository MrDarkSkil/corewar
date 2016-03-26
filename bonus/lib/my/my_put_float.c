/*
** my_put_float.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_corewar
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Mar 23 12:34:53 2016 Eric DESCHODT
** Last update Wed Mar 23 12:34:54 2016 Eric DESCHODT
*/

#include "my.h"

void		my_put_float(long double nb, int size)
{
  int		i;

  i = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  while (nb > 1)
    nb = nb * 0.1 + (i++ * 0);
  while (i > 0)
    {
      nb = nb * 10;
      my_putchar((int)nb + '0');
      nb = nb - (int)nb + (i-- * 0);
    }
  i = 0;
  my_putchar('.');
  while (i < size)
    {
      nb = nb * 10;
      my_putchar((int)nb + '0');
      nb = nb - (int)nb;
      i++;
    }
}
