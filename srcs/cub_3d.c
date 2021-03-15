/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:00:33 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/15 16:07:31 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	error(char *error_msg, t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->texture.no_texture != NULL)
		free(cub->texture.no_texture);
	if (cub->texture.so_texture != NULL)
		free(cub->texture.so_texture);
	if (cub->texture.we_texture != NULL)
		free(cub->texture.we_texture);
	if (cub->texture.ea_texture != NULL)
		free(cub->texture.ea_texture);
	if (cub->texture.texture_sprite != NULL)
		free(cub->texture.texture_sprite);
	if (cub->map.tab_map != NULL)
	{
		while (cub->map.tab_map[i])
			free(cub->map.tab_map[i++]);
		free(cub->map.tab_map);
	}
	ft_close_files(cub->file.file_fd);
	ft_putstr_color("Error\n", "\033[31m\033[1m");
	ft_putstr_color(error_msg, "\033[38;5;166m");
	// while(1);
	exit(-1);
}

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

int	ft_tablen(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map.tab_map[i])
		i++;
	return (i);
}

void	fill_flood_map(t_cub *cub, int y, int x)
{
	if (y < 0 || x < 0 || y > (ft_tablen(cub) - 1) || \
		x > ((int)ft_strlen(cub->map.tab_map[y]) - 1))
		error("The map is not close.\n", cub);
	if (ft_ischar("|.$#", cub->map.tab_map[y][x]))
		return ;
	if (cub->map.tab_map[y][x] == '1')
	{
		cub->map.tab_map[y][x] = '|';
		return ;
	}
	if (cub->map.tab_map[y][x] == '0')
		cub->map.tab_map[y][x] = '.';
	if (cub->map.tab_map[y][x] == '2')
		cub->map.tab_map[y][x] = '$';
	if (cub->map.tab_map[y][x] == '3')
		cub->map.tab_map[y][x] = '#';
	fill_flood_map(cub, y - 1, x);
	fill_flood_map(cub, y + 1, x);
	fill_flood_map(cub, y, x - 1);
	fill_flood_map(cub, y, x + 1);
}

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
	int i;

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
	cub->floor.color = 256 * 256 * cub->floor.r + 256 * cub->floor.g + cub->floor.b;
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

char	*ft_strjoin_cub(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * i + 2)))
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n++] = '\n';
	str[n] = 0;
	free(s1);
	return (str);
}

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
	int	i;
	int	n;

	i = 0;
	while (cub->map.tab_map[i])
	{
		n = 0;
		while (cub->map.tab_map[i][n])
		{
			if (ft_ischar("NSEW", cub->map.tab_map[i][n]))
			{
				if (cub->verif.spawn)
					error("There is many spawn point.\n", cub);
				cub->player.spawn_direction = cub->map.tab_map[i][n];
				cub->player.y = i + 0.5;
				cub->player.x = n + 0.5;
				cub->verif.spawn++;
			}
			n++;
		}
		i++;
	}
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

