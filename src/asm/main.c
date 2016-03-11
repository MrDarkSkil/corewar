/*
** main.c for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Fri Mar 11 11:03:06 2016 Juliani Renaud
** Last update Fri Mar 11 12:34:00 2016 Juliani Renaud
*/

#include "corewar.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit (0);
}

char		*my_memeset(char *str, char c, int len)
{
  int		i;

  i = 0;
  while (i < len)
    str[i++] = c;
  return (str);
}

char		*recup(char *str)
{
  int		i;
  int		j;
  char		*rturn;

  if ((rturn = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_puterror("Error with mallic rturn in recup\n");
  i = 0;
  j = 0;
  while (str[i] != '"' && str[i] != '\0')
    i++;
  i++;
  while (str[i] != '"' && str[i] != '\0')
    {
      rturn[j] = str[i];
      i++;
      j++;
    }
  rturn[j] = '\0';
  return (rturn);
}

char		*changopen(char *str)
{
  int		i;
  char		*rturn;

  i = 0;
  if ((rturn = malloc(sizeof(char) * (my_strlen(str) + 4))) == NULL)
    my_puterror("Error with malloc rturn in changopen\n");
  while (str[i] != '.')
    {
      rturn[i] = str[i];
      i++;
    }
  rturn = my_strcat(rturn, ".cor");
  return (rturn);
}

void		write_name_comment(int fdwrite, char *name, char *comment)
{
  if ((write(fdwrite, name, PROG_NAME_LENGTH)) == -1)
    my_puterror("Error with write name in write_name_comment\n");
  if ((write(fdwrite, comment, COMMENT_LENGTH)) == -1)
    my_puterror("Error with write comment in write_name_comment\n");
}

int		main(int ac, char **av)
{
  int		fdread;
  int		fdwrite;
  char		*name;
  char		*comment;

  ac = ac;
  if ((fdread = open(av[1], O_RDONLY)) == -1)
    my_puterror("Error with open av in main\n");
  if ((fdwrite = open(changopen(av[1]), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
		      | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    my_puterror("Error with open av in main\n");
  if ((name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1))) == NULL)
    my_puterror("Error with malloc name in main\n");
  if ((comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1))) == NULL)
    my_puterror("Error with malloc name in main\n");
  name = my_memeset(name, '\0', (PROG_NAME_LENGTH + 1));
  comment = my_memeset(comment, '\0', (COMMENT_LENGTH + 1));
  name = recup(get_next_line(fdread));
  comment = recup(get_next_line(fdread));
  write_name_comment(fdwrite, name, comment);
  return (0);
}
