/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_for_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 08:35:32 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/02 08:43:31 by ldauga           ###   ########lyon.fr   */
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

void	mfc_aff_map(t_mfc *mfc)
{
	int	y;

	y = 0;
	while (mfc->map[y])
		dprintf(1, "%s\n", mfc->map[y++]);
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
	srand	(time(NULL));

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