int	parsing_file(t_cub *cub)
{
	int		verif;
	char	*line;

	line = NULL;
	cub->file.file_fd = ft_open_files(cub->file.file_path);
	while ((verif = get_next_line(cub->file.file_fd, &line)))
	{
		if (verif < 0)
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
	if (verif == 0 && cub->verif.pars != 8)
		error("Some elements are missing.\n", cub);
	if (cub->verif.pars == 8)
		parsing_map(cub, &line);
	return (0);
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

void	init_structs(char *path, t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	check_file_path(path, cub);
	cub->base.dec = "0123456789";
	cub->base.hex = "0123456789ABCDEF";
	cub->verif.old_key = 2147483647;
	cub->player.rotate_speed = 0.03;
	cub->player.speed = 0.05;
}

void	free_all(t_cub *cub)
{
	int i;

	i = 0;
	free(cub->texture.no_texture);
	free(cub->texture.so_texture);
	free(cub->texture.we_texture);
	free(cub->texture.ea_texture);
	free(cub->texture.texture_sprite);
	while (cub->map.tab_map[i])
	{
		free(cub->map.tab_map[i]);
		i++;
	}
	free(cub->map.tab_map);
	ft_close_files(cub->file.file_fd);
}

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
			if (ft_ischar(" ", cub->map.tab_map[y][x]))
				printf("\033[31m░\033[0m");
			else if (cub->map.tab_map[y][x] == '|') 
				printf("\033[34m█\033[0m");
			else if (cub->map.tab_map[y][x] == '#') 
				printf("\033[32m█\033[0m");
			else if (cub->map.tab_map[y][x] == '.')
				printf("\033[38;5;128m┼\033[0m");
			else if (cub->map.tab_map[y][x] == '$')
				printf("\033[33m☺\033[0m");
			else if (ft_ischar("NSEW", cub->map.tab_map[y][x]))
				aff_player(cub->map.tab_map[y][x]);
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
	printf("\n\nCOLORS\n    sky : %d\n    floor : %d\n", cub->sky.color, cub->floor.color);
	printf("player spawn direction :%c\n", cub->player.spawn_direction);
	printf("spawn : [%d;%d]\n", (int)cub->player.y, (int)cub->player.x);
	aff_map(cub);
}

int	game_finish(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->texture.no_texture != NULL)
		free(cub->texture.no_texture);
	if (cub->texture.so_texture != NULL)
		free(cub->texture.so_texture);
	if (cub->texture.we_texture != NULL)
		free(cub->texture.we_texture);
	if (cub->texture.ea_texture != NULL)
		free(cub->texture.ea_texture);
	if (cub->texture.texture_sprite != NULL)
		free(cub->texture.texture_sprite);
	if (cub->map.tab_map != NULL)
	{
		while (cub->map.tab_map[i])
			free(cub->map.tab_map[i++]);
		free(cub->map.tab_map);
	}
	ft_close_files(cub->file.file_fd);
	ft_putstr_color("Game finish.\n", "\033[38;5;166m");
	// while(1);
	exit(1);
}

void	multiply_px_minimap(t_cub *cub, int color, int y, int x)
{
	int temp_color;
    int tx;
    int ty;
    int mx;
    int my;

	temp_color = color;
    tx = cub->map.x_minimap_coef * x;
    ty = cub->map.y_minimap_coef * y;

    mx = tx + cub->map.x_minimap_coef;
    my = ty + cub->map.y_minimap_coef;
    while (ty < my)
    {
        tx = cub->map.x_minimap_coef * x;
        while (tx < mx)
        {
			if (tx == cub->map.x_minimap_coef * x || tx == mx - 1 || ty == cub->map.y_minimap_coef * y || ty == my - 1)
			{
				if (ft_ischar("|#", cub->map.tab_map[y][x]))
					color = 0x00222222;
			}
			else
				color = temp_color;
			cub->rci.addr[ty * cub->rci.line_length + tx] = color;
            tx++;
        }
        ty++;
    }
}

void	multiply_px_player(t_cub *cub, int color, int y, int x)
{
    int tx;
    int ty;
    int mx;
    int my;

    tx = 3 * x;
    ty = 3 * y;

    mx = tx + 3;
    my = ty + 3;
    while (ty < my)
    {
        tx = 3 * x;
        while (tx < mx)
        {

        	mlx_pixel_put(cub->mlx.id, cub->wind.id, tx, ty, color);
            tx++;
        }
        ty++;
    }
}

void	multiply_px_map(t_cub *cub, int color, int y, int x)
{
	int temp_color;
    int tx;
    int ty;
    int mx;
    int my;

	temp_color = color;
    tx = cub->map.x_full_map_coef * x;
    ty = cub->map.y_full_map_coef * y;
    mx = tx + cub->map.x_full_map_coef;
    my = ty + cub->map.y_full_map_coef;
    while (ty < my)
    {
        tx = cub->map.x_full_map_coef * x;
        while (tx < mx)
        {
			if (tx == cub->map.x_full_map_coef * x || tx == mx - 1 || ty == cub->map.y_full_map_coef * y || ty == my - 1)
			{
				if (ft_ischar("|$#", cub->map.tab_map[y][x]))
					color = 0x00222222;
				if (x == (int)cub->player.x && y == (int)cub->player.y)
					color = 0x00FFFFFF;
			}
			else
				color = temp_color;
			cub->rci.addr[ty * cub->rci.line_length + tx] = color;
            tx++;
        }
        ty++;
    }
}

void	up_key(t_cub *cub)
{
	if (!ft_ischar("$|#", cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y * cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_y * cub->player.speed);
	if (!ft_ischar("$|#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + cub->rc.dir_x * cub->player.speed)]))
		cub->player.x += (cub->rc.dir_x * cub->player.speed);
}

void	down_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y * -cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_y * -cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + cub->rc.dir_x * -cub->player.speed)]))
		cub->player.x += (cub->rc.dir_x * -cub->player.speed);
}

