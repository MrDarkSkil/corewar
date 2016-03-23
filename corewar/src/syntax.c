/*
** syntax.c for syntax.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 20:47:49 2016 Antoine Roig
** Last update Wed Mar 23 22:59:08 2016 Antoine Roig
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
      if (my_strcmp(tmp->arg, "-dump") == 0 && is_nbr(tmp->next->arg) == 0)
	{
	  dump = my_getnbr(tmp->next->arg);
	  d++;
	}
      tmp = tmp->next;
    }
  if (d > 1)
    {
      my_putstr("Multiple difinition of option dump\n");
      exit(0);
    }
  return (dump);
}

int	valid_n(char *nb)
{
  if (my_getnbr(nb) >= 1 && my_getnbr(nb) <= 4)
    return (0);
  else
    return (1);
}

int	valid_a(char *nb)
{
  if (my_getnbr(nb) >= 1 && my_getnbr(nb) <= MEM_SIZE)
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
	      if (a > 1 || n > 1 || d > 1)
		{
		  printf("in n : a = %d\n n = %d\n d = %d\n", a, n, d);
		  exit(0);
		}
	      if (my_strcmp(tmp2->arg, "-a") == 0)
		a++;
	      if (my_strcmp(tmp2->arg, "-n") == 0)
		n++;
	      if (my_strcmp(tmp2->arg, "-dump") == 0)
		d++;
	      tmp2 = tmp2->next;
	    }
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
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
	      if (a > 1 || n > 1 || d > 1)
		{
		  printf("in a : a = %d\n n = %d\n d = %d\n", a, n, d);
		  exit(0);
		}
	      if (my_strcmp(tmp2->arg, "-a") == 0)
		a++;
	      if (my_strcmp(tmp2->arg, "-n") == 0)
		n++;
	      if (my_strcmp(tmp2->arg, "-dump") == 0)
		d++;
	      tmp2 = tmp2->next;
	    }
	  return (0);
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
	    printf("%s\n", tmp->arg);
	    printf("%s\n", tmp->prev->arg);
	    puts("para");
	    exit(0);
	  }
      tmp = tmp->next;
    }
  return (0);
}

int	syntax(t_dlist *list)
{
  int	dump;

  check_para(list);
  dump = check_dump(list);
  printf("dump = %d\n", dump);
  find_n(list);
  find_a(list);
  return (0);
}
