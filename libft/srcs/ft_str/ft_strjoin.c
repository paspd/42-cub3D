/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:19:52 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:39:21 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n] = 0;
	free(s1);
	return (str);
}
