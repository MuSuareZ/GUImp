/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:36 by flashman          #+#    #+#             */
/*   Updated: 2020/08/13 19:45:16 by msuarez-         ###   ########.fr       */
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
	env->brush_radius = 10;
	env->is_mouse_button_down = 0;
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
	env->ren = SDL_CreateRenderer(env->window, -1, 1);
	if (!env->ren)
		error_exit("Failed to create renderer\n", 3);
}

void	draw_circle(t_env *env)
{
	for(int y =- env->brush_radius; y <= env->brush_radius; y++)
		for(int x =- env->brush_radius; x <= env->brush_radius; x++)
			if(x * x + y * y <= env->brush_radius * env->brush_radius)
				SDL_RenderDrawPoint(env->ren, env->mouse_pos.x + x, env->mouse_pos.y + y);
}

int		main(int argc, char *argv[])
{
	t_env			*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	init_env(argc, argv, env);
	SDL_SetRenderDrawColor(env->ren, 242, 242, 242, 255);
	SDL_RenderClear(env->ren);
	SDL_SetRenderDrawColor(env->ren, 255, 0, 0, 255);
	env->quit = 0;
	while (!env->quit)
	{
		while (SDL_PollEvent(&env->event) != 0)
		{
			if (env->event.type == SDL_QUIT)
				env->quit = 1;
			if (env->event.type == SDL_MOUSEMOTION)
			{
				env->mouse_pos.x = env->event.button.x;
				env->mouse_pos.y = env->event.button.y;
				if (env->is_mouse_button_down)
					draw_circle(env);
			}
			if (env->event.type == SDL_MOUSEBUTTONUP)
				env->is_mouse_button_down = 0;
			if (env->event.type == SDL_MOUSEBUTTONDOWN)
			{
				env->is_mouse_button_down = 1;
				draw_circle(env);
			}
		}
		ft_putstr("Mouse X: ");
		ft_putnbr(env->mouse_pos.x);
		ft_putstr("\n");
		ft_putstr("Mouse Y: ");
		ft_putnbr(env->mouse_pos.y);
		ft_putstr("\n\n");
		SDL_RenderPresent(env->ren);
	}
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->window);
	SDL_Quit();
	return (0);
}
