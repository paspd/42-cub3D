/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:20:20 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 10:31:24 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	respawn(t_cub *cub)
{
	cub->player.x = cub->player.spawn_x;
	cub->player.y = cub->player.spawn_y;
	init_vector(cub);
}

void	move(t_cub *cub, int key)
{
	if (key == 3)
		cub->move.open_door = 1;
	if (key == 46)
	{
		if (cub->verif.map)
			cub->verif.map = 0;
		else
			cub->verif.map = 1;
	}
	if (key == 2)
		cub->move.right = 1;
	if (key == 13 || key == 126)
		cub->move.up = 1;
	if (key == 1 || key == 125)
		cub->move.down = 1;
	if (key == 0)
		cub->move.left = 1;
	if (key == 124 || key == 14)
		cub->move.right_arrow = 1;
	if (key == 123 || key == 12)
		cub->move.left_arrow = 1;
	if (key == 15)
		respawn(cub);
	aff_map_wind(cub);
}

int	key_press(int key, t_cub *cub)
{
	if (key == 48)
		cub->verif.full_map = 1;
	if (key == 122)
		screen_shoot(cub);
	if (key == 53)
		game_finish(cub);
	if (!cub->verif.full_map)
	{
		move(cub, key);
	}
	if (key != cub->verif.old_key)
		dprintf(1, "touche :%d\n", key);
	cub->verif.old_key = key;
	return (0);
}

int	key_release(int	key, t_cub *cub)
{
	if (key == 3)
		cub->move.open_door = 0;
	if (key == 48)
		cub->verif.full_map = 0;
	if (key == 2)
		cub->move.right = 0;
	if (key == 13 || key == 126)
		cub->move.up = 0;
	if (key == 1 || key == 125)
		cub->move.down = 0;
	if (key == 0)
		cub->move.left = 0;
	if (key == 124 || key == 14)
		cub->move.right_arrow = 0;
	if (key == 123 || key == 12)
		cub->move.left_arrow = 0;
	return (1);
}
