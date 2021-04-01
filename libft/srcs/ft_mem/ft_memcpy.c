/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:23:12 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:27:23 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t		i;
	char		*s1;
	char		*s2;

	if (dst == NULL && src == NULL)
		return (0);
	s1 = dst;
	s2 = src;
	i = 0;
	while (n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	return (s1);
}
