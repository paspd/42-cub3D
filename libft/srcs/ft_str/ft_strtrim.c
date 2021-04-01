/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:30:18 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:50:59 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_charset(char *set, char s1)
{
	int	i;

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
	int	k;

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

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	if (!s1)
		return (0);
	while (!ft_charset(set, s1[i]))
		i++;
	y = ft_strlen(s1) - 1;
	while (y > 0 && ft_charset(set, s1[y]) == 0)
		y--;
	if (y <= i)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
	}
	else
	{
		str = malloc(sizeof(char) * (y - i + 2));
		if (!str)
			return (0);
	}
	return (chaine(i, y, str, s1));
}
