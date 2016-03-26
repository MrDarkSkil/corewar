/*
** my_putchar.c for lib in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Oct  6 09:01:27 2015 Eric DESCHODT
** Last update Wed Mar 23 12:19:20 2016 Eric DESCHODT
*/

#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
