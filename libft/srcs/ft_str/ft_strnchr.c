/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:40:30 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:41:18 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_strnchr(char *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
