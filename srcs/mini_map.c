/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:10:41 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:12:54 by ldauga           ###   ########lyon.fr   */
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
			else if (cub->map.tab_map[y][x] == '.' || ft_ischar("NSEW#", cub->map.tab_map[y][x]))
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
	int temp_color;
    int tx;
    int ty;
    int mx;
    int my;

	temp_color = color;
    tx = cub->map.x_minimap_coef * x;
    ty = cub->map.y_minimap_coef * y;

    mx = tx + cub->map.x_minimap_coef;
    my = ty + cub->map.y_minimap_coef;
    while (ty < my)
    {
        tx = cub->map.x_minimap_coef * x;
        while (tx < mx)
        {
			if (tx == cub->map.x_minimap_coef * x || tx == mx - 1 || ty == cub->map.y_minimap_coef * y || ty == my - 1)
			{
				if (ft_ischar("|#", cub->map.tab_map[y][x]))
					color = 0x00222222;
			}
			else
				color = temp_color;
			cub->rci.addr[ty * cub->rci.line_length + tx] = color;
            tx++;
        }
        ty++;
    }
}
