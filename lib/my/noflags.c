/*
** my_printf.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Nov  2 14:52:58 2015 Eric DESCHODT
** Last update Fri Feb 12 13:10:41 2016 Eric DESCHODT
*/

#include "myprintf.h"

void		print_noflags(int *i, char *flags)
{
  my_putchar('%');
  my_putstr(flags);
  (*i)++;
}
