/*
** my_showstr.c for libmy.a in /home/descho_e/library
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct 14 09:28:51 2015 Eric DESCHODT
** Last update Wed Mar 23 12:20:54 2016 Eric DESCHODT
*/

#include "my.h"

int	my_strlenbis(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void	aff_nbrbis(int nbr, char *str, int pow)
{
  if (nbr > 0)
    {
      aff_nbrbis(nbr / pow, str, pow);
      my_putchar(str[nbr % pow]);
    }
}

int	my_putnbr_basebis(int nbr, char *base)
{
  int	pow;
  int	execpt;

  execpt = 0;
  if (nbr == -2147483648)
    {
      nbr = nbr + 1;
      execpt = 1;
    }
  pow = my_strlenbis(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  aff_nbrbis(nbr, base, pow);
  if (execpt == 1)
    {
      my_putchar('\b');
      my_putchar(base[(nbr % pow) + 1]);
    }
  return (0);
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  if (str[i] < 16)
	    my_putchar('0');
	  my_putnbr_basebis(str[i], "0123456789abcdef");
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
