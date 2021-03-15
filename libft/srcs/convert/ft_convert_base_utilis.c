/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_utilis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:59:31 by leodauga          #+#    #+#             */
/*   Updated: 2021/02/10 13:00:54 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		ft_len(int nbr, char *base)
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
	if (!(retour = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_putnbr_base(nbr, base_to, retour, i - 1);
	retour[i] = 0;
	return (retour);
}