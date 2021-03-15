/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:01:42 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/01 13:14:08 by leodauga         ###   ########.fr       */
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
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (0);
	while (s[y])
	{
		dest[y] = (*f)(y, s[y]);
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
