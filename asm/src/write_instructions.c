/*
** write_instructions.c for write_instructions in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 13:41:19 2016 Léo Hubert
** Last update Wed Mar 23 23:56:50 2016 Léo Hubert
*/

#include		"compilator.h"

int			all_space(char *str)
{
  int			i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (-1);
      i++;
    }
  return (0);
}

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

int			check_param(char *str)
{
  return (1);
}

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

int			write_instructions(int fd, int fdwrite)
{
  char			*tmp;
  char			*ins;
  char			*param;
  t_asm			*my_asm;

  (void)fdwrite;
  my_asm = NULL;
  while ((tmp = get_next_line(fd)))
    {
      if (tmp != NULL && tmp[0] != '.' && all_space(tmp) != 0)
	{
	  tmp = remove_space(tmp);
	  ins = parse_action(tmp, 0);
	  param = parse_action(tmp, 1);
	  ins = remove_space(ins);
	  param = remove_space(param);
	  if (check_arg(ins) != 1)
	    return (-1);
	  if (check_param(param) != 1)
	    return (-1);
	  my_asm = add_action(my_asm, ins, param);
	}
    }
  if (instructions_file(fdwrite, my_asm) == -1)
    return (-1);
  return (0);
}
