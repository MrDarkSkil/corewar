/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Sat Mar 19 17:19:12 2016 Antoine Roig
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

int		get_header(int fd, header_t *head)
{
  read(fd, head, PROG_NAME_LENGTH + COMMENT_LENGTH + (4 + 4) * 2);
  revert_endian(&head->magic);
  revert_endian(&head->prog_size);
  if (head->magic != COREWAR_EXEC_MAGIC)
    {
      my_printf("Invalid Magic Number\n");
      return (-1);
    }
  return (0);
}

int		create_champ(t_champ *new_elem,
			     t_lcmd *info,
			     unsigned char *board)
{
  int		fd;
  char		*prog;
  int		i;
  header_t	head;
  t_byte        nb;

  nb.full = info->id;
  if ((fd = open(info->name, O_RDONLY)) == -1
      || get_header(fd, &head) == -1
      || (prog = malloc(sizeof(char) * head.prog_size + 1)) == NULL
      || read(fd, prog, head.prog_size + 1) == -1)
    return (-1);
  new_elem->instru = &board[info->a];
  new_elem->start = &board[info->a];
  new_elem->cycle = 0;
  new_elem->cursor = info->a;
  new_elem->size = head.prog_size;
  new_elem->id = info->id;
  new_elem->name = info->name;
  new_elem->reg[0][0] = nb.byte[0];
  new_elem->reg[0][1] = nb.byte[1];
  new_elem->reg[0][2] = nb.byte[2];
  new_elem->reg[0][3] = nb.byte[3];
  i = 0;
  while (i < head.prog_size + 1)
    board[info->a++] = prog[i++];
  close (fd);
  free(prog);
  return (0);
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
  start_vm(vm, board);
  return (0);
}
