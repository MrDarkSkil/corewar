/*
** my_printf.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Nov  2 14:52:58 2015 Eric DESCHODT
** Last update Fri Feb 12 13:09:22 2016 Eric DESCHODT
*/

#include "myprintf.h"

int		my_printf(const char *fmt, ...)
{
  va_list	pa;
  int		i;
  int		j;

  i = 0;
  va_start(pa, fmt);
  while (fmt != NULL && fmt[i] != 0)
    {
      if (fmt[i] == '%' && fmt[i + 1] != '%')
	{
	  j = i + 1;
	  while ((fmt[j] < 'A' || (fmt[j] > 'Z' && fmt[j] < 'a')
		  || fmt[j] > 'z') && fmt[j] != '\0' && fmt[j] != '%')
	    j++;
	  i = (fmt[j] != '%' && j != 0) ?
	    get_flag(i, j + 1, fmt, &pa) : i + my_putchar('%');
	}
      else if (fmt[i] == '%' && fmt[i + 1] == '%')
	my_putchar(fmt[i++]);
      else if (fmt[i] != '%')
	my_putchar(fmt[i]);
      i++;
    }
  va_end(pa);
  return (0);
}
