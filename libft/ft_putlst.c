/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusthol <krusthol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:44:38 by krusthol          #+#    #+#             */
/*   Updated: 2019/10/23 23:30:25 by krusthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst, void (f)(char const *s))
{
	if (lst != NULL)
		f(lst->content);
	if (lst->next != NULL)
		ft_putlst(lst->next, f);
}
