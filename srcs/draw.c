/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:31:41 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 11:30:06 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"
void	draw_vertical_line_2(int x, int y_min, int y_max, t_cub *cub)
{
	int	color;

	while (y_min <= y_max)
	{
		cub->texture.y = (int)cub->texture.texture_pos & (cub->tex.height - 1);
		cub->texture.texture_pos += cub->texture.coef_y;
		color = cub->tex.addr[cub->texture.y * cub->tex.height + \
			cub->texture.x];
		if (cub->verif.black)
			color = 0;
		cub->rci.addr[y_min * cub->rci.line_length + x] = color;
		y_min++;
	}
	y_max++;
	if (y_max != cub->wind.height)
	{
		cub->rci.addr[x + cub->rci.line_length * y_max++] = 0;
		cub->rci.addr[x + cub->rci.line_length * y_max++] = 0;
	}
	while (y_max < cub->wind.height)
		cub->rci.addr[x + cub->rci.line_length * y_max++] = cub->floor.color;
	cub->verif.old_map_x = cub->map.x;
	cub->verif.old_map_y = cub->map.y;
	cub->verif.old_side = cub->verif.side;
}

void	draw_vertical_line(int x, int y_min, int y_max, t_cub *cub)
{
	int		i;
	int		sky_y;

	i = 0;
	sky_y = cub->sky.height / cub->wind.height;
	if (cub->verif.old_map_x != cub->map.x || cub->verif.old_map_y != \
		cub->map.y || cub->verif.side != cub->verif.old_side)
		cub->verif.black = 1;
	else
		cub->verif.black = 0;
	cub->texture.coef_y = (double)cub->tex.height / cub->draw.wall_height;
	cub->texture.texture_pos = (cub->draw.draw_start - cub->wind.height / 2 + \
		cub->draw.wall_height / 2) * cub->texture.coef_y;
	while (i < y_min)
	{
		cub->rci.addr[i * cub->rci.line_length + x] = cub->sky.color;
		i++;
	}
	if (y_min != 0)
	{
		cub->rci.addr[x + cub->rci.line_length * y_min++] = 0;
		cub->rci.addr[x + cub->rci.line_length * y_min++] = 0;
	}
	draw_vertical_line_2(x, y_min, y_max, cub);
}

void	draw(t_cub *cub, int x)
{
	cub->draw.wall_height = cub->wind.height / cub->ray.dist_wall;
	cub->draw.draw_start = -cub->draw.wall_height / 2 + cub->wind.height / 2;
	if (cub->draw.draw_start < 0)
		cub->draw.draw_start = 0;
	cub->draw.draw_end = cub->draw.wall_height / 2 + cub->wind.height / 2;
	if (cub->draw.draw_end >= cub->wind.height)
		cub->draw.draw_end = cub->wind.height - 1;
	check_4_texture(cub);
	draw_vertical_line(x, cub->draw.draw_start, cub->draw.draw_end, cub);
}
