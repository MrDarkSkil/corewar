/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Thu Mar 10 15:19:26 2016 Eric DESCHODT
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

int		main(int ac, char **av)
{
  int		fd;
  header_t	head;

  if ((ac == 0)
      || (fd = open(av[1], O_RDONLY)) == -1)
    return (0);
  read(fd, &head, PROG_NAME_LENGTH + COMMENT_LENGTH + 4 + 4); 
  revert_endian(&head.magic);
  revert_endian(&head.prog_size);
  print_info(&head);
  if (head.magic != COREWAR_EXEC_MAGIC)
    {
      my_printf("Invalid Magic Number\n");
      return (-1);
    }
  close (fd);
  return (0);
}
