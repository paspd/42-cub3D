/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:01:42 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:40:16 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	y;
	char			*dest;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	while (s[y])
	{
		dest[y] = (*f)(y, s[y]);
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
