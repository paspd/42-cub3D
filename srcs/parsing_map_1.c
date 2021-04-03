/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:57:17 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:01:36 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/cub.h"

void	clean_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.tab_map[y])
	{
		x = 0;
		while (cub->map.tab_map[y][x])
		{
			if (ft_ischar("0123", cub->map.tab_map[y][x]))
				cub->map.tab_map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

int	parsing_map_3(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.tab_map[y])
	{
		x = 0;
		while (cub->map.tab_map[y][x])
		{
			if (ft_ischar("NSEW", cub->map.tab_map[y][x]))
			{
				if (cub->verif.spawn)
					error("There is many spawn point.\n", cub);
				cub->player.spawn_direction = cub->map.tab_map[y][x];
				cub->player.y = y + 0.5;
				cub->player.x = x + 0.5;
				cub->verif.spawn++;
			}
			x++;
		}
		y++;
	}
	cub->player.spawn_x = cub->player.x;
	cub->player.spawn_y = cub->player.y;
	if (!cub->verif.spawn)
		error("There is no spawn point.\n", cub);
	fill_flood_map(cub, cub->player.y, cub->player.x);
	clean_map(cub);
	return (0);
}

int	parsing_map_2(t_cub *cub)
{
	int	i;
	int	n;

	i = 0;
	while (cub->map.tab_map[i])
	{
		n = 0;
		while (cub->map.tab_map[i][n])
		{
			if (!ft_ischar(" 0123NSEW", cub->map.tab_map[i][n]))
				error("There is a type unidentifiable.\n", cub);
			n++;
		}
		i++;
	}
	parsing_map_3(cub);
	return (0);
}

void	check_coef_map(t_cub *cub)
{
	int y;
	int	longest_line;

	longest_line = 0;
	y = 0;
	while (cub->map.tab_map[y])
	{
		if ((int)ft_strlen(cub->map.tab_map[y]) > longest_line)
			longest_line = (int)ft_strlen(cub->map.tab_map[y]);
		y++;
	}
	cub->map.x_full_map_coef = cub->wind.width / longest_line;
	cub->map.y_full_map_coef = cub->wind.height / y;
	cub->map.x_minimap_coef = cub->map.x_full_map_coef * 0.4;
	cub->map.y_minimap_coef = cub->map.y_full_map_coef * 0.4;
}

int	parsing_map(t_cub *cub, char **str)
{
	char	*line;
	char	*temp;

	temp = calloc(1, sizeof(char));
	if (str[0] == 0)
		free(*str);
	else
	{
		temp = ft_strjoin_cub(temp, *str);
		free(*str);
	}
	while (0 < get_next_line(cub->file.file_fd, &line))
	{
		temp = ft_strjoin_cub(temp, line);
		free(line);
	}
	temp = ft_strjoin_cub(temp, line);
	free(line);
	cub->map.tab_map = ft_split(temp, '\n');
	free(temp);
	parsing_map_2(cub);
	check_coef_map(cub);
	return (0);
}