/*
** utils.c for utils.c in /home/roig_a/Corewar/coreware
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Mon Mar  7 15:53:27 2016 Antoine Roig
** Last update Wed Mar 23 22:43:48 2016 Léo Hubert
*/

#include "corewar.h"

void    *xmalloc(int size)
{
  void  *element;

  element = NULL;
  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}
