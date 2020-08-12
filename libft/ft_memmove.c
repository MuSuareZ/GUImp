/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:21 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/25 18:19:30 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int				iter;
	int				n;
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;
	unsigned char	*buffer;

	iter = 0;
	n = (int)len;
	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	buffer = (unsigned char*)malloc(sizeof(size_t) * len);
	while (iter < n)
	{
		buffer[iter] = src_ptr[iter];
		iter++;
	}
	iter = 0;
	while (n--)
	{
		dst_ptr[iter] = buffer[iter];
		iter++;
	}
	if (buffer)
		free(buffer);
	return (dst_ptr);
}
