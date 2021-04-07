/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:14:07 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:26:03 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	up_key(t_cub *cub)
{
	if (!ft_ischar("$|#", cub->map.tab_map[(int)(cub->player.y + \
		cub->rc.dir_y * cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_y * cub->player.speed);
	if (!ft_ischar("$|#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + \
		cub->rc.dir_x * cub->player.speed)]))
		cub->player.x += (cub->rc.dir_x * cub->player.speed);
}

void	down_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y * \
		-cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_y * -cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + \
		cub->rc.dir_x * -cub->player.speed)]))
		cub->player.x += (cub->rc.dir_x * -cub->player.speed);
}

void	left_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_x * \
		cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_x * cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x - \
		cub->rc.dir_y * cub->player.speed)]))
		cub->player.x -= (cub->rc.dir_y * cub->player.speed);
}

void	right_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y - cub->rc.dir_x * \
		cub->player.speed)][(int)cub->player.x]))
		cub->player.y -= (cub->rc.dir_x * cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + \
		cub->rc.dir_y * cub->player.speed)]))
		cub->player.x += (cub->rc.dir_y * cub->player.speed);
}

void	check_move(t_cub *cub)
{
	if (cub->move.open_door)
		if (cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y)][(int)(cub->player.x + \
			cub->rc.dir_x)] == '#')
			cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y)][(int)(cub->player.x + \
				cub->rc.dir_x)] = '.';
	if (cub->move.left_arrow)
	{
		if (ft_ischar("NE", cub->player.spawn_direction))
			left_arrow(cub);
		else
			right_arrow(cub);
	}
	move_2(cub);
}
