/*
** comilator.h for compilator in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 17:53:01 2016 Léo Hubert
** Last update Thu Mar 24 18:03:20 2016 Eric DESCHODT
*/

#ifndef _COMPILATOR
# define _COMPILATOR

# include	<sys/stat.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	"op.h"
# include	"get_next_line.h"
# include	"my.h"

typedef struct	s_asm
{
  char		*ins;
  char		*param;
  int		first;
  struct s_asm	*next;
  struct s_asm	*prev;
}		t_asm;

typedef struct	s_arg
{
  int		value;
  int		size;
}		t_arg;

short int       swap_shnbr(short int nbr);
void            *xmalloc(int size);
char		*take_begin(char	*str,
			    char	c);
char		*parse_name(char	*str);
char		*parse_comment(char	*str);
char		*get_name(char		*str);
char		*get_comment(char	*str);
int		swap_nbr(int		nbr);
int		my_strlen(char		*str);
char		*my_strfusion(char	*str,
			      char	*str2);
int		create_cor(char		*file);
char		*take_after(char	*str,
			    char	c);
char		*take_begin(char	*str,
			    char	c);
int		my_strcmp(char		*s1,
			  char		*s2);
int		my_strcmp_2(char	*s1,
			    char	*s2);
int		create_header(int	fd,
			      int	fdwrite);
t_asm		*add_action(t_asm	*list,
			    char	*ins,
			    char	*param);
int		write_instructions(int	fd,
				   int	fdwrite);
char		*remove_space(char	*str);

int             agregate(char *nb, int *i, char *tmp);

int             get_args(t_arg *arg, char *nb, int *i, char *tmp);
int             live(char *param, int fdwrite, char code);
int             sti(char *param, int fdwrite, char code);
int             ld(char *param, int fdwrite, char code);
int             and(char *param, int fdwrite, char code);
int		countword(char *str, char caract);
int		current(char *str, char caract);
char		**my_str_to_wordtab(char *str, char caract);
#endif /* _COMPILATOR */
