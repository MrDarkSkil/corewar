/*
** parse_header.c for parse_header in /home/hubert_i/tmp/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 23:34:15 2016 Léo Hubert
** Last update Fri Mar 25 15:31:07 2016 Léo Hubert
*/

#include "compilator.h"

char	*remove_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || (str[i] == '\t' && str[i] != '\0'))
    i++;
  return (&str[i]);
}

char	*parse_name(char *str)
{
  int	i;
  char	*result;

  i = -1;
  if ((result = malloc(PROG_NAME_LENGTH)) == NULL
      || my_strlen(str) > PROG_NAME_LENGTH)
    return (NULL);
  while (str[++i])
    result[i] = str[i];
  while (++i < PROG_NAME_LENGTH)
    result[i] = 0;
  return (result);
}

char	*parse_comment(char *str)
{
  int	i;
  char	*result;

  i = -1;
  if ((result = malloc(COMMENT_LENGTH)) == NULL
      || my_strlen(str) > COMMENT_LENGTH)
    return (NULL);
  while (str[++i])
    result[i] = str[i];
  while (++i < COMMENT_LENGTH)
    result[i] = 0;
  return (result);
}

char	*get_name(char *str)
{
  if (my_strcmp(NAME_CMD_STRING, take_begin(str, ' ')) != 0)
    return (NULL);
   str = take_after(str, '"');
   str = parse_name(str);
  if (my_strlen(str) > 0)
    {
      str = remove_space(str);
      str[my_strlen(str) -1] = '\0';
      return (&str[1]);
    }
  else
    return (NULL);
}

char	*get_comment(char *str)
{
  if (my_strcmp(COMMENT_CMD_STRING, take_begin(str, ' ')) != 0)
    return (NULL);
  str = take_after(str, '"');
  str = parse_comment(str);
  if (my_strlen(str) > 0)
    {
      str = remove_space(str);
      str[my_strlen(str) -1] = '\0';
      return (&str[1]);
    }
  else
    return (NULL);
}
