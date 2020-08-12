/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:31:29 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/24 20:36:40 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret_fresh;
	t_list	*fresh;

	if (!lst)
		return (NULL);
	fresh = f(lst);
	ret_fresh = fresh;
	while (lst->next)
	{
		lst = lst->next;
		if (!(fresh->next = f(lst)))
		{
			free(fresh->next);
			return (NULL);
		}
		fresh = fresh->next;
	}
	return (ret_fresh);
}
