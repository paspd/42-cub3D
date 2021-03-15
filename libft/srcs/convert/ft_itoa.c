/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:10:29 by ldauga            #+#    #+#             */
/*   Updated: 2021/01/22 15:59:08 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_intlen(int n)
{
	unsigned int	nbr;
	int				len;

	len = 1;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	else
		nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	if (n == 0)
		len = 2;
	return (len);
}

char		*ft_itoa(int n)
{
	int				length;
	int				negative;
	char			*str;
	unsigned int	nbr;

	negative = (n < 0) ? 1 : 0;
	length = ft_intlen(n) - 1;
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (0);
	if (n == 0)
		str[0] = '0';
	str[length] = 0;
	if (negative)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	while (length-- > negative)
	{
		str[length] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
