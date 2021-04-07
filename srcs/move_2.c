/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:23:08 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:26:42 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	move_2(t_cub *cub)
{
	if (cub->move.right_arrow)
	{
		if (ft_ischar("NE", cub->player.spawn_direction))
			right_arrow(cub);
		else
			left_arrow(cub);
	}
	if (cub->move.up)
		up_key(cub);
	if (cub->move.down)
		down_key(cub);
	if (cub->move.left)
		right_key(cub);
	if (cub->move.right)
		left_key(cub);
}
