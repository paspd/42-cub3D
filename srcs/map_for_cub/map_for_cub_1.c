/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_for_cub_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:55:30 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/01 16:12:13 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/map_for_cub.h"

void	mfc_error(char *error_msg)
{
	ft_putstr_color("ERROR: ", "\033[31m\033[1m");
	ft_putstr_color(error_msg, "\033[38;5;166m");
	exit(-1);
}

int	check_argv(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_isdigit(s1[i]))
			return (0);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ft_isdigit(s2[i]))
			return (0);
		i++;
	}
	return (1);
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
		if (!mfc->map[i])
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

int	randomizer_map(int percent_nb1, int percent_nb2)
{
	int	num;

	num = ft_rand_in_range(1, 100);
	if (num < percent_nb1)
		return ('2');
	else if (num < percent_nb2)
		return ('0');
	else
		return ('1');
}

void	new_map(t_mfc *mfc)
{
	int	x;
	int	y;

	y = 0;
	while (y < mfc->height)
	{
		x = 0;
		while (x < mfc->width)
		{
			if (y == 0 || y == mfc->height - 1 || x == 0 || x == mfc->width - 1)
				mfc->map[y][x] = '1';
			else
				mfc->map[y][x] = randomizer_map(5, 80);
			x++;
		}
		mfc->map[y][x] = 0;
		y++;
	}
	put_player(mfc);
	mfc->map[y] = 0;
}

int	main(int argc, char const *argv[])
{
	t_mfc	mfc;

	srand(time (NULL));
	if (argc != 3)
		mfc_error("You must put some args.\n");
	if (!check_argv(argv[1], argv[2]))
		mfc_error("Args are only digit.\n");
	mfc.nb_sprite = ft_rand_in_range(0, 10);
	mfc.width = ft_atoi((char *)argv[1]);
	mfc.height = ft_atoi((char *)argv[2]);
	if (mfc.height < 3 || mfc.width < 3)
		mfc_error("The smallest map is 3x3.\n");
	mfc.player_x = mfc.width / 2 + 0.5;
	mfc.player_y = mfc.height / 2 + 0.5;
	if (!malloc_map(&mfc))
		mfc_error("MALLOC error.\n");
	new_map(&mfc);
	mfc_aff_map(&mfc);
	free_map(&mfc);
	return (0);
}
