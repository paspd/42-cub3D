/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_for_cub_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:08:43 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/01 16:14:15 by ldauga           ###   ########lyon.fr   */
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

void	mfc_aff_map(t_mfc *mfc)
{
	int	i;

	i = 0;
}

