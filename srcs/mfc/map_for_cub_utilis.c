/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_for_cub_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 08:38:31 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/02 08:55:30 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/map_for_cub.h"

int	randomizer_map(int percent_nb1, int percent_nb2)
{
	int	num;

	num = ft_rand_in_range(1, 100);
	if (num < percent_nb1)
		return (50);
	else if (num < percent_nb2)
		return (48);
	else
		return (49);
}

void	put_player(t_mfc *mfc)
{
	char	c;
	int		rand;

	rand = ft_rand_in_range(0, 3);
	if (rand == 0)
		c = 'N';
	if (rand == 1)
		c = 'W';
	if (rand == 2)
		c = 'E';
	if (rand == 3)
		c = 'S';
	mfc->map[mfc->player_y][mfc->player_x] = c;
}

int	malloc_map(t_mfc *mfc)
{
	int	i;

	i = 0;
	mfc->map = calloc(sizeof(char *), (mfc->height + 1));
	if (!mfc->map)
		return (0);
	while (i <= mfc->height)
	{
		mfc->map[i] = calloc(sizeof(char), mfc->width + 1);
		if (!mfc->map)
			return (0);
		i++;
	}
	return (1);
}

void	free_map(t_mfc *mfc)
{
	int	i;

	i = 0;
	while (i < mfc->height)
	{
		free(mfc->map[i]);
		i++;
	}
	free(mfc->map);
}
