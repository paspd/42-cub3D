/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:10:41 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:20:17 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	aff_map_wind(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	if (cub->verif.map)
	{
		while (cub->map.tab_map[y])
		{
			x = 0;
			while (cub->map.tab_map[y][x])
			{
				if (cub->map.tab_map[y][x] == '|')
					multiply_px_minimap(cub, 0x00FF0000, y, x);
				else if (cub->map.tab_map[y][x] == '#')
					multiply_px_minimap(cub, 0x0000FF00, y, x);
				else if (ft_ischar("NSEW#.", cub->map.tab_map[y][x]))
					multiply_px_minimap(cub, cub->floor.color, y, x);
				else if (cub->map.tab_map[y][x] == '$')
					multiply_px_minimap(cub, 0x00FFFF00, y, x);
				x++;
			}
			y++;
		}
		multiply_px_minimap(cub, 0x00FE8800, cub->player.y, cub->player.x);
	}
}

void	multiply_px_minimap(t_cub *cub, int color, int y, int x)
{
	cub->m.temp_color = color;
	cub->m.ty = cub->map.y_minimap_coef * y;
	cub->m.my = cub->m.ty + cub->map.y_minimap_coef;
	while (cub->m.ty < cub->m.my)
	{
		cub->m.tx = cub->map.x_minimap_coef * x;
		cub->m.mx = cub->m.tx + cub->map.x_minimap_coef;
		while (cub->m.tx < cub->m.mx)
		{
			color = cub->m.temp_color;
			if (cub->m.tx == cub->map.x_minimap_coef * x || cub->m.tx == cub->m.mx - 1 || \
				cub->m.ty == cub->map.y_minimap_coef * y \
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
