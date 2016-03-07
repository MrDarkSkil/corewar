/*
** my_put_nbr_base.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf/lib/my
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Nov 12 09:19:45 2015 Eric DESCHODT
** Last update Fri Feb 12 13:12:21 2016 Eric DESCHODT
*/

#include "myprintf.h"

void		aff_nbr_base(unsigned int nbr, int pow, char *base)
{
  if (nbr > 0)
    {
      aff_nbr_base(nbr / pow, pow, base);
      my_putchar(base[nbr % pow]);
    }
}

void		my_put_nbr_base(unsigned int nbr, char *base)
{
  int		baselen;

  baselen = my_strlen(base);
  if (nbr == 0)
    my_putchar(base[0]);
  aff_nbr_base(nbr, baselen, base);
}
