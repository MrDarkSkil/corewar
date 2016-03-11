/*
** my_strcat.c for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Fri Mar 11 11:59:47 2016 Juliani Renaud
** Last update Fri Mar 11 12:04:33 2016 Juliani Renaud
*/

#include "corewar.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		len;
  char		*str;

  i = 0;
  len = 0;
  if ((str = malloc(sizeof(char) *
		    (my_strlen(dest) + my_strlen(src) + 3))) == NULL)
    my_puterror("Error with malloc str in my_strcat\n");
  while (dest[len] != '\0')
    len++;
  while (dest[i])
    {
      str[i] = dest[i];
      i++;
    }
  i = 0;
  while (src[i])
    {
      str[len] = src[i];
      i++;
      len++;
    }
  str[len] = '\0';
  return (str);
}
