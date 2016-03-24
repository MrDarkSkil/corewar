/*
** syntax.c for syntax.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 20:47:49 2016 Antoine Roig
** Last update Thu Mar 24 03:10:07 2016 Antoine Roig
*/

#include "corewar.h"

void	find_n2(t_list *tmp2, int *a, int *n, int *d)
{
  if ((*a) > 1 || (*n) > 1 || (*d) > 1)
    {
      printf("a = %d n = %d d = %d" , *a, *n, *d);
      exit(0);
    }
  if (my_strcmp(tmp2->arg, "-a") == 0)
      (*a)++;
  if (my_strcmp(tmp2->arg, "-n") == 0)
      (*n)++;
  if (my_strcmp(tmp2->arg, "-dump") == 0)
    (*d)++;
}

int	find_n(t_dlist *list)
{
  t_list	*tmp;
  int		n;
  int		a;
  int		d;
  t_list        *tmp2;

  tmp = list->begin;
  n = 0;
  a = 0;
  d = 0;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-n") == 0 && valid_n(tmp->next->arg) == 0)
	{
	  n++;
	  tmp = tmp->next->next;
	  tmp2 = tmp;
	  while (my_strcmp(is_cor(tmp2->arg), ".cor") != 0)
	    {
	      find_n2(tmp2, &a, &n, &d);
	      tmp2 = tmp2->next;
	    }
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

void	find_a2(t_list *tmp2, int *a, int *n, int *d)
{
  if ((*a) > 1 || (*n) > 1 || (*d) > 1)
    exit(0);
  if (my_strcmp(tmp2->arg, "-a") == 0)
    (*a)++;
  if (my_strcmp(tmp2->arg, "-n") == 0)
    (*n)++;
  if (my_strcmp(tmp2->arg, "-dump") == 0)
    (*d)++;
}

int	find_a(t_dlist *list)
{
  t_list	*tmp;
  int		n;
  int		a;
  int		d;
  t_list        *tmp2;

  tmp = list->begin;
  while (tmp)
    {
      a = 0;
      n = 0;
      d = 0;
      if (my_strcmp(tmp->arg, "-a") == 0 && valid_a(tmp->next->arg) == 0)
	{
	  a++;
	  tmp = tmp->next->next;
	  tmp2 = tmp;
	  while (my_strcmp(is_cor(tmp2->arg), ".cor") != 0)
	    {
	      find_a2(tmp, &a, &n, &d);
	      tmp2 = tmp2->next;
	    }
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

int	syntax(t_dlist *list)
{
  check_para(list);
  check_dump(list);
  find_n(list);
  find_a(list);
  return (0);
}