void	left_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_x  * cub->player.speed)][(int)cub->player.x]))
		cub->player.y += (cub->rc.dir_x * cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x - cub->rc.dir_y * cub->player.speed)]))
		cub->player.x -= (cub->rc.dir_y * cub->player.speed);	
}

void	right_key(t_cub *cub)
{
	if (!ft_ischar("|$#", cub->map.tab_map[(int)(cub->player.y - cub->rc.dir_x * cub->player.speed)][(int)cub->player.x]))
		cub->player.y -= (cub->rc.dir_x * cub->player.speed);
	if (!ft_ischar("|$#", cub->map.tab_map[(int)cub->player.y][(int)(cub->player.x + cub->rc.dir_y * cub->player.speed)]))
		cub->player.x += (cub->rc.dir_y * cub->player.speed);
}

void	aff_map_wind(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	if (cub->verif.map)
	{
	while (cub->map.tab_map[y])
	{
		x = 0;
		while (cub->map.tab_map[y][x])
		{
			if (cub->map.tab_map[y][x] == '|') 
				multiply_px_minimap(cub, 0x00FF0000, y, x);
			else if (cub->map.tab_map[y][x] == '#') 
				multiply_px_minimap(cub, 0x0000FF00, y, x);
			else if (cub->map.tab_map[y][x] == '.' || ft_ischar("NSEW#", cub->map.tab_map[y][x]))
				multiply_px_minimap(cub, cub->floor.color, y, x);
			else if (cub->map.tab_map[y][x] == '$')
				multiply_px_minimap(cub, 0x000000FF, y, x);
			x++;
		}
		y++;
	}
			multiply_px_minimap(cub, 0x00FE8800, cub->player.y, cub->player.x);
	}
}

void	init_node_dist(t_cub *cub)
{
	if (cub->ray.dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.node_dist_x = (cub->player.x - cub->map.x) * cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.node_dist_x = (cub->map.x + 1.0 - cub->player.x) * cub->ray.delta_dist_x;
	}
	if (cub->ray.dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.node_dist_y = (cub->player.y - cub->map.y) * cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.node_dist_y = (cub->map.y + 1.0 - cub->player.y) * cub->ray.delta_dist_y;
	}
}

void	check_ray(t_cub *cub)
{
	cub->verif.wall = 0;
		while (cub->verif.wall == 0)
		{
			if (cub->ray.node_dist_x < cub->ray.node_dist_y)
			{
				cub->ray.node_dist_x += cub->ray.delta_dist_x;
				cub->map.x += cub->ray.step_x;
				cub->verif.wall_side = 0;
			}
			else
			{
				cub->ray.node_dist_y += cub->ray.delta_dist_y;
				cub->map.y += cub->ray.step_y;
				cub->verif.wall_side = 1;
			}
			if (ft_ischar("|$#", cub->map.tab_map[cub->map.y][cub->map.x]))
				cub->verif.wall = 1;
		}
		if (cub->verif.wall_side == 0)
			cub->ray.dist_wall = (cub->map.x - cub->player.x + \
				(1 - cub->ray.step_x) / 2) / cub->ray.dir_x;
		else
			cub->ray.dist_wall = (cub->map.y - cub->player.y + \
				(1 - cub->ray.step_y) / 2) / cub->ray.dir_y;
}

void	select_texture(t_cub *cub)
{
	if (cub->verif.wall_side && cub->map.y < cub->player.y)
	{
		cub->tex.addr = cub->we.addr;
		cub->tex.height = cub->we.height;
		cub->tex.width = cub->we.width;
	}
	else if (cub->verif.wall_side && cub->map.y > cub->player.y)
	{
		cub->tex.addr = cub->ea.addr;
		cub->tex.height = cub->ea.height;
		cub->tex.width = cub->ea.width;
	}
	else if (!cub->verif.wall_side && cub->map.x < cub->player.x)
	{
		cub->tex.addr = cub->no.addr;
		cub->tex.height = cub->no.height;
		cub->tex.width = cub->no.width;
	}
	else if (!cub->verif.wall_side && cub->map.x > cub->player.x)
	{
		cub->tex.addr = cub->so.addr;
		cub->tex.height = cub->so.height;
		cub->tex.width = cub->so.width;
	}
}

