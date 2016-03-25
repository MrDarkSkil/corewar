/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Fri Mar 25 11:55:44 2016 Eric DESCHODT
*/

# include		"compilator.h"

int			ldi2(short int arg[3],
			     int fdwrite,
			     char *tmp,
			     int nb)
{
  arg[2] = my_getnbr(tmp);
  arg[1] = swap_shnbr(arg[1]);
  arg[2] = swap_shnbr(arg[2]);
  if ((write(fdwrite, &nb, 1) == -1)
      || (write(fdwrite, &arg[0], 2) == -1)
      || (write(fdwrite, &arg[1], 2) == -1)
      || (write(fdwrite, &arg[2], 1) == -1))
    return (-1);
  return (7);
}

int			ldi(char *param,
			    int fdwrite,
			    char code)
{
  char			nb;
  int			i;
  char			*tmp;
  short int		arg[3];

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  i = 7;
  nb = 0;
  tmp = param;
  agregate(&nb, &i, tmp);
  arg[0] = my_getnbr(tmp);
  tmp++;
  while (*tmp != ',')
    tmp++;
  tmp++;
  agregate(&nb, &i, tmp);
  arg[1] = my_getnbr(tmp);
  while (*tmp != ',')
    tmp++;
  tmp++;
  agregate(&nb, &i, tmp);
  return (ldi2(arg, fdwrite, tmp, nb));
}
