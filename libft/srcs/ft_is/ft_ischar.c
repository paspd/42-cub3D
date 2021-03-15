/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:45:58 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/04 12:47:56 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_ischar(char *str, int c)
{
	int i;

	if (!str)
	return (0);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}