/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:48:20 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 13:48:51 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	init_we(t_cub *cub)
{
	cub->we.img = mlx_xpm_file_to_image(cub->mlx.id, cub->texture.we_texture, &cub->we.width, &cub->we.height);
	if (!cub->we.img)
		error("The WE texture file path is'n valid.\n", cub);
	cub->we.addr = (int *)mlx_get_data_addr(cub->we.img, &cub->we.bits_per_pixel, &cub->we.line_length, &cub->we.endian);
	cub->we.line_length /= 4;
}

void	init_so(t_cub *cub)
{
	cub->so.img = mlx_xpm_file_to_image(cub->mlx.id, cub->texture.so_texture, &cub->so.width, &cub->so.height);
	if (!cub->so.img)
		error("The SO texture file path is'n valid.\n", cub);
	cub->so.addr = (int *)mlx_get_data_addr(cub->so.img, &cub->so.bits_per_pixel, &cub->so.line_length, &cub->so.endian);
	cub->so.line_length /= 4;
}

void	init_ea(t_cub *cub)
{
	cub->ea.img = mlx_xpm_file_to_image(cub->mlx.id, cub->texture.ea_texture, &cub->ea.width, &cub->ea.height);
	if (!cub->ea.img)
		error("The EA texture file path is'n valid.\n", cub);
	cub->ea.addr = (int *)mlx_get_data_addr(cub->ea.img, &cub->ea.bits_per_pixel, &cub->ea.line_length, &cub->ea.endian);
	cub->ea.line_length /= 4;
}

void	init_no(t_cub *cub)
{
	cub->no.img = mlx_xpm_file_to_image(cub->mlx.id, cub->texture.no_texture, &cub->no.width, &cub->no.height);
	if (!cub->no.img)
		error("The NO texture file path is'n valid.\n", cub);
	cub->no.addr = (int *)mlx_get_data_addr(cub->no.img, &cub->no.bits_per_pixel, &cub->no.line_length, &cub->no.endian);
	cub->no.line_length /= 4;
}

void	init_sprite(t_cub *cub)
{
	cub->s_img.img = mlx_xpm_file_to_image(cub->mlx.id, cub->texture.texture_sprite, &cub->s_img.width, &cub->s_img.height);
	if (!cub->s_img.img)
		error("The sprite texture file path is'n valid.\n", cub);
	cub->s_img.addr = (int *)mlx_get_data_addr(cub->s_img.img, &cub->s_img.bits_per_pixel, &cub->s_img.line_length, &cub->s_img.endian);
	cub->s_img.line_length /= 4;
}
