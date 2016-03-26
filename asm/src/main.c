/*
** test.c for test in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 16:45:26 2016 Léo Hubert
** Last update Fri Mar 25 19:46:08 2016 Léo Hubert
*/

#include		"compilator.h"

int			create_cor(char *file)
{
  int			fd;
  int			fdwrite;
  int			error;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (-5);
  if ((fdwrite = open(my_strfusion(take_begin(file, '.'), ".cor"),
		      O_WRONLY | O_CREAT | O_TRUNC,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-2);
  if (create_header(fd, fdwrite) == -1)
    return (-3);
  if ((error = write_instructions(fd, fdwrite)) != 0)
    return (error);
  close(fd);
  close(fdwrite);
  return (0);
}

int			main(int ac, char **av)
{
  int			i;
  int			res;

  i = 1;
  if (ac > 1)
    {
      res = create_cor(av[i]);
      if (res == -1)
	return (my_putstr_error("Error champion not OK\n"));
      else if (res == -2)
	return (my_putstr_error("Error when create outfile \n"));
      else if (res == -3)
	return (my_putstr_error("Error: .name or .comment not \
found or not good\n"));
      else if (res == -5)
	return (my_putstr_error("File file_name not accessible"));
    }
  else if (ac == 1)
    {
      my_putstr("Error aguments\n");
    }
  return (0);
}
