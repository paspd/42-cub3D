/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:36:08 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:36:18 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	error(char *error_msg, t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->texture.no_texture != NULL)
		free(cub->texture.no_texture);
	if (cub->texture.so_texture != NULL)
		free(cub->texture.so_texture);
	if (cub->texture.we_texture != NULL)
		free(cub->texture.we_texture);
	if (cub->texture.ea_texture != NULL)
		free(cub->texture.ea_texture);
	if (cub->texture.texture_sprite != NULL)
		free(cub->texture.texture_sprite);
	if (cub->map.tab_map != NULL)
	{
		while (cub->map.tab_map[i])
			free(cub->map.tab_map[i++]);
		free(cub->map.tab_map);
	}
	ft_close_files(cub->file.file_fd);
	ft_putstr_color("Error\n", "\033[31m\033[1m");
	ft_putstr_color(error_msg, "\033[38;5;166m");
	exit(-1);
}

int	game_finish(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->texture.no_texture != NULL)
		free(cub->texture.no_texture);
	if (cub->texture.so_texture != NULL)
		free(cub->texture.so_texture);
	if (cub->texture.we_texture != NULL)
		free(cub->texture.we_texture);
	if (cub->texture.ea_texture != NULL)
		free(cub->texture.ea_texture);
	if (cub->texture.texture_sprite != NULL)
		free(cub->texture.texture_sprite);
	if (cub->map.tab_map != NULL)
	{
		while (cub->map.tab_map[i])
			free(cub->map.tab_map[i++]);
		free(cub->map.tab_map);
	}
	ft_close_files(cub->file.file_fd);
	ft_putstr_color("Game finish.\n", "\033[38;5;166m");
	exit(1);
}
