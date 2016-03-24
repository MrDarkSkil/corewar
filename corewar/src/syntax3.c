/*
** syntax3.c for syntax3.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 00:23:38 2016 Antoine Roig
** Last update Thu Mar 24 14:22:54 2016 Antoine Roig
*/

#include "corewar.h"

int	check_paral(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (my_strcmp(is_cor(tmp->arg), ".cor") != 0
	  && is_nbr(tmp->arg) != 0
	  && my_strcmp(tmp->arg, "-dump") != 0
	  && my_strcmp(tmp->arg, "-a") != 0
	  && my_strcmp(tmp->arg, "-n") != 0)
	{
	  my_putstr("Para error : ");
	  my_putstr(tmp->arg);
	  write(1, "\n", 1);
	  exit(0);
	}
      tmp = tmp->next;
    }
  return (0);
}

int	check_para(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (is_nbr(tmp->arg) == 0)
	if (tmp == list->begin || (my_strcmp(tmp->prev->arg, "-dump") != 0 &&
				   my_strcmp(tmp->prev->arg, "-a") != 0 &&
				   my_strcmp(tmp->prev->arg, "-n") != 0))
	  {
	  my_putstr("Para error : ");
	  my_putstr(tmp->arg);
	  write(1, "\n", 1);
	  exit(0);
	  }
      tmp = tmp->next;
    }
  return (0);
}

void	my_puterror(char *str)
{
  my_putstr("Bad argument for : ");
  my_putstr(str);
  write(1, "\n", 1);
  exit (0);
}

void	search_cor_a(t_list *tmp2, int *a, int *n, int *d)
{
  find_a2(tmp2, a, n, d);
  tmp2 = tmp2->next;
}

void	search_cor_n(t_list *tmp2, int *a, int *n, int *d)
{
  find_n2(tmp2, a, n, d);
  tmp2 = tmp2->next;
}
