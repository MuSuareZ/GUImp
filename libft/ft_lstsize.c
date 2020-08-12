/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:46:03 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/23 22:51:26 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **alst)
{
	t_list	*iter;
	int		i;

	if (alst != NULL)
	{
		i = 1;
		iter = *alst;
		while (iter->next)
		{
			iter = iter->next;
			i++;
		}
		return (i);
	}
	return (0);
}
