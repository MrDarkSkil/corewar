/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Thu Mar 24 15:13:56 2016 Eric DESCHODT
*/

# include		"compilator.h"

int			live(char *param,
			     int fdwrite,
			     char code)
{
  int 			nb;

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  nb = my_getnbr(&param[1]);
  nb = swap_nbr(nb);
  if (write(fdwrite, &nb, 4) == -1)
    return (-1);
  return (5);
}
