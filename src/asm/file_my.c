/*
** file_my.c for file_my in /home/hubert_i/tmp/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 23:35:03 2016 Léo Hubert
** Last update Sun Mar 20 23:36:46 2016 Léo Hubert
*/

#include "compilator.h"

int swap_nbr(int nbr)
{
  int new_nbr;

  new_nbr = ((nbr >> 24) &0xff) | ((nbr << 8) &0xff0000)
    | ((nbr >> 8) &0xff00) | ((nbr << 24) &0xff000000);
  return (new_nbr);
}

int	my_putstr(char *str)
{
  int	i;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	counter;

 counter = -1;
  if (str == NULL)
    return (0);
  while (str[++counter] != 0);
  return (counter);
}

char	*my_strfusion(char *str, char *str2)
{
  char	*result;
  int	counter;
  int	counter2;

  counter = 0;
  counter2 = 0;
  if ((result = malloc(my_strlen(str) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str[counter] != 0)
    {
      result[counter] = str[counter];
      counter++;
    }
  while (str2[counter2] != 0)
    {
      result[counter] = str2[counter2];
      counter2++;
      counter++;
    }
  result[counter] = '\0';
  return (result);
}
