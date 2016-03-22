/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Tue Mar 22 14:01:26 2016 Eric DESCHODT
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
      my_printf("%s%x ", (board[i] < 16) ? "0" : "",  board[i]);
      i++;
    }
  my_printf("\n");
}

int		main(int ac, char **av)
{
  unsigned char	board[MEM_SIZE];
  t_vm		*vm;
  t_dlist	*list;

  if (ac < 2)
    return (0);
  init_board(board);
  list = NULL;
  list = new_list(list);
  vm = NULL;
  vm = new_vm(vm);
  fill_list(list, av);
  find_dump(list, vm);
  find_champ(list, vm, board);
  show_list_vm(vm);
  init_alive(vm);
  start_vm(vm, board);
  return (0);
}
