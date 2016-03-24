/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Thu Mar 24 01:27:43 2016 Antoine Roig
*/

#include "corewar.h"

void		init_board(unsigned char *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      board[i] = 0;
      i++;
    }
}

void		printboard(unsigned char *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (board[i] < 16)
	my_putchar(' ');
      my_put_nbr_base(board[i], "0123456789abcdef");
      i++;
    }
  my_putchar('\n');
}

void	id_champ2(t_vm *vm, char *tab)
{
  int	i;
  t_champ *tmp;

  tmp = vm->begin;
  while (tmp)
    {
      if (tmp->id == 0)
  	{
  	  i = -1;
  	  while (tab[++i])
	    if (tab[i] != 'x')
	      {
		tmp->id = tab[i] - 48;
		tab[i] = 'x';
		break;
	      }
  	}
      tmp = tmp->next;
    }
}

void	id_champ(t_vm *vm)
{
  char		*tab;
  t_champ	*tmp;
  int		i;

  tmp = vm->begin;
  tab = xmalloc(sizeof(char) * 5);
  tab[0] = '1';
  tab[1] = '2';
  tab[2] = '3';
  tab[3] = '4';
  tab[4] = '\0';
  while (tmp)
    {
      i = -1;
      while (tab[++i])
	if (tmp->id == tab[i] - 48)
	  tab[i] = 'x';
      tmp = tmp->next;
    }
  id_champ2(vm, tab);
}

int		main(int ac, char **av)
{
  unsigned char	board[MEM_SIZE];
  t_vm		*vm;
  t_dlist	*list;
  t_dlist	*list_s;

  if (ac < 2)
    return (0);
  list = NULL;
  list_s = NULL;
  list = new_list(list);
  list_s = new_list(list_s);
  init_board(board);
  vm = NULL;
  vm = new_vm(vm);
  fill_list(list, av);
  syntax(list);
  find_dump(list, vm);
  find_champ(list, vm, board, 0);
  id_champ(vm);
  show_list_vm(vm);
  exit (0);
  /* cursor_champ(vm); */
  vm->debug = 1;
  init_alive(vm);
  start_vm(vm, board);
  return (0);
}
