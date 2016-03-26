/*
** get_next_line.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_getnextline/maintest
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Jan  4 10:11:52 2016 Eric DESCHODT
** Last update Mon Mar  7 14:46:25 2016 Eric DESCHODT
*/

#include "get_next_line.h"

int		size(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	i++;
    }
  return (i);
}

char		*saving(char *stock)
{
  char		*save;
  int		i;

  if ((save = malloc(sizeof(char) * size(stock) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (stock[++i] != '\0')
    save[i] = stock[i];
  save[i] = '\0';
  return (save);
}

int		add(char *s, char *stock, const int fd)
{
  int		lecture;
  int           i;
  int		find;
  static int	on = 0;

  find = 0;
  lecture = 0;
  if (s != NULL && stock != NULL)
    {
      i = -1;
      while (stock[++i] != '\0')
        {
	  find = (stock[i] == '\n') ? 1 : find;
          s[i] = stock[i];
        }
      s[i] = '\0';
    }
  if ((find == 0) && (lecture = read(fd, &s[size(stock)], READ_SIZE)) != -1)
    (&s[size(stock)])[lecture] = '\0';
  if (lecture == 0 && find == 0 && on == 0 && i != 0)
      stock[0] = (on++ * 0);
  return ((lecture == 0 && find == 0 && on == 0 && i == 0) ? (-1)
	  : ((lecture == 0 && find == 0 && on == 0) ? (-2) : (lecture)));
}

char		*free_end(char *s, char *stock)
{
  if (stock != NULL)
    free(stock);
  if (s != NULL)
    free(s);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*stock = NULL;
  char		*s;
  int		t;

  if (fd == -1 || (READ_SIZE <= 0) || ((s = malloc(BUF + size(stock))) == NULL)
      || ((t = (add(s, stock, fd))) == -1))
    return (free_end(s, stock));
  if (t == -2)
    return (s);
  if (t != 0 || (t == 0 && stock != NULL && stock[0] != '\0'))
    {
      (stock != NULL) ? free(stock) : free(NULL);
      stock = s - 1;
      while (*(++stock) != '\0')
	if (*stock == '\n')
	  {
	    *stock++ = '\0';
	    stock = saving(stock);
	    return (s);
	  }
      stock = s;
      return (get_next_line(fd));
    }
  return (free_end(s, stock));
}
