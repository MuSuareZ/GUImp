/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:54:53 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/23 22:26:49 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_invert_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (n * -1);
	}
	return (n);
}

static int	handle_negative_min(void)
{
	ft_putnbr(-21474);
	ft_putnbr(83648);
	return (1);
}

void		ft_putnbr(int n)
{
	int value;
	int result[10];
	int count;

	if (n == ft_edgeint("min") && handle_negative_min())
		return ;
	count = 0;
	value = ft_invert_negative(n);
	while (value > 9)
	{
		result[count] = value % 10;
		value = value / 10;
		count++;
	}
	ft_putchar(value + '0');
	count--;
	while (count != -1)
		ft_putchar(result[count--] + '0');
}
