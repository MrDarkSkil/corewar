/*
** my_strdup.c for my_strdup.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 23:51:37 2016 Antoine Roig
** Last update Thu Mar 24 00:05:58 2016 Antoine Roig
*/

#include "corewar.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strdup(char *src)
{
  char *new;

  new = xmalloc(sizeof(char) * my_strlen(src) + 1);
  if (new == NULL)
    return (new);
  my_strcpy(new, src);
  return (new);
}
