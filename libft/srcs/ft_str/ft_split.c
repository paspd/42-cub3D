/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:39:04 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:36:08 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static char	**ft_malloc_tab(char **result, char *str, char c, int size)
{
	int	i;
	int	check;
	int	word_nb;

	word_nb = 0;
	i = 0;
	while (i < size)
	{
		check = 0;
		while (str[i] != c && i++ < size)
			check++;
		if (check > 0)
			word_nb++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (word_nb + 1));
	if (!result)
		return (NULL);
	return (result);
}

static int	ft_malloc_str(char **result, char *str, char c, int size)
{
	int	i;
	int	k;
	int	big;

	i = 0;
	k = 0;
	while (i < size)
	{
		big = 0;
		while (str[i] != c && i++ < size)
			big++;
		if (big > 0)
		{
			result[k] = (char *)malloc(sizeof(char) * (big + 1));
			if (!result[k++])
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_filling(char **result, char *str, char c, int size)
{
	int	i;
	int	index;
	int	tab;

	i = 0;
	tab = 0;
	while (i < size)
	{
		index = 0;
		while (str[i] != c && i < size)
		{
			result[tab][index] = str[i];
			result[tab][index + 1] = '\0';
			i++;
			index++;
		}
		if (index > 0)
			tab++;
		i++;
	}
	result[tab] = 0;
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		size;
	int		i;

	size = 0;
	result = 0;
	if (!(s))
		return (NULL);
	while (s[size])
		size++;
	result = ft_malloc_tab(result, s, c, size);
	if (!result)
		return (NULL);
	if (!(ft_malloc_str(result, s, c, size)))
	{
		i = 0;
		while (result[i])
			free(result[i++]);
		free(result);
		return (NULL);
	}
	ft_filling(result, s, c, size);
	return (result);
}
