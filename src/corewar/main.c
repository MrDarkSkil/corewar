/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Mon Mar  7 15:55:03 2016 Antoine Roig
*/

#include "corewar.h"

int	main(int ac, char **av)
{
  int	nb_champ;
  t_vm	*vm;

  ac = ac;
  vm = NULL;
  nb_champ = atoi(av[1]);
  vm = new_vm(vm);
  launch_vm(vm, nb_champ);
  show_list(vm); 
  return (0);
}
