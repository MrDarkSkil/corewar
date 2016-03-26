/*
** my_takestr.c for take_str in /home/hubert_i/rendu/2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar  2 01:43:33 2016 Léo Hubert
** Last update Wed Mar 23 11:20:42 2016 Léo Hubert
*/

#include "compilator.h"

char	*take_after(char *str, char c)
{
  int	i;

  i = -1;
  if (str == NULL)
    return ("ERROR");
  while (str[++i] != c && str[i]);
  return (&str[i + 1]);
}

char	*take_begin(char *str, char c)
{
  int	i;

  i = -1;
  if (str == NULL)
    return ("ERROR");
  while (str[++i] != c && str[i]);
  str[i] = '\0';
  return (str);
}
