/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Fri Mar 25 19:00:04 2016 Léo Hubert
*/

# include		"compilator.h"

int			agregate(char *nb, int *i, char *tmp)
{
  if (*tmp == 'r')
    {
      *nb &=~(1 << *i);
      (*i)--;
      *nb |= (1 << *i);
      (*i)--;
      return (1);
    }
  else if (*tmp == '%')
    {
      *nb |= (1 << *i);
      (*i)--;
      *nb &= ~(1 << *i);
      (*i)--;
      return (4);
    }
  else
    {
      *nb |= (1 << *i);

      (*i)--;
      *nb |= (1 << *i);
      (*i)--;
      return (2);
    }
}

int			check_start(int fdwrite, t_asm *my_asm)
{
 int			i;
 int			size;

  i = 0;
  size = 0;
  while (my_strcmp(op_tab[i].mnemonique, my_asm->ins)
	 != 0 && op_tab[i].code != 0)
    i++;
  if (op_tab[i].code == 0 ||
      (op_tab[i].wfunc != NULL &&
       (size = op_tab[i].wfunc
	(my_asm->param, fdwrite, op_tab[i].code)) == -1))
    return (-1);
  return (size);
}

int			instructions_file(int fdwrite, t_asm *my_asm)
{
  int			i;
  int			size;
  int			tmp;

  i = 0;
  tmp = 0;
  size = check_start(fdwrite, my_asm);
  my_asm = my_asm->next;
  while (my_asm->first == 0)
    {
      i = 0;
      while (my_strcmp(op_tab[i].mnemonique, my_asm->ins) != 0
	     && op_tab[i].code != 0)
	i++;
      if (op_tab[i].code == 0
	  || (op_tab[i].wfunc != NULL
	      && (tmp = op_tab[i].wfunc
		  (my_asm->param, fdwrite, op_tab[i].code)) == -1))
	return (-1);
      size += tmp;
      my_asm = my_asm->next;
    }
  return (size);
}
