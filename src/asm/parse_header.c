/*
** parse_header.c for parse_header in /home/hubert_i/tmp/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 23:34:15 2016 Léo Hubert
** Last update Mon Mar 21 17:27:23 2016 Eric DESCHODT
*/

#include "compilator.h"

char	*parse_name(char *str)
{
  int	i;
  char	*result;

  i = 0;
  if ((result = malloc(PROG_NAME_LENGTH + 2)) == NULL
      || my_strlen(str) > PROG_NAME_LENGTH)
    return (NULL);
  while (str[i])
    {
      result[i] = str[i];
      i++;
    }
  while (i < PROG_NAME_LENGTH)
    {
      result[i] = 0;
      i++;
    }
  return (result);
}

char	*parse_comment(char *str)
{
  int	i;
  char	*result;

  i = 0;
  if ((result = malloc(COMMENT_LENGTH  + 2)) == NULL
      || my_strlen(str) > COMMENT_LENGTH)
    return (NULL);
  while (str[i])
    {
      result[i] = str[i];
      i++;
    }
  while (i < COMMENT_LENGTH)
    {
      result[i] = 0;
      i++;
    }
  return (result);
}

char	*get_name(char *str)
{
  char	*name;

  if (my_strcmp(NAME_CMD_STRING, take_begin(str, ' ')) != 0)
    return (NULL);
  name = parse_name(take_after(str, '\"'));
  if (my_strlen(name) > 0)
    {
      name[my_strlen(name) - 1] = '\0';
      return (name);
    }
  else
    return (NULL);
}

char	*get_comment(char *str)
{
  char	*comment;

  if (my_strcmp(COMMENT_CMD_STRING, take_begin(str, ' ')) != 0)
    return (NULL);
  comment = parse_comment(take_after(str, '\"'));
  if (my_strlen(comment) > 0)
    {
      comment[my_strlen(comment) - 1] = '\0';
      return (comment);
    }
  else
    return (NULL);
}
