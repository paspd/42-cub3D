/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:41:51 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 15:49:32 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	init_structs(char *path, t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	check_file_path(path, cub);
	cub->verif.gnl = 1;
	cub->base.dec = "0123456789";
	cub->base.hex = "0123456789ABCDEF";
	cub->verif.old_key = 2147483647;
	cub->player.rotate_speed = 0.05;
	cub->player.speed = 0.09;
}

void	init_node_dist(t_cub *cub)
{
	if (cub->ray.dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.node_dist_x = (cub->player.x - cub->map.x) \
			* cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.node_dist_x = (cub->map.x + 1.0 - cub->player.x) \
			* cub->ray.delta_dist_x;
	}
	if (cub->ray.dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.node_dist_y = (cub->player.y - cub->map.y) \
			* cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.node_dist_y = (cub->map.y + 1.0 - cub->player.y) \
			* cub->ray.delta_dist_y;
	}
}

void	init_vector(t_cub *cub)
{
	if (ft_ischar("NS", cub->player.spawn_direction))
	{
		cub->rc.plane_x = 0.66;
		cub->rc.plane_y = 0;
		if (cub->player.spawn_direction == 'N')
		{
			cub->rc.dir_x = 0;
			cub->rc.dir_y = -1;
		}
		else
		{
			cub->rc.dir_x = 0;
			cub->rc.dir_y = 1;
		}
	}
	else
		norm(cub);
}

void	init_final_img(t_cub *cub)
{
	cub->rci.img = mlx_new_image(cub->mlx.id, \
		cub->wind.width, cub->wind.height);
	if (!cub->rci.img)
		error("MLX error.\n", cub);
	cub->rci.addr = (int *)mlx_get_data_addr(cub->rci.img, \
		&cub->rci.bits_per_pixel, &cub->rci.line_length, &cub->rci.endian);
	if (!cub->rci.addr)
		error("MLX error.\n", cub);
	cub->rci.line_length /= 4;
	cub->sky.img = mlx_xpm_file_to_image(cub->mlx.id, \
		"./textures/ciel_3.xpm", &cub->sky.width, &cub->sky.height);
	if (!cub->sky.img)
		error("MLX error.\n", cub);
	cub->sky.addr = (int *)mlx_get_data_addr(cub->sky.img, \
		&cub->sky.bits_per_pixel, &cub->sky.line_length, &cub->sky.endian);
}

void	init_img(t_cub *cub)
{
	init_final_img(cub);
	init_no(cub);
	init_so(cub);
	init_we(cub);
	init_ea(cub);
	init_sprite(cub);
}
