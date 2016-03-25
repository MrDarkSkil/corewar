/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Fri Mar 25 17:31:14 2016 Eric DESCHODT
*/

#include "corewar.h"

int		get_header(int fd, header_t *head)
{
  read(fd, head, PROG_NAME_LENGTH + COMMENT_LENGTH + (4 + 4) * 2);
  revert_endian(&head->magic);
  revert_endian(&head->prog_size);
  if (head->magic != COREWAR_EXEC_MAGIC)
    {
      my_putstr("Invalid Magic Number\n");
      return (-1);
    }
  return (0);
}

void		champ_memory(header_t head,
			     unsigned char *board,
			     t_lcmd *info,
			     char *prog)
{
 int		i;

  i = 0;
  while (i < head.prog_size + 1)
    {
      if (board[info->a % MEM_SIZE] != 0)
      	{
      	  my_putstr("Not enough space\n");
      	  exit(0);
      	}
      board[info->a++ % MEM_SIZE] = prog[i++];
    }
}

void		champ_info(t_champ *new_elem,
			   unsigned char *board,
			   t_lcmd *info,
			   header_t head)
{
  if (info->p == 0 && info->a == 0)
    new_elem->cursor = MEM_SIZE * 0;
  else if (info->p == 1 && info->a == 0)
    new_elem->cursor = MEM_SIZE / 2;
  else if (info->p == 2 && info->a == 0)
    new_elem->cursor = MEM_SIZE / 4;
  else if (info->p == 3 && info->a == 0)
    new_elem->cursor = MEM_SIZE - (MEM_SIZE / 4);
  else
    new_elem->cursor = info->a;
  info->a = new_elem->cursor;
  new_elem->start = &board[new_elem->cursor];
  new_elem->instru = &board[new_elem->cursor];
  new_elem->cycle = 0;
  new_elem->size = head.prog_size;
  new_elem->id = info->id;
  new_elem->name = info->name;
}

t_champ	*pad_reg(t_champ * new_elem)
{
  int	y;
  int	x;

  y = 1;
  while (y < REG_NUMBER)
    {
      x = 0;
      while (x < REG_SIZE)
	{
	  new_elem->reg[y][x] = 0;
	  x++;
	}
      y++;
    }
  return (new_elem);
}

int		create_champ(t_champ *new_elem,
			     t_lcmd *info,
			     unsigned char *board)
{
  int		fd;
  char		*prog;
  header_t	head;
  int		rd;

  if ((fd = open(info->name, O_RDONLY)) == -1
      || get_header(fd, &head) == -1
      || (prog = xmalloc(sizeof(char) * head.prog_size + 1)) == NULL
      || (rd = read(fd, prog, head.prog_size + 1)) == -1)
    return (-1);
  champ_info(new_elem, board, info, head);
  champ_memory(head, board, info, prog);
  new_elem = pad_reg(new_elem);
  new_elem->name = my_strdup(head.prog_name);
  new_elem->carry = 0;
  close (fd);
  free(prog);
  return (0);
}