void	check_4_texture(t_cub *cub)
{
	if (cub->verif.wall_side)
		cub->texture.coef_x = cub->player.x + ((cub->map.y - cub->player.y + (1 - cub->ray.step_y) / 2) / cub->ray.dir_y) * cub->ray.dir_x;
	else
		cub->texture.coef_x = cub->player.y + ((cub->map.x - cub->player.x + (1 - cub->ray.step_x) / 2) / cub->ray.dir_x) * cub->ray.dir_y;
	cub->texture.coef_x -= floor(cub->texture.coef_x);
	select_texture(cub);
	cub->texture.x = (int)(cub->texture.coef_x * (double)(cub->tex.width));
	if (cub->verif.wall_side == 0 && cub->rc.dir_x > 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
	else if (cub->verif.wall_side && cub->rc.dir_y < 0)
		cub->texture.x = cub->tex.width - cub->texture.x - 1;
}

void	draw_vertical_line(int x, int y_min, int y_max, t_cub *cub)
{

	int		i;

	i = 0;
	double step = (double)cub->tex.height / cub->draw.wall_height;
	double texPos = (cub->draw.draw_start - cub->wind.height / 2 + cub->draw.wall_height / 2) * step;
	while (i < y_min)
	{
		cub->rci.addr[i * cub->rci.line_length + x] = cub->sky.color;
		i++;
	}
	if (y_min != 0)
	{
		cub->rci.addr[y_min++ * cub->rci.line_length + x] = 0;
		cub->rci.addr[y_min++ * cub->rci.line_length + x] = 0;
	}
	while (y_min <= y_max)
	{
		cub->texture.y = (int)texPos & (cub->tex.height - 1);
		texPos += step;
		cub->rci.addr[y_min * cub->rci.line_length + x] = cub->tex.addr[cub->texture.y * cub->tex.height + cub->texture.x];
		y_min++;
	}
	y_max++;
	if (y_max != cub->wind.height)
	{
		cub->rci.addr[y_max++ * cub->rci.line_length + x] = 0;
		cub->rci.addr[y_max++ * cub->rci.line_length + x] = 0;
	}
	while (y_max < cub->wind.height)
		cub->rci.addr[y_max++ * cub->rci.line_length + x] = cub->floor.color;
}

void	draw(t_cub *cub, int x)
{
	cub->draw.wall_height = cub->wind.height / cub->ray.dist_wall;
	cub->draw.draw_start = -cub->draw.wall_height / 2 + cub->wind.height / 2;
	if (cub->draw.draw_start < 0)
		cub->draw.draw_start = 0;
	cub->draw.draw_end = cub->draw.wall_height / 2 + cub->wind.height / 2;
	if (cub->draw.draw_end >= cub->wind.height)
		cub->draw.draw_end = cub->wind.height - 1;
	check_4_texture(cub);
	draw_vertical_line(x, cub->draw.draw_start, cub->draw.draw_end, cub);
}

void	left_arrow(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->rc.dir_x;
	cub->rc.dir_x = cub->rc.dir_x * cos(-cub->player.rotate_speed) - cub->rc.dir_y * sin(-cub->player.rotate_speed);
	cub->rc.dir_y = old_dir_x * sin(-cub->player.rotate_speed) + cub->rc.dir_y * cos(-cub->player.rotate_speed);
	old_plane_x = cub->rc.plane_x;
	cub->rc.plane_x = cub->rc.plane_x * cos(-cub->player.rotate_speed) - cub->rc.plane_y * sin(-cub->player.rotate_speed);
	cub->rc.plane_y = old_plane_x * sin(-cub->player.rotate_speed) + cub->rc.plane_y * cos(-cub->player.rotate_speed);
}

void	right_arrow(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->rc.dir_x;
	cub->rc.dir_x = cub->rc.dir_x * cos(cub->player.rotate_speed) - cub->rc.dir_y * sin(cub->player.rotate_speed);
	cub->rc.dir_y = old_dir_x * sin(cub->player.rotate_speed) + cub->rc.dir_y * cos(cub->player.rotate_speed);
	old_plane_x = cub->rc.plane_x;
	cub->rc.plane_x = cub->rc.plane_x * cos(cub->player.rotate_speed) - cub->rc.plane_y * sin(cub->player.rotate_speed);
	cub->rc.plane_y = old_plane_x * sin(cub->player.rotate_speed) + cub->rc.plane_y * cos(cub->player.rotate_speed);
}

void	init_vector(t_cub *cub)
{
	if (ft_ischar("NS", cub->player.spawn_direction))
	{
		cub->rc.plane_x = 0.66;
		cub->rc.plane_y = 0;
		if (cub->player.spawn_direction == 'N')
		{
			cub->rc.dir_x = 0;
			cub->rc.dir_y = -1;
		}
		else
		{
			cub->rc.dir_x = 0;
			cub->rc.dir_y = 1;
		}
	}
	else
	{
		cub->rc.plane_x = 0;
		cub->rc.plane_y = 0.66;
		if (cub->player.spawn_direction == 'E')
		{
			cub->rc.dir_x = 1;
			cub->rc.dir_y = 0;
		}
		else
		{
			cub->rc.dir_x = -1;
			cub->rc.dir_y = 0;
		}
	}
}

void	check_move(t_cub *cub)
{
	if (cub->move.open_door)
		if (cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y)][(int)(cub->player.x + cub->rc.dir_x)] == '#')
			cub->map.tab_map[(int)(cub->player.y + cub->rc.dir_y)][(int)(cub->player.x + cub->rc.dir_x)] = '.';
	if (cub->move.left_arrow)
	{
		if (ft_ischar("NE", cub->player.spawn_direction))
			left_arrow(cub);
		else
			right_arrow(cub);
	}
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

