/*
** my_strcpy.c for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 14:31:42 2016 Eric DESCHODT
** Last update Mon Feb 29 09:36:26 2016 Eric DESCHODT
*/

#include "libgraph.h"

char	*my_strcpy(char *dest, char *source)
{
  int	i;

  i = 0;
  while (source[i] != '\0')
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
