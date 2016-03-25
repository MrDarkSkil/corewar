/*
** header.c for header in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 10:40:06 2016 Léo Hubert
** Last update Fri Mar 25 15:06:54 2016 Léo Hubert
*/

#include "compilator.h"

int	create_header(int fd, int fdwrite)
{
  int	magic_number;
  int	size;
  char	*str;

  size = swap_nbr(20);
  magic_number = swap_nbr(COREWAR_EXEC_MAGIC);
  if (write(fdwrite, &magic_number, 4) == -1)
    return (-1);
  if ((str = get_name(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, PROG_NAME_LENGTH) == -1)
    return (-1);
  if (write(fdwrite, &size, 8) == -1)
    return (-1);
  if ((str = get_comment(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, COMMENT_LENGTH + 4) == -1)
    return (-1);
  return (0);
}
