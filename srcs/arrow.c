/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:05:31 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 10:20:09 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	left_arrow(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->rc.dir_x;
	cub->rc.dir_x = cub->rc.dir_x * cos(-cub->player.rotate_speed) - \
		cub->rc.dir_y * sin(-cub->player.rotate_speed);
	cub->rc.dir_y = old_dir_x * sin(-cub->player.rotate_speed) + \
		cub->rc.dir_y * cos(-cub->player.rotate_speed);
	old_plane_x = cub->rc.plane_x;
	cub->rc.plane_x = cub->rc.plane_x * cos(-cub->player.rotate_speed) - \
		cub->rc.plane_y * sin(-cub->player.rotate_speed);
	cub->rc.plane_y = old_plane_x * sin(-cub->player.rotate_speed) + \
		cub->rc.plane_y * cos(-cub->player.rotate_speed);
}

void	right_arrow(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->rc.dir_x;
	cub->rc.dir_x = cub->rc.dir_x * cos(cub->player.rotate_speed) - \
		cub->rc.dir_y * sin(cub->player.rotate_speed);
	cub->rc.dir_y = old_dir_x * sin(cub->player.rotate_speed) + \
		cub->rc.dir_y * cos(cub->player.rotate_speed);
	old_plane_x = cub->rc.plane_x;
	cub->rc.plane_x = cub->rc.plane_x * cos(cub->player.rotate_speed) - \
		cub->rc.plane_y * sin(cub->player.rotate_speed);
	cub->rc.plane_y = old_plane_x * sin(cub->player.rotate_speed) + \
		cub->rc.plane_y * cos(cub->player.rotate_speed);
}
