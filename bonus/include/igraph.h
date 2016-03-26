/*
** libtekgui.h for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 13:19:12 2016 Eric DESCHODT
** Last update Sat Mar 26 10:21:43 2016 Eric DESCHODT
*/

#ifndef			IGRAPH_H_
# define		IGRAPH_H_

# include <unistd.h>
# include "lapin.h"
# include "libgraph.h"

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_texture		*back;
  t_bunny_position	size;
  t_bunny_position	pos;
}			t_data;

t_bunny_response        mainloop(void *_data);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym      key,
			    void                *p);

void                    square(t_bunny_pixelarray *pix,
                               t_bunny_position size,
                               t_bunny_position pos,
                               int champ);

void                    printboardgraph(t_bunny_pixelarray *pix,
                                        unsigned char *board);

# endif /* IGRAPH_H_ */

