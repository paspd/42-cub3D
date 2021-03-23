/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:41:57 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:57:34 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;
	int		a;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != (((unsigned char *)s2)[i]))
		{
			a = ((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]);
			return (a);
		}
		i++;
	}
	return (0);
}
