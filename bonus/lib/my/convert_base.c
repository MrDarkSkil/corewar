/*
** convert_base.c for  in /home/descho_e/rendu/jour8
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Oct  7 12:26:47 2015 Eric DESCHODT
** Last update Wed Mar 23 12:17:54 2016 Eric DESCHODT
*/

#include "my.h"

int     sizeofstr(int nbr, char *base)
{
  int   pow;
  int	i;

  i = 0;
  pow = my_strlen(base);
  if (nbr < 0)
    {
      i = i + 1;
      nbr = -nbr;
    }
  if (nbr == 0)
    i = i + 1;
  while (nbr / pow != 0)
    {
      i++;
      nbr = nbr / pow;
    }
  return (i + 1);
}

void	convert(int nbr,
		char *base,
		char *result,
		int size)
{
  int	i;
  int	stop;

  i = size - 1;
  stop = 0;
  result[size] = '\0';
  if (nbr < 0)
    {
      result[0] = '-';
      nbr = -nbr;
      stop = 1;
    }
  while (i >= stop)
    {
      result[i] = base[nbr % my_strlen(base)];
      nbr = nbr / my_strlen(base);
      i--;
    }
}

char	*convert_base(char *nbr,
		      char *base_from,
		      char *base_to)
{
  int	nb;
  int	size;
  char	*result;

  nb = my_getnbr_base(nbr, base_from);
  size = sizeofstr(nb, base_to);
  if ((result = malloc(size + 1)) == NULL)
    return (NULL);
  convert(nb, base_to, result, size);
  return (result);
}
