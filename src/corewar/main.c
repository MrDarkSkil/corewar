/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Mon Mar 14 13:43:21 2016 Eric DESCHODT
*/

#include "corewar.h"

void		revert_endian(int *nb)
{
  t_byte	tmp;
  char		swap;

  tmp.full = *nb;
  swap = tmp.byte[0];
  tmp.byte[0] = tmp.byte[3];
  tmp.byte[3] = swap;
  swap = tmp.byte[1];
  tmp.byte[1] = tmp.byte[2];
  tmp.byte[2] = swap;
  *nb = tmp.full;
}

void		print_info(header_t *head)
{
  my_printf("%d\n", head->magic);
  my_printf("%s\n", head->prog_name);
  my_printf("%d\n", head->prog_size);
  my_printf("%s\n", head->comment);
}

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
			     char *name,
			     unsigned int a,
			     unsigned char *board)
{
  int		fd;
  char		*prog;
  int		i;
  header_t	head;

  if ((fd = open(name, O_RDONLY)) == -1
      || get_header(fd, &head) == -1
      || (prog = malloc(sizeof(char) * head.prog_size + 1)) == NULL
      || read(fd, prog, head.prog_size + 1) == -1)
    return (-1);
  new_elem->instru = &board[a];
  new_elem->cycle = 0;
  new_elem->cursor = 0;
  new_elem->size = head.prog_size;
  i = 0;
  while (i < head.prog_size + 1)
    board[a++] = prog[i++];
  close (fd);
  free(prog);
  return (0);
}
int		main(int ac, char **av)
{
  unsigned char	board[MEM_SIZE];
  t_champ	new_elem;
  t_vm		vm;

  if (ac < 2)
    return (0);
  init_board(board);
  create_champ(&new_elem, av[1], 0, board);
  new_elem.next = &new_elem;
  new_elem.prev = &new_elem;
  vm.begin = &new_elem;
  vm.end = &new_elem;
  vm.nb = 1;
  vm.begin->id = 1;
  /* printboard(board); */
  start_vm(&vm, board);
  return (0);
}
