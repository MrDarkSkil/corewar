/*
** utils.c for utils.c in /home/roig_a/Corewar/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar  7 15:53:27 2016 Antoine Roig
** Last update Thu Mar 17 11:39:32 2016 Eric DESCHODT
*/

#include "corewar.h"

void    *xmalloc(int size)
{
  void  *element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

void            revert_endian(int *nb)
{
  t_byte        tmp;
  char          swap;

  tmp.full = *nb;
  swap = tmp.byte[0];
  tmp.byte[0] = tmp.byte[3];
  tmp.byte[3] = swap;
  swap = tmp.byte[1];
  tmp.byte[1] = tmp.byte[2];
  tmp.byte[2] = swap;
  *nb = tmp.full;
}

void            print_info(header_t *head)
{
  my_printf("%d\n", head->magic);
  my_printf("%s\n", head->prog_name);
  my_printf("%d\n", head->prog_size);
  my_printf("%s\n", head->comment);
}
