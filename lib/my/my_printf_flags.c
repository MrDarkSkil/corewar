/*
** my_printf.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Nov  2 14:52:58 2015 Eric DESCHODT
** Last update Fri Feb 12 13:11:10 2016 Eric DESCHODT
*/

#include "myprintf.h"

int		find_flags(t_format_id *stock, char c)
{
  if (c == '-')
    stock->flag_minus = 1;
  else if (c == '0')
    stock->flag_zero = 1;
  else if (c == '+')
    stock->flag_plus = 1;
  else if (c == ' ')
    stock->flag_blank = 1;
  else if (c == '#')
    stock->flag_hashtag = 1;
  else
    return (1);
  return (0);
}

int		init_stock(char *flags, t_format_id *stock)
{
  int		i;

  if (my_strlen(flags) > 1)
    {
      i = 0;
      while (find_flags(stock, flags[i]) == 0)
	i++;
      if (flags[i] >= '0' && flags[i] <= '9')
	{
	  stock->min_field = my_getnbr(&flags[i]);
	  while (flags[i] >= '0' && flags[i] <= '9')
	    i++;
	}
      if (flags[i] == '.')
	{
	  i++;
	  stock->max_field = my_getnbr(&flags[i]);
	  while (flags[i] >= '0' && flags[i] <= '9')
	    i++;
	}
      stock->argument = flags[i];
    }
  else
    stock->argument = flags[0];
  return (0);
}

int		decypher_flags(t_format_id *stock, va_list *pa)
{
  if (stock->argument == 'd' || stock->argument == 'i')
    printf_decimal(stock, pa);
  else if (stock->argument == 'o')
    printf_octal(stock, pa);
  else if (stock->argument == 'x' || stock->argument == 'X')
    printf_hexa(stock, pa);
  else if (stock->argument == 'c')
    my_putchar(va_arg(*pa, int));
  else if (stock->argument == 's')
    my_putstr(va_arg(*pa, char *));
  else if (stock->argument == 'b')
    printf_binary(pa);
  else if (stock->argument == 'p')
    printf_pointer(pa);
  else if (stock->argument == 'S')
    my_showstr(va_arg(*pa, char *));
  else if (stock->argument == 'u')
    printf_unddec(pa);
  else if (stock->argument == 'f' || stock->argument == 'e'
	   || stock->argument == 'E' || stock->argument == 'g'
	   || stock->argument == 'G')
    printf_float(stock, pa);
  else
    return (-1);
  return (0);
}

void		first_init_stock(t_format_id *stock)
{
  stock->flag_minus = 0;
  stock->flag_zero = 0;
  stock->flag_plus = 0;
  stock->flag_blank = 0;
  stock->flag_hashtag = 0;
  stock->min_field = 0;
  stock->max_field = -1;
  stock->argument = 0;
}

int		get_flag(int i, int j, const char *fmt, va_list *pa)
{
  char		*flags;
  t_format_id	*stock;
  int		end;
  int		k;

  end = 1;
  k = 0;
  if ((stock = malloc(sizeof(t_format_id))) != NULL
      && (flags = malloc(sizeof(char *) * (j - i))) != NULL)
    {
      if (fmt[j] == '\0')
	end = 0 + (j-- * 0);
      while (j != i)
	flags[k++] = fmt[j--];
      flags[k] = '\0';
      first_init_stock(stock);
      init_stock(my_revstr(flags), stock);
      if (decypher_flags(stock, pa) == -1)
	print_noflags(&i, flags);
      i = i + my_strlen(flags) - end;
      free(stock);
      free(flags);
      return (i);
    }
  return (0);
}
