/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:36 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/01 13:14:08 by leodauga         ###   ########.fr       */
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
	if (!(str = malloc(sizeof(char) * len + 1)))
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
