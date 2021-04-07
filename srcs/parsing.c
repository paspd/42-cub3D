/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:33:56 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 13:45:16 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"
int	parsing_res(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((!ft_ischar(" 	R0123456789", line[i])))
			error("The resolution is not valid.\n", cub);
		i++;
	}
	i = 0;
	cub->verif.pars++;
	while (!(ft_isdigit(line[i])) && line[i])
		i++;
	while (ft_isdigit(line[i]) && line[i])
		cub->wind.width = cub->wind.width * 10 + (line[i++] - 48);
	while (!(ft_isdigit(line[i])) && line[i])
		i++;
	while (ft_isdigit(line[i]) && line[i])
		cub->wind.height = cub->wind.height * 10 + (line[i++] - 48);
	if (cub->wind.width > 3840 || cub->wind.height > 2160 || \
		!cub->wind.width || !cub->wind.height)
		error("The res is not valid.\n", cub);
	return (0);
}

int	parsing_texture_check(char *line)
{
	if (ft_strnstr(line, "NO", 2))
		return (1);
	if (ft_strnstr(line, "SO", 2))
		return (1);
	if (ft_strnstr(line, "WE", 2))
		return (1);
	if (ft_strnstr(line, "EA", 2))
		return (1);
	if (ft_strnstr(line, "S", 1))
		return (1);
	return (0);
}

int	parsing_file(t_cub *cub)
{
	char	*line;

	line = NULL;
	cub->file.file_fd = ft_open_files(cub->file.file_path);
	while (cub->verif.gnl)
	{
		cub->verif.gnl = get_next_line(cub->file.file_fd, &line);
		if (cub->verif.gnl < 0)
			error("The path of the map is not valid.\n", cub);
		if (ft_strnchr(line, 'R', 1))
			parsing_res(cub, line);
		else if (parsing_texture_check(line))
			parsing_texture_no(cub, line);
		else if (ft_strnchr(line, 'F', 1))
			parsing_floor_color(cub, line);
		else if (ft_strnchr(line, 'C', 1))
			parsing_sky_color(cub, line);
		else if (cub->verif.pars == 8)
			break ;
		free(line);
	}
	if (cub->verif.pars != 8)
		error("Some elements are missing.\n", cub);
	parsing_map(cub, &line);
	return (0);
}
