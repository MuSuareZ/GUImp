#ifndef GUIMP_WINDOW_H
# define GUIMP_WINDOW_H

# include "guimp.h"
# include <SDL2/SDL.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Renderer	*ren;
	t_point			mouse_pos;
	int				is_mouse_button_down;
	int				window_width;
	int				window_height;
	int				quit;
}					t_win;

int					error_exit(char *str, int i);
void				init_win(t_win *win);
void				quit_win(t_win *win);
#endif
