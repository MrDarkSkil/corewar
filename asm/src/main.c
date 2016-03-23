/*
** test.c for test in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 16:45:26 2016 Léo Hubert
** Last update Wed Mar 23 16:12:41 2016 Léo Hubert
*/

#include		"compilator.h"

int			create_cor(char *file)
{
  int			fd;
  int			fdwrite;
  int			error;

  if (((fd = open(file, O_RDONLY)) == -1 )||
      (fdwrite = open(my_strfusion(take_begin(file, '.'), ".cor"),
		      O_WRONLY | O_CREAT | O_TRUNC,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-2);
  if (create_header(fd, fdwrite) == -1)
    return (-1);
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
	return (my_putstr("Error champion not OK\n"));
      else if (res == -2)
	return (my_putstr("File Not Found or Error when create outfile \n"));
    }
  else if (ac == 1)
    {
      my_putstr("Error aguments\n");
    }
  return (0);
}
