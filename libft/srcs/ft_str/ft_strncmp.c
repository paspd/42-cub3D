/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:53:52 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/01 13:14:08 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int				i;
	int				limit;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	limit = n;
	while (i < limit)
	{
		a = s1[i];
		b = s2[i];
		if (a != b || !s1[i] || !s2[i])
			return (a - b);
		i++;
	}
	return (0);
}
