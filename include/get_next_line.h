/*
** get_next_line.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_getnextline
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Mon Jan  4 09:59:31 2016 Eric DESCHODT
** Last update Wed Mar 23 15:30:03 2016 Léo Hubert
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>

# ifndef READ_SIZE
#  define READ_SIZE (6)
# endif /* !READ_SIZE */

# ifndef BUF
#  define BUF (READ_SIZE + 1)
# endif /* !BUF */

char   	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
