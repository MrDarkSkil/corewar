/*
** my_put_nbr_base.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_corewar
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Mar 23 12:34:37 2016 Eric DESCHODT
** Last update Wed Mar 23 12:34:39 2016 Eric DESCHODT
*/

#include "my.h"

void		aff_nbr_base(unsigned int nbr,
			     int pow,
			     char *base)
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
