/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:22:49 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:52:25 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*christof;
	t_list	*result;

	if (!lst)
		return (NULL);
	christof = 0;
	while (lst)
	{
		result = ft_lstnew(f(lst->content));
		if (!result)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&christof, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&christof, result);
	}
	return (christof);
}
