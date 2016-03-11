/*
** my_strncmp.c for my_strncmp  in /home/roig_a/Corewar/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 10 16:44:32 2016 Antoine Roig
** Last update Thu Mar 10 16:44:33 2016 Antoine Roig
*/

int     my_strncmp(char *s1, char *s2, int nb)
{
  int   i;

  i = 0;
  while (s1[i] && s2[i] && i < nb)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
