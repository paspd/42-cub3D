/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_utilis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:22:59 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:23:00 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_len(int nbr, char *base)
{
	int			len;
	int			i;
	long int	nb;

	nb = nbr;
	len = ft_strlen(base);
	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb / len > 0)
	{
		nb /= len;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, char *retour, int i)
{
	unsigned int	nb;
	unsigned int	len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		retour[0] = '-';
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= len)
		ft_putnbr_base((nb / len), base, retour, i - 1);
	retour[i] = (base[nb % len]);
}

char	*retour(int nbr, char *base_to)
{
	int		i;
	char	*retour;

	i = ft_len(nbr, base_to);
	retour = (char *)malloc(sizeof(char) * (i + 1));
	if (!retour)
		return (0);
	ft_putnbr_base(nbr, base_to, retour, i - 1);
	retour[i] = 0;
	return (retour);
}
