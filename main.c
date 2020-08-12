/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flashman <flashman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:36 by flashman          #+#    #+#             */
/*   Updated: 2020/08/12 13:52:30 by flashman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int		error_exit(char *str, int i)
{
	ft_putstr(str);
	return (i);
}

int		main(int argc, char *argv[])
{
	SDL_Window	*window;
	SDL_Surface	*window_surface;

	if (argv[0] != 0)
		argc++;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error_exit("Failed to initialize the SDL2 library\n", 1);
	window = SDL_CreateWindow("SDL2 Window",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
	if (!window)
		error_exit("Failed to create window\n", 2);
	window_surface = SDL_GetWindowSurface(window);
	if (!window_surface)
		error_exit("Failed to get the surface from the window\n", 3);
	SDL_Event event;
	SDL_PollEvent(&event);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
