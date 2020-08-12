/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:17:14 by krusthol          #+#    #+#             */
/*   Updated: 2019/11/03 11:43:47 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int	minus;

	i = 0;
	while (*str && ft_isspace((int)*str))
		str++;
	if ((minus = (*str == '-')) || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
		i = i * 10 + (*str++ - 48);
	return (minus ? i * (-1) : i);
}
