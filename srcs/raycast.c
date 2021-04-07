/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:15:32 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:55:55 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	raycasting_bis(t_cub *cub)
{
	aff_sprite(cub);
	aff_map_wind(cub);
	if (cub->verif.save)
		screen_shoot(cub);
	mlx_clear_window(cub->mlx.id, cub->wind.id);
	mlx_put_image_to_window(cub->mlx.id, cub->wind.id, cub->rci.img, 0, 0);
	check_direction(cub);
	cub->sprite.nb_sprite = 0;
}

int	raycasting(t_cub *cub)
{
	int	x;

	x = 0;
	usleep(20000);
	if (cub->verif.full_map)
		full_map(cub);
	else
	{
		check_move(cub);
		while (x < cub->wind.width)
		{
			check_rayca(cub, x);
			init_node_dist(cub);
			check_ray(cub);
			draw(cub, x);
			cub->rc.buff[x] = cub->ray.dist_wall;
			x++;
		}
		raycasting_bis(cub);
	}
	return (1);
}

void	check_ray(t_cub *cub)
{
	cub->verif.wall = 0;
	while (cub->verif.wall == 0)
	{
		check_ray_bis(cub);
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
		cub->tex = cub->we;
		cub->verif.side = 0;
	}
	else if (!cub->verif.wall_side && cub->map.x > cub->player.x)
	{
		cub->tex = cub->ea;
		cub->verif.side = 1;
	}
	else if (cub->verif.wall_side && cub->map.y < cub->player.y)
	{
		cub->tex = cub->no;
		cub->verif.side = 2;
	}
	else if (cub->verif.wall_side && cub->map.y > cub->player.y)
	{
		cub->tex = cub->so;
		cub->verif.side = 3;
	}
}

void	check_4_texture(t_cub *cub)
{
	if (cub->verif.wall_side)
		cub->texture.coef_x = cub->player.x + ((cub->map.y - cub->player.y + \
			(1 - cub->ray.step_y) / 2) / cub->ray.dir_y) * cub->ray.dir_x;
	else
		cub->texture.coef_x = cub->player.y + ((cub->map.x - cub->player.x + \
			(1 - cub->ray.step_x) / 2) / cub->ray.dir_x) * cub->ray.dir_y;
	cub->texture.coef_x -= floor(cub->texture.coef_x);
	select_texture(cub);
	cub->texture.x = (int)(cub->texture.coef_x * (double)(cub->tex.width));
	if (cub->verif.wall_side == 0 && cub->rc.dir_x > 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
	else if (cub->verif.wall_side && cub->rc.dir_y < 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
}
