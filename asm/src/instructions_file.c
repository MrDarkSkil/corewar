/*
** instructions_file.c for instructions_file in /home/hubert_i/rendu/2015/coreware
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar 23 23:54:53 2016 Léo Hubert
** Last update Thu Mar 24 01:20:32 2016 Eric DESCHODT
*/

# include		"compilator.h"

int			live(char *param, char nbr_args, int fdwrite, char code)
{
  if (write(fdwrite, &code, 1) == -1)
    return (-1);
  return (0);
}

int			instructions_file(int fdwrite, t_asm *my_asm)
{
  int			i;

  i = 0;
  my_asm = my_asm->next;
  while (my_strcmp(op_tab[i].mnemonique, my_asm->ins) != 0
	 && op_tab[i].code != 0)
    i++;
  if (op_tab[i].code == 0
      || (op_tab[i].wfunc != NULL
	  && op_tab[i].wfunc(my_asm->param, op_tab[i].nbr_args,
			     fdwrite, op_tab[i].code) == -1))
    return (-1);
  while (my_asm->first == 0)
    {
      i = 0;
      while (my_strcmp(op_tab[i].mnemonique, my_asm->ins) != 0
	     && op_tab[i].code != 0)
	i++;
      if (op_tab[i].code == 0
	  || (op_tab[i].wfunc != NULL
	      && op_tab[i].wfunc(my_asm->param, op_tab[i].nbr_args,
				 fdwrite, op_tab[i].code) == -1))
	return (-1);
      my_asm = my_asm->next;
    }
  return (0);
}
