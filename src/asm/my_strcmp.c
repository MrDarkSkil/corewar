/*
** my_strcmp.c for my_strcmp in /home/hubert_1/rendu/Piscine_C_J06/ex_06
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 14:52:28 2015 leo hubert
** Last update Wed Mar 23 11:19:43 2016 Léo Hubert
*/

#include <stdlib.h>
#include "compilator.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);
}

int	my_strcmp_2(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  if ((s1[i] == '=' || s2[i] == '=') && (s1[i - 1] == s2[i - 1]))
    return (-1);
  return (0);
}
