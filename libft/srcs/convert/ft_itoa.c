/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:10:29 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:24:38 by ldauga           ###   ########lyon.fr   */
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

char	*ft_itoa(int n)
{
	int				length;
	char			*str;
	unsigned int	nbr;

	length = ft_intlen(n) - 1;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[length] = 0;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	while (length-- > (n < 0))
	{
		str[length] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
