/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Fri Mar 25 19:43:18 2016 Léo Hubert
*/

#include		"compilator.h"

int			get_args(t_arg *arg,
				 char *nb,
				 int *i,
				 char *tmp)
{
  if ((arg->size = agregate(nb, i, tmp)) != 2)
    tmp++;
  arg->value = my_getnbr(tmp);
  if (arg->size == 4)
    arg->value = swap_nbr(arg->value);
  else if (arg->size == 2)
    arg->value = swap_shnbr(arg->value);
  return (arg->size);
}

int			ld(char *param,
			   int fdwrite,
			   char code)
{
  char			nb;
  t_arg			arg[2];
  int			i;
  char			*tmp;

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  i = 7;
  nb = 0;
  tmp = param;
  if ((get_args(&arg[0], &nb, &i, tmp)) != 2)
    tmp++;
  while (*tmp != ',')
    tmp++;
  tmp++;
  if ((get_args(&arg[1], &nb, &i, tmp)) != 2)
    tmp++;
  if (write(fdwrite, &nb, 1) == -1
      || (write(fdwrite, &arg[0].value, arg[0].size) == -1)
      || (write(fdwrite, &arg[1].value, arg[1].size) == -1))
    return (-1);
  return (arg[0].size + arg[1].size + 2);
}

int			and2(int fdwrite, int nb, t_arg arg[3])
{
  if (write(fdwrite, &nb, 1) == -1
      || (write(fdwrite, &arg[0].value, arg[0].size) == -1)
      || (write(fdwrite, &arg[1].value, arg[1].size) == -1)
      || (write(fdwrite, &arg[2].value, arg[2].size) == -1))
    return (-1);
  return (arg[0].size + arg[1].size + arg[2].size + 2);
}

int                     and(char *param,
			    int fdwrite,
			    char code)
{
  char                  nb;
  t_arg                 arg[3];
  int                   i;
  char                  *tmp;

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  i = 7;
  nb = 0;
  tmp = param;
  if ((get_args(&arg[0], &nb, &i, tmp)) != 2)
    tmp++;
  while (*tmp != ',')
    tmp++;
  tmp++;
  if ((get_args(&arg[1], &nb, &i, tmp)) != 2)
    tmp++;
  while (*tmp != ',')
    tmp++;
  tmp++;
  if ((get_args(&arg[2], &nb, &i, tmp)) != 2)
    tmp++;
  return (and2(fdwrite, nb, arg));
}

int                     zjump(char *param,
			      int fdwrite,
			      char code)
{
  char			*tmp;
  short int		nb;

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  tmp = param;
  tmp++;
  nb = my_getnbr(param);
  nb = swap_shnbr(nb);
  if (write(fdwrite, &nb, 2) == -1)
    return (-1);
  return (3);
}
