/*
** comilator.h for compilator in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 17:53:01 2016 Léo Hubert
** Last update Wed Mar 23 12:31:32 2016 Eric DESCHODT
*/

#ifndef _COMPILATOR
#define _COMPILATOR

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "get_next_line.h"
#include "my.h"

char	*take_begin(char *str, char c);
char	*parse_name(char *str);
char	*parse_comment(char *str);
char	*get_name(char *str);
char	*get_comment(char *str);
int     swap_nbr(int nbr);
int	my_strlen(char *str);
char	*my_strfusion(char *str, char *str2);
int	create_cor(char *file);
char	*take_after(char *str, char c);
char	*take_begin(char *str, char c);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp_2(char *s1, char *s2);
int	create_header(int fd, int fdwrite);

#endif /* _COMPILATOR */
