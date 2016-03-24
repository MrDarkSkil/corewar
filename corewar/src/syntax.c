/*
** syntax.c for syntax.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 20:47:49 2016 Antoine Roig
<<<<<<< HEAD
** Last update Thu Mar 24 01:27:27 2016 Juliani Renaud
=======
** Last update Thu Mar 24 01:25:58 2016 Antoine Roig
>>>>>>> 1a4315de2bc3e8fbb6684ea8a6bf71feef67453d
*/

#include "corewar.h"

void	find_n2(t_list *tmp2, int *a, int *n, int *d)
{
  if ((*a) > 1 || (*n) > 1 || (*d) > 1)
      exit(0);
  if (my_strcmp(tmp2->arg, "-a") == 0)
      (*a)++;
  if (my_strcmp(tmp2->arg, "-n") == 0)
      (*n)++;
  if (my_strcmp(tmp2->arg, "-dump") == 0)
<<<<<<< HEAD
    (*d)++;
=======
      (*d)++;
>>>>>>> 1a4315de2bc3e8fbb6684ea8a6bf71feef67453d
}

int	find_n(t_dlist *list)
{
  t_list	*tmp;
  int		n;
  int		a;
  int		d;
  t_list        *tmp2;

  a = 0;
  n = 0;
  d = 0;
  tmp = list->begin;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-n") == 0 && valid_n(tmp->next->arg) == 0)
	{
	  n++;
	  tmp2 = tmp->next->next;
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

  a = 0;
  n = 0;
  d = 0;
  tmp = list->begin;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-a") == 0 && valid_a(tmp->next->arg) == 0)
	{
	  a++;
	  tmp2 = tmp->next->next;
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
