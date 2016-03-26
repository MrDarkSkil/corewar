/*
** loop.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Mar 26 09:36:26 2016 Eric DESCHODT
** Last update Sat Mar 26 10:49:25 2016 Eric DESCHODT
*/

#include "corewar.h"

t_bunny_response        mainloop(void *_data)
{
  t_data		*data;

  data = _data;
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response       key(t_bunny_event_state state,
                           t_bunny_keysym      key,
                           void                *p)
{
  (void)p;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_ERROR);
  return (GO_ON);
}

void			square(t_bunny_pixelarray *pix,
			       t_bunny_position size,
			       t_bunny_position	pos,
			       int champ)
{
  t_bunny_position	pixel;
  t_bunny_position	draw;
  t_color		color[6];
  
  color[0].full = WHITE;
  color[0].argb[3] = 100;
  color[1].full = RED;
  color[2].full = YELLOW;
  color[3].full = GREEN;
  color[4].full = BLUE;
  color[5].argb[0] = 100;
  color[5].argb[1] = 100;
  color[5].argb[2] = 100;
  color[5].argb[3] = 255;
  pixel.y = 0;
  while (pixel.y < size.y)
    {
      pixel.x = 0;
      while (pixel.x < size.x)
	{
	  draw.x = pos.x + pixel.x;
	  draw.y = pos.y + pixel.y;
	  if (pixel.x < 1 || pixel.x >= size.x - 1
	      || pixel.y < 1 || pixel.y >= size.y - 1)
	    tekpixel(pix, &draw, &color[5]);
	  else
	    tektranspa(pix, &draw, &color[champ]);
	  pixel.x++;
	}
      pixel.y++;
    }
}

void			printboardgraph(t_bunny_pixelarray *pix,
					unsigned char *board)
{
  int			i;
  t_bunny_position	pos;
  t_bunny_position	size;

  pos.x = 0;
  pos.y = 70;
  size.x = 10;
  size.y = 10;
  i = 0;
  while (i < MEM_SIZE)
    {
      square(pix, size, pos, board[i]);
      pos.x += size.x;
      i++;
      if (i % 101 == 0)
	{
	  pos.x = 0;
	  pos.y += size.y;
	}
    }
}
