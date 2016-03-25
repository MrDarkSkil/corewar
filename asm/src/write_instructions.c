/*
** write_instructions.c for write_instructions in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 13:41:19 2016 Léo Hubert
** Last update Fri Mar 25 15:39:13 2016 Léo Hubert
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

int			check_live(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1 || params[0][0] != '%'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 256)
    return (-1);
  return (1);
}

int			check_ld(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 2)
    return (-1);
  return (1);
}

int			check_st(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 2)
    return (-1);
  if (params[0][0] != 'r' || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16)
    return (-1);
  return (1);
}

int			check_add(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[0][0] != 'r'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16
      || params[1][0] != 'r'
      || is_num(&params[1][1]) == -1
      || my_getnbr(&params[1][1]) < 1
      || my_getnbr(&params[1][1]) > 16
      || params[2][0] != 'r'
      || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_sub(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[0][0] != 'r'
      || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16
      || params[1][0] != 'r'
      || is_num(&params[1][1]) == -1
      || my_getnbr(&params[1][1]) < 1
      || my_getnbr(&params[1][1]) > 16
      || params[2][0] != 'r'
      || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_and(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[2][0] != 'r' || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_or(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[2][0] != 'r' || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_xor(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[2][0] != 'r' || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_zjmp(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  return (1);
}

int			check_ldi(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[2][0] != 'r' || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_sti(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[0][0] != 'r' || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16)
    return (-1);
  return (1);
}

int			check_fork(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  return (1);
}

int			check_lld(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 2)
    return (-1);
  return (1);
}

int			check_lldi(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 3)
    return (-1);
  if (params[2][0] != 'r' || is_num(&params[2][1]) == -1
      || my_getnbr(&params[2][1]) < 1
      || my_getnbr(&params[2][1]) > 16)
    return (-1);
  return (1);
}

int			check_lfork(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  return (1);
}

int			check_aff(char *param)
{
  char			**params;

  params = my_str_to_wordtab(param, SEPARATOR_CHAR);
  if (count_cee(params) != 1)
    return (-1);
  if (params[0][0] != 'r' || is_num(&params[0][1]) == -1
      || my_getnbr(&params[0][1]) < 1
      || my_getnbr(&params[0][1]) > 16)
    return (-1);
  return (1);
}


int			init_ptIns(int (*ptIns[17])(char *param))
{
  ptIns[0] = check_live;
  ptIns[1] = check_ld;
  ptIns[2] = check_st;
  ptIns[3] = check_add;
  ptIns[4] = check_sub;
  ptIns[5] = check_and;
  ptIns[6] = check_or;
  ptIns[7] = check_xor;
  ptIns[8] = check_zjmp;
  ptIns[9] = check_ldi;
  ptIns[10] = check_sti;
  ptIns[11] = check_fork;
  ptIns[12] = check_lld;
  ptIns[13] = check_lldi;
  ptIns[14] = check_lfork;
  ptIns[15] = check_aff;
  ptIns[16] = NULL;
  return (0);
}

int			check_param(char *ins, char *param)
{
  int	(*ptIns[17])(char *param);
  int	i;

  i = -1;
  init_ptIns(ptIns);
  while (op_tab[++i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, ins) == 0)
	return (ptIns[i](param));
    }
  return (-1);
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


char			*remove_all_space(char *str)
{
  int			i;
  int			ibis;
  char			*result;

  i = -1;
  ibis = 0;
  result = xmalloc(sizeof(char) * my_strlen(str));
  while (str[ibis] != '\0')
    {
      if (str[ibis] != ' ' && str[ibis] != '\t')
	result[++i] = str[ibis];
      ibis++;

    }
  result[++i] = '\0';
  return (result);
}

int			write_instructions(int fd, int fdwrite)
{
  char			*tmp;
  char			*ins;
  char			*param;
  t_asm			*my_asm;
  int			size;

  my_asm = NULL;
  while ((tmp = get_next_line(fd)))
    {
      if (tmp != NULL && tmp[0] != '.' && all_space(tmp) != 0)
	{
	  tmp = remove_space(tmp);
	  ins = parse_action(tmp, 0);
	  param = parse_action(tmp, 1);
	  ins = remove_all_space(ins);
	  param = remove_all_space(param);
	  if (check_arg(ins) != 1)
	    return (-1);
	  if (check_param(ins, param) != 1)
	    return (-1);
	  my_asm = add_action(my_asm, ins, param);
	}
    }
  my_asm = my_asm->next;
  if ((size = instructions_file(fdwrite, my_asm)) == -1)
    return (-1);
  /* HEADER WRITE SIZE */
  return (0);
}
