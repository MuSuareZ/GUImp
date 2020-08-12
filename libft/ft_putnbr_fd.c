/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:59:46 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/22 13:09:49 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_catch_negative_max(int nb)
{
	if (nb == -2147483648)
	{
		return (-2147483647);
	}
	else
	{
		return (nb);
	}
}

static int	ft_offset_negative_max(int nb)
{
	if (nb == -2147483648)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	ft_invert_negative(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		return (nb * -1);
	}
	else
	{
		return (nb);
	}
}

static void	ft_print_offset(int offset, int result, int fd)
{
	if (offset == 1)
	{
		ft_putchar_fd(result + offset + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int value;
	int result[10];
	int count;
	int offset;

	count = 0;
	offset = ft_offset_negative_max(n);
	value = ft_catch_negative_max(n);
	value = ft_invert_negative(value, fd);
	while (value > 9)
	{
		result[count] = value % 10;
		value = value / 10;
		count++;
	}
	ft_putchar_fd(value + '0', fd);
	count--;
	while (count != -1 + offset)
	{
		ft_putchar_fd(result[count] + '0', fd);
		count--;
	}
	ft_print_offset(offset, result[count], fd);
}
