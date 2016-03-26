/*
** utils.c for utils.c in /home/roig_a/Corewar/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar  7 15:53:27 2016 Antoine Roig
** Last update Fri Mar 25 22:01:00 2016 Eric DESCHODT
*/

#include "corewar.h"

void		*xmalloc(int size)
{
  void		*element;

  element = NULL;
  element = malloc(size);
  if (!element)
    {
      my_putstr("Can’t perform malloc.\n");
      exit(EXIT_FAILURE);
    }
  return (element);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (s1[i] - s2[i]);
  return (0);
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
  my_put_nbr(head->magic);
  my_putchar('\n');
  my_putstr(head->prog_name);
  my_putchar('\n');
  my_put_nbr(head->prog_size);
  my_putchar('\n');
  my_putstr(head->comment);
  my_putchar('\n');
}
