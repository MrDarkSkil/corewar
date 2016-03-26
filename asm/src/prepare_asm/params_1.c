/*
** params_1.c for params_1 in /home/hubert_i/rendu/2015/coreware/asm/src/prepare_asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 19:18:38 2016 Léo Hubert
** Last update Fri Mar 25 19:38:35 2016 Léo Hubert
*/

#include		"compilator.h"

int			check_fork(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  return (1);
}

int			check_aff(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  if (params[0][0] != 'r' || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16)
    return (-1);
  return (1);
}
