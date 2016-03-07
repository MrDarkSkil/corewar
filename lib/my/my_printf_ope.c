/*
** my_printf.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Nov  2 14:52:58 2015 Eric DESCHODT
** Last update Wed Feb 17 09:16:03 2016 Eric DESCHODT
*/

#include "myprintf.h"

void		printf_decimal(t_format_id *stock,
			       va_list *pa)
{
  int		nbr;
  int		size;
  int		i;
  int		tmp;
  char		*str_nbr;
  char		sign;

  sign = 0;
  nbr = va_arg(*pa, int);
  tmp = nbr;
  i = 0;
  while (tmp != 0)
    tmp = tmp / 10 + (i++ * 0);
  size = i;
  str_nbr = int_in_str(nbr, size);
  if (stock->flag_blank == 1)
    sign = ' ';
  if (stock->flag_plus == 1)
    sign = '+';
  if (nbr > 0 && sign != 0)
    my_putchar(sign);
  if (nbr == 0)
    my_putchar('0');
  my_putstr(str_nbr);
  free(str_nbr);
}

void		printf_octal(t_format_id *stock, va_list *pa)
{
  unsigned int  nbr;

  nbr = va_arg(*pa, unsigned int);
  if (stock->flag_hashtag == 1)
    my_putstr("0");
  my_put_nbr_base(nbr, "01234567");
}

void             printf_hexa(t_format_id *stock, va_list *pa)
{
  unsigned int  nbr;

  nbr = va_arg(*pa, unsigned int);
  if (stock->argument == 'x' && stock->flag_hashtag == 1)
    my_putstr("0x");
  else if (stock->argument == 'X' && stock->flag_hashtag == 1)
    my_putstr("0X");
  if (stock->argument == 'x')
    my_put_nbr_base(nbr, "0123456789abcdef");
  else
    my_put_nbr_base(nbr, "0123456789ABCDEF");
}

void            printf_pointer(va_list *pa)
{
  int  nbr;

  nbr = va_arg(*pa, int);

  if (nbr == 0)
    {
      my_putstr("(nil)");
      return ;
    }
  else if (nbr < 0)
    nbr = my_getnbr_base("7FFFFFFF", "0123456789ABCDEF") - nbr + 1;
  my_putstr("0x7ffe");
  my_put_nbr_base(nbr, "0123456789abcdef");
}


void             printf_binary(va_list *pa)
{
  unsigned int  nbr;

  nbr = va_arg(*pa, unsigned int);
  my_put_nbr_base(nbr, "01");
}
