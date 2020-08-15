/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:41 by flashman          #+#    #+#             */
/*   Updated: 2020/08/15 17:04:53 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_GUIMP_H
# define GUIMP_GUIMP_H

# include "libft/libft.h"
# include "window.h"
# include <stdlib.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

typedef struct	s_env
{
	SDL_Event		event;
	SDL_Texture		*tex;
	SDL_Surface		*bmp;
	SDL_Rect		eraser;
	int				brush_radius;
}				t_env;

#endif
