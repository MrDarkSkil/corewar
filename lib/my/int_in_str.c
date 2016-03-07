/*
** my_printf.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_my_printf
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Nov  2 14:52:58 2015 Eric DESCHODT
** Last update Fri Feb 12 13:09:09 2016 Eric DESCHODT
*/

#include "myprintf.h"

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
