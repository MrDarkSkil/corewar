/*
** write_instructions.c for write_instructions in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 13:41:19 2016 Léo Hubert
** Last update Fri Mar 25 19:54:57 2016 Léo Hubert
*/

#include		"compilator.h"

int			all_space(char *str)
{
  int			i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (-1);
      i++;
    }
  return (0);
}

int			write_size(int fdwrite, int size)
{
  int			set;

  set = 8 + PROG_NAME_LENGTH;
  size = swap_nbr(size);
  if (lseek(fdwrite, set, SEEK_SET) == -1
      || write(fdwrite, &size, 4) == -1)
    return (-1);
  return (0);
}

int			write_instructions(int fd, int fdwrite)

{
  char			*tmp;
  int			size;
  int			i;
  char			*ins;
  char			*param;
  t_asm			*my_asm;

  i = 2;
  my_asm = NULL;
  while ((tmp = get_next_line(fd)))
    {
      i++;
      if (tmp != NULL && tmp[0] != '.' && all_space(tmp) != 0)
	{
	  tmp = remove_space(tmp);
	  ins = parse_action(tmp, 0);
	  param = parse_action(tmp, 1);
	  ins = remove_all_space(ins);
	  param = remove_all_space(param);
	  if (check_arg(ins) != 1 ||
	      check_param(ins, param) != 1)
	    return (error_line(i));
	  my_asm = add_action(my_asm, ins, param);
	}
    }
  my_asm = my_asm->next;
  if ((size = instructions_file(fdwrite, my_asm)) == -1
      || write_size(fdwrite, size) == -1)
    return (-1);
  return (0);
}
