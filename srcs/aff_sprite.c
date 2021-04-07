/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:23:12 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/07 09:14:51 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	sort_sprite(t_cub *cub)
{
	int		i;
	double	temp;

	i = 0;
	while (i < cub->sprite.nb_sprite - 1)
	{
		if (check_s_dist(cub, i))
		{
			temp = cub->sprite.pos_x[i];
			cub->sprite.pos_x[i] = cub->sprite.pos_x[i + 1];
			cub->sprite.pos_x[i + 1] = temp;
			temp = cub->sprite.pos_y[i];
			cub->sprite.pos_y[i] = cub->sprite.pos_y[i + 1];
			cub->sprite.pos_y[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	check_s(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->sprite.nb_sprite)
	{
		if ((int)(cub->sprite.pos_x[i] - 0.50) == cub->map.x)
			if ((int)(cub->sprite.pos_y[i] - 0.50) == cub->map.y)
				return (0);
		i++;
	}
	return (1);
}

void	calcul_sprite(t_afs *afs, t_cub *cub)
{
	afs->spr_hei = abs((int)(cub->wind.height / (afs->transform_y))) / 1;
	afs->draw_y.draw_start = -afs->spr_hei / 2 + \
		cub->wind.height / 2 + afs->v_move_scre;
	if (afs->draw_y.draw_start < 0)
		afs->draw_y.draw_start = 0;
	afs->draw_y.draw_end = afs->spr_hei / 2 + cub->wind.height / 2 + \
		afs->v_move_scre;
	if (afs->draw_y.draw_end >= cub->wind.height)
		afs->draw_y.draw_end = cub->wind.height - 1;
	afs->spr_wid = abs((int)(cub->wind.height / (afs->transform_y))) / 1;
	afs->draw_x.draw_start = -afs->spr_wid / 2 + afs->spr_screen_x;
	if (afs->draw_x.draw_start < 0)
		afs->draw_x.draw_start = 0;
	afs->draw_x.draw_end = afs->spr_wid / 2 + afs->spr_screen_x;
	if (afs->draw_x.draw_end >= cub->wind.width)
		afs->draw_x.draw_end = cub->wind.width - 1;
}

void	draw_sprite(t_afs *afs, t_cub *cub)
{
	int	y;
	int	stripe;

	stripe = afs->draw_x.draw_start;
	while (stripe <= afs->draw_x.draw_end)
	{
		afs->tex_x = (int)(256 * (stripe - (-afs->spr_wid / 2 + \
			afs->spr_screen_x)) * cub->s_img.width / afs->spr_wid) / 256;
		if (afs->transform_y > 0 && stripe >= 0 && stripe < \
			cub->wind.width && afs->transform_y < cub->rc.buff[stripe])
		{
			y = afs->draw_y.draw_start;
			while (y < afs->draw_y.draw_end)
			{
				draw_sprite_2(afs, cub, y, stripe);
				y++;
			}
		}
		stripe++;
	}
}

void	aff_sprite(t_cub *cub)
{
	int		i;
	t_afs	afs;

	sort_sprite(cub);
	i = 0;
	while (i <= cub->sprite.nb_sprite)
	{
		afs.sprite_x = cub->sprite.pos_x[i] - cub->player.x;
		afs.sprite_y = cub->sprite.pos_y[i] - cub->player.y;
		afs.inv_det = 1.0 / (cub->rc.plane_x * cub->rc.dir_y - \
			cub->rc.dir_x * cub->rc.plane_y);
		afs.transform_x = afs.inv_det * (cub->rc.dir_y * afs.sprite_x - \
			cub->rc.dir_x * afs.sprite_y);
		afs.transform_y = afs.inv_det * (-cub->rc.plane_y * afs.sprite_x + \
			cub->rc.plane_x * afs.sprite_y);
		afs.spr_screen_x = (int)((cub->wind.width / 2) * (1 + afs.transform_x / \
			afs.transform_y));
		afs.v_move_scre = (int)(0.0 / afs.transform_y);
		calcul_sprite(&afs, cub);
		draw_sprite(&afs, cub);
		i++;
	}
}
