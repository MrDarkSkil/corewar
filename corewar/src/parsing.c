/*
** parsing.c for parsing.c in /home/roig_a/coreware/coreware/src/list
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 16 14:47:43 2016 Antoine Roig
** Last update Wed Mar 23 22:27:47 2016 Eric DESCHODT
*/

#include "corewar.h"

void		fill_list(t_dlist *list, char **av)
{
  int		y;

  y = 1;
  while (av[y])
    {
      add_list_end(list, av[y]);
      y++;
    }
}

t_list	*double_pop(t_dlist *list, int j, t_list *tmp)
{
  tmp = pop_list_somewhere(list, j);
  tmp = pop_list_somewhere(list, j);
  return (tmp);
}

void		info_champ(t_dlist *list, int i, t_lcmd *info, char *name)
{
  t_list	*tmp;
  int		j;

  fill_info(info, name);
  tmp = list->begin;
  j = 0;
  while (j < i)
    {
      if (my_strcmp("-a", tmp->arg) == 0)
	{
	  tmp = double_pop(list, j, tmp);
	  info->a = my_getnbr(tmp->arg);
	  i -= 2;
	  tmp = list->begin;
	}
      else if (my_strcmp("-n", tmp->arg) == 0)
	{
	  tmp = double_pop(list, j, tmp);
	  info->id = my_getnbr(tmp->arg);
	  i -= 2;
	  tmp = list->begin;
	}
      else
	tmp = parsing2(tmp, &j);
    }
}

void		find_dump(t_dlist *list, t_vm *vm)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list->begin;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-dump") == 0)
	{
	  tmp = pop_list_somewhere(list, i);
	  tmp = pop_list_somewhere(list, i);
	  vm->dump = my_getnbr(tmp->arg);
	  return;
	}
      i++;
      tmp = tmp->next;
    }
  vm->dump = 0;
}

void		find_champ(t_dlist *list, t_vm *vm, unsigned char *board, int i)
{
  t_list	*tmp;
  t_lcmd	*info;
  t_champ	*new_elem;

  tmp = list->begin;
  new_elem = xmalloc(sizeof(t_champ));
  while (tmp)
    {
      if (my_strcmp(&tmp->arg[my_strlen(tmp->arg) - 4], ".cor") == 0)
	{
	  info = xmalloc(sizeof(t_lcmd));
	  info_champ(list, i, info, tmp->arg);
	  if ((info->id) == 0 && vm->nb < 4)
	    info->id = vm->nb + 1;
	  if (create_champ(new_elem, info, board) == -1)
	    exit(0);
	  add_list_end_vm(vm, new_elem);
	  i = 0;
	  pop_list_begin(list);
	  tmp = list->begin;
	}
      else
	tmp = tmp->next;
      i++;
    }
}
