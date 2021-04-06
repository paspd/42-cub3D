/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:34:47 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 10:32:23 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

int	ft_tablen(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map.tab_map[i])
		i++;
	return (i);
}

void	check_file_path(char *path, t_cub *cub)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] != 'b')
		error("The file path of the map must be finised by .cub\n", cub);
	i--;
	if (path[i] != 'u')
		error("The file path of the map must be finised by .cub\n", cub);
	i--;
	if (path[i] != 'c')
		error("The file path of the map must be finised by .cub\n", cub);
	i--;
	if (path[i] != '.')
		error("The file path of the map must be finised by .cub\n", cub);
	i--;
	cub->file.file_path = path;
}

void	check_direction(t_cub *cub)
{
	char	*dir;

	dir = "NULL";
	if ((cub->rc.dir_x <= 0.750 && cub->rc.dir_x >= -0.750) && \
		cub->rc.dir_y <= -0.500)
		dir = "N";
	if ((cub->rc.dir_y <= 0.750 && cub->rc.dir_y >= -0.750) && \
		cub->rc.dir_x <= -0.500)
		dir = "W";
	if ((cub->rc.dir_x <= 0.750 && cub->rc.dir_x >= -0.750) && \
		cub->rc.dir_y >= 0.500)
		dir = "S";
	if ((cub->rc.dir_y <= 0.750 && cub->rc.dir_y >= -0.750) && \
		cub->rc.dir_x >= 0.500)
		dir = "E";
	mlx_string_put(cub->mlx.id, cub->wind.id, cub->wind.width / 2, \
		cub->wind.height * 0.05, 0x00FFFFFF - cub->sky.color, dir);
}

int	check_s_dist(t_cub *cub, int i)
{
	double	vec_x;
	double	vec_x_2;
	double	vec_y;
	double	vec_y_2;

	vec_x = fabs(cub->player.x - cub->sprite.pos_x[i]);
	vec_y = fabs(cub->player.y - cub->sprite.pos_y[i]);
	vec_x_2 = fabs(cub->player.x - cub->sprite.pos_x[i + 1]);
	vec_y_2 = fabs(cub->player.y - cub->sprite.pos_y[i + 1]);
	if (sqrt(pow(vec_x, 2) + pow(vec_y, 2)) < sqrt(pow(vec_x_2, 2) + \
		pow(vec_y_2, 2)))
		return (1);
	return (0);
}
