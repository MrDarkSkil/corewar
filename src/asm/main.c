/*
** test.c for test in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 16:45:26 2016 Léo Hubert
** Last update Tue Mar 22 20:30:55 2016 Léo Hubert
*/

#include "compilator.h"

int	create_cor(char *file)
{
  int	fd;
  int	fdwrite;
  char	*str;
  int	magic_number;

  magic_number = swap_nbr(COREWAR_EXEC_MAGIC);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-2);
  if ((fdwrite = open(my_strfusion(take_begin(file, '.'), ".cor"),
		      O_WRONLY | O_CREAT | O_TRUNC,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-3);
  if (write(fdwrite, &magic_number, 4) == -1)
    return (-1);
  if ((str = get_name(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, PROG_NAME_LENGTH + 5) == -1)
    return (-1);
  if ((str = get_comment(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, COMMENT_LENGTH + 5) == -1)
    return (-1);
  close(fd);
  close(fdwrite);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;
  int	res;

  i = 1;
  if (ac > 1)
    {
      res = create_cor(av[i]);
      if (res == -1)
	return (my_putstr("Error champion not OK"));
      else if (res == -2)
	return (my_putstr("File Not Found:"));
      else if (res == -3)
	return (my_putstr("Error load read file"));
    }
  else if (ac == 1)
    {
      my_putstr("Error aguments\nMettre message appropriè. (sans fautes :p)");
    }
  return (0);
}
