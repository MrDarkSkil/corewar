/*
** int_in_str.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_corewar
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Mar 23 12:35:05 2016 Eric DESCHODT
** Last update Wed Mar 23 12:35:07 2016 Eric DESCHODT
*/

#include "my.h"

char		*int_in_str(int nbr, int size)
{
  int		i;
  char		*result;
  int		sign;

  sign = 1;
  if (nbr < 0)
    nbr = -nbr + (sign-- * 0) + (size++ * 0);
  size++;
  result = malloc(sizeof(char) * size);
  if (result != NULL)
    {
      i = size - 2;
      my_memset(result, size, '\0');
      while (nbr != 0)
	{
	  result[i] = (nbr % 10) + 48;
	  nbr = nbr / 10;
	  i--;
	}
      if (sign == 0)
	result[0] = '-';
    }
  return (result);
}
