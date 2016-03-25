/*
** tekgui_load.c for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 13:17:37 2016 Eric DESCHODT
** Last update Mon Feb 29 09:34:16 2016 Eric DESCHODT
*/

#include "libgraph.h"

char                    *get_chmp(char *chmp,
                                  t_bunny_ini *file,
				  int i)
{
  int                   size;
  char                  *str;

  size = my_strlen((char *)bunny_ini_get_field(file, NULL, chmp, i));
  if (size == 0)
    return (NULL);
  if ((str = bunny_malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  my_strcpy(str, (char *)bunny_ini_get_field(file, NULL, chmp, i));
  return (str);
}
