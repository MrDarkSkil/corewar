/*
** parsing.c for parsing in /home/hubert_i/rendu/2015/coreware/asm/src/prepare_asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 19:14:33 2016 Léo Hubert
** Last update Fri Mar 25 19:41:07 2016 Léo Hubert
*/

#include "compilator.h"

char			*my_strdup(char *str)
{
  char			*result;
  int			i;

  i = -1;
  result = xmalloc(sizeof(char) * my_strlen(str));
  if (str != NULL)
    while (str[++i])
      result[i] = str[i];
  return (result);
}

char			*parse_action(char *str, int select)
{
  char			*result;
  int			i;

  result = my_strdup(str);
  i = 0;
  if (select == 0)
    {
      while (result[++i] != '\t' && result[i] != ' ' && result[i]);
      result[i] = '\0';
      return (result);
    }
  else if (select == 1)
    {
      while (result[++i] != '\t' && result[i] != ' ' && result[i]);
      return (&result[i]);
    }
  return ("error");
}

char			*remove_all_space(char *str)
{
  int			i;
  int			ibis;
  char			*result;

  i = -1;
  ibis = 0;
  result = xmalloc(sizeof(char) * my_strlen(str));
  while (str[ibis] != '\0')
    {
      if (str[ibis] != ' ' && str[ibis] != '\t')
	result[++i] = str[ibis];
      ibis++;

    }
  result[++i] = '\0';
  return (result);
}
