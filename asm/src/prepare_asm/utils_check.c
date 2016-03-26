/*
** utils_check.c for utils_check in /home/hubert_i/rendu/2015/coreware/asm/src/prepare_asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 19:22:31 2016 Léo Hubert
** Last update Fri Mar 25 19:36:44 2016 Léo Hubert
*/

#include "compilator.h"

int			check_arg(char *str)
{
  int			i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(str, op_tab[i].mnemonique) == 0)
	return (1);
      i++;
    }
  return (-1);
}

int			count_cee(char **tab)
{
  int			i;

  i = -1;
  if (tab != NULL)
    while (tab[++i]);
  return (i);
}

int			is_num(char *nbr)
{
  int			i;

  i = 0;
  if (nbr != NULL)
    {
      while (nbr[i])
	{
	  if (!(nbr[i] >= '0' && nbr[i] <= '9'))
	    return (-1);
	  i++;
	}
    }
  return (0);
}
