//
// Created by flashman on 8/15/20.
//

# include "window.h"

int		error_exit(char *str, int i)
{
	ft_putstr(str);
	return (i);
}

void	init_win(t_win *win)
{
	win->quit = 0;
	win->is_mouse_button_down = 0;
	win->window_width = 680;
	win->window_height = 480;
	win->window = SDL_CreateWindow("SDL2 Window",
								   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win->window_width,
								   win->window_height, SDL_WINDOW_RESIZABLE);
	if (!win->window)
		error_exit("Failed to create window\n", 2);
	win->ren = SDL_CreateRenderer(win->window, -1, 1);
	if (!win->ren)
		error_exit("Failed to create renderer\n", 3);
}

void 	quit_win(t_win *win)
{
	win->quit = 1;
	SDL_RenderClear(win->ren);
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->window);
}
