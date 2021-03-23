/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:36 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:38:40 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = 0;
	return ((char *)str);
}
