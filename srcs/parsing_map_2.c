/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:01:40 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:02:56 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

char	*ft_strjoin_cub(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * i + 2)))
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n++] = '\n';
	str[n] = 0;
	free(s1);
	return (str);
}

void	fill_flood_map(t_cub *cub, int y, int x)
{
	if (y < 0 || x < 0 || y > (ft_tablen(cub) - 1) || \
		x > ((int)ft_strlen(cub->map.tab_map[y]) - 1))
		error("The map is not close.\n", cub);
	if (ft_ischar("|.$#", cub->map.tab_map[y][x]))
		return ;
	if (cub->map.tab_map[y][x] == '1')
	{
		cub->map.tab_map[y][x] = '|';
		return ;
	}
	if (cub->map.tab_map[y][x] == '0')
		cub->map.tab_map[y][x] = '.';
	if (cub->map.tab_map[y][x] == '2')
		cub->map.tab_map[y][x] = '$';
	if (cub->map.tab_map[y][x] == '3')
		cub->map.tab_map[y][x] = '#';
	fill_flood_map(cub, y - 1, x);
	fill_flood_map(cub, y + 1, x);
	fill_flood_map(cub, y, x - 1);
	fill_flood_map(cub, y, x + 1);
}
