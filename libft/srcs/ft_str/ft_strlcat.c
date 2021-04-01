/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:15:12 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:39:38 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_strlen2(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *s1, char *s2, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen2(s2) + dstsize);
	while (s1[i] != '\0' && i < dstsize)
		i++;
	j = i;
	while (s2[i - j] != '\0' && i < dstsize - 1)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < dstsize)
		s1[i] = '\0';
	return (j + ft_strlen2(s2));
}
