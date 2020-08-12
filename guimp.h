/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:41 by flashman          #+#    #+#             */
/*   Updated: 2020/08/12 18:59:28 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_GUIMP_H
# define GUIMP_GUIMP_H

# include "libft/libft.h"
# include <SDL2/SDL.h>

typedef struct	s_env
{
	SDL_Window		*window;
	SDL_Surface		*window_surface;
	SDL_Event		event;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	SDL_Surface		*bmp;
	int				window_width;
	int				window_height;
	int				quit;
}				t_env;

#endif
