/*
** error.c for error in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 16:28:42 2016 Léo Hubert
** Last update Fri Mar 25 18:59:15 2016 Léo Hubert
*/

#include "compilator.h"

int			my_putchar_error(char c)
{
  write(2, &c, 1);
  return (-42);
}

int			my_putstr_error(char *str)
{
  int			i;

  if (str != NULL)
    {
      i = 0;
      while (str[i])
	{
	  my_putchar_error(str[i]);
	  i++;
	}
    }
  return (-42);
}

int			my_putnbr_error(int nb)
{
  if (nb < 10)
    my_putchar_error(nb + '0');
  else if (nb > 9)
    {
      my_putnbr_error(nb / 10);
      my_putchar_error(nb % 10 + '0');
    }
  return (-42);
}

int			error_line(int line)
{
  my_putstr_error("Syntax error line ");
  my_putnbr_error(line);
  my_putchar_error('\n');
  return (-42);
}