void	put_gray(t_cub *cub)
{
	int x;
	int	y;

	y = 0;
	while (y < cub->wind.height)
	{
		x = 0;
		while (x < cub->wind.width)
		{
			cub->rci.addr[y * cub->rci.line_length + x] = 0x00555555;
			x++;
		}
		y++;
	}
}

void	full_map(t_cub *cub)
{
	int x;
	int y;
	
	if (cub->verif.full_map)
	{
		put_gray(cub);
		y = 0;
		while (cub->map.tab_map[y])
		{
			x = 0;
			while (cub->map.tab_map[y][x])
			{
				if (ft_ischar("NSEW.#", cub->map.tab_map[y][x]))
					multiply_px_map(cub, cub->floor.color, y, x);
				if (cub->map.tab_map[y][x] == '|')
					multiply_px_map(cub, 0x00FF0000, y, x);
				if (cub->map.tab_map[y][x] == '#')
					multiply_px_map(cub, 0x0000FF00, y, x);
				if (cub->map.tab_map[y][x] == '$')
					multiply_px_map(cub, 0x00FFFF00, y, x);
				x++;
			}
			y++;
		}
		multiply_px_map(cub, 0x00FF00FF, cub->player.y, cub->player.x);
	}
	mlx_put_image_to_window(cub->mlx.id, cub->wind.id, cub->rci.img, 0, 0);
}

void	check_direction(t_cub *cub)
{
	char	*dir;

	dir = "NULL";
	if ((cub->rc.dir_x <= 0.750 && cub->rc.dir_x >= -0.750) && cub->rc.dir_y <= -0.500)
		dir = "N";
	if ((cub->rc.dir_y <= 0.750 && cub->rc.dir_y >= -0.750) && cub->rc.dir_x <= -0.500)
		dir = "W";
	if ((cub->rc.dir_x <= 0.750 && cub->rc.dir_x >= -0.750) && cub->rc.dir_y >= 0.500)
		dir = "S";
	if ((cub->rc.dir_y <= 0.750 && cub->rc.dir_y >= -0.750) && cub->rc.dir_x >= 0.500)
		dir = "E";
	mlx_string_put(cub->mlx.id, cub->wind.id, cub->wind.width / 2, cub->wind.height * 0.05, 0x00FFFFFF - cub->sky.color, dir);
}

int	raycasting(t_cub *cub)
{
	int x;

	x = 0;
	if (cub->verif.full_map)
		full_map(cub);
	else
	{
		check_move(cub);
		while (x < cub->wind.width)
		{
			cub->rc.camera = 2 * x / (double)cub->wind.width - 1;
			cub->ray.dir_x = cub->rc.dir_x + cub->rc.plane_x * cub->rc.camera;
	    	cub->ray.dir_y = cub->rc.dir_y + cub->rc.plane_y * cub->rc.camera;
			cub->map.x = (int)cub->player.x;
			cub->map.y = (int)cub->player.y;
			cub->ray.delta_dist_x = fabs(1 / cub->ray.dir_x);
			cub->ray.delta_dist_y = fabs(1 / cub->ray.dir_y);
			init_node_dist(cub);
			check_ray(cub);
			draw(cub, x);
			x++;
		}
		aff_map_wind(cub);
		mlx_put_image_to_window(cub->mlx.id, cub->wind.id, cub->rci.img, 0, 0);
		check_direction(cub);
	}
	return (1);
}

