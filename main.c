/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:36 by flashman          #+#    #+#             */
/*   Updated: 2020/08/12 18:55:53 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int		error_exit(char *str, int i)
{
	ft_putstr(str);
	return (i);
}

void	init_env(int argc, char *argv[], t_env *env)
{
	env->window_width = 680;
	env->window_height = 480;
	if (argv[0] != 0)
		argc++;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error_exit("Failed to initialize the SDL2 library\n", 1);
	env->window = SDL_CreateWindow("SDL2 Window",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, env->window_width,
	env->window_height, SDL_WINDOW_RESIZABLE);
	if (!env->window)
		error_exit("Failed to create window\n", 2);
	env->window_surface = SDL_GetWindowSurface(env->window);
	if (!env->window_surface)
		error_exit("Failed to get the surface from the window\n", 3);
	// 1 in my computer is the opengl, I tried from 0 to 3 (0 is metal, 2 is opengles2, 3 is software)
	env->ren = SDL_CreateRenderer(env->window, -1, 1);
	if (!env->ren)
		error_exit("Failed to create renderer\n", 4);
	// I was trying with a picture that I had here that worked before without the renderer
	// Just try it with a bmp picture u have there
	env->bmp = SDL_LoadBMP("/Users/murillosuarez/Desktop/fon.bmp");
	if (!env->bmp)
		error_exit("Failed to load BMP\n", 5);
	env->tex = SDL_CreateTextureFromSurface(env->ren, env->bmp);
	SDL_FreeSurface(env->bmp);
	if (!env->tex)
		error_exit("Failed to load texture\n", 6);
}

int		main(int argc, char *argv[])
{
	t_env			*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	init_env(argc, argv, env);
	env->quit = 0;
	while (!env->quit)
	{
		while (SDL_PollEvent(&env->event) != 0)
		{
			if (env->event.type == SDL_QUIT)
				env->quit = 1;
		}
		SDL_RenderClear(env->ren);
		SDL_RenderCopy(env->ren, env->tex, NULL, NULL);
		SDL_RenderPresent(env->ren);
		SDL_UpdateWindowSurface(env->window);
	}
	SDL_DestroyTexture(env->tex);
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->window);
	SDL_Quit();
	return (0);
}
