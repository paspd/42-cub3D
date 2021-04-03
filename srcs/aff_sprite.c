/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:23:12 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:30:10 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	sort_sprite(t_cub *cub)
{
	int	i;
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

void	aff_sprite(t_cub *cub)
{
	int	i;

	sort_sprite(cub);
	i = 0;
	while (i <= cub->sprite.nb_sprite)
	{
		double spriteX = cub->sprite.pos_x[i] - cub->player.x;
    	double spriteY = cub->sprite.pos_y[i] - cub->player.y;
		double invDet = 1.0 / (cub->rc.plane_x * cub->rc.dir_y - cub->rc.dir_x * cub->rc.plane_y);
		double transformX = invDet * (cub->rc.dir_y * spriteX - cub->rc.dir_x * spriteY);
    	double transformY = invDet * (-cub->rc.plane_y * spriteX + cub->rc.plane_x * spriteY);
		int spriteScreenX = (int)((cub->wind.width / 2) * (1 + transformX / transformY));
      	int vMoveScreen = (int)(0.0 / transformY);
		int spriteHeight = abs((int)(cub->wind.height / (transformY))) / 1;
		int drawStartY = -spriteHeight / 2 + cub->wind.height / 2 + vMoveScreen;
      	if(drawStartY < 0)
		  drawStartY = 0;
      	int drawEndY = spriteHeight / 2 + cub->wind.height / 2 + vMoveScreen;
      	if(drawEndY >= cub->wind.height)
		  drawEndY = cub->wind.height - 1;
		int spriteWidth = abs((int)(cub->wind.height / (transformY))) / 1;
    	int drawStartX = -spriteWidth / 2 + spriteScreenX;
    	if(drawStartX < 0)
			drawStartX = 0;
    	int drawEndX = spriteWidth / 2 + spriteScreenX;
    	if(drawEndX >= cub->wind.width)
			drawEndX = cub->wind.width - 1;
		int stripe = drawStartX;
		int color;
		while (stripe <= drawEndX)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * cub->s_img.width / spriteWidth) / 256;
			if(transformY > 0 && stripe >= 0 && stripe < cub->wind.width && transformY < cub->rc.buff[stripe])
			{
				int y = drawStartY;
				while(y < drawEndY)
        		{
          			int d = (y- vMoveScreen) * 256 - cub->wind.height * 128 + spriteHeight * 128;
          			int texY = ((d * cub->s_img.height) / spriteHeight) / 256;
         			color = cub->s_img.addr[cub->s_img.width * texY + texX];
          			if(color != 0x00FF0000 && (cub->s_img.width * texY + texX) < (cub->s_img.width * cub->s_img.height))
					  	cub->rci.addr[y * cub->rci.line_length + stripe] = color;
					y++;
				}
			}
			stripe++;
	}
	i++;
}
}
