/*
** str_to_wordtab.c for str_to_wordtab in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Jan 20 04:46:21 2016 Léo Hubert
** Last update Thu Mar 24 03:21:22 2016 Léo Hubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	countword(char *str, char caract)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i])
    {
      while (str[i] == caract)
	i++;
      if (str[i])
	c++;
      while (str[i] != caract && str[i] != 0)
	i++;
    }
  return (c);
}

int	current(char *str, char caract)
{
  int	i;

  i = 0;
  while (str[i] != caract && str[i] != '\0')
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char caract)
{
  int	i;
  int	l;
  int	t;
  char	**tab;

  i = 0;
  l = 0;
  tab = malloc((countword(str, caract) + 1) * sizeof(char*));
  while (str[i] == caract)
    i++;
  while (str[i] != 0)
    {
      tab[l] = malloc((current(&str[i], caract) + 1) * sizeof(char));
      t = 0;
      while (str[i] != caract && str[i] != '\0')
	tab[l][t++] = str[i++];
      tab[l++][t] = '\0';
      while (str[i] == caract)
	i++;
    }
  tab[l] = NULL;
  return (tab);
}
