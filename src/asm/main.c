/*
** test.c for test in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 16:45:26 2016 Léo Hubert
** Last update Sun Mar 20 23:29:41 2016 Léo Hubert
*/

#include "compilator.h"

char	*parse_name(char *str)
{
  int	i;
  char	*result;

  i = 0;
  if ((result = malloc(PROG_NAME_LENGTH + 2)) == NULL || my_strlen(str) > PROG_NAME_LENGTH)
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
  if ((result = malloc(COMMENT_LENGTH  + 2)) == NULL || my_strlen(str) > COMMENT_LENGTH)
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

int	create_cor(char *file)
{
  int	fd;
  int	fdwrite;
  char	*str;
  int	magic_number;

  magic_number = swap_nbr(COREWAR_EXEC_MAGIC);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-2);
  if ((fdwrite = open(my_strfusion(take_begin(file, '.'), ".cor"), O_WRONLY | O_CREAT | O_TRUNC,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-3);
  if (write(fdwrite, &magic_number, 4) == -1)
    return (-1);
  if ((str = get_name(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, PROG_NAME_LENGTH) == -1)
    return (-1);
  if ((str = get_comment(get_next_line(fd))) == NULL)
    return (-1);
  if (write(fdwrite, str, COMMENT_LENGTH) == -1)
    return (-1);
  close(fd);
  close(fdwrite);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;
  int	res;

  i = 1;
  if (ac > 1)
    {
      res = create_cor(av[i]);
      if (res == -1)
	return (my_putstr("Error champion not OK"));
      else if (res == -2)
	return (my_putstr("File Not Found:"));
      else if (res == -3)
	return (my_putstr("Error load read file"));
    }
  else if (ac == 1)
    {
      my_putstr("Error aguments\nMettre message appropriè. (sans fautes :p)");
    }
  return (0);
}
