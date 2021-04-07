/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:08:53 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:20:39 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	put_gray(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->wind.height)
	{
		x = 0;
		while (x < cub->wind.width)
		{
			cub->rci.addr[y * cub->rci.line_length + x] = 0x00555555;
			x++;
		}
		y++;
	}
}

void	full_map_2(t_cub *cub, int y, int x)
{
	if (ft_ischar("NSEW.", cub->map.tab_map[y][x]))
		multiply_px_map(cub, cub->floor.color, y, x);
	if (cub->map.tab_map[y][x] == '|')
		multiply_px_map(cub, 0x00FF0000, y, x);
	if (cub->map.tab_map[y][x] == '#')
		multiply_px_map(cub, 0x0000FF00, y, x);
	if (cub->map.tab_map[y][x] == '$')
		multiply_px_map(cub, 0x00FFFF00, y, x);
}

void	full_map(t_cub *cub)
{
	int	x;
	int	y;

	usleep(10000);
	if (cub->verif.full_map)
	{
		put_gray(cub);
		y = 0;
		while (cub->map.tab_map[y])
		{
			x = 0;
			while (cub->map.tab_map[y][x])
			{
				full_map_2(cub, y, x);
				x++;
			}
			y++;
		}
		multiply_px_map(cub, 0x00FF00FF, cub->player.y, cub->player.x);
	}
	mlx_put_image_to_window(cub->mlx.id, cub->wind.id, cub->rci.img, 0, 0);
}

void	multiply_px_map(t_cub *cub, int color, int y, int x)
{
	cub->m.temp_color = color;
	cub->m.ty = cub->map.y_full_map_coef * y;
	cub->m.my = cub->m.ty + cub->map.y_full_map_coef;
	while (cub->m.ty < cub->m.my)
	{
		cub->m.tx = cub->map.x_full_map_coef * x;
		cub->m.mx = cub->m.tx + cub->map.x_full_map_coef;
		while (cub->m.tx < cub->m.mx)
		{
			color = cub->m.temp_color;
			if (cub->m.tx == cub->map.x_full_map_coef * x || cub->m.tx == cub->m.mx - 1 || \
				cub->m.ty == cub->map.y_full_map_coef * y \
					|| cub->m.ty == cub->m.my - 1)
			{
				if (ft_ischar("|$#", cub->map.tab_map[y][x]))
					color = 0x00222222;
				if (x == (int)cub->player.x && y == (int)cub->player.y)
					color = 0x00FFFFFF;
			}
			cub->rci.addr[cub->m.ty * cub->rci.line_length + cub->m.tx] = color;
			cub->m.tx++;
		}
		cub->m.ty++;
	}
}
