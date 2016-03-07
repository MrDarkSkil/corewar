/*
** my_putchar.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:01:27 2015 Eric DESCHODT
** Last update Fri Feb 12 13:12:44 2016 Eric DESCHODT
*/

#include "myprintf.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
