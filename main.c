/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:36 by flashman          #+#    #+#             */
/*   Updated: 2020/08/15 16:58:54 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "guimp.h"

void	init_env(t_env *env, t_win *win)
{
	env->eraser.w = 10;
	env->eraser.h = 10;
	env->brush_radius = 10;
	init_win(win);
	TTF_Init();
	// if (SDL_Init(SDL_INIT_VIDEO) < 0)
	// 	error_exit("Failed to initialize the SDL2 library\n", 1);
	// env->window = SDL_CreateWindow("SDL2 Window",
	// SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, env->window_width,
	// env->window_height, SDL_WINDOW_RESIZABLE);
	// if (!env->window)
	// 	error_exit("Failed to create window\n", 2);
	// env->ren = SDL_CreateRenderer(env->window, -1, 1);
	// if (!env->ren)
	// 	error_exit("Failed to create renderer\n", 3);
}

void	brush_tool(t_env *env, t_win *win)
{
	SDL_SetRenderDrawColor(win->ren, 255, 0, 0, 255);
	for(int y =- env->brush_radius; y <= env->brush_radius; y++)
		for(int x =- env->brush_radius; x <= env->brush_radius; x++)
			if(x * x + y * y <= env->brush_radius * env->brush_radius)
				SDL_RenderDrawPoint(win->ren, win->mouse_pos.x + x, win->mouse_pos.y + y);
}

void	eraser_tool(t_env *env, t_win *win)
{
	env->eraser.x = win->mouse_pos.x - env->eraser.w / 2;
	env->eraser.y = win->mouse_pos.y - env->eraser.h / 2;
	SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
	SDL_RenderFillRect(win->ren, &env->eraser);
}

void	clear_screen(t_win *win)
{
	SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
	SDL_RenderClear(win->ren);
}

int		main(void)
{
	t_win			*win;
	t_env			*env;
	//t_button		*button;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (-1);
	init_env(env, win);
	//button = new_button(win);
	//button->pro.pos.x = center(win->window_width, button->pro.siz.width);
	//button->pro.pos.y = 10;
	SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
	SDL_RenderClear(win->ren);
	while (!win->quit)
	{
		while (SDL_PollEvent(&env->event) != 0)
		{
			if (env->event.type == SDL_QUIT || env->event.button.button == SDL_SCANCODE_ESCAPE)
				quit_win(win);
			if (env->event.type == SDL_MOUSEBUTTONUP)
				win->is_mouse_button_down = 0;
			if (env->event.type == SDL_MOUSEBUTTONDOWN)
			{
				win->is_mouse_button_down = 1;
				//Button 1 = Left mouse click, Button 2 = Middle click, Button 3 = Right click
				//If you use Visual Studio or something, I really recommend hovering the mouse
				//over GetMouseState and SDL_BUTTON to see it's description message
				if (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(2))
					clear_screen(win);
				if (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1))
					brush_tool(env, win);
				if (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(3))
					eraser_tool(env, win);
			}
			if (env->event.type == SDL_MOUSEMOTION)
			{
				win->mouse_pos.x = env->event.button.x;
				win->mouse_pos.y = env->event.button.y;
				if (win->is_mouse_button_down && SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(3))
					eraser_tool(env, win);
				if (win->is_mouse_button_down && SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1))
					brush_tool(env, win);
			}
		}
		//render_button(button);
		SDL_RenderPresent(win->ren);
	}
	// SDL_DestroyRenderer(env->ren);
	// SDL_DestroyWindow(env->window);
	SDL_Quit();
	return (0);
}
