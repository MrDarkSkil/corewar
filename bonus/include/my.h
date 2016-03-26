/*
** my.h for  in /home/descho_e/Piscine/Piscine_C_J09/include
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Oct  8 09:07:44 2015 Eric DESCHODT
** Last update Fri Mar 25 22:08:15 2016 Eric DESCHODT
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>

int		my_getnbr(char *);
int		my_showstr(char *);
void		my_put_float(long double, int);
int		my_put_nbr(int);
void		my_put_nbr_base(unsigned int, char *);
int		my_putchar(char);
int		my_putstr(char *);
int		my_strlen(char *);
char		*my_strcat(char *, char *);
char		*convert_base(char *, char *, char *);
int		my_getnbr_base(char *, char *);
char		*my_revstr(char *);
void            my_memset(char *, int, char);
char            *int_in_str(int, int);

#endif /* !MY_H_ */
