/*
** params_4.c for params_4 in /home/hubert_i/rendu/2015/coreware/asm/src/prepare_asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 19:21:16 2016 Léo Hubert
** Last update Fri Mar 25 19:36:45 2016 Léo Hubert
*/

#include		"compilator.h"

int			check_live(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1 || params[0][0] != '%'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 256)
    return (-1);
  return (1);
}

int			check_ld(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 2)
    return (-1);
  return (1);
}

int			check_st(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 2)
    return (-1);
  if (params[0][0] != 'r' || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16)
    return (-1);
  return (1);
}

int			check_add(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[0][0] != 'r'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16
      || params[1][0] != 'r'
      || is_num(&params[1][1]) == -1
      || my_getnbr(&params[1][1]) < 1
      || my_getnbr(&params[1][1]) > 16
      || params[2][0] != 'r'
      || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_sub(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[0][0] != 'r'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16
      || params[1][0] != 'r'
      || is_num(&params[1][1]) == -1
      || my_getnbr(&params[1][1]) < 1
      || my_getnbr(&params[1][1]) > 16
      || params[2][0] != 'r'
      || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}
