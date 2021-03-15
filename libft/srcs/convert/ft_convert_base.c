/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:55:32 by leodauga          #+#    #+#             */
/*   Updated: 2021/03/03 12:43:58 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		verif_base(char *base)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (base[++i])
	{
		if ((base[i] == '+' || base[i] == '-') ||
				(base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	if (j < 2)
		return (0);
	return (i);
}

int		is_ok(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		convert(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int				i;
	int				j;
	int				sign;
	int				nb;

	i = 0;
	sign = 0;
	nb = 0;
	j = verif_base(base);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign++;
	while (str[i] && (is_ok(base, str[i]) == 1))
	{
		nb = nb * j + convert(str[i], base);
		i++;
	}
	// free(str);
	return ((sign % 2 == 0) ? nb : -nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (verif_base(base_from) == 0 || verif_base(base_to) == 0)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	return (retour(nb, base_to));
}