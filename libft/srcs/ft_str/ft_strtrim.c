/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:30:18 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/01 13:14:08 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_charset(char *set, char s1)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

static char	*chaine(int i, int y, char *str, char *s1)
{
	int		k;

	k = 0;
	while (i <= y)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	if (!s1)
		return (0);
	while (!ft_charset(set, s1[i]))
		i++;
	y = ft_strlen(s1) - 1;
	while (y > 0 && ft_charset(set, s1[y]) == 0)
		y--;
	if (y <= i)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (0);
	}
	else if (!(str = malloc(sizeof(char) * (y - i + 2))))
		return (0);
	return (chaine(i, y, str, s1));
}
