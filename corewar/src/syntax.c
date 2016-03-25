/*
** syntax.c for syntax.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 20:47:49 2016 Antoine Roig
** Last update Fri Mar 25 13:01:32 2016 Antoine Roig
*/

#include "corewar.h"

void	find_n2(t_list *tmp2, int *a, int *n, int *d)
{
  if ((*a) > 1 || (*n) > 1 || (*d) > 1)
    {
      my_putstr("To much arguments.\n");
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
  t_var		var;
  t_list        *tmp2;

  tmp = list->begin;
  while (tmp)
    {
      init_var(&var);
      if (my_strcmp(tmp->arg, "-n") == 0)
	{
	  var.n++;
	  if (tmp->next == NULL || valid_a(tmp->next->arg) != 0)
	    my_puterror("-n");
	  tmp = tmp->next->next;
	  tmp2 = tmp;
	  while (my_strcmp(is_cor(tmp2->arg), ".cor") != 0)
	    {
	      search_cor_n(tmp2, &(var.a), &(var.n), &(var.d));
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
  printf("%d %d %d\n", *a, *n, *d);
  if ((*a) > 1 || (*n) > 1 || (*d) > 1)
    {
      my_putstr("To much arguments.\n");
      exit(0);
    }
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
  t_var		var;
  t_list        *tmp2;

  tmp = list->begin;
  while (tmp)
    {
      init_var(&var);
      if (my_strcmp(tmp->arg, "-a") == 0)
	{
	  var.a++;
	  if (tmp->next == NULL || valid_a(tmp->next->arg) != 0)
	    my_puterror("-a");
	  tmp = tmp->next->next;
	  tmp2 = tmp;
	  while (my_strcmp(is_cor(tmp2->arg), ".cor") != 0)
	    {
	      search_cor_a(tmp2, &(var.a), &(var.n), &(var.d));
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
  check_dump(list);
  check_paral(list);
  check_para(list);
  find_a(list);
  find_n(list);
  return (0);
}
