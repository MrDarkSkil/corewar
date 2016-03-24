/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Thu Mar 24 03:01:21 2016 Eric DESCHODT
*/

# include		"compilator.h"

int			live(char *param,
			     int fdwrite,
			     char code)
{
  int 			nb;

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  nb = my_getnbr(&param[1]);
  nb = swap_nbr(nb);
  if (write(fdwrite, &nb, 4) == -1)
    return (-1);
  return (0);
}

short int		swap_shortnbr(short int nbr)
{
  short int		new_nbr;
  char			test[2];
  char			swap;

  (short int)test = nbr;
  swap = test[0];
  test[0] = test[1];
  test[1] = swap;
  new_nbr = (short int)test;
  return (new_nbr);
}


void			agregate(char *nb, int *i, char *tmp, short int *arg)
{
  if (*tmp == 'r')
    {
      *nb &=~(1 << *i);
      (*i)--;
      *nb |= (1 << *i);
      (*i)--;
      tmp++;
      *arg = my_getnbr(tmp);
    }
  else if (*tmp == '%')
    {
      *nb |= (1 << *i);
      (*i)--;
      *nb &= ~(1 << *i);
      (*i)--;
      tmp++;
      *arg = my_getnbr(tmp);
    }
  else
    {
      *nb |= (1 << *i);
      (*i)--;
      *nb |= (1 << *i);
      (*i)--;
      *arg = my_getnbr(tmp);
    }
}

int			sti(char *param,
			    int fdwrite,
			    char code)
{

  char			nb;
  int			i;
  char			*tmp;
  short int		arg[3];

  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  i = 7;
  nb = 0;
  tmp = param;
  agregate(&nb, &i, tmp, &arg[0]);
  tmp++;
  while (*tmp != ',')
    tmp++;
  tmp++;
  agregate(&nb, &i, tmp, &arg[1]);
  while (*tmp != ',')
    tmp++;
  tmp++;
  agregate(&nb, &i, tmp, &arg[2]);
  arg[1] = swap_shortnbr(arg[1]);
  arg[2] = swap_shortnbr(arg[2]);
  if ((write(fdwrite, &nb, 1) == -1)
      || (write(fdwrite, &arg[0], 1) == -1)
      || (write(fdwrite, &arg[1], 2) == -1)
      || (write(fdwrite, &arg[2], 2) == -1))
    return (-1);
  return (0);
}

int			instructions_file(int fdwrite, t_asm *my_asm)
{
  int			i;

  i = 0;

  while (my_strcmp(op_tab[i].mnemonique, my_asm->ins) != 0
	 && op_tab[i].code != 0)
    i++;
  if (op_tab[i].code == 0
      || (op_tab[i].wfunc != NULL
	  && op_tab[i].wfunc(my_asm->param, fdwrite, op_tab[i].code) == -1))
    return (-1);
  my_asm = my_asm->next;
  while (my_asm->first == 0)
    {
      i = 0;
      while (my_strcmp(op_tab[i].mnemonique, my_asm->ins) != 0
	     && op_tab[i].code != 0)
	i++;
      if (op_tab[i].code == 0
	  || (op_tab[i].wfunc != NULL
	      && op_tab[i].wfunc(my_asm->param,
				 fdwrite, op_tab[i].code) == -1))
	return (-1);
      my_asm = my_asm->next;
    }
  return (0);
}
