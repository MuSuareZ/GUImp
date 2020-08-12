/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:35:06 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/23 22:39:45 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *iter;

	if (alst != NULL && new != NULL)
	{
		iter = *alst;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
		new->next = NULL;
	}
}
