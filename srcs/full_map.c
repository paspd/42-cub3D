/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:08:53 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 12:48:19 by ldauga           ###   ########lyon.fr   */
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

int	multiply_px_map_bis(t_cub *cub, int y, int x, int temp_color)
{
	if (ft_ischar("|$#", cub->map.tab_map[y][x]))
		return (0x00222222);
	if (x == (int)cub->player.x && y == (int)cub->player.y)
		return (0x00FFFFFF);
	return (temp_color);
}

void	multiply_px_map(t_cub *cub, int color, int y, int x)
{
	int	temp_color;
	int	tx;
	int	ty;
	int	mx;
	int	my;

	temp_color = color;
	ty = cub->map.y_full_map_coef * y;
	my = ty + cub->map.y_full_map_coef;
	while (ty < my)
	{
		tx = cub->map.x_full_map_coef * x;
		mx = tx + cub->map.x_full_map_coef;
		while (tx < mx)
		{
			color = temp_color;
			if (tx == cub->map.x_full_map_coef * x || tx == mx - 1 || \
				ty == cub->map.y_full_map_coef * y || ty == my - 1)
				multiply_px_map_bis(cub, y, x, temp_color);
			cub->rci.addr[ty * cub->rci.line_length + tx] = color;
			tx++;
		}
		ty++;
	}
}
