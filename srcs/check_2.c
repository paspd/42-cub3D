/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:51:22 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:57:41 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	check_ray_bis(t_cub *cub)
{
	if (cub->ray.node_dist_x < cub->ray.node_dist_y)
	{
		cub->ray.node_dist_x += cub->ray.delta_dist_x;
		cub->map.x += cub->ray.step_x;
		cub->verif.wall_side = 0;
	}
	else
	{
		cub->ray.node_dist_y += cub->ray.delta_dist_y;
		cub->map.y += cub->ray.step_y;
		cub->verif.wall_side = 1;
	}
	if (cub->map.tab_map[cub->map.y][cub->map.x] == '$' && check_s(cub))
	{
		cub->sprite.pos_x[cub->sprite.nb_sprite] = cub->map.x + 0.50;
		cub->sprite.pos_y[cub->sprite.nb_sprite] = cub->map.y + 0.50;
		cub->sprite.nb_sprite++;
		cub->verif.old_s_x = cub->map.x;
		cub->verif.old_s_y = cub->map.y;
	}
}