int	key_press(int key, t_cub *cub)
{
	if (key == 48)
		cub->verif.full_map = 1;
	if (key == 53)
		game_finish(cub);
	if (!cub->verif.full_map)
	{
		if (key == 3)
			cub->move.open_door = 1;
		if (key == 46)
		{
			if (cub->verif.map)
				cub->verif.map = 0;
			else
				cub->verif.map = 1; 
		}
		if (key == 2)
			cub->move.right = 1;
		if (key == 13 || key == 126)
			cub->move.up = 1;
		if (key == 1 || key == 125)
			cub->move.down = 1;
		if (key == 0)
			cub->move.left = 1;
		if (key == 124 || key == 14)
			cub->move.right_arrow = 1;
		if (key == 123 || key == 12)
			cub->move.left_arrow = 1;
		aff_map_wind(cub);
	}
	if (key != cub->verif.old_key)
		dprintf(1, "touche :%d\n", key);
	cub->verif.old_key = key;
	return (0);
}

int		key_release(int	key, t_cub *cub)
{
	if (key == 3)
		cub->move.open_door = 0;
	if (key == 48)
		cub->verif.full_map = 0;
	if (key == 2)
		cub->move.right = 0;
	if (key == 13 || key == 126)
		cub->move.up = 0;
	if (key == 1 || key == 125)
		cub->move.down = 0;
	if (key == 0)
		cub->move.left = 0;
	if (key == 124 || key == 14)
		cub->move.right_arrow = 0;
	if (key == 123 || key == 12)	
		cub->move.left_arrow = 0;
	return (1);
}

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

void	init_final_img(t_cub *cub)
{
	cub->rci.img = mlx_new_image(cub->mlx.id, cub->wind.width, cub->wind.height);
	if (!cub->rci.img)
		error("MLX error.\n", cub);
	cub->rci.addr = (int *)mlx_get_data_addr(cub->rci.img, &cub->rci.bits_per_pixel, &cub->rci.line_length, &cub->rci.endian);
	if (!cub->rci.addr)
		error("MLX error.\n", cub);
	cub->rci.line_length /= 4;
}

void	init_img(t_cub *cub)
{
	init_final_img(cub);
	init_no(cub);
	init_so(cub);
	init_we(cub);
	init_ea(cub);
}

void	start_graphic(t_cub	*cub)
{
	init_img(cub);
	init_vector(cub);
	raycasting(cub);
	mlx_hook(cub->wind.id, 2, 0, key_press, cub);
	mlx_hook(cub->wind.id, 3, 1, key_release, cub);
	mlx_hook(cub->wind.id, 17, 1, game_finish, cub);
	mlx_loop_hook(cub->mlx.id, raycasting, cub);
}

int	parsing(char *path, t_cub *cub)
{
	init_structs(path, cub);
	parsing_file(cub);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub cub;
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		cub.verif.screen_shoot = 1;
	if (argc == 2)
		parsing((char *)argv[1], &cub);
	else if (argc < 2)
	{
		ft_putstr("\033[31m\033[1mERROR: \033[0m");
		ft_putstr("\033[38;5;166mVeuillez entrer en argument ");
		ft_putstr("le path d'une carte\033[0m");
		exit (-1);
	}
	else if (argc > 2)
	{
		ft_putstr("\033[31m\033[1mERROR: \033[0m");
		ft_putstr("\033[38;5;166mVeuillez entrer en argument ");
		ft_putstr("un seul path de carte\033[0m");
		exit (-1);
	}
	if (!(cub.mlx.id = mlx_init()))
		error("MLX error.\n", &cub);
	if (!(cub.wind.id = mlx_new_window(cub.mlx.id, cub.wind.width, cub.wind.height, "Cub3D")))
		error("MLX error.\n", &cub);
	aff_all(&cub);
	start_graphic(&cub);
	mlx_loop(cub.mlx.id);
	return (0);
}