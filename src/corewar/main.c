/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Thu Mar 10 17:09:46 2016 Eric DESCHODT
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

void		init_board(char *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      board[i] = 0;
      i++;
    }
}

void		printboard(char *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    printf("%x ", board[i++]);
  printf("\n");
}

int		main(int ac, char **av)
{
  int		fd;
  header_t	head;
  char		*prog;
  char		board[MEM_SIZE];
  int		i;
  int		a;

  if ((ac <= 2)
      || (fd = open(av[3], O_RDONLY)) == -1)
    return (0);
  init_board(board);
  read(fd, &head, PROG_NAME_LENGTH + COMMENT_LENGTH + (4 + 4) * 2); 
  revert_endian(&head.magic);
  revert_endian(&head.prog_size);
  if (head.magic != COREWAR_EXEC_MAGIC)
    {
      my_printf("Invalid Magic Number\n");
      return (-1);
    }
  if (((prog = malloc(sizeof(char) * head.prog_size + 1)) == NULL)
      || read(fd, prog, head.prog_size) == -1)
    return (-1);
  a = my_getnbr(av[2]) % MEM_SIZE;
  i = 0;
  while (i < head.prog_size)
    board[a++] = prog[i++];
  printboard(board);
   close (fd);
  return (0);
}
