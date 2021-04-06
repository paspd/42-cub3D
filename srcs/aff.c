/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:07:47 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 10:18:32 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	aff_player(int c)
{
	if (c == 'N')
		printf("\033[38;5;166m▲\033[0m");
	if (c == 'S')
		printf("\033[38;5;166m▼\033[0m");
	if (c == 'E')
		printf("\033[38;5;166m►\033[0m");
	if (c == 'W')
		printf("\033[38;5;166m◄\033[0m");
}

void	aff_map_utilis(char c)
{
	if (ft_ischar(" ", c))
		printf("\033[31m░\033[0m");
	else if (c == '|')
		printf("\033[34m█\033[0m");
	else if (c == '#')
		printf("\033[32m█\033[0m");
	else if (c == '.')
		printf("\033[38;5;128m┼\033[0m");
	else if (c == '$')
		printf("\033[33m☺\033[0m");
	else if (ft_ischar("NSEW", c))
		aff_player(c);
}

void	aff_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.tab_map[y])
	{
		x = 0;
		while (cub->map.tab_map[y][x])
		{
			aff_map_utilis(cub->map.tab_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	aff_all(t_cub *cub)
{
	printf("R: %d %d\n", cub->wind.width, cub->wind.height);
	printf("NO: \"%s\"\n", cub->texture.no_texture);
	printf("SO: \"%s\"\n", cub->texture.so_texture);
	printf("WE: \"%s\"\n", cub->texture.we_texture);
	printf("EA: \"%s\"\n", cub->texture.ea_texture);
	printf("S: \"%s\"\n", cub->texture.texture_sprite);
	printf("F: %d,%d,%d\n", cub->floor.r, cub->floor.g, cub->floor.b);
	printf("C: %d,%d,%d\n", cub->sky.r, cub->sky.g, cub->sky.b);
	printf("\n\nCOLORS\n    sky : %d\n    floor : %d\n", \
		cub->sky.color, cub->floor.color);
	printf("player spawn direction :%c\n", cub->player.spawn_direction);
	printf("spawn : [%d;%d]\n", (int)cub->player.y, (int)cub->player.x);
	aff_map(cub);
}
