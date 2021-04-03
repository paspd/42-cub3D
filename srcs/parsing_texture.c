/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:49:49 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 13:56:10 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/cub.h"

int	parsing_texture_sprite(t_cub *cub, char *line)
{
	int		i;
	int		n;

	i = 1;
	if (ft_strnstr(line, "S", 1))
	{
		cub->verif.pars++;
		i++;
		while (line[i] == ' ' && line[i])
			i++;
		n = i;
		while (line[n])
			n++;
		cub->texture.texture_sprite = malloc(n * sizeof(char));
		n = 0;
		while (line[i])
			cub->texture.texture_sprite[n++] = line[i++];
		cub->texture.texture_sprite[n] = 0;
		if (cub->texture.texture_sprite[0] == '\0')
			error("There is no file path for sprite.\n", cub);
	}
	return (1);
}

int	parsing_texture_ea(t_cub *cub, char *line)
{
	int		i;
	int		n;

	i = 1;
	if (ft_strnstr(line, "EA", 2))
	{
		cub->verif.pars++;
		i++;
		while (line[i] == ' ' && line[i])
			i++;
		n = i;
		while (line[n])
			n++;
		cub->texture.ea_texture = malloc(n * sizeof(char));
		n = 0;
		while (line[i])
			cub->texture.ea_texture[n++] = line[i++];
		cub->texture.ea_texture[n] = 0;
		if (cub->texture.ea_texture[0] == '\0')
			error("There is no file path for EA.\n", cub);
	}
	else
		parsing_texture_sprite(cub, line);
	return (1);
}

int	parsing_texture_we(t_cub *cub, char *line)
{
	int		i;
	int		n;

	i = 1;
	if (ft_strnstr(line, "WE", 2))
	{
		cub->verif.pars++;
		i++;
		while (line[i] == ' ' && line[i])
			i++;
		n = i;
		while (line[n])
			n++;
		cub->texture.we_texture = malloc(n * sizeof(char));
		n = 0;
		while (line[i])
			cub->texture.we_texture[n++] = line[i++];
		cub->texture.we_texture[n] = 0;
		if (cub->texture.we_texture[0] == '\0')
			error("There is no file path for WE.\n", cub);
	}
	else
		parsing_texture_ea(cub, line);
	return (1);
}

int	parsing_texture_so(t_cub *cub, char *line)
{
	int		i;
	int		n;

	i = 1;
	if (ft_strnstr(line, "SO", 2))
	{
		cub->verif.pars++;
		i++;
		while (line[i] == ' ' && line[i])
			i++;
		n = i;
		while (line[n])
			n++;
		cub->texture.so_texture = malloc(n * sizeof(char));
		n = 0;
		while (line[i])
			cub->texture.so_texture[n++] = line[i++];
		cub->texture.so_texture[n] = 0;
		if (cub->texture.so_texture[0] == '\0')
			error("There is no file path for SO.\n", cub);
	}
	else
		parsing_texture_we(cub, line);
	return (1);
}

int	parsing_texture_no(t_cub *cub, char *line)
{
	int		i;
	int		n;

	i = 1;
	if (ft_strnstr(line, "NO", 2))
	{
		cub->verif.pars++;
		i++;
		while (line[i] == ' ' && line[i])
			i++;
		n = i;
		while (line[n])
			n++;
		cub->texture.no_texture = malloc(n * sizeof(char));
		n = 0;
		while (line[i])
			cub->texture.no_texture[n++] = line[i++];
		cub->texture.no_texture[n] = 0;
		if (cub->texture.no_texture[0] == '\0')
			error("There is no file path for NO.\n", cub);
	}
	else
		parsing_texture_so(cub, line);
	return (1);
}