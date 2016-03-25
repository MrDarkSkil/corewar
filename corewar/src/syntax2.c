/*
** syntax2.c for syntax2.c in /home/roig_a/COREWAR/coreware/corewar/src
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 00:10:31 2016 Antoine Roig
** Last update Fri Mar 25 14:25:06 2016 Antoine Roig
*/

#include "corewar.h"

int             is_nbr(char *str)
{
  int   i;

  i = 0;

  while (str[i])
    {
      if (str[i] >= 48 && str[i] <= 57)
        i++;
      else
	return (1);
    }
  return (0);
}

int	valid_n(char *nb)
{
  if (!nb)
    return (1);
  if (is_nbr(nb) != 0)
    return (1);
  if (my_getnbr(nb) >= 1 && my_getnbr(nb) <= 4)
    return (0);
  else
    return (1);
}

int	valid_a(char *nb)
{
  if (!nb)
    return (1);
  if (is_nbr(nb) != 0)
    return (1);
  if (my_getnbr(nb) >= 0 && my_getnbr(nb) <= MEM_SIZE)
    return (0);
  else
    return (1);
}

char	*is_cor(char *name)
{
  char	*cor;

  cor = (char*)(name + (my_strlen(name) - 4));
  return (cor);
}

int	check_dump(t_dlist *list)
{
  int		dump;
  t_list	*tmp;
  int		d;

  d = 0;
  dump = 0;
  tmp = list->begin;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-dump") == 0)
	{
	  if (tmp->next && is_nbr_dump(tmp->next->arg) == 0)
	    {
	      dump = my_getnbr(tmp->next->arg);
	      d++;
	    }
	  else
	    my_puterror("-dump");
	}
      tmp = tmp->next;
    }
  if (d > 1)
    my_puterror("Multiple difinition of option dump\n");
  return (dump);
}
