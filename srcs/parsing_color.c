/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:03:54 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:04:54 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	parsing_sky_color_bis(t_cub *cub, char *line, int i)
{
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The sky's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->sky.b = cub->sky.b * 10 + (line[i++] - 48);
	if (cub->sky.r > 255 || cub->sky.g > 255 || cub->sky.b > 255)
		error("The sky's color is not valid.\n", cub);
	cub->sky.color = 256 * 256 * cub->sky.r + 256 * cub->sky.g + cub->sky.b;
}

void	parsing_sky_color(t_cub *cub, char *line)
{
	int	i;

	i = 1;
	cub->verif.pars++;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The sky's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->sky.r = cub->sky.r * 10 + (line[i++] - 48);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The sky's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->sky.g = cub->sky.g * 10 + (line[i++] - 48);
	parsing_sky_color_bis(cub, line, i);
}

void	parsing_floor_color_bis(t_cub *cub, char *line, int i)
{
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The floor's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->floor.b = cub->floor.b * 10 + (line[i++] - 48);
	if (cub->floor.r > 255 || cub->floor.g > 255 || cub->floor.b > 255)
		error("The floor's color is not valid.\n", cub);
	cub->floor.color = 256 * 256 * cub->floor.r + 256 * \
		cub->floor.g + cub->floor.b;
}

void	parsing_floor_color(t_cub *cub, char *line)
{
	int i;

	i = 1;
	cub->verif.pars++;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The floor's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->floor.r = cub->floor.r * 10 + (line[i++] - 48);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (!ft_isdigit(line[i]))
		error("The floor's color is not valid.\n", cub);
	while (ft_isdigit(line[i]) && line[i])
		cub->floor.g = cub->floor.g * 10 + (line[i++] - 48);
	parsing_floor_color_bis(cub, line, i);
}
