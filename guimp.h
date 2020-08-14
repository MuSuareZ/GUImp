/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:41 by flashman          #+#    #+#             */
/*   Updated: 2020/08/14 14:27:28 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_GUIMP_H
# define GUIMP_GUIMP_H

# include "libft/libft.h"
# include <math.h>
# include <SDL2/SDL.h>

typedef	struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_env
{
	SDL_Window		*window;
	SDL_Surface		*window_surface;
	SDL_Event		event;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	SDL_Surface		*bmp;
	SDL_Rect		eraser;
	t_point			mouse_pos;
	int				brush_radius;
	int				is_mouse_button_down;
	int				window_width;
	int				window_height;
	int				quit;
}				t_env;

#endif
