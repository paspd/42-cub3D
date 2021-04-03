/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:15:32 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:27:11 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

int	raycasting(t_cub *cub)
{
	int x;

	x = 0;
	usleep(20000);
	if (cub->verif.full_map)
		full_map(cub);
	else
	{
		check_move(cub);
		while (x < cub->wind.width)
		{
			cub->rc.camera = 2 * x / (double)cub->wind.width - 1;
			cub->ray.dir_x = cub->rc.dir_x + cub->rc.plane_x * cub->rc.camera;
	    	cub->ray.dir_y = cub->rc.dir_y + cub->rc.plane_y * cub->rc.camera;
			cub->map.x = (int)cub->player.x;
			cub->map.y = (int)cub->player.y;
			cub->ray.delta_dist_x = fabs(1 / cub->ray.dir_x);
			cub->ray.delta_dist_y = fabs(1 / cub->ray.dir_y);
			init_node_dist(cub);
			check_ray(cub);
			draw(cub, x);
			cub->rc.buff[x] = cub->ray.dist_wall;
			x++;
		}
		aff_sprite(cub);
		aff_map_wind(cub);
		if (cub->verif.save)
			screen_shoot(cub);
		mlx_clear_window(cub->mlx.id, cub->wind.id);
		mlx_put_image_to_window(cub->mlx.id, cub->wind.id, cub->rci.img, 0, 0);
		check_direction(cub);
		cub->sprite.nb_sprite = 0;
	}
	return (1);
}

void	check_ray(t_cub *cub)
{
	cub->verif.wall = 0;
		while (cub->verif.wall == 0)
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
			if (ft_ischar("|#", cub->map.tab_map[cub->map.y][cub->map.x]))
				cub->verif.wall = 1;
		}
		if (cub->verif.wall_side == 0)
			cub->ray.dist_wall = (cub->map.x - cub->player.x + \
				(1 - cub->ray.step_x) / 2) / cub->ray.dir_x;
		else
			cub->ray.dist_wall = (cub->map.y - cub->player.y + \
				(1 - cub->ray.step_y) / 2) / cub->ray.dir_y;
}

void	select_texture(t_cub *cub)
{
	if (!cub->verif.wall_side && cub->map.x < cub->player.x)
	{
		cub->tex.addr = cub->we.addr;
		cub->tex.height = cub->we.height;
		cub->tex.width = cub->we.width;
		cub->verif.side = 0;
	}
	else if (!cub->verif.wall_side && cub->map.x > cub->player.x)
	{
		cub->tex.addr = cub->ea.addr;
		cub->tex.height = cub->ea.height;
		cub->tex.width = cub->ea.width;
		cub->verif.side = 1;
	}
	else if (cub->verif.wall_side && cub->map.y < cub->player.y)
	{
		cub->tex.addr = cub->no.addr;
		cub->tex.height = cub->no.height;
		cub->tex.width = cub->no.width;
		cub->verif.side = 2;
	}
	else if (cub->verif.wall_side && cub->map.y > cub->player.y)
	{
		cub->tex.addr = cub->so.addr;
		cub->tex.height = cub->so.height;
		cub->tex.width = cub->so.width;
		cub->verif.side = 3;
	}
}

void	check_4_texture(t_cub *cub)
{
	if (cub->verif.wall_side)
		cub->texture.coef_x = cub->player.x + ((cub->map.y - cub->player.y + (1 - cub->ray.step_y) / 2) / cub->ray.dir_y) * cub->ray.dir_x;
	else
		cub->texture.coef_x = cub->player.y + ((cub->map.x - cub->player.x + (1 - cub->ray.step_x) / 2) / cub->ray.dir_x) * cub->ray.dir_y;
	cub->texture.coef_x -= floor(cub->texture.coef_x);
	select_texture(cub);
	cub->texture.x = (int)(cub->texture.coef_x * (double)(cub->tex.width));
	if (cub->verif.wall_side == 0 && cub->rc.dir_x > 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
	else if (cub->verif.wall_side && cub->rc.dir_y < 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
}
