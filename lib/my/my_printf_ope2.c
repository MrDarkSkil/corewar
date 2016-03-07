/*
** my_printf_ope2.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf/lib/my
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Nov 12 12:15:35 2015 Eric DESCHODT
** Last update Fri Feb 12 13:12:02 2016 Eric DESCHODT
*/
#include "myprintf.h"

void		printf_unddec(va_list *pa)
{
  unsigned int	nbr;

  nbr = va_arg(*pa, unsigned int);
  my_put_nbr_base(nbr, "0123456789");
}

void            printf_float(t_format_id *stock, va_list *pa)
{
  double        nbr;
  int		sign;


  nbr = va_arg(*pa, double);
  if (stock->flag_blank == 1)
    sign = ' ';
  if (stock->flag_plus == 1)
    sign = '+';
  if (nbr > 0 && sign != 0)
    my_putchar(sign);
  if (stock->max_field == -1)
    my_put_float(nbr, 6);
  else
    my_put_float(nbr, stock->max_field);
}
